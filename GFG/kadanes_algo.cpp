int maxSubarraySum(int arr[], int n)
{        
    int sumTillNow = 0, ans = 0, maxx = -100000000;
    for(int i = 0; i < n; i++)
    {
        sumTillNow += arr[i];
        maxx = max(arr[i], maxx);
        ans = max(ans, sumTillNow);
        sumTillNow = max((int)0, sumTillNow);
    }
    if(maxx < 0)
        return maxx;
    return ans;
}

/*

Analysis:

Time Complexity: O(N)
Space Complexity: O(1)

Direct application of Kadane's, except for handling the case when all array elements are <0.

*/