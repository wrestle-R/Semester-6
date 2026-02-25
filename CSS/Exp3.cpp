#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int primeQ, baseH;
	cout << "Enter a prime number (q): ";
	cin >> primeQ;
	cout << "Enter a base (h): ";
	cin >> baseH;

	int secretX, secretY;
	cout << "Enter X's secret: ";
	cin >> secretX;
	cout << "Enter Y's secret: ";
	cin >> secretY;

	int pubX = (int)pow(baseH, secretX) % primeQ;
	int pubY = (int)pow(baseH, secretY) % primeQ;

	cout << "X's public value: " << pubX << endl;
	cout << "Y's public value: " << pubY << endl;

	int sharedX = (int)pow(pubY, secretX) % primeQ;
	int sharedY = (int)pow(pubX, secretY) % primeQ;

	cout << "Shared key (X): " << sharedX << endl;
	cout << "Shared key (Y): " << sharedY << endl;

	return 0;
}