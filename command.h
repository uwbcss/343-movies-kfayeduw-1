#ifndef COMMAND_H
#define COMMAND_H

#include <map>
#include <string>

using namespace std;

class Command;

class CommandFactory {
public:
  virtual Command *makeCommand() const = 0;

  static Command *create(const string &data);

protected:
  static void registerType(const char &type, CommandFactory *factory);

private:
  static map<char, CommandFactory *> &getMap();
};

class Command {
public:
  char type;
  bool discard = false;

  virtual void init(string data) = 0;
  virtual void execute() = 0;

  virtual ~Command() = default;
};

#endif