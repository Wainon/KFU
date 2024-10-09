#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> creatM(int n, bool flag) {
    vector<vector<int>> res;
    vector<int> c;
    if (flag) {
        int k = 1;
        for (int x = 1; x <= n; ++x) {
            c = {};
            for (int y = 1; y <= n; ++y) {
                cin >> k;
                c.push_back(k);
            }
            res.push_back(c);
        }
    }
    else {
        int k = 1;
        for (int x = 1; x <= n; ++x) {
            c = {};
            for (int y = 1; y <= n; ++y) {
                c.push_back(k++);
            }
            res.push_back(c);
        }
    }
    return res;
}
void printM(const vector<vector<int>>& mat) {
    size_t t = mat.size();
    if (t % 2 == 0) {
        for (int x = 0; x < t; ++x) {
            cout << "[";
            if (t / 2  == x) {
                cout << "-";
                for (int y = 0; y < t; ++y) cout << "----";
                cout << "---]\n[";
            }
            for (int y = 0; y < t; ++y) {
                if (t / 2 == y)cout << "  |";
                if (mat[x][y] < 10) {
                    cout << "   " << mat[x][y];
                }
                else if (mat[x][y] < 100) {
                    cout << "  " << mat[x][y];
                }
                else {
                    cout << " " << mat[x][y];
                }
            }
            cout << " ]\n";
        }
    }
    else {
        cout << "Не чётная матрица\n\n";
        for (int x = 0; x < t; ++x) {
            cout << "[";
            for (int y = 0; y < t; ++y) { 
                if (mat[x][y] < 10) {
                    cout << "   " << mat[x][y];
                }
                else if (mat[x][y] < 100) {
                    cout << "  " << mat[x][y];
                }
                else {
                    cout << " " << mat[x][y];
                }
            }
            cout << " ]\n";
        }
    }
   
}
void turn(vector<vector<int>>& mat) {
    size_t t = mat.size();
    if (t % 2 == 0) {
        for (int y = 0; y < t / 2; ++y) {
            for (int x = 0; x < t / 2; ++x) {
                swap(mat[y][x], mat[y][x + t / 2]);
            }
        }
        for (int y = t/2; y < t; ++y) {
            for (int x = 0; x < t / 2; ++x) {
                swap(mat[y][x], mat[y][x + t / 2]);
            }
        }
        for (int y = 0; y < t/2; ++y) {
            for (int x = 0; x < t / 2; ++x) {
                swap(mat[y][x], mat[y+t/2][x + t / 2]);
            }
        }

    }
    else {
        cout << "Не чётная длина, не получится поделить матрицу на 4 равных квадрата\n\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n; bool flag;

    cout << "Введите n ";
    cin >> n;

    cout << "Вести в ручную - 1\nВести автоматически - 0\n";
    cin >> flag;

    vector<vector<int>> x = creatM(n, flag);
    printM(x);
    cout << "\n\n";
    clock_t start, ende;
    start = clock();

    turn(x);

    ende = clock();
    printM(x);
    printf("\n\nЗатрачено времени %.4f секунд\n\n\n", ((double)ende - start) / ((double)CLOCKS_PER_SEC));
    cin >> n;
}