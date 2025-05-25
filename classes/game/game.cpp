//---------------------------------------------------------------------------------------------------------------------
//
/// Definitions for the Game class. It initializes the map and keeps track of the gamestate.
//
#include <format>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


#include "game.hpp"
#include "../exception/gameexception.hpp"
#include "../messagehandler/messagehandler.hpp"

Game::Game(Player& player_one, Player& player_two) : player_one_(player_one), player_two_(player_two) {}

void Game::loadGameMap(std::string file)
{
  // Check if file could be opened
  std::ifstream map_config(file);
  if(!map_config.is_open())
  {
    throw(GameException("E_CANNOT_OPEN_FILE"));
  }

  // Check file for correct magic word
  std::string line;
  std::getline(map_config, line);
  if(line != "MAP")
  {
    throw(GameException("E_WRONG_FILE"));
  }

  // Init x and y size
  std::getline(map_config, line);
  x_size_ = stoi(line);
  std::getline(map_config, line);
  y_size_ = stoi(line);
  
  // Read map tiles from file and initialize map
  map_.resize(y_size_);
  std::string token;
  for(size_t counter = 0; counter < y_size_; counter++)
  {
    std::getline(map_config, line);
    std::stringstream line_to_delimit(line);
    while(std::getline(line_to_delimit, token, ' '))
    {
      map_[counter].push_back(token.at(0));
    }
  }

  // Initialize unit map with nullptr for each tile
  unit_map_.resize(y_size_);
  for(auto& row : unit_map_)
  {
    row.resize(x_size_);
  }

  round_number_ = 1;
}

std::string Game::printLogic(unsigned int x, unsigned int y)
{
  std::string output;
  char field = map_[y][x];
  if(field == 'G')
  {
    output += color_green;
  }
  else if(field == 'W')
  {
    output += color_blue;
  }
  else if(field == 'M')
  {
    output += color_yellow;
  }

  if(unit_map_[y][x] != nullptr)
  {
    //TODO: Add unit character
    output += ('(' + ')');
  }
  else
  {
    output += " ";
    output += field;
    output += " ";
  }

  output += color_reset;
  return output;
}

// TODO: Think about index formatting, I don't like the way double digit numbers look
void Game::printMap()
{
  std::cout << MessageHandler::getInstance().getMessage("D_TOP_BORDER") << std::endl;
  std::cout << "    ";
  for(size_t index = 0; index < x_size_; index++)
  {
    std::cout << std::format(" {:02d}", index + 1);
  }
  std::cout << std::endl;

  std::string print_string;
  for(size_t y = 0; y < y_size_; y++)
  {
    print_string = std::format("  {:02d} ", y + 1);
    for(size_t x = 0; x < x_size_; x++)
    {
      print_string += printLogic(x, y);
    }
    std::cout << print_string;
    std::cout << std::endl;
  }
  std::cout << MessageHandler::getInstance().getMessage("D_BOTTOM_BORDER") << std::endl << std::endl;
}