#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");
    int x;
    double e;
    cout << "Введите х ∈ [-1;1) и е: ";
    cin >> x >> e;
    double res =-x;
    auto inf = std::numeric_limits<double>::infinity();
    double Xup = x,log=10,s=0;
    cout << "\n";
    clock_t start, end;
    start = clock();
    int k;
    for ( k = 2; k <= 10000000; ++k) {
        Xup *= x;
        s = Xup / k;
         if (s == inf || s == -inf) {
             cout << "изменениея происходят на чила блиские ную. Прошло " << k << " операций\n";
             break;
         }
         
         res -= s;
        if ((abs(abs(res) - abs(log)) <= e)) {
            cout << "Заданая точность была достигнута за " << k << " операций\n";
            break;
        }
        log = res;
    }
    end = clock();
    if (k == 100000) {
        cout <<"Зажданая tочность не была достигнута за "<<k<<" операций\n";
    }
    cout << "Результат: "<< res;
    printf("\nЗатрачено времени %.4f секунд\n\n\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    cin >> x;
}