int maximumTop(vector<int> &nums, int k){
    int ans = -1, removed = 0;
    for(int i = 0; i < nums.size(); i++){
        if(k == 0){
            ans = max(ans, nums[i]);
            break;
        }
        if(k % 2 == 0){
            ans = max(ans, nums[i]);
        }else{
            if(k > 2 and (removed > 0 or (i + 1 < nums.size()))){
                ans = max(ans, nums[i]);
            }
        }
        k -= 1;
        removed += 1;
    }
    return ans;
}