#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"
#include <vector>

struct Transaction {
  string transactionType;
  string mediaType;
  Movie *m;
};

class Customer {
private:
  int id;
  string name;
  vector<Transaction> history;

public:
  explicit Customer(string &data);

  int getId() const;
  string getName();
  vector<Transaction> &getHistory();

  void borrowItem(Movie *m, string mediaType);
  void returnItem(Movie *m, string mediaType);

  ~Customer() = default;
};

#endif