#include "returncommand.h"
#include "movie.h"
#include "store.h"
#include <iostream>

using namespace std;

void ReturnCommand::init(string data) {

  this->type = 'R';
  data = data.substr(2, data.size() - 2);

  this->customerID = stoi(Movie::getNextArgument(data, " "));
  this->mediaType = Movie::getNextArgument(data, " ");
  this->movieType = Movie::getNextArgument(data, " ");
  this->movieData = data;
}

void ReturnCommand::execute() {

  if (this->mediaType != "D") {
    cout << "Unknown media type: '" << this->mediaType << "'!" << endl;
    return;
  }

  Customer *c = Store::getInstance().getCustomer(this->customerID);
  if (c == nullptr) {
    cout << "Unknown customer id: " << this->customerID << endl;
    return;
  }

  unordered_map<char, vector<Movie *>> inventory =
      Store::getInstance().getInventory();

  if (inventory.count(this->movieType[0]) == 0) {
    cout << "Unknown movie type: " << this->movieType << endl;
    return;
  }

  Movie *first = inventory[this->movieType[0]][0];
  Movie *m = first->fromBRString(this->movieData);

  if (m == nullptr) {
    cout << "Could not find movie: " << this->movieData << endl;
    return;
  }

  c->returnItem(m, this->mediaType);
}

ReturnCommandFactory::ReturnCommandFactory() { registerType('R', this); }

Command *ReturnCommandFactory::makeCommand() const {
  return new ReturnCommand();
}

ReturnCommandFactory anonymousReturnCommandFactory;