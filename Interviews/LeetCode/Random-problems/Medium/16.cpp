int threeSumClosest(vector<int>& nums, int target) 
{
    sort(nums.begin(), nums.end());
     int minDeviation = 100000, ans = 0;
     for(int i = 0; i <= nums.size() - 3; i++)
     {
        int j = i + 1, k = nums.size() - 1;
        while(j < k)
        {
            int sumNow = nums[i] + nums[j] + nums[k];
            int deviation = abs(target - sumNow);

            if(deviation < minDeviation)
            {
                minDeviation = deviation;
                ans = sumNow;
            }

            if(sumNow == target)
                return sumNow;
            else if(sumNow > target)
                k -= 1;
            else
                j += 1;
        }
     }

     return ans;
}

/*

Analysis:

Time Complexity: O(N*N)
Space Complexity: O(1)

A bit tricky, use sorting and 2-pointer, although maybe sorting, nested for and lowerbound also works, but that will be O(N*N*logn) complexity.

*/