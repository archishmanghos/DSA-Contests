int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalGas = 0, n = gas.size();
    for(int i = 0; i < n; i++)
    {
        totalGas += gas[i] - cost[i];
    }

    if(totalGas < 0)
    {
        return -1;
    }

    int ans = 0;
    totalGas = 0;
    for(int i = 0; i < n; i++)
    {
        totalGas += gas[i] - cost[i];
        if(totalGas < 0)
        {
            ans = i + 1;
            totalGas = 0;
        }
    }

    return ans;
}