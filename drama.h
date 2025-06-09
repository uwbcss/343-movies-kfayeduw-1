#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include <vector>

class Drama : public Movie {
private:
public:
  void init(string data) override;
  void sortVector(vector<Movie *> &v) override;
  string toString() override;
  Movie *fromBRString(string s) override;
};

class DramaFactory : public MovieFactory {
public:
  DramaFactory();
  Movie *makeMovie() const override;
};

#endif