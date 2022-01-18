bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int cnt = 0, ans = 0;
    bool start = false, atleastOne = false;
    for(int i = 0; i < flowerbed.size(); i++)
    {
        if(flowerbed[i] == 1)
        {
            if(start)
            {
                ans += (cnt - 1) / 2;
            }
            else
            {
                ans += cnt / 2;
            }
            start = true;
            atleastOne = true;
            cnt = 0;
        }
        else
        {
            cnt += 1;
        }
    }

    if(!atleastOne)
    {
        ans += (cnt + 1) / 2;
    }
    else
    {
        ans += cnt / 2;
    }
    return ans >= n;
}