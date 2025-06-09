#include "inventorycommand.h"
#include "store.h"
#include <algorithm>
#include <iostream>

using namespace std;

void InventoryCommand::init(string data) {
  if (data.size() != 1) {
    cout << "Invalid H command: '" << data << "'" << endl;
    this->discard = true;
    return;
  }
  this->type = 'I';
}

void InventoryCommand::execute() {

  cout << "\n===================== INVENTORY =====================" << endl;

  unordered_map<char, vector<Movie *>> inventory =
      Store::getInstance().getInventory();

  vector<char> typeOrder = {'F', 'D', 'C'};

  for (char type : typeOrder) {

    vector<Movie *> v = inventory[type];
    if (v.empty()) {
      continue;
    }

    v[0]->sortVector(v);

    for (Movie *m : v) {
      cout << m->toString() << " (" << to_string(m->maxStock - m->stock)
           << " borrowed)" << endl;
    }
  }

  cout << "=====================================================\n" << endl;
}

InventoryCommandFactory::InventoryCommandFactory() { registerType('I', this); }

Command *InventoryCommandFactory::makeCommand() const {
  return new InventoryCommand();
}

InventoryCommandFactory anonymousInventoryCommandFactory;