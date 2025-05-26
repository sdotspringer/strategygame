//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the Game class. It initializes the map and keeps track of the gamestate.
//
#ifndef GAME_HPP
#define GAME_HPP

#include "../units/unit.hpp"
#include "../exception/gameexception.hpp"
#include "../player/player.hpp"
#include <iostream>
#include <memory>

// Color constants for terminal output
const std::string color_green = "\033[42m";
const std::string color_yellow = "\033[43m";
const std::string color_blue = "\033[44m";
const std::string color_reset = "\033[0m";

//---------------------------------------------------------------------------------------------------------------------
//
/// Games class that initializes the map and handles map printing and the overall gamestate.
///
/// @param x_size_ Maximum value of the x coordinate
/// @param y_size_ Maximum value of the y coordinate
/// @param map_ Map that stores the ground-type
/// @param unit_map_ Map that stores untit location
/// @param round_number_ Counter that keeps track of the turn number
///
/// @attention Copy constructor and assignment operator are deleted;
//
class Game
{
  private:
    Player* player_one_;
    Player* player_two_;
    unsigned int x_size_ = 0;
    unsigned int y_size_ = 0;
    std::vector<std::vector<char>> map_ = {};
    std::vector<std::vector<std::unique_ptr<Unit>>> unit_map_ = {};
    unsigned int round_number_ = 0;

    std::string printLogic(unsigned int x, unsigned int y);
  public:

    Game();
    Game(Game& original) = delete;
    Game& operator=(Game& original) = delete;
    ~Game();
  
    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Initializes the map, based on the size and tiles in the config file. Also initializes all the unit fields to
    /// nullptr
    ///
    /// @param file The file that contains the map
    //
    void loadGameMap(std::string file);
  
    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Prints the map. Backgroundcolor of the field depends on the ground-type. If a unit is present the char
    /// representation of that unit is printed, otherwise the character representation of the ground-type.
    ///
    //    
    void printMap();

    //-----------------------------------------------------------------------------------------------------------------
    //
    /// Receives the current round number from the `Game` instance.
    ///
    /// @return Current round number as unsigned int
    //   
    unsigned int getRoundNumber() const;
};


#endif