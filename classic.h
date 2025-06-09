#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"
#include <vector>

class Classic : public Movie {
private:
public:
  string majorActor;
  int month;

  void init(string data) override;
  void sortVector(vector<Movie *> &v) override;
  string toString() override;
  Movie *fromBRString(string s) override;
};

class ClassicFactory : public MovieFactory {
public:
  ClassicFactory();
  Movie *makeMovie() const override;
};

#endif