#include <stdio.h>
#include <assert.h>

struct team
{
	int gardes[5];
	double fitness;
};

void main()
{
	struct team Beitar;
	Beitar.fitness = 0.3;
	
}

double calcChance(int grades[], double fitness,int home)
{
	double sum;
	for (int i = 0; i < 4; i++)
	{
		sum += grades[i];
	}
	return sum / fitness + home *3;

}