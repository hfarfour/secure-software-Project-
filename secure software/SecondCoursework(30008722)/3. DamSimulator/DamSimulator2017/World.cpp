#include "World.h"
#include <chrono>
#include "SecureConverter.h"

using namespace std::chrono;

Time World::GetTime() const
{
   uint64_s hours = (m_time / uint64_s(60)) % uint64_s(24); //#V2_1
   uint64_s minutes = m_time % uint64_s(60); //#V2_1

   //Modulo of hours and minutes guarantee an acceptable range for int32 conversion.
   return Time(SecureConverter::Toint32(hours), SecureConverter::Toint32(minutes)); //#V2_2
}

bool World::Update()
{
   uint64_s time = duration_cast<seconds>(system_clock::now().time_since_epoch()).count();

   if (m_time != time)
   {
      m_time = time;

      //Update energy demand.
      static const double minutesOffset = 1080.0; //offset peak by 6 hours.
      static const double minutesInADay = 60 * 24;
      static const double pi = 3.14159265359;

      //Convert from secure ints to double, no chance of overflow.
      double timeDouble = static_cast<double>(m_time.GetValue());
      double amplituteDouble = static_cast<double>(ENERGY_DEMAND_AMPLITUTE.GetValue());

      //Calculate the energy demand from a sin wave.
      double energyDemandVariation = (sin(((timeDouble + minutesOffset) / minutesInADay) * pi) + 1) * 0.5 * amplituteDouble;

      m_energyDemand = ENERGY_DEMAND_MIN + SecureConverter::Toint32(energyDemandVariation); //#V2_2 #V2_3

      //Update weather.
      if (m_time > m_rainChangeTime)
      {
         m_rainChangeTime = m_time + SecureConverter::Touint64(m_rainDistribution(m_rainRandom)); //#V2_1 #V2_3
         m_isRaining = !m_isRaining;
      }

      //Increment water level.
      m_waterLevel = WATER_LEVEL_RUNOFF_INCREMENT + m_waterLevel; //#V2_2
      if (m_isRaining)
      {
         m_waterLevel = WATER_LEVEL_RAIN_INCREMENT + m_waterLevel; //#V2_2
      }

      //Decrement water level.
      m_waterLevel = m_waterLevel - (WATER_LEVEL_DECREMENT_FACTOR * m_valveRelease); //#V2_2

      //Check water level max.
      if (m_waterLevel > WATER_LEVEL_MAX)
      {
         m_isSpillwayActive = true;
         m_waterLevel = WATER_LEVEL_MAX;
      }
      else if (m_isSpillwayActive)
      {
         m_isSpillwayActive = false;
      }

      //Check water level min.
      if (m_waterLevel < WATER_LEVEL_MIN)
      {
         m_isEmpty = true;
         m_waterLevel = WATER_LEVEL_MIN;
      }
      else if (m_isEmpty)
      {
         m_isEmpty = false;
      }

      //Energy output
      if (m_isEmpty)
      {
         m_energyOutput = 0;
      }
      else
      {
         m_energyOutput = ENERGY_OUTPUT_MAX * m_valveRelease; //#V2_2
      }

      return true;
   }
   return false;
}
