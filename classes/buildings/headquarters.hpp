//---------------------------------------------------------------------------------------------------------------------
//
/// Declarations for the Headquarters class. Inherits from Building
//
#ifndef HEADQUARTERS_HPP
#define HEADQUARTERS_HPP

#include "building.hpp"

class Headquarters : public Building
{
  private:

  public:
  Headquarters() = delete;
  Headquarters(const unsigned x_location, const unsigned y_location);
  Headquarters(Headquarters& original) = delete;
  Headquarters& operator=(Headquarters& original) = delete;
  ~Headquarters() = default;
};

#endif