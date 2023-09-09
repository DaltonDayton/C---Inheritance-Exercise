#include <iostream>
#include <string>

#include "Creature.h"

using std::cout;
using std::endl;
using std::string;

std::random_device Creature::rd;
std::mt19937 Creature::gen(Creature::rd());

Creature::Creature(const string &name)
{
  this->name = name;
}

void Creature::print()
{
  cout << "The damage is: " << value << endl;
}

unsigned int Creature::getValue()
{
  return value;
}

Creature *Creature::fight(Creature *first, Creature *second)
{
  if (first->getValue() > second->getValue())
  {
    return first;
  }
  else
  {
    return second;
  }
}
