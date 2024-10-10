#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <vector>
#include <algorithm>
#include <string>

using namespace std;
void print(const string& s) {
    for (int i = 1, k = 0; i <= s.size(); ++i) {
        if (k == 8) {
            cout << " ";
            k = 0;
        }
        k++;
        cout << s[i - 1];
    }
    cout << "\n";
}
string ToDec(string num, int base) {
    int dec = 0;
    int multiplier = 1;
    for (int i = num.length() - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            dec += (num[i] - '0') * multiplier;
        }
        else {
            dec += (num[i] - 'A' + 10) * multiplier;
        }
        multiplier *= base;
    }
    return to_string(dec);
}

string ToBin(string num) {
    int n = stoi(num);
    string s = "";
    while (n!=0)
    {
        s = to_string(n % 2) + s ;
        n = n / 2;
    }
    for (int i = s.size(); i < 32; ++i) {
        s = "0" + s;
    }
    return s;
}

void plas1(string& s, int t) {
    if (s[t] == '0') {
        s[t] = '1';
        return;
    }
    else {
        s[t] = '0';
        plas1(s, t - 1);
        return;
    }
}

string creat(string n, int m) {
    bool flag = 0;
    if (n[0]=='-') {
        n=n.substr(1); flag = 1;
    }
    if(m!=10) n = ToDec(n,m);
    n = ToBin(n);
    if (flag) {
        print(n);
        cout << "\n";
        for (int i = 0; i < n.size(); ++i) {
            n[i] = (n[i]=='1') ? '0' : '1';
        }
        plas1(n, n.size() - 1);
    }
    return(n);
}

int main() {
    setlocale(LC_ALL, "Russian");
    string n;int m;
    cout << "Ведите число и его систему: ";
    cin >> n >> m;
    cout << "\n";
    string s = creat(n, m);
    print(s);
    cout << "\n\nenter чтобы продолжить";
    cin >> n;
}