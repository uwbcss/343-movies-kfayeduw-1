#include "customermap.h"
#include "customer.h"
#include <iostream>

using namespace std;

int tableSize = 127;

CustomerMap::CustomerMap() {

  for (int i = 0; i < tableSize; i++) {
    vector<Customer *> bucket;
    this->map.push_back(bucket);
  }
}

void CustomerMap::addCustomer(Customer *c) {

  int idx = c->getId() % tableSize;
  vector<Customer *> &bucket = this->map[idx];

  for (Customer *existingCustomer : bucket) {
    if (existingCustomer->getId() == c->getId()) {
      return;
    }
  }

  bucket.push_back(c);
}

Customer *CustomerMap::getCustomer(int id) {

  int idx = id % tableSize;
  vector<Customer *> &bucket = this->map[idx];

  for (Customer *c : bucket) {
    if (c->getId() == id) {
      return c;
    }
  }

  return nullptr;
}

void CustomerMap::clear() {
  for (vector<Customer *> v : this->map) {
    for (int i = 0; i < v.size(); i++) {
      Customer *c = v[i];
      delete c;
    }
  }
}