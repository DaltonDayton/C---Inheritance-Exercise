#include <iostream>
#include <random>

using std::cin;
using std::cout;
using std::endl;

class Creature
{
public:
  void print();
  static std::random_device rd;
  static std::mt19937 gen;
  static std::uniform_int_distribution<> distrib;

protected:
  unsigned int value{};

private:
};
std::random_device Creature::rd;
std::mt19937 Creature::gen(Creature::rd());
std::uniform_int_distribution<> Creature::distrib(1, 5);

void Creature::print()
{
  cout << "The damage is: " << value << endl;
}

class Applods : public Creature
{
public:
  Applods();

private:
};

Applods::Applods()
{
  this->value = Creature::distrib(Creature::gen);
}

int main()
{
  Applods myApplods[10];
  // Barbles myBarbles[10];
  // Cruds myCruds[10];

  for (int i = 0; i < 10; i++)
  {
    myApplods[i].print();
  }

  cin.get();
}
