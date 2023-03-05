#pragma once
#include "Role.h"

class IDevice
{
public:
   virtual Users::Role GetRequiredRole() const = 0;
};