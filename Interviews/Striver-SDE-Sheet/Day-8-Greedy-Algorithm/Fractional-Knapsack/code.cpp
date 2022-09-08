double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr, arr + n, [](Item &a, Item &b){
        double value1 = (double)a.value / a.weight;
        double value2 = (double)b.value / b.weight;
        return value1 > value2;
    });
    double ans = 0;
    for(int i = 0; i < n; i++){
        int minWeightCanTake = min(arr[i].weight, W);
        double value = (double)arr[i].value / arr[i].weight;
        double valueToBeAdded = value * minWeightCanTake;
        ans += valueToBeAdded, W -= minWeightCanTake;
    }
    
    return ans;
}