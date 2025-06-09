#ifndef RETURNCOMMAND_H
#define RETURNCOMMAND_H

#include "command.h"
#include "customer.h"
#include "movie.h"

class ReturnCommand : public Command {
private:
  int customerID;
  string mediaType;
  string movieType;
  string movieData;

public:
  void init(string data) override;
  void execute() override;
};

class ReturnCommandFactory : public CommandFactory {
public:
  ReturnCommandFactory();
  Command *makeCommand() const override;
};

#endif