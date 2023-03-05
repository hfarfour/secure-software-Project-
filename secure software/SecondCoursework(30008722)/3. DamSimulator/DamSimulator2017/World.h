#pragma once
#include <random>
#include "SecureInts.h"
#include "Time.h"

//Contains all the simulation logic of the world.
class World
{
public:
   bool Update();

   Time GetTime() const;
   bool GetIsRaining() const { return m_isRaining; }
   int32_s GetEnergyOutput() const { return m_energyOutput; }
   int32_s GetEnergyDemand() const { return m_energyDemand; }
   bool GetIsSpillwayActive() const { return m_isSpillwayActive; }
   int32_s GetMaxWaterLevel() const { return WATER_LEVEL_MAX; }
   int32_s GetWaterLevel() const { return m_waterLevel; }
   void SetValveRelease(const int32_s& valveRelease) { m_valveRelease = valveRelease; };
   int32_s GetValveRelease() const { return m_valveRelease; }

private:
   //World
   uint64_s m_time = 0; //Minutes

   //Energy
   const int32_s ENERGY_DEMAND_MIN = 1000; //MW
   const int32_s ENERGY_DEMAND_AMPLITUTE = 1000; //MW
   const int32_s ENERGY_OUTPUT_MAX = 2600; //MW

   //Water
   const int32_s WATER_LEVEL_DECREMENT_FACTOR = 10;
   const int32_s WATER_LEVEL_RUNOFF_INCREMENT = 400;
   const int32_s WATER_LEVEL_RAIN_INCREMENT = 30;
   const int32_s WATER_LEVEL_MAX = 100000;
   const int32_s WATER_LEVEL_MIN = 0;

   //Rain
   const int32_t MIN_RAIN_CHANGE_TIME = 10; //Minutes. These can be int32_t as no arithmetic is performed. 
   const int32_t MAX_RAIN_CHANGE_TIME = 60; //Minutes
   std::uniform_int_distribution<> m_rainDistribution{ MIN_RAIN_CHANGE_TIME, MAX_RAIN_CHANGE_TIME };
   std::mt19937 m_rainRandom{ 777 };

   //Sensor values.
   bool m_isRaining = false;
   uint64_s m_rainChangeTime = 0;
   int32_s m_energyDemand = 0;
   int32_s m_energySupply = 0;
   bool m_isSpillwayActive = false;
   bool m_isEmpty = false;
   int32_s m_valveRelease = 0;
   int32_s m_waterLevel = 0;
   int32_s m_energyOutput = 0;
};