int maxDistToClosest(vector<int> &seats)
{
    int lastIndexOfOne = -1, n = seats.size(), ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(seats[i] == 1)
        {
            ans = max(ans, (lastIndexOfOne < 0 ? i : (i - lastIndexOfOne) / 2));
            lastIndexOfOne = i;
        }
    }
    ans = max(ans, n - lastIndexOfOne - 1);
    return ans;
}