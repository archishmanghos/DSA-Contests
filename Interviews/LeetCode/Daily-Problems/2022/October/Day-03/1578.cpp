int minCost(string colors, vector<int>& neededTime) {
    int ans = 0, maxx = neededTime[0], cnt = 1, sum = neededTime[0];
    for (int i = 1; i < colors.size(); i++) {
        if (colors[i] == colors[i - 1]) {
            cnt += 1;
            maxx = max(maxx, neededTime[i]);
            sum += neededTime[i];
        } else {
            if (cnt > 1) {
                ans += sum - maxx;
            }
            cnt = 1;
            sum = maxx = neededTime[i];
        }
    }
    if (cnt > 1) {
        ans += sum - maxx;
    }

    return ans;
}