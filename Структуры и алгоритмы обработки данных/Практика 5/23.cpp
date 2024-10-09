#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<int> createV(int n) {
    cout << "Создание списка \n";
    vector<int> x;
    for (int i = n; i > 0; --i) x.push_back(i) ;

    cout << "Создание списка зaвершено\n";
    return x;
}

void tree(vector<int>& x, int n, int k) {

    int begin, left, rght;

    left = 2 * k;
    rght = 2 * k + 1;
    begin = k;

    if (left < n && x[left] > x[begin]) {
        begin = left;
    }
    if (rght < n && x[rght] > x[begin]) {
        begin = rght;
    }
    if (begin != k) {
        swap(x[k], x[begin]);
        tree(x, n, begin);
    }
}
void sorte(vector<int>& x,bool revers=false) {
    size_t t = x.size();
    if (revers) {
        sorte(x);
        reverse(x.begin(), x.end());
    }
    else {
        for (int i = t / 2 - 1; i >= 0; i--) {
            tree(x, t, i);
        }

        for (int i = t - 1; i > 0; i--) {

            swap(x[0], x[i]);
            tree(x, i, 0);
        }
    }
   
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите n ";
    cin >> n;
    cout << "\n";
    vector<int> x = createV(n);//создание списка
    cout << "\n";
    clock_t start, ende;

    start = clock();

     sorte(x);// Cортерока по возрастанию
     //sorte(x, 1);
    //sort(begin(x), end(x));

    ende = clock();
    for (auto i = x.begin(); i != x.cend(); ++i) cout << *i << " ";
    printf("\n\nЗатрачено времени %.4f секунд\n\n\n", ((double)ende - start) / ((double)CLOCKS_PER_SEC));
    cin >> n;
}