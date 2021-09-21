vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    set<multiset<int>> ans;
    int n = nums.size();
    if(n >= 4)
    {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int temp1 = nums[i] + nums[i + 1];
            int temp2 = target - (nums[i + 2] + nums[i + 3]);
            if(temp1 > temp2)
                break;
            temp1 = nums[i] + nums[n - 3];
            temp2 = target - (nums[n - 2] + nums[n - 1]);
            if(temp2 > temp1)
                continue;

            for(int j = i + 1; j < n - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int temp11 = nums[i] + nums[j];
                int temp12 = target - (nums[j + 1] + nums[j + 2]);
                if(temp11 > temp12)
                    break;
                temp11 = nums[i] + nums[j];
                temp12 = target - (nums[n - 2] + nums[n - 1]);
                if(temp12 > temp11)
                    continue;

                int k = j + 1, l = n - 1;
                while(k < l)
                {
                    int sum1 = nums[i] + nums[j];
                    int sum2 = target - (nums[k] + nums[l]);

                    if(sum1 == sum2)
                    {
                        multiset<int> temp;
                        temp.insert(nums[i]);
                        temp.insert(nums[j]);
                        temp.insert(nums[k]);
                        temp.insert(nums[l]);
                        ans.insert(temp);
                        k += 1;
                        l -= 1;
                    }
                    else
                    {
                        if(sum2 > sum1)
                            k += 1;
                        else
                            l -= 1;
                    }
                }
            }
        }
    }


    vector<vector<int>> finalAns;
    for(auto it : ans)
    {
        vector<int> temp;
        for(int j : it)
            temp.push_back(j);
        finalAns.push_back(temp);
    }

    return finalAns;
}

/*

Analysis:
Time-Complexity: O(N^3)
Space-Complexity: O(2*(4*N)), could be reduced to O(4*N) by avoiding an extra multiset

Straight 2-pointer approach, be aware of integer overflow and make good use of if statements because they can reduce the runtime from 900ms to 20ms!

*/