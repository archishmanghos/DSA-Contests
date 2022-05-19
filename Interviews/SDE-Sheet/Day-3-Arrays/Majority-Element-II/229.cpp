vector<int> majorityElement(vector<int>& nums) {
    long majorityElement1 = 1e10, majorityElement2 = 1e10;
    int count1 = 0, count2 = 0, n = nums.size();
    
    for(int i : nums){
        if(i == majorityElement1) count1 += 1;
        else if(i == majorityElement2) count2 += 1;
        else if(count1 == 0) majorityElement1 = i, count1 = 1;
        else if(count2 == 0) majorityElement2 = i, count2 = 1;
        else count1--, count2--;
    }
    
    count1 = count2 = 0;
    for(int i : nums){
        count1 += i == majorityElement1;
        count2 += i == majorityElement2;
    }
    
    vector<int> ans;
    if(count1 > (n / 3)) ans.push_back(majorityElement1);
    if(count2 > (n / 3)) ans.push_back(majorityElement2);
    return ans;
}