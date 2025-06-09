#ifndef BORROWCOMMAND_H
#define BORROWCOMMAND_H

#include "command.h"
#include "customer.h"
#include "movie.h"

class BorrowCommand : public Command {
private:
  int customerID;
  string mediaType;
  string movieType;
  string movieData;

public:
  void init(string data) override;
  void execute() override;
};

class BorrowCommandFactory : public CommandFactory {
public:
  BorrowCommandFactory();
  Command *makeCommand() const override;
};

#endif