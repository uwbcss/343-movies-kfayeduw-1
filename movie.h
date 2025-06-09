#ifndef MOVIE_H
#define MOVIE_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class Movie;

class MovieFactory {
public:
  virtual Movie *makeMovie() const = 0;

  static Movie *create(const string &data);

protected:
  static void registerType(const char &type, MovieFactory *factory);

private:
  static map<char, MovieFactory *> &getMap();
};

class Movie {
public:
  char type;
  int maxStock;
  int stock;
  string title;
  string director;
  int year;

  virtual void init(string data) = 0;
  virtual void sortVector(vector<Movie *> &v) = 0;
  virtual string toString() = 0;
  virtual Movie *fromBRString(string s) = 0;

  static string getNextArgument(string &s, string splitter);

  virtual ~Movie() = default;
};

#endif