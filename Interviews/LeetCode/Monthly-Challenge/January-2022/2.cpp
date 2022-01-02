int numPairsDivisibleBy60(vector<int> &time)
{
    vector<bool> done(505, false);
    vector<int> cnt(505, 0);
    for(int i = 0; i < time.size(); i++)
    {
        time[i] %= 60;
        cnt[time[i]] += 1;
    }
    int ans = 0;
    for(int i = 0; i < time.size(); i++)
    {
        int mirror = (60 - time[i]) % 60;
        if(done[time[i]] || done[mirror])
            continue;
        if(time[i] == mirror)
            ans += cnt[mirror] * (cnt[mirror] - 1) / 2;
        else
            ans += cnt[time[i]] * cnt[mirror];
        done[time[i]] = done[mirror] = true;
    }
    return ans;
}