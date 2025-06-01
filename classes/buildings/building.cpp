//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the Building class. Buildings can recruit different types of units.
//
#include "building.hpp"
#include "../player/player.hpp"
#include <iostream>

Building::Building(std::string name, const unsigned int health_max,
  const unsigned int x_location, const unsigned int y_location, BuildingType type) :
name_(name), health_max_(health_max),
health_current_(health_max), x_location_(x_location),
y_location_(y_location), type_(type), owner_(nullptr) {}


void Building::debugPrintBuilding()
{
  std::cout << name_ << " at location: " << x_location_ + 1 << "," << y_location_ + 1 << ". Owner: ";
  if(owner_ == nullptr)
  {
    std::cout << "Nobody.";
  }
  std::cout << std::endl;
}
