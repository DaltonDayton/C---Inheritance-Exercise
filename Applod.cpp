#include <string>

#include "Applod.h"

Applods::Applods() : Creature("applod")
{
  std::uniform_int_distribution<> distrib(1, 5);
  this->value = distrib(Creature::gen);
}

string Applods::getInfo()
{
  return "Name: " + this->name + " Damage: " + std::to_string(this->value);
}
