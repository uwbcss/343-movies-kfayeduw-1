#include "store.h"
#include "customer.h"
#include "movie.h"
#include <iostream>

using namespace std;

Store::~Store() {
  for (auto pair : this->inventory) {
    vector<Movie *> v = pair.second;
    for (int i = 0; i < v.size(); i++) {
      Movie *m = v[i];
      delete m;
    }
  }

  this->customerMap.clear();
}

void Store::addMovieToInventory(Movie *m) {
  this->inventory[m->type].push_back(m);
}

void Store::registerCustomer(Customer *c) { this->customerMap.addCustomer(c); }

Customer *Store::getCustomer(int id) {
  return this->customerMap.getCustomer(id);
}

unordered_map<char, vector<Movie *>> Store::getInventory() {
  return this->inventory;
}