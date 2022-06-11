class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int sum = nums[0], i = 0, j = 0, terms = 1;
        while(i < nums.size() and j < nums.size()){
            if(sum * terms < k){
                j += 1;
                if(j >= i) ans += j - i;
                if(j < nums.size()) sum += nums[j];
            }else{
                sum -= nums[i];
                terms -= 1;
                i += 1;
            }
        }

        return ans;
    }
};