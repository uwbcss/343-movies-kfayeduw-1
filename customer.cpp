#include "customer.h"
#include <iostream>

using namespace std;

Customer::Customer(string &data) {

  int spaceIdx = data.find(" ");

  this->id = stoi(data.substr(0, spaceIdx));
  this->name = data.substr(spaceIdx + 1, data.size() - spaceIdx + 1);
}

int Customer::getId() const { return this->id; }

string Customer::getName() { return this->name; }

vector<Transaction> &Customer::getHistory() { return this->history; }

void Customer::borrowItem(Movie *m, string mediaType) {

  if (m->stock < 1) {
    cout << m->title << " is out of stock!" << endl;
    return;
  }

  m->stock--;
  this->history.push_back({"B", mediaType, m});
}

void Customer::returnItem(Movie *m, string mediaType) {

  bool borrowed = false;

  for (Transaction t : this->history) {
    if (t.m == m) {
      borrowed = t.transactionType == "B";
    }
  }

  if (!borrowed) {
    cout << "User " << this->id
         << " tried to return a book they did not borrow!" << endl;
    return;
  }

  m->stock++;
  this->history.push_back({"R", mediaType, m});
}