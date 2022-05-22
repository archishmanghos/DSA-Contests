int minimumLines(vector<vector<int>>& stockPrices) {
    int n = stockPrices.size();
    sort(stockPrices.begin(), stockPrices.end(), [](vector<int> &a, vector<int> &b){
       return a[0] < b[0];
    });

    if(n == 1) return 0;
    int ans = 1;
    for(int i = 2; i < n; i++){
        int x1 = stockPrices[i - 2][0], y1 = stockPrices[i - 2][1];
        int x2 = stockPrices[i - 1][0], y2 = stockPrices[i - 1][1];
        int x3 = stockPrices[i][0], y3 = stockPrices[i][1];
        
        if(1LL * (x3 - x2) * (y2 - y1) != 1LL * (y3 - y2) * (x2 - x1)) ans++;
    }
    
    return ans;
}