int triangularSum(vector<int> &nums){
    vector<int> v = nums;
    while(v.size() > 1){
        vector<int> temp;
        for(int i = 0; i < v.size() - 1; i++){
            temp.push_back((v[i] + v[i + 1]) % 10);
        }
        v = temp;
    }
    
    return v[0];
}