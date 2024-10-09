#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    int m;
    double x;
    cout << "Введите m и x: ";
    cin >> m >> x;
    auto inf = std::numeric_limits<double>::infinity();
    long double res = 1, x2 = x * x, l = 1, f = 1, log=0;
    clock_t start, end;
    start = clock();
    for (int i = 1; i <= m; ++i) {
        l *= x2;
        f = f*(i*2)*(i*2 - 1);
        log = (l / f);
        if (inf== log) {
            cout << "Изменения не существены, прошло " << i << " итераций \n";
            break;
        }
        res += log;
    }
    cout << "результат: " << res;
    end = clock();
    printf("\nЗатрачено времени %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
    cin>>x;
}
