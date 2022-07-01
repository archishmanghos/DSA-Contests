#include<bits/stdc++.h>

int lengthOfNum(int n){
    int len = 0;
    while(n > 0){
        len += 1;
        n /= 10;
    }

    return len;
}

int getPowerTen(int len){
    int ans = 1;
    for(int i = 1; i < len; i++) ans *= 10;
    return ans;
}

int minimumCoins(int n, int x){
    queue<int> q;
    q.push(1);
    vector<bool> visited(1000005, false);
    int szOfN = lengthOfNum(n);

    int ans = 0;
    while(!q.empty()){
        int sz = q.size();
        for(int i = 1; i <= sz; i++){
            long curNum = q.front();
            q.pop();
            int curLength = lengthOfNum(curNum);
            if(visited[curNum] or curLength > szOfN) continue;
            if(curNum == n) return ans;
            visited[curNum] = true;

            long possibility1 = curNum * x;
            long possibility2 = (getPowerTen(curLength) * (curNum % 10)) + (curNum / 10);
            q.push(possibility1);
            if(curNum % 10 != 0) q.push(possibility2);
        }
        ans += 1;
    }

    return -1;
}
