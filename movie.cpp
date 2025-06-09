#include "movie.h"
#include <iostream>

using namespace std;

map<char, MovieFactory *> &MovieFactory::getMap() {
  static map<char, MovieFactory *> factories;
  return factories;
}

void MovieFactory::registerType(const char &type, MovieFactory *factory) {
  getMap().emplace(type, factory);
}

Movie *MovieFactory::create(const string &data) {
  char type = data[0];
  if (getMap().count(type) == 0) {
    cout << "Can't create a movie of type '" << type << "'!" << endl;
    return nullptr;
  }
  Movie *m = getMap().at(type)->makeMovie();
  m->init(data);
  return m;
}

string Movie::getNextArgument(string &s, string splitter) {

  int splitIdx = s.find(splitter);
  if (splitIdx < 0 || splitIdx >= s.length()) {
    string arg = s;
    s = "";
    return arg;
  }

  string arg = s.substr(0, splitIdx);
  s = s.substr(splitIdx + splitter.size(),
               s.size() - splitIdx + splitter.size());
  return arg;
}