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
    std::vector<std::shared_ptr<Unit>> units_;
    unsigned int currency_ = 0;
  public:
    Player() = default;
    Player(const Player& original) = delete;
    Player& operator=(const Player& original) = delete;
    ~Player() = default;


    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Sets the currency of a player to a specific amount.
    ///
    /// @param amount The value that `currency_` should have
    //   
    void setCurrency(const unsigned int amount);

    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Receives the current currency value of this player instance.
    ///
    /// @return Unsigned int of the available currency amount to a player
    //   
    unsigned int getCurrency() const;
};

#endif