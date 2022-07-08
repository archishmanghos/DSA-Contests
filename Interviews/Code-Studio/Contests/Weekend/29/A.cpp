#include<bits/stdc++.h>

int sortArray(vector<int> &a, int n) {
    int minElement = INT_MAX, maxElement = 0;
    for(int i : a){
        minElement = min(minElement, i);
        maxElement = max(maxElement, i);
    }

    if(is_sorted(a.begin(), a.end())) return 0;
    if(a[0] == minElement or a[n - 1] == maxElement) return 1;
    if(a[0] == maxElement and a[n - 1] == minElement) return 3;
    return 2;
}