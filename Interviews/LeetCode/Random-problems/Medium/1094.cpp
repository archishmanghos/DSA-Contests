bool carPooling(vector<vector<int>> &trips, int capacity)
{
    int n = trips.size();
    vector<int> gettingInorOut(1005, 0);
    int start = 1000, end = 0;
    for(int i = 0; i < n; i++)
    {
        gettingInorOut[trips[i][1]] += trips[i][0];
        gettingInorOut[trips[i][2]] -= trips[i][0];
        start = min(start, trips[i][1]);
        end = max(end, trips[i][2]);
    }

    int peopleInside = 0;
    for(int i = start; i <= end; i++)
    {
        peopleInside += gettingInorOut[i];
        if(peopleInside > capacity)
            return false;
    }

    return true;
}