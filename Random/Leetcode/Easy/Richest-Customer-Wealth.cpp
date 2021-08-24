int maximumWealth(vector<vector<int>>& accounts) 
{
        int ans = 0;
        for(int i = 0; i < accounts.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < accounts[i].size(); j++)
                sum += accounts[i][j];
            ans = max(ans, sum);
        }
        
        return ans;
}

/*

Analysis:

Time-Complexity: O(number of people * number of bank accounts)
Space-Complexity: O(1)

Easy solution, just simulate what has been asked in the problem

*/