#include "apc_class.h"

#include <stdio.h>
#include <stdlib.h>
#include <fstream>

#define ROBOTS_DISTANCE 4000
#define ROD_LENGTH 500

double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

double dist(State p1, State p2) {
	double sum = 0;
	for (int i = 0; i < p1.size(); i++)
		sum += (p1[i]-p2[i])*(p1[i]-p2[i]);

	return sqrt(sum);
}

int main() {

	int Seed = time(NULL);
	srand( Seed );
	cout << "Seed in testing: " << Seed << endl;

	// APC
	two_robots A({-ROBOTS_DISTANCE/2, 0, 0, 0 }, {ROBOTS_DISTANCE/2, 0, 0, PI_}, ROD_LENGTH);

	// State q(6,1);
	// q = {0.3, -0.5, 0.5, 0, 0.4, 0};
	// //q[4] = 1;
	// A.printVector(q);

	// A.FKsolve_rob(q, 2);
	// Matrix T = A.get_FK_solution_T2();
	// A.printMatrix(T);

	// for (int i = 0; i < 8; i++) {
	// 	A.IKsolve_rob(T, 2, i);

	// 	A.printVector(A.get_IK_solution_q2());
	// }

	Matrix Q;
	Q.push_back({1, 0, 0, ROD_LENGTH});
	Q.push_back({0, 1, 0, 0});
	Q.push_back({0, 0, 1, 0});
	Q.push_back({0, 0, 0, 1});

	State q(12);// = {-0.262098, 1.25857, -1.81284, -3.13239, -0.0252604, 1.13626, -1.7244, -1.04968, -0.715249, 1.57762, 2.10969, 2.22163};
	State q1(6), q2(6);
	while (1) {
		// Random active chain
		for (int i = 0; i < 6; i++)
			q1[i] = 0;//fRand(-3.14, 3.14);
		//q1 = {2.95755, -1.57497, -1.56365, 1.01619, 0.0953593, -2.15862};
		int ik_sol = rand() % 8;
		

		if (A.calc_specific_IK_solution_R1(Q, q1, ik_sol)) 
			q2 = A.get_IK_solution_q2();
		else
			continue;

			cout << ik_sol << endl;

		for (int i = 0; i < 6; i++) {
			q[i] = q1[i];
			q[i+6] = q2[i];
		}
		//if (A.check_angle_limits(q))
			break;
	}

	

	A.printVector(q1);

	

	
	
	A.log_q(q);



}

