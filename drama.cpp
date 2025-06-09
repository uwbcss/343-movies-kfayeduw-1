#include "drama.h"
#include "store.h"
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void Drama::init(string data) {

  data = data.substr(3, data.size() - 3);

  this->type = 'D';
  this->stock = stoi(getNextArgument(data, ", "));
  this->maxStock = this->stock;
  this->director = getNextArgument(data, ", ");
  this->title = getNextArgument(data, ", ");
  this->year = stoi(getNextArgument(data, ", "));
}

bool compareDrama(Movie *a, Movie *b) {

  Drama *da = static_cast<Drama *>(a);
  Drama *db = static_cast<Drama *>(b);

  if (da->director != db->director) {
    return da->director < db->director;
  }
  return da->title < db->title;
}

void Drama::sortVector(vector<Movie *> &v) {

  sort(v.begin(), v.end(), compareDrama);
}

string Drama::toString() {
  return "D, " + to_string(this->stock) + ", " + this->director + ", " +
         this->title + ", " + to_string(this->year);
}

Movie *Drama::fromBRString(string s) {

  string searchDirector = getNextArgument(s, ", ");
  string searchTitle = getNextArgument(s, ",");

  unordered_map<char, vector<Movie *>> inventory =
      Store::getInstance().getInventory();

  vector<Movie *> dramas = inventory['D'];

  for (Movie *m : dramas) {
    Drama *d = static_cast<Drama *>(m);
    if (d->director != searchDirector) {
      continue;
    }
    if (d->title == searchTitle) {
      return d;
    }
  }

  return nullptr;
}

DramaFactory::DramaFactory() { registerType('D', this); }

Movie *DramaFactory::makeMovie() const { return new Drama(); }

DramaFactory anonymousDramaFactory;