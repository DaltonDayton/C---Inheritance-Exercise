#pragma once

#include <string>

#include "Creature.h"

class Barbles : public Creature
{
public:
  Barbles();
  void print();
  unsigned int getValue();
  string getInfo();

private:
  unsigned int secondValue{};
};
