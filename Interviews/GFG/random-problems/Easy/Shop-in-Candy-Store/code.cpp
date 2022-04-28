vector<int> candyStore(int candies[], int N, int K){
    sort(candies, candies + N);
    int ans1 = 0, ans2 = 0, i = 0, j = N - 1;
    while(i <= j){
        ans1 += candies[i++];
        j -= K;
    }
    
    i = 0, j = N - 1;
    while(i <= j){
        ans2 += candies[j--];
        i += K;
    }
    
    return {ans1, ans2};
}