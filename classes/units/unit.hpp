//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the abstract base class Unit
//
#ifndef UNIT_HPP
#define UNIT_HPP

#include <string>
#include <vector>
#include <tuple>

//---------------------------------------------------------------------------------------------------------------------
//
/// Defines what type a specific unit is
//
enum class UnitType
{
  WARRIOR,
  ARCHER,
  MAGE
};

//---------------------------------------------------------------------------------------------------------------------
//
/// Defines how a unit can move
//
enum class MovementType
{
  WALK,
  FLY,
  SWIM
};

//---------------------------------------------------------------------------------------------------------------------
//
/// Abstract base class for all units.
///
/// @param type_ Type of the unit
/// @param health_base_ Initial health of a unit
/// @param health_current_ Current health of a specific unit
/// @param attack_base_ Initial attack of a unit
/// @param attack_current_ Current attack of a specific unit
/// @param movement_ How many fields a unit can cross per turn
/// @param movement_type_ How the unit moves
/// @param can_move_ If a unit can move this turn
///
/// @attention Deleted constructor without arguments, copy constructor and assignment operator
//
class Unit
{
  protected:
    UnitType type_;
    const unsigned int health_base_;
    unsigned int health_current_;
    const unsigned int attack_base_;
    unsigned int attack_current_;
    unsigned int movement_;
    MovementType movement_type_;
    bool can_move_;
    unsigned int x_location_;
    unsigned int y_location_;
    unsigned int cost_;

  public:
    Unit() = delete;
    Unit(UnitType type, unsigned int health_base, unsigned int attack_base, unsigned int movement,
         MovementType movement_type, unsigned int x_location, unsigned int y_location);
    Unit(Unit& original) = delete;
    Unit& operator=(Unit& original) = delete;
    virtual ~Unit() = default;

    Unit& operator<(Unit& compare_to);

    virtual void attack() = 0;
    virtual void move() = 0;

};

#endif