const long long INF = 1e18 + 7;
int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end());
    long long maxx = -INF, ans = 0;
    for(int i = 0; i < points.size(); i++)
    {
        if(maxx < points[i][0])
        {
            ans += 1;
            maxx = points[i][1];
        }
        else
            maxx = min(maxx, (long long)points[i][1]);
    }
    return ans;
}