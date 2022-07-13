int fillCups(vector<int>& amount) {
    int ans = 0;
    sort(amount.begin(), amount.end());
    
    while(amount[0] >= 1 and amount[2] >= 2){
        amount[0] -= 1;
        amount[1] -= 1;
        amount[2] -= 2;
        ans += 2;
        sort(amount.begin(), amount.end());
    }
    
    if(amount[0] > 0) ans += amount[0], amount[1] -= amount[0];
    if(amount[1] > 0) ans += amount[1], amount[2] -= amount[1];
    ans += amount[2];
    
    return ans;
}