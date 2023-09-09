#include <iostream>
#include <random>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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

class Applods : public Creature
{
public:
  Applods();
  string getInfo();

private:
};

Applods::Applods() : Creature("applod")
{
  std::uniform_int_distribution<> distrib(1, 5);
  this->value = distrib(Creature::gen);
}

string Applods::getInfo()
{
  return "Name: " + this->name + " Damage: " + std::to_string(this->value);
}

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

class Cruds : public Creature
{
public:
  Cruds();
  string getInfo();

private:
};

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

void displayAll(vector<Creature *> &someCreatures)
{
  for (int i = 0; i < someCreatures.size(); i++)
  {
    cout << someCreatures[i]->getInfo() << endl;
  }
}

int main()
{
  vector<Creature *> myCreatures;
  for (int i = 0; i < 10; i++)
  {
    myCreatures.push_back(new Applods());
    myCreatures.push_back(new Barbles());
    myCreatures.push_back(new Cruds());
  }

  displayAll(myCreatures);

  cout << "---------------------------" << endl;
  cout << "---------- Fight ----------" << endl;
  cout << "---------------------------" << endl;

  vector<Creature *> winners;

  for (int i = 0; i < myCreatures.size(); i += 2)
  {
    Creature *winner = Creature::fight(myCreatures[i], myCreatures[i + 1]);
    cout << "The fighters: " << endl;
    cout << " " << myCreatures[i]->getInfo() << endl;
    cout << " " << myCreatures[i + 1]->getInfo() << endl;
    cout << "The winner was: " << winner->getInfo() << endl;
    winners.push_back(winner);
  }

  cin.get();
  return 0;
}
