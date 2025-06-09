/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "command.h"
#include "customer.h"
#include "movie.h"
#include "store.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

void processMovieData() {
  cout << "=====================================" << endl;
  cout << "Start processMovieData" << endl;
  ifstream file("data4movies.txt");
  assert(file.is_open());

  string line;
  while (getline(file, line)) {

    if (line.empty()) {
      continue;
    }

    Movie *m = MovieFactory::create(line);
    if (m == nullptr) {
      continue;
    }

    Store::getInstance().addMovieToInventory(m);
  }

  file.close();
  cout << "End processMovieData" << endl;
  cout << "=====================================" << endl;
}

void processCustomerData() {
  cout << "=====================================" << endl;
  cout << "Start processCustomerData" << endl;
  ifstream file("data4customers.txt");
  assert(file.is_open());

  string line;
  while (getline(file, line)) {

    if (line.empty()) {
      continue;
    }

    Customer *c = new Customer(line);

    Store::getInstance().registerCustomer(c);
  }

  file.close();
  cout << "End processCustomerData" << endl;
  cout << "=====================================" << endl;
}

void processCommandsSmall() {
  cout << "=====================================" << endl;
  cout << "Start processCommandsSmall" << endl;
  ifstream file("testcommands-1.txt");
  assert(file.is_open());

  string line;
  while (getline(file, line)) {

    if (line.empty()) {
      continue;
    }

    Command *c = CommandFactory::create(line);
    if (c == nullptr) {
      continue;
    }

    if (!c->discard) {
      c->execute();
    }

    delete c;
  }

  file.close();
  cout << "End processCommandsSmall" << endl;
  cout << "=====================================" << endl;
}

void processCommandsLarge() {
  cout << "=====================================" << endl;
  cout << "Start processCommandsLarge" << endl;
  ifstream file("data4commands.txt");
  assert(file.is_open());

  string line;
  while (getline(file, line)) {

    if (line.empty()) {
      continue;
    }

    Command *c = CommandFactory::create(line);
    if (c == nullptr) {
      continue;
    }

    if (!c->discard) {
      c->execute();
    }

    delete c;
  }

  file.close();
  cout << "End processCommandsLarge" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  processMovieData();
  processCustomerData();
  // processCommandsSmall();
  processCommandsLarge();
}
