#include "historycommand.h"
#include "customer.h"
#include "store.h"
#include <algorithm>
#include <iostream>

using namespace std;

void HistoryCommand::init(string data) {

  this->type = 'H';

  if (data.length() != 6) {
    cout << "Invalid H command: '" << data << "'" << endl;
    this->discard = true;
    return;
  }

  this->customerID = stoi(data.substr(2, data.size() - 2));
}

void HistoryCommand::execute() {

  Customer *c = Store::getInstance().getCustomer(this->customerID);
  if (c == nullptr) {
    cout << "Unknown customer id: " << this->customerID << endl;
    return;
  }

  cout << "\n====================== HISTORY (" << this->customerID
       << ") ======================" << endl;

  for (Transaction t : c->getHistory()) {
    string out = t.transactionType == "B" ? "Borrow (" : "Return (";
    out += t.mediaType + "): ";
    out += t.m->toString();
    cout << out << endl;
  }

  cout << "============================================================\n"
       << endl;
}

HistoryCommandFactory::HistoryCommandFactory() { registerType('H', this); }

Command *HistoryCommandFactory::makeCommand() const {
  return new HistoryCommand();
}

HistoryCommandFactory anonymousHistoryCommandFactory;