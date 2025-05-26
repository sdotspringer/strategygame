//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the Building class. Buildings can recruit different types of units.
//
#include "building.hpp"

Building::Building(const unsigned int health_max, const unsigned int x_location, const unsigned int y_location) :
health_max_(health_max), health_current_(health_max), x_location_(x_location), y_location_(y_location) {}
