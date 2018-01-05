#include "StateValidityCheckerPCS.h"

#include <stdio.h>
#include <stdlib.h>
#include <fstream>

int main() {

	int Seed = time(NULL);
	srand( Seed );
	cout << "Seed in testing: " << Seed << endl;

	// APC
	StateValidityChecker svc(1);

	State q = svc.sample_q();
	svc.printVector(q);

	svc.two_robots::log_q(q);

}