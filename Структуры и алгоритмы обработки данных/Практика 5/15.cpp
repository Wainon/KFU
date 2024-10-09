#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <set>
#include <random>

using namespace std;



int main() {
    setlocale(LC_ALL, "Russian");
    int flag,n;
    cout << "Введите n\n1 - рандомный вод;\n0 - для вода в ручную;\n";
    cin >> n >> flag;
    cout << "\n";
    set<int> x;
    cout << "Создание списка \n";
    if (flag) {
        int s = 1, e = 20;
        for (int i = 0; i < n; ++i) x.insert( rand() % (e - s + 1) + s);
    }
    else {
        int s;
        for (int i = 0; i < n; ++i) {
            cout << "-\n";
            cin >> s;
            x.insert(s);
        }
    }
    cout << "Создание списка зaвершено\n";
    clock_t start, end;
    start = clock();
   
    cout <<"\nВ списке " <<x.size() << " различных элементов\n";

    end = clock();
    for (auto i = x.begin(); i != x.cend(); ++i) cout << *i << "  ";
    printf("\n\nЗатрачено времени %.4f секунд\n\n\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    cin >> n;
}