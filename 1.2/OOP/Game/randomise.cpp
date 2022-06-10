#include "randomise.h"

Randomise::Randomise()
{
  this->rdseed = time(NULL);
  randarray();
}

int Randomise::read(int i)
{
  return this->array[i];
}

void Randomise::randarray()
{
	srand(rdseed);
	this->rdseed = rand();
	int queue[10];
	for (int i = 0; i < 9; ++i)
	{
		queue[i] = i+1;
	}
	for (int i = 0; i < 9; ++i)
	{
		int stp = rand()%9;
		while(!queue[stp])
		{
			stp ++;
			stp %= 9;
		}
		this->array[i] = queue[stp];
		queue[stp] = 0;
	}
}
