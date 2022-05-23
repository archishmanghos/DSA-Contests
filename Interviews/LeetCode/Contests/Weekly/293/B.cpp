int maxConsecutive(int bottom, int top, vector<int>& special) {
    sort(special.begin(), special.end());
    int prevFloor = bottom - 1, ans = top - special.back();
    for(int floors : special) ans = max(ans, floors - prevFloor - 1), prevFloor = floors;
    return ans;
}