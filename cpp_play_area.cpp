// cpp_play_area.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <random>
using namespace std;

int main() {
	int total_hits = 10000000;
	int hits_inside = 0;

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);

	for (int hits = 0; hits < total_hits; ++hits) {

		double x = dis(gen);
		double y = dis(gen);

		double radius = sqrt(pow(x, 2) + pow(y, 2));
		if (radius < 1.0) {
			hits_inside = hits_inside + 1;
		}
	}

	double pi = 4.0 * static_cast<double>(hits_inside) / total_hits;
	cout << pi << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
