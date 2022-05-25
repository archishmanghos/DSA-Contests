int maxMeetings(int start[], int end[], int n){
    vector<pair<int, int>> interval;
    for(int i = 0; i < n; i++) interval.push_back({start[i], end[i]});
    sort(interval.begin(), interval.end(), [](pair<int, int> &a, pair<int, int> &b){
       return a.second < b.second;
    });
    
    int ans = 0, endInterval = -1;
    for(int i = 0; i < n; i++){
        if(interval[i].first <= endInterval) continue;
        ans += 1;
        endInterval = interval[i].second;
    }
    
    return ans;
}