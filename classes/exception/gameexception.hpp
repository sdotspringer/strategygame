//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the GameException class. Used to throw custom exceptions.
//
#ifndef GAMEEXCEPTION_HPP
#define GAMEEXCEPTION_HPP

#include <exception>
#include <string>

class GameException : public std::exception
{
  private:
    const std::string exception_key_;

  public:
    GameException(std::string key);
    const char* what() const noexcept override;

};


#endif