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
