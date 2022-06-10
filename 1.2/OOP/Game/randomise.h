#ifndef RANDOMISE_H
#define RANDOMISE_H

#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <algorithm>

class Randomise
{
public:
  Randomise();
  void randarray();
  int read(int i);

private:
  int array[10];
  int rdseed;
};
#endif // RANDOMISE_H
