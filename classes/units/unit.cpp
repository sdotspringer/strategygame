//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the abstract base class Unit.
//
#include "unit.hpp"

Unit::Unit(UnitType type, unsigned int health_base, unsigned int attack_base, unsigned int movement,
           MovementType movement_type, unsigned int x_location, unsigned int y_location) :
type_(type),
health_base_(health_base),
health_current_(health_base),
attack_base_(attack_base),
attack_current_(attack_base),
movement_(movement),
movement_type_(movement_type),
x_location_(x_location),
y_location_(y_location) {}

Unit& Unit::operator<(Unit& compare_to)
{
  if(x_location_ < compare_to.x_location_)
  {
    return *this;
  }
  else if(x_location_ == compare_to.x_location_)
  {
    if(y_location_ < compare_to.y_location_)
    {
      return *this;
    }
  }
  return compare_to;
}