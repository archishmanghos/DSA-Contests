int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int first = cost[0], second = cost[1];
    for(int i = 2; i < n; i++){
        int third = min(first, second) + cost[i];
        first = second, second = third;
    }
    
    return min(first, second);
}