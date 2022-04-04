vector<int> twoSum(vector<int> &nums, int target){
    vector<pair<int, int>> v;
    for(int i = 0; i < nums.size(); i++){
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    int i = 0, j = v.size() - 1;
    while(i < j){
        int sum = v[i].first + v[j].first;
        if(sum == target){
            ans = {v[i].second, v[j].second};
            break;
        }
        if(sum > target){
            j -= 1;
        }else{
            i += 1;
        }
    }
    
    return ans;
}