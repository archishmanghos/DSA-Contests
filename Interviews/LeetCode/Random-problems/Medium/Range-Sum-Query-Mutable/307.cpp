class NumArray {
private:
    vector<int> BIT, a;
    int n;
    void updateBit(int index, int val) {
        int change = val - a[index];
        a[index] = val;
        for (; index <= n; index += index & -index) {
            BIT[index] += change;
        }
    }
    int getSum(int index) {
        int ans = 0;
        for (; index >= 1; index -= index & -index) {
            ans += BIT[index];
        }

        return ans;
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        BIT.resize(n + 1);
        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            updateBit(i, nums[i - 1]);
        }
    }

    void update(int index, int val) {
        updateBit(index + 1, val);
    }

    int sumRange(int left, int right) {
        return getSum(right + 1) - getSum(left);
    }
};