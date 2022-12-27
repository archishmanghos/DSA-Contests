#include <bits/stdc++.h>
using namespace std;

long long maxArea(long long A[], int len) {
    int64_t ans = 0;
    int i = 0, j = len - 1;
    while (i <= j) {
        ans = max (ans * 1ll, min(A[i], A[j]) * 1ll * (j - i));
        if (A[i] > A[j]) j -= 1;
        else i += 1;
    }

    return ans;
}