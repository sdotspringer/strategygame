#include "classes/game/game.hpp"
#include "classes/units/unit.hpp"

#include <iostream>
#include <fstream>

enum ExitCodes
{
  SUCCESFUL_TERMINATION,
  INVALID_ARGUMENT_COUNT,
  INVALID_FILE_PATH,
  OUT_OF_MEMORY
};

int main(int argc, char* argv[])
{
if(argc != 2)
{
  std::cout << "[ERROR] Wrong number of game arguments." << std::endl;
  return INVALID_ARGUMENT_COUNT;
}

Game game;
game.loadGameMap(argv[1]);
game.printXAndY();
game.printMap();

return SUCCESFUL_TERMINATION;
}