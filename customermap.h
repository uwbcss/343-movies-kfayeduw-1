#ifndef CUSTOMERMAP_H
#define CUSTOMERMAP_H

#include "customer.h"
#include <vector>

class CustomerMap {
private:
  vector<vector<Customer *>> map;

public:
  CustomerMap();
  void addCustomer(Customer *c);
  Customer *getCustomer(int id);
  void clear();
};

#endif