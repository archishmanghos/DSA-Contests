vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    vector<int> indexing(int(1e6 + 5), -1);
    int n = nums.size();
    set<int> origIntegers;
    for(int i = 0; i < nums.size(); i++) indexing[nums[i]] = i, origIntegers.insert(nums[i]);

    for(auto i : operations){
        indexing[i[1]] = indexing[i[0]];
        indexing[i[0]] = -1;
        origIntegers.erase(i[0]);
        origIntegers.insert(i[1]);
    }

    nums.assign(n, 0);
    for(int i : origIntegers) nums[indexing[i]] = i;

    return nums;
}