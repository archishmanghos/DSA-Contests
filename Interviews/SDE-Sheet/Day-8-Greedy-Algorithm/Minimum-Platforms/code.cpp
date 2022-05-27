int findPlatform(int arr[], int dep[], int n){
    int ans = 0;
    sort(arr, arr + n);
    sort(dep, dep + n);
    
    int curPlatforms = 0, arrivalPointer = 0, departurePointer = 0;
    while(arrivalPointer < n){
        if(arr[arrivalPointer] <= dep[departurePointer]) arrivalPointer += 1, curPlatforms += 1;
        else departurePointer += 1, curPlatforms -= 1;
        ans = max(ans, curPlatforms);
    }

    return ans;
}