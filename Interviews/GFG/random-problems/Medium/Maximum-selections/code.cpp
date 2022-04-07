int max_non_overlapping( vector< vector<int> > &ranges ){
    sort(ranges.begin(), ranges.end(), [](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    int end = -1, ans = 0;
    for(int i = 0; i < ranges.size(); i++){
        if(ranges[i][0] >= end){
            ans += 1;
            end = ranges[i][1];
        }
    }
    
    return ans;
}