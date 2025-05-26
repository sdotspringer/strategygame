//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the Player class. 
//
#include "player.hpp"

void Player::setCurrency(const unsigned int amount)
{
  currency_ = amount;
}

unsigned int Player::getCurrency() const
{
  return currency_;
}