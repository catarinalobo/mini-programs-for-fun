#include <iostream>
#include <limits>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;


double estimate_pi(long int ntrials) {

	srand(time(NULL));

	long int ninside_circ = 0;
	double x, y;
	
	for(long int i=0; i<ntrials; i++) {

		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;

		if(x*x+y*y <= 1)
			ninside_circ++;
	
	}

	return (double)ninside_circ/ntrials*4;
}

int main() {

	long int ntrials;

	while(cin >> ntrials) 
		cout << "Pi ~= " << setprecision(numeric_limits<double>::digits10+1) << estimate_pi(ntrials) << endl;

}