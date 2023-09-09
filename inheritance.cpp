#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

#include "Creature.h"
#include "Applod.h"
#include "Barble.h"
#include "Crud.h"

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

  cout << "---------------------------" << endl;
  cout << "-------- Winners ----------" << endl;
  cout << "---------------------------" << endl;

  // cycle through winners and count each type
  int applodCount = 0;
  int barbleCount = 0;
  int crudCount = 0;

  for (int i = 0; i < winners.size(); i++)
  {
    if (winners[i]->getName() == "applod")
    {
      applodCount++;
    }
    else if (winners[i]->getName() == "barble")
    {
      barbleCount++;
    }
    else if (winners[i]->getName() == "crud")
    {
      crudCount++;
    }
  }

  cout << "Applods: " << applodCount << endl;
  cout << "Barbles: " << barbleCount << endl;
  cout << "Cruds: " << crudCount << endl;

  return 0;
}
