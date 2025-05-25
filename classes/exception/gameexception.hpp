//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the GameException class. Used to throw custom exceptions.
//
#ifndef GAMEEXCEPTION_HPP
#define GAMEEXCEPTION_HPP

#include <exception>
#include <string>

//---------------------------------------------------------------------------------------------------------------------
//
/// Used to throw custom exceptions. Works together with the `MessageHandler` to output the correct exception message.
///
/// @param exception_key_ The key that is returned in the `what()` method. Used for lookup in `MessageHandler`
///
/// @attention Copy constructor, assignment operator and no argument constructor are deleted.
//
class GameException : public std::exception
{
  private:
    const std::string exception_key_;

  public:
    GameException() = delete;
    GameException(std::string key);
    GameException(GameException& copy) = delete;
    GameException& operator=(GameException& copy) = delete;
    ~GameException() = default;

    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Overrides standard `what()` to return the key for the `MessageHandler`
    ///
    /// @return Exception message key
    // 
    const char* what() const noexcept override;

};


#endif