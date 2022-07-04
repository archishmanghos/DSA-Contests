int candy(vector<int>& ratings) {
    int n = ratings.size(), i = 1, j = n - 2;
    vector<int> leftNeighbour(n, 1), rightNeighbour(n, 1);
    
    while(i < n){
        if(ratings[i] > ratings[i - 1]) leftNeighbour[i] = leftNeighbour[i - 1] + 1;
        if(ratings[j] > ratings[j + 1]) rightNeighbour[j] = rightNeighbour[j + 1] + 1;
        i++, j--;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans += max(leftNeighbour[i], rightNeighbour[i]);
    return ans;
}