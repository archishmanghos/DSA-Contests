int singleNumber(vector<int> &nums) {
    int xorVal = 0;
    for (int i: nums) {
        xorVal ^= i;
    }
    return xorVal;
}