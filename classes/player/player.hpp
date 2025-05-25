//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the Player class. 
//
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <set>
#include <memory>
#include "../units/unit.hpp"
#include "../buildings/building.hpp"

class Player
{
  private:
    std::shared_ptr<Unit> units_;
    std::shared_ptr<Building> buildings_;
    unsigned int currency_;
  public:
    Player() = default;
    Player(Player& original) = delete;
    Player& operator=(Player& original) = delete;
    ~Player() = default;

};

#endif