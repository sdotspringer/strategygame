//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the Building class. Buildings can recruit different types of units.
//
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <memory>
#include "../player/player.hpp"

class Building
{
  protected:
    const unsigned int health_max_;
    unsigned int health_current_;
    const unsigned int x_location_;
    const unsigned int y_location_;
  public:
    Building() = delete;
    Building(const unsigned int health_max, const unsigned int x_location, const unsigned int y_location);
    Building(Building& original) = delete;
    Building& operator=(Building& original) = delete;
    ~Building() = default;
};

#endif
