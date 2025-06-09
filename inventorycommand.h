#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "command.h"

class InventoryCommand : public Command {
private:
public:
  void init(string data) override;
  void execute() override;
};

class InventoryCommandFactory : public CommandFactory {
public:
  InventoryCommandFactory();
  Command *makeCommand() const override;
};

#endif