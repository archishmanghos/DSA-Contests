int minPartitions(string n)
{
    int ans = 0;
    for(int i = 0; i < n.size(); i++)
        ans = max(ans, (int)(n[i] - '0'));
    return ans;
}

/*

Time-Complexity: O(n.size())
Space-Complexity: O(1)

Since on every iteration, every digit gets reduces by atmost 1, the digit with the maximum value is the answer

*/