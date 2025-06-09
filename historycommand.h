#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "command.h"

class HistoryCommand : public Command {
private:
  int customerID;

public:
  void init(string data) override;
  void execute() override;
};

class HistoryCommandFactory : public CommandFactory {
public:
  HistoryCommandFactory();
  Command *makeCommand() const override;
};

#endif