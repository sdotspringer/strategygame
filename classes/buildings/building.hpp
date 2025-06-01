//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the Building class. Buildings can recruit different types of units.
//
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <memory>

class Player;

enum class BuildingType
{
  HEADQUARTERS,
  BARRACKS
};

class Building
{
  protected:
    std::string name_;
    const unsigned int health_max_;
    unsigned int health_current_;
    const unsigned int x_location_;
    const unsigned int y_location_;
    BuildingType type_;
    Player* owner_;
  public:
    Building() = delete;
    Building(std::string name, const unsigned int health_max,
      const unsigned int x_location, const unsigned int y_location, BuildingType type);
    Building(Building& original) = delete;
    Building& operator=(Building& original) = delete;
    ~Building() = default;

    void debugPrintBuilding();
};

#endif
