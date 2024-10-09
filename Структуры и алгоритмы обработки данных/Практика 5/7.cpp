#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <list>

using namespace std;

void sdv(list<int>& x, int k) {
    list<int> c;
    size_t t = x.size();
    if (k > 0) {
        for (int i = 0;i<k; ++i) {
            c.push_back(x.back());
            x.pop_back();
        }
        for (int i = 0; i < k; ++i) {
            x.push_front(c.front());
            c.pop_front();
        }
    }
    else if(k<0){
        for (int i = 0; i < -k; ++i) {
            c.push_back(x.front());
            x.pop_front();
        }
        for (int i = 0; i < -k; ++i) {
            x.push_back(c.front());
            c.pop_front();
        }
    }
    else {
        c = x;
    }
    return;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int k,n;
    cout << "Введите n и k: ";
    cin >> n >> k;
    cout << "\n";
    list<int> x;
    cout << "Создание списка \n";
    for (int i = 1; i <= n; ++i) x.push_back(i);
    cout << "Создание списка зaвершено\n";
    clock_t start, end;
    start = clock();
    sdv(x, k);
    end = clock();
    for (auto i = x.begin(); i != x.cend(); ++i) cout << *i << "  ";
    printf("\nЗатрачено времени %.4f секунд\n\n\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    cin >> n;
}