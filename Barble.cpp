#include <iostream>

#include "Barble.h"

using std::cout;
using std::endl;

Barbles::Barbles() : Creature("barble")
{
  std::uniform_int_distribution<> distrib(1, 2);
  this->value = distrib(Creature::gen);
  std::uniform_int_distribution<> distrib2(1, 3);
  this->secondValue = distrib2(Creature::gen);
}

void Barbles::print()
{
  cout << "The values are " << this->value << " and " << this->secondValue << endl;
}

unsigned int Barbles::getValue()
{
  return this->value + this->secondValue;
}

string Barbles::getInfo()
{
  return "Name: " + this->name + " Damage 1: " + std::to_string(this->value) + " Damage 2: " + std::to_string(this->secondValue);
}
