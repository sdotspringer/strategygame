//---------------------------------------------------------------------------------------------------------------------
//
/// Implementation of the abstract base class for units. 
//
#ifndef UNIT_HPP
#define UNIT_HPP

#include <string>

//---------------------------------------------------------------------------------------------------------------------
//
/// What category a specific unit belongs to
//
enum class UnitType
{
  WARRIOR,
  ARCHER,
  MAGE
};

//---------------------------------------------------------------------------------------------------------------------
//
/// Abstract base class for all units.
///
/// @param name_ Name of the unit
/// @param type_
//
class Unit
{
  protected:
    UnitType type_;
    uint health_base_;
    uint health_current_;
    uint attack_base_;
    uint attack_current_;
    uint movement_;
    bool can_move_;
    bool ground_;
    bool flight_;
    bool swim_;

  public:
    Unit() = delete;
    Unit(UnitType type);

    virtual void attack() = 0;

};

#endif