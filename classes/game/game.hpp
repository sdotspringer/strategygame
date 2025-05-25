//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the Game class. It initializes the map and keeps track of the gamestate.
//
#ifndef GAME_HPP
#define GAME_HPP

#include "../units/unit.hpp"
#include "../exception/gameexception.hpp"
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
    uint x_size_;
    uint y_size_;
    std::vector<std::vector<char>> map_;
    std::vector<std::vector<std::unique_ptr<Unit>>> unit_map_;
    uint round_number_;

    std::string printLogic(uint x, uint y);
  public:
    Game() = default;
    Game(Game& original) = delete;
    Game& operator=(Game& original) = delete;
    ~Game() = default;

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
};


#endif