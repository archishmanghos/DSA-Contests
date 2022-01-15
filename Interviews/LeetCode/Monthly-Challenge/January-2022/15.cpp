int INF = 100007;
int minJumps(vector<int> &arr)
{
    map<int, vector<int>> mp;
    int n = arr.size();
    for(int i = 0; i < n; i++)
        mp[arr[i]].push_back(i);

    queue<int> q;
    q.push(0);
    int ans = 0;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    visited[0] = true;

    while(!q.empty())
    {
        int sz = q.size();
        for(int i = 1; i <= sz; i++)
        {
            int index = q.front();
            if(index == n - 1)
                return ans;
            q.pop();
            if(index + 1 < n)
            {
                if(!visited[index + 1])
                {
                    q.push(index + 1);
                    visited[index + 1] = true;
                }
            }
            if(index - 1 >= 0)
            {
                if(!visited[index - 1])
                {
                    q.push(index - 1);
                    visited[index - 1] = true;
                }
            }
            for(int j : mp[arr[index]])
            {
                if(j != index)
                {
                    if(!visited[j])
                    {
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            mp[arr[index]].clear();
        }
        ans += 1;
    }
    return ans;
}