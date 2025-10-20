// cppPractical3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


double func(double y, double t) {
    return y - t * t + 1;
}

double euler(double y0, double t0, double h, int n) {
    ofstream myfile;
	myfile.open("euler_ode_data.csv");
    
    double y = y0;
    double t = t0;
    for (int i = 0; i < n; i++) {
        y = y + h * func(y, t);
        t = t + h;
		myfile << t << ";" << y << endl;
    }
	myfile.close();
    return y;
}

int question1() {
    double y0 = 1.0;
    double t0 = 0.0;
    double T = 10.0;
    int n = 101;
    double h = T / n;
	cout << "the step size is: " << h << endl;
	double result = euler(y0, t0, h, n);
	cout << "the approximate euler result is: " << result << endl;
    return 0;
}

double rungekutta(double y0, double t0, double h, int n) {
    ofstream myfile;
    myfile.open("rungekutta_ode_data.csv");
	double y = y0;
	double t = t0;
    for (int i = 0; i < n; i++) {
        double k1 = func(y, t);
        double k2 = func(y + h * k1, t + h);
        y = y + (h / 2) * (k1 + k2);
        t = t + h;
        myfile << t << ";" << y << endl;
	}
	myfile.close();
	return y;
}

int question2() {
    double y0 = 1.0;
    double t0 = 0.0;
    double T = 10.0;
    int n = 101;
    double h = T / n;
    cout << "the step size is: " << h << endl;
    double result = rungekutta(y0, t0, h, n);
    cout << "the approximate rungekutta result is: " << result << endl;
    return 0;
}

int main()
{
	return question1();
	//return question2();
}
