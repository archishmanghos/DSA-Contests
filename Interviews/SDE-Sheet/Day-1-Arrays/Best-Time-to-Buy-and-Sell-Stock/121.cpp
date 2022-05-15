int maxProfit(vector<int> &prices){
    int ans = 0, minStockPrice = INT_MAX;
    
    for(int i = 0; i < prices.size(); i++){
        minStockPrice = min(prices[i], minStockPrice);
        ans = max(ans, prices[i] - minStockPrice);
    }
    
    return ans;
}