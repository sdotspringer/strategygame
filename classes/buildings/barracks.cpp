#include "barracks.hpp"

Barracks::Barracks(unsigned x_location, const unsigned y_location) :
  Building("Barracks", 20, x_location, y_location, BuildingType::BARRACKS) {}

std::unique_ptr<Unit> Barracks::createUnit(UnitType type)
{

}