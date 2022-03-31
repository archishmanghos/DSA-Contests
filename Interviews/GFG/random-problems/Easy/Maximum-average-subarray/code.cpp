int findMaxAverage(int arr[], int n, int k){
    int sumTillNow = 0, sumNow = 0;
    for(int i = 0; i < k; i++){
        sumNow += arr[i];
        sumTillNow += arr[i];
    }
    int i = k, lb = 0;
    while(i < n){
        sumNow += arr[i] - arr[i - k];
        if(sumNow > sumTillNow){
            lb = i - k + 1;
            sumTillNow = sumNow;
        }
        i += 1;
    }
    
    return lb;
}