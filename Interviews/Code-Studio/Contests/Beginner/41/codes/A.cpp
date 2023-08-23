#include <bits/stdc++.h>
using namespace std;

int checkSequence(int a, int d, int x) {
    if (d == 0) return x == a;
    if (x < a) {
        if (d < 0) return (x - a) % d == 0;
        return 0;
    }
    if (d < 0) return 0;
    return (x - a) % d == 0;
}