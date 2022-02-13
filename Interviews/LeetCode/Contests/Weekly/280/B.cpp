int minimumOperations(vector<int> &nums) {
    map<int, int> cnt1, cnt2;
    int ans = 0;
    int change = -1, maxx = -1, nextMax = -1, change22 = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            cnt1[nums[i]] += 1;
            if (cnt1[nums[i]] > maxx) {
                maxx = cnt1[nums[i]];
                change = nums[i];
            }
        }
    }

    for (auto i: cnt1) {
        if (i.first != change and i.second > nextMax) {
            nextMax = i.second;
            change22 = i.first;
        }
    }

    int change1 = -1, maxx1 = -1, nextMax1 = -1, change11 = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 1) {
            cnt2[nums[i]] += 1;
            if (cnt2[nums[i]] > maxx1) {
                maxx1 = cnt2[nums[i]];
                change1 = nums[i];
            }
        }
    }

    for (auto i: cnt2) {
        if (i.first != change1 and i.second > nextMax1) {
            nextMax1 = i.second;
            change11 = i.first;
        }
    }

    if (change1 != change) {
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                ans += nums[i] != change;
            } else {
                ans += nums[i] != change1;
            }
        }
        return ans;
    } else {
        vector<int> v1, v2;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                v1.push_back(change);
            } else {
                v1.push_back(change11);
            }
        }

        int ans1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans1 += v1[i] != nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                v2.push_back(change22);
            } else {
                v2.push_back(change1);
            }
        }

        int ans2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans2 += v2[i] != nums[i];
        }

        return min(ans1, ans2);
    }

}