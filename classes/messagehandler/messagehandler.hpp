//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the singleton MessageHandler class. Parses the message config file and handles message output.
//
#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include <string>
#include <unordered_map>

//---------------------------------------------------------------------------------------------------------------------
//
/// Class that parses message key value pairs from the config file and is able to return the messages as string.
///
/// @param messages_ The map that contains the message identifier key and the corresponding message text.
///
/// @attention This is a singleton, copy constructor and assignment operator are deleted
//
class MessageHandler
{
  private:
    std::unordered_map<std::string, std::string> messages_;
    
    MessageHandler() = default;
    
    public:
    MessageHandler(const MessageHandler& original) = delete;
    MessageHandler& operator=(const MessageHandler& original) = delete;
    ~MessageHandler() = default;

    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Method that returns the instance of the singleton.
    ///
    /// @return Instance of class
    //
    static MessageHandler& getInstance();

    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Initializes all of the messages from the specified file.
    ///
    /// @param file The file where the MessageHandler should read from.
    //
    void initializeMessages(std::string file);

    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Returns the message string belonging to the entered key.
    ///
    /// @param key What key should be looked up in the map.
    ///
    /// @return The string that is mapped to the key.
    //
    std::string getMessage(std::string key);
};

#endif