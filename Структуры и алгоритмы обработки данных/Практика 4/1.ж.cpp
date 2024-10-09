#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
long double fac(int x) {
    while (x>0)
    {
        return x * fac(x - 1);
    }
    return 1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x;
    double e;
    cout << "Введите х и е: ";
    cin >> x >> e;
     double res = 1 / x;
    auto inf = std::numeric_limits<double>::infinity();
     double Xup = x, x2 = x * x, f = 1, Of = 1,log=0,s=0;
    cout << "\n";
    clock_t start, end;
    start = clock();
    int k;
    for ( k = 1; k <= 1000; ++k) {

        f = f * (k * 2 + 1) * (k * 2);

         s=(((k % 2 == 0) ? -1 : 1) * Xup) / (Of * f);
         if (s == inf || s == -inf) {
             cout << "изменениея происходят на чила блиские ную. Прошло " << k << " операций\n";
             break;
         }
         res += s;
        if ((abs(abs(res) - abs(log)) <= e)) {
            cout << "Заданая точность была достигнута за " << k << " операций\n";
            break;
        }
        log = res;
        Xup *= x2;
        Of += 2;
    }
    end = clock();
    if (k == 100000) {
        cout <<"Зажданая ьочность не была достигнута за "<<k<<" операций\n";
    }
    cout << "Результат: "<< res;
    printf("\nЗатрачено времени %.4f секунд\n\n\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));


    res = 1 / x;
    for (k = 1; k <= 1000; ++k) {
        s= (pow(-1, k + 1) * pow(x, 2 * k - 1)) / ((2 * k - 1) * fac(2 * k + 1));
        if (s == inf || s == -inf ) {
            cout << "изменениея происходят на чила блиские ную. Прошло " << k << " операций\n";
            break;
        }
        res += s;
        if ((abs(abs(res) - abs(log)) <= e)) {
            cout << "Заданая точность была достигнута за " << k << " операций\n";
            break;
        }
        log = res;   
    }
    end = clock();
    if (k == 100000) {
        cout << "Зажданая ьочность не была достигнута за " << k << " операций\n";
    }
    cout << "Результат: " << res;
    printf("\nЗатрачено времени %.4f секунд\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
    cin >> x;
}