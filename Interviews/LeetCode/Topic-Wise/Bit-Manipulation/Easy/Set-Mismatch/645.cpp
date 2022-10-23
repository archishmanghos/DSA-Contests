class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xorval = 0, n = nums.size();
        for (int i = 0, j = 1; i < n; i++, j++) {
            xorval ^= nums[i] ^ j;
        }

        int setBit = 0;
        for (int i = 0; i < 15; i++) {
            if ((xorval >> i) & 1) {
                setBit = i;
                break;
            }
        }

        int bucket1 = 0, bucket2 = 0;
        for (int i = 0, j = 1; i < n; i++, j++) {
            if ((nums[i] >> setBit) & 1) {
                bucket1 ^= nums[i];
            } else {
                bucket2 ^= nums[i];
            }

            if ((j >> setBit) & 1) {
                bucket1 ^= j;
            } else {
                bucket2 ^= j;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == bucket1) {
                return {bucket1, bucket2};
            }
        }

        return {bucket2, bucket1};
    }
};