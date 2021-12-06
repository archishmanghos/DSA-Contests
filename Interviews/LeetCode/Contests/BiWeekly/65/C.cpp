class Solution 
{
    public:
        vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
        {
            map<int, int> maxx;
            sort(items.begin(), items.end());
            vector<int> all;
            int maxxx = 0;
            int inf = 1e9 + 7;
            all.push_back(0);
            for(int i = 0; i < items.size(); i++)
            {
                if(!maxx[items[i][0]])
                    all.push_back(items[i][0]);
                if(items[i][1] > maxxx)
                    maxxx = items[i][1];
                maxx[items[i][0]] = maxxx;
            }
            all.push_back(inf);
            sort(all.begin(), all.end());
            vector<int> ans;
            for(int i = 0; i < queries.size(); i++)
            {
                int lb = upper_bound(all.begin(), all.end(), queries[i]) - all.begin();
                lb -= 1;
                if(lb == 0 || lb == all.size() - 1)
                    ans.push_back(0);
                else
                    ans.push_back(maxx[all[lb]]);
            }
            return ans;
        }
};