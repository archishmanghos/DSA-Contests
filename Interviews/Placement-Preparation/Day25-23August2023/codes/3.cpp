#include <bits/stdc++.h>
using namespace std;

int kaiserImpact(int n, int m, int a, int b, int w, double k) {
    double slope1 = (double)a / b;
    double slope2 = (double)a / (b + w);
    cout << slope1 << ' ' << slope2 << '\n';
    return (k >= slope1 and k <= slope2);
}
