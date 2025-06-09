#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <vector>

class Comedy : public Movie {
private:
public:
  void init(string data) override;
  void sortVector(vector<Movie *> &v) override;
  string toString() override;
  Movie *fromBRString(string s) override;
};

class ComedyFactory : public MovieFactory {
public:
  ComedyFactory();
  Movie *makeMovie() const override;
};

#endif