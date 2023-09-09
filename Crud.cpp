#include "Crud.h"

Cruds::Cruds() : Creature("crud")
{
  std::uniform_int_distribution<> distrib(1, 2);
  this->value = distrib(Creature::gen);
  if (this->value == 2)
  {
    this->value = 5;
  }
}

string Cruds::getInfo()
{
  return "Name: " + this->name + " Damage: " + std::to_string(this->value);
}
