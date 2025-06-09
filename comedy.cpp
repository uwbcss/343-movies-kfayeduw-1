#include "comedy.h"
#include "store.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void Comedy::init(string data) {

  data = data.substr(3, data.size() - 3);

  this->type = 'F';
  this->stock = stoi(getNextArgument(data, ", "));
  this->maxStock = this->stock;
  this->director = getNextArgument(data, ", ");
  this->title = getNextArgument(data, ", ");
  this->year = stoi(getNextArgument(data, ", "));
}

bool compareComedy(Movie *a, Movie *b) {

  Comedy *ca = static_cast<Comedy *>(a);
  Comedy *cb = static_cast<Comedy *>(b);

  if (ca->title != cb->title) {
    return ca->title < cb->title;
  }
  return ca->year < cb->year;
}

void Comedy::sortVector(vector<Movie *> &v) {

  sort(v.begin(), v.end(), compareComedy);
}

string Comedy::toString() {
  return "F, " + to_string(this->stock) + ", " + this->director + ", " +
         this->title + ", " + to_string(this->year);
}

Movie *Comedy::fromBRString(string s) {

  string searchTitle = getNextArgument(s, ", ");
  int searchYear = stoi(s);

  unordered_map<char, vector<Movie *>> inventory =
      Store::getInstance().getInventory();

  vector<Movie *> comedies = inventory['F'];

  for (Movie *m : comedies) {
    Comedy *c = static_cast<Comedy *>(m);
    if (c->title != searchTitle) {
      continue;
    }
    if (c->year == searchYear) {
      return c;
    }
  }

  return nullptr;
}

ComedyFactory::ComedyFactory() { registerType('F', this); }

Movie *ComedyFactory::makeMovie() const { return new Comedy(); }

ComedyFactory anonymousComedyFactory;