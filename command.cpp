#include "command.h"
#include <iostream>

using namespace std;

map<char, CommandFactory *> &CommandFactory::getMap() {
  static map<char, CommandFactory *> factories;
  return factories;
}

void CommandFactory::registerType(const char &type, CommandFactory *factory) {
  getMap().emplace(type, factory);
}

Command *CommandFactory::create(const string &data) {
  char type = data[0];
  if (getMap().count(type) == 0) {
    cout << "Can't create a command of type '" << type << "'!" << endl;
    return nullptr;
  }
  Command *c = getMap().at(type)->makeCommand();
  c->init(data);
  return c;
}