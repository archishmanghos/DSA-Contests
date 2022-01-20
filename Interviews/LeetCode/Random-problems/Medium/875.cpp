int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = 0;
    for(int i : piles)
    {
        high = max(i, high);
    }

    auto check = [](int k, int h, vector<int> v)->bool
    {
        int hour = 0;
        for(int i = 0; i < v.size(); i++)
        {
            hour += (v[i] + k - 1) / k;
        }
        return hour <= h;
    };

    while(low < (high - 1))
    {
        int mid = low + (high - low) / 2;
        if(check(mid, h, piles))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(check(low, h, piles))
    {
        return low;
    }
    return high;
}