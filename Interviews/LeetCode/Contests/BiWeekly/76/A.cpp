int findClosestNumber(vector<int> &nums){
    int ans = -1, dist = 1000000;
    for(int i : nums){
        if(abs(i) == dist){
            ans = max(ans, i);
        }else if(abs(i) < dist){
            dist = abs(i);
            ans = i;
        }
    }
    
    return ans;
}