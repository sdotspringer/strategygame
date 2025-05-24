//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the GameException class. Used to throw custom exceptions.
//
#ifndef GAMEEXCEPTION_HPP
#define GAMEEXEPTION_HPP

#include <exception>
#include <string>

class GameException : public std::exception
{
  private:
    const std::string exception_message_;

  public:
    GameException() {}
    const char* what() const noexcept override;

};


#endif