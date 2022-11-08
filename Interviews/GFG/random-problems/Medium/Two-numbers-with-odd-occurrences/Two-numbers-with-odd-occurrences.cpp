class Solution {
   public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        int64_t xorr = 0;
        for (int i = 0; i < N; i++) {
            xorr ^= Arr[i];
        }

        int bit = 37;
        for (int i = 37; i >= 0; i--) {
            if ((xorr >> i) & 1) {
                bit = i;
                break;
            }
        }

        int64_t bucket1 = 0, bucket2 = 0;
        for (int i = 0; i < N; i++) {
            if ((Arr[i] >> bit) & 1) {
                bucket1 ^= Arr[i];
            } else {
                bucket2 ^= Arr[i];
            }
        }

        vector<long long int> ans;
        if (bucket1 < bucket2)
            ans = {bucket2, bucket1};
        else
            ans = {bucket1, bucket2};

        return ans;
    }
};