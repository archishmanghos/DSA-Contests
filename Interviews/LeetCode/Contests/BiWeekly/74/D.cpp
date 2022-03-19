int cache[1005][1005];
int dp(int index, int carpetsLeft, int &carpetLen, int &n, vector<int> &whiteTiles){
    if(index >= n){
        return 0;
    }
    if(cache[index][carpetsLeft] != -1){
        return cache[index][carpetsLeft];
    }
    
    int whiteLeft = (index > 0 ? whiteTiles[index - 1] : 0);
    int whiteRight = (index + carpetLen <= n ? whiteTiles[index + carpetLen - 1] : whiteTiles[n - 1]);
    int toBeColoured = whiteRight - whiteLeft;
    int ans;
    if(carpetsLeft == 0){
        ans = dp(n, 0, carpetLen, n, whiteTiles);
    }else{
        ans = max(dp(index + carpetLen, carpetsLeft - 1, carpetLen, n, whiteTiles) + toBeColoured, dp(index + 1, carpetsLeft, carpetLen, n, whiteTiles));
    }
    return cache[index][carpetsLeft] = ans;
}
int minimumWhiteTiles(string floor, int numCarpets, int carpetLen){
    int n = floor.size();
    vector<int> whiteTiles(n + 2, 0);
    int white = 0;
    for(int i = 0; i < n; i++){
        white += floor[i] == '1';
        whiteTiles[i] = white;
    }
    
    memset(cache, -1, sizeof(cache));
    int deletion = dp(0, numCarpets, carpetLen, n, whiteTiles);
    return white - deletion;
}