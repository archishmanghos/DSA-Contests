vector<int> sequentialDigits(int low, int high)
{
    vector<int> all;
    for(int i = 2; i <= 9; i++)
    {
        int powerOf10 = 1;
        for(int j = 1; j < i; j++)
        {
            powerOf10 *= 10;
        }
        for(int j = 1; j <= (9 - i + 1); j++)
        {
            int sum = 0, p = powerOf10;
            for(int k = j; k <= (j + i - 1); k++)
            {
                sum += p * k;
                p /= 10;
            }
            all.push_back(sum);
        }
    }

    int startIndex = lower_bound(all.begin(), all.end(), low) - all.begin();
    int endIndex = upper_bound(all.begin(), all.end(), high) - all.begin() - 1;
    vector<int> ans;
    for(int i = startIndex; i <= endIndex; i++)
    {
        ans.push_back(all[i]);
    }

    return ans;
}