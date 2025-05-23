#include "classes/units/unit.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
if(argc != 2)
{
  std::cout << "[ERROR] Wrong number of game arguments." << std::endl;
  return 1;
}

std::ifstream file(argv[1]);
if(!file.is_open())
{
  std::cout << "[ERROR] Please enter a valid file path." << std::endl;
  return 2;
}
return 0;
}