int searchInsertK(vector<int>Arr, int N, int k){
    int low = 0, high = N - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(Arr[mid] == k){
            return mid;
        }
        if(Arr[mid] < k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    
    return low;
}