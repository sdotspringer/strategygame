#include "classes/game/game.hpp"
#include "classes/units/unit.hpp"
#include "classes/messagehandler/messagehandler.hpp"
#include "classes/exception/gameexception.hpp"

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
if(argc != 3)
{
  std::cout << "[ERROR] Wrong number of game arguments." << std::endl;
  return INVALID_ARGUMENT_COUNT;
}

MessageHandler::getInstance().initializeMessages(argv[2]);

Player one;
Player two;
Game game{};
game.loadGameMap(argv[1]);

game.printMap();
game.debugPrintBuildings();

return SUCCESFUL_TERMINATION;
}