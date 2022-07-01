vector<vector<long long int>> matrixMultiply(vector<vector<long long int>> a, vector<vector<long long int>> b, int mod){
    int n, m, o;
    if(a[0].size() == b.size()){
        n = a.size(), m = b[0].size(), o = a[0].size();
    }else{
        return {{-1, -1}};
    }

    vector<vector<long long int>> ans(n, vector<long long int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < o; k++){
                ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }

    return ans;
}

long long int findMaxPower(long long int n){
    long long int ans = 1, cnt = 0;
    while(ans * 2 <= n) ans *= 2, cnt += 1;
    return cnt;
}

int FindNthTerm(long long int n) {
    vector<vector<long long int>> matrixToFind = {{1, 0}, {0, 1}};
    vector<vector<vector<long long int>>> poweredMatrices;
    poweredMatrices.push_back({{1, 1}, {1, 0}});

    long long int power = n - 1, mod = 1e9 + 7;
    long long int maxPowerReqd = findMaxPower(power);
    for(int i = 1; i <= maxPowerReqd; i++){
        vector<vector<long long int>> prevMatrix = poweredMatrices.back();
        vector<vector<long long int>> newMatrix = matrixMultiply(prevMatrix, prevMatrix, mod);
        poweredMatrices.push_back(newMatrix);
    }

    for(int i = maxPowerReqd; i >= 0; i--){
        if(power & (1 << i)){
            matrixToFind = matrixMultiply(matrixToFind, poweredMatrices[i], mod);
        }
    }

    long long int ans = matrixToFind[0][0] + matrixToFind[0][1];
    return (ans % mod);
}