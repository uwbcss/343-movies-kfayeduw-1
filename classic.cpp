#include "classic.h"
#include "store.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void Classic::init(string data) {

  data = data.substr(3, data.size() - 3);

  this->type = 'C';
  this->stock = stoi(getNextArgument(data, ", "));
  this->maxStock = this->stock;
  this->director = getNextArgument(data, ", ");
  this->title = getNextArgument(data, ", ");
  data = getNextArgument(data, ", ");
  this->majorActor =
      getNextArgument(data, " ") + " " + getNextArgument(data, " ");
  this->month = stoi(getNextArgument(data, " "));
  this->year = stoi(getNextArgument(data, " "));
}

bool compareClassic(Movie *a, Movie *b) {

  Classic *ca = static_cast<Classic *>(a);
  Classic *cb = static_cast<Classic *>(b);

  if (ca->year != cb->year) {
    return ca->year < cb->year;
  }
  if (ca->month != cb->month) {
    return ca->month < cb->month;
  }
  return ca->majorActor < cb->majorActor;
}

void Classic::sortVector(vector<Movie *> &v) {

  sort(v.begin(), v.end(), compareClassic);
}

string Classic::toString() {
  return "C, " + to_string(this->stock) + ", " + this->director + ", " +
         this->title + ", " + this->majorActor + " " + to_string(this->month) +
         " " + to_string(this->year);
}

Movie *Classic::fromBRString(string s) {

  int searchMonth = stoi(getNextArgument(s, " "));
  int searchYear = stoi(getNextArgument(s, " "));
  string searchActor = s;

  unordered_map<char, vector<Movie *>> inventory =
      Store::getInstance().getInventory();

  vector<Movie *> classics = inventory['C'];

  for (Movie *m : classics) {
    Classic *c = static_cast<Classic *>(m);
    if (c->month != searchMonth) {
      continue;
    }
    if (c->year != searchYear) {
      continue;
    }
    if (c->majorActor == searchActor) {
      return c;
    }
  }

  return nullptr;
}

ClassicFactory::ClassicFactory() { registerType('C', this); }

Movie *ClassicFactory::makeMovie() const { return new Classic(); }

ClassicFactory anonymousClassicFactory;