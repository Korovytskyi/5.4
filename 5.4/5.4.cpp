// 5.4.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>
using namespace std;
double P0(const int K, const int N)
{
	double P=1;
	for (int K=25; K <= 25; K++)
		P *= sqrt(1+(N/K));
	return P;
}
double P1(const int K, const int N, const int i)
{
	if (i > N)
		return 0;
	else
		return sqrt(1 + (N / K)) + P1(K, N, i + 1);
}
double P2(const int K, const int N, const int i)
{
	if (K < N)
		return 0;
	else
		return sqrt(1 + (N / K)) + P2(K, N, i - 1);
}
double P3(const int K, const int N, const int i, double t)
{
	t = t + sqrt(1 + (N / K));
	if (K >= 25)
		return t;
	else
		return P3(K, N, i + 1, t);
}
double P4(const int K, const int N, const int i, double t)
{
	t = t + sqrt(1 +( N / K));
	if (K <= N)
		return t;
	else
		return P4(K, N, i - 1, t);
}

int main()
{
	int K, N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << P0(N,25) << endl;
	cout << "(rec up ++) S1 = " << P1( N,N,25) << endl;
	cout << "(rec up --) S2 = " << P2(N, 25, 25) << endl;
	cout << "(rec down ++) S3 = " << P3(N, 25, N, 0) << endl;
	cout << "(rec down --) S4 = " << P4(N, 25, 25, 0) << endl;
	return 0;
}