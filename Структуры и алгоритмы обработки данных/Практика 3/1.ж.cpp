#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите n: ";
	cin >> n;
	double x=0, l=1;

	clock_t start, end;
	start = clock();
	for (int i = 1; i <= n; ++i) {
		l += 2;
		x += ((i % 2 == 0) ? 1.0 : -1.0) / l;
	}
	cout << "результат: " << x;
	end = clock();
	printf("\nЗатрачено времени %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

	start=0, end=0;
	x = 0;
	start = clock();
	for (int i = 1; i <= n; ++i) {
		
		x += pow(-1.0, i) / (2.0 * i + 1.0);
	}
	cout << "результат: " << x;
	end = clock();
	printf("\nЗатрачено времени %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	cin>>n;
}
