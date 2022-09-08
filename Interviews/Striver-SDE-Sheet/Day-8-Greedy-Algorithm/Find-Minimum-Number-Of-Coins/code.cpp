int findMinimumCoins(int amount){
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans = 0;
    for(int i = 0; i < coins.size(); i++){
        int countCoins = amount / coins[i];
        ans += countCoins;
        amount -= countCoins * coins[i];
    }
    
    return ans;
}