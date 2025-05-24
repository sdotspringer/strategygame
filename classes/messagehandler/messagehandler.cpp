//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the singleton MessageHandler class. Parses the message config file and handles message output.
//
#include "messagehandler.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


MessageHandler& MessageHandler::getInstance()
{
  static MessageHandler instance;
  return instance;
}

void MessageHandler::initializeMessages(std::string file)
{
  std::string message_key;
  std::string message_text;
  std::string line;
  std::ifstream message_file(file);

  if(!message_file.is_open())
  {
    std::cout << "[ERROR] Message file could not be opened" << std::endl;
    return;
  }

  std::getline(message_file, line);
  if(line != "MESSAGES")
  {
    std::cout << "[ERROR] Message file is not correct" << std::endl;
  }

  while(std::getline(message_file, line))
  {
    std::stringstream line_to_parse(line);
    std::getline(line_to_parse, message_key, ':');
    std::getline(line_to_parse, message_text, ':');

    messages_.insert({message_key, message_text});
  }
}

std::string MessageHandler::getMessage(std::string key)
{
  if(messages_.contains(key))
  {
    return messages_.at(key);
  }
  return "[ERROR] Message not found, check the config file!";
}