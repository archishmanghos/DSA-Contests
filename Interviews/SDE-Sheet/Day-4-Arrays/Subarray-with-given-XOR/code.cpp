int solve(vector<int> &A, int B) {
    int xorVal = 0, ans = 0;
    unordered_map<int, int> xorIndex;
    xorIndex[0] = 1;
    for(int i = 0; i < A.size(); i++){
        xorVal ^= A[i];
        if(xorIndex.find(xorVal ^B) != xorIndex.end()) ans += xorIndex[xorVal ^ B];
        xorIndex[xorVal] += 1;
    }

    return ans;
}