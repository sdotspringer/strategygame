//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the GameException class. Used to throw custom exceptions.
//
#include "gameexception.hpp"
#include "../messagehandler/messagehandler.hpp"

GameException::GameException(std::string key) : exception_key_(key) {}

const char* GameException::what() const noexcept
{
  return exception_key_.c_str();
}
