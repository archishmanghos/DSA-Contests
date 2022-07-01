int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    vector<int> boxBuckets(1001, 0);
    for(auto box : boxTypes) boxBuckets[box[1]] += box[0];
    
    int ans = 0, remTruckSize = truckSize;
    for(int i = 1000; i >= 1; i--){
        int minBoxToTake = min(boxBuckets[i], remTruckSize);
        ans += minBoxToTake * i;
        remTruckSize -= minBoxToTake;
        if(!remTruckSize) return ans;
    }
    
    return ans;
}