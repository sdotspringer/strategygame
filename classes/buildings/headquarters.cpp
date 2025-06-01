#include "headquarters.hpp"

Headquarters::Headquarters(const unsigned x_location, const unsigned y_location) :
  Building("Headquarters", 20, x_location, y_location, BuildingType::HEADQUARTERS) {}