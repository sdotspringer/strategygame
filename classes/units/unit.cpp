//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the abstract base class Unit.
//
#include "unit.hpp"

Unit::Unit(UnitType type, uint health_base, uint attack_base, uint movement, MovementType movement_type) :
type_(type),
health_base_(health_base),
health_current_(health_base),
attack_base_(attack_base),
attack_current_(attack_base),
movement_(movement),
movement_type_(movement_type) {}

