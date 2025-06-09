#ifndef STORE_H
#define STORE_H

#include "customer.h"
#include "customermap.h"
#include "movie.h"
#include <unordered_map>
#include <vector>

class Store {
private:
  unordered_map<char, vector<Movie *>> inventory;
  CustomerMap customerMap;

public:
  ~Store();

  static Store &getInstance() {
    static Store instance;
    return instance;
  }

  void addMovieToInventory(Movie *m);
  void registerCustomer(Customer *c);
  Customer *getCustomer(int id);
  unordered_map<char, vector<Movie *>> getInventory();
};

#endif