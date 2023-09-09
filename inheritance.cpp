#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

class Creature
{
public:
  void print();
  unsigned int getValue();
  static std::random_device rd;
  static std::mt19937 gen;

protected:
  unsigned int value{};

private:
};
std::random_device Creature::rd;
std::mt19937 Creature::gen(Creature::rd());

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

private:
};

Applods::Applods()
{
  std::uniform_int_distribution<> distrib(1, 5);
  this->value = distrib(Creature::gen);
}

class Barbles : public Creature
{
public:
  Barbles();
  void print();
  unsigned int getValue();

private:
  unsigned int secondValue{};
};

Barbles::Barbles()
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

class Cruds : public Creature
{
public:
  Cruds();

private:
};

Cruds::Cruds()
{
  std::uniform_int_distribution<> distrib(1, 2);
  this->value = distrib(Creature::gen);
  if (this->value == 2)
  {
    this->value = 5;
  }
}

int main()
{
  Applods myApplods[10];
  Barbles myBarbles[10];
  Cruds myCruds[10];

  for (int i = 0; i < 10; i++)
  {
    myApplods[i].print();
  }

  cout << "----------------" << endl;

  for (int i = 0; i < 10; i++)
  {
    myBarbles[i].print();
  }

  cout << "----------------" << endl;

  for (int i = 0; i < 10; i++)
  {
    myCruds[i].print();
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
