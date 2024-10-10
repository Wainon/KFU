#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <algorithm>

using namespace std;

int maxs(const vector<vector<int>>& mat) {
    int maxs = 0;
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[0].size(); j++)
        {
            if (maxs < mat[i][j]) {
                maxs = mat[i][j];
            }
        }
    }
    return maxs;

}
vector<vector<int>> creatM(int n, int m, bool flag) {
    vector<vector<int>> res;
    vector<int> c;
    if (flag) {
        int k = 1;
        for (int x = 1; x <= n; ++x) {
            c = {};
            for (int y = 1; y <= m; ++y) {
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
            for (int y = 1; y <= m; ++y) {
                c.push_back(rand() % 100 + 1);
            }
            res.push_back(c);
        }
    }
    return res;
}
void printM(const vector<vector<int>>& mat) {
    size_t t = mat.size();
    size_t t2 = mat[0].size();
    int m = maxs(mat);


    for (int x = 0; x < t; ++x) {
        cout << "[";
        for (int y = 0; y < t2; ++y) {
                if  (mat[x][y] == m){
                if (mat[x][y] < 10) {
                    cout << "   |" << mat[x][y]<<"|";
                }
                else if (mat[x][y] < 100) {
                    cout << "   |" << mat[x][y]<<"|";
                }
                else {
                    cout << " |" << mat[x][y] << "|";
                }
                }
                else if (mat[x][y] < 10) {
                    cout << "     " << mat[x][y];
                }
                else if (mat[x][y] < 100) {
                    cout << "    " << mat[x][y];
                }
                else {
                    cout << "   " << mat[x][y];
                }
            }
            cout << " ]\n";
        }
    
   
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n,m; bool flag;

    cout << "Введите n & m ";
    cin >> n;
    cin >> m;
    cout << "Вести в ручную - 1\nВести автоматически - 0\n";
    cin >> flag;

    vector<vector<int>> x = creatM(n,m, flag);
    cout << "\n\n";
    clock_t start, ende;
    start = clock();

    int l = maxs(x);
    
    ende = clock();
    printM(x);
    cout << "\n\nМаксимальное число " << l << "\n\n";
    printf("\n\nЗатрачено времени %.4f секунд\n\n\n", ((double)ende - start) / ((double)CLOCKS_PER_SEC));
    cin >> n;
}