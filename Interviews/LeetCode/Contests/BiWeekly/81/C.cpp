int maximumXOR(vector<int>& nums) {
    vector<int> cntOnes(32, 0);
    for(int i = 0; i < 32; i++){
        for(int j : nums){
            if((j & (1 << i)) != 0) cntOnes[i] += 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < 32; i++){
        if(cntOnes[i] > 0) ans |= (1 << i);
    }

    return ans;
}