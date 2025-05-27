#include "barracks.hpp"

Barracks::Barracks(unsigned x_location, const unsigned y_location) :
  Building(20, x_location, y_location) {}

std::unique_ptr<Unit> Barracks::createUnit(UnitType type)
{

}