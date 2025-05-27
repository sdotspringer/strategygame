//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the Barracks class. Inherits from Building
//
#ifndef BARRACKS_HPP
#define BARRACKS_HPP

#include "building.hpp"
#include "../units/unit.hpp"

class Barracks : public Building
{
  private:

  public:
  Barracks() = delete;
  Barracks(const unsigned x_location, const unsigned y_location);
  Barracks(Barracks& original) = delete;
  Barracks& operator=(Barracks& original) = delete;
  ~Barracks() = default;

  std::unique_ptr<Unit> createUnit(UnitType type);
};

#endif