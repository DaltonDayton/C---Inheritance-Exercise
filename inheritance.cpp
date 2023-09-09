#include <iostream>
#include <random>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Creature
{
public:
  Creature(const string &name);
  void print();
  unsigned int getValue();
  virtual string getInfo() = 0; // Pure virtual method (Makes the class abstract)

  static std::random_device rd;
  static std::mt19937 gen;

protected:
  unsigned int value{};
  string name;

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

int main()
{
  Applods myApplods[10];
  Barbles myBarbles[10];
  Cruds myCruds[10];

  for (int i = 0; i < 10; i++)
  {
    cout << myApplods[i].getInfo() << endl;
  }

  cout << "----------------" << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << myBarbles[i].getInfo() << endl;
  }

  cout << "----------------" << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << myCruds[i].getInfo() << endl;
  }

  for (int i = 0; i < 10; i++)
  {
    unsigned int a = myApplods[i].getValue();
    unsigned int b = myBarbles[i].getValue();
    unsigned int c = myCruds[i].getValue();

    if (a > b)
    {
      if (a > c)
      {
        cout << "The Applod won" << endl;
      }
      else
      {
        cout << "The Crud won" << endl;
      }
    }
    else
    {
      if (b > c)
      {
        cout << "The Barble won" << endl;
      }
      else
      {
        cout << "The Crud won" << endl;
      }
    }
  }

  cin.get();
  return 0;
}
