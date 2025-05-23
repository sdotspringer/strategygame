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
    const uint health_base_;
    uint health_current_;
    const uint attack_base_;
    uint attack_current_;
    uint movement_;
    MovementType movement_type_;
    bool can_move_;

  public:
    Unit() = delete;
    Unit(UnitType type, uint health_base, uint attack_base, uint movement, MovementType movement_type);
    Unit(Unit& original) = delete;
    Unit operator=(Unit& original) = delete;

    virtual void attack() = 0;

};

#endif