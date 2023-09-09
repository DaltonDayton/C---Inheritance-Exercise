#pragma once

#include <random>
#include <string>

using std::string;

class Creature
{
public:
  Creature(const string &name);
  void print();
  unsigned int getValue();
  virtual string getInfo() = 0; // Pure virtual method (Makes the class abstract)
  static Creature *fight(Creature *first, Creature *second);

protected:
  unsigned int value{};
  string name;
  static std::random_device rd;
  static std::mt19937 gen;

private:
};
