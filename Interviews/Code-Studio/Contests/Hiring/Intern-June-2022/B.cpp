#include <bits/stdc++.h>

int getTotalRewards(int n, vector < int > arr) {
    set<int> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0) continue;
        if(s.find(arr[i]) == s.end()) ans += 1;
        s.insert(arr[i]);
    }

    return ans;
}