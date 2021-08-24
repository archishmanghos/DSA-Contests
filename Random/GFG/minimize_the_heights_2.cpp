int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int ans = arr[n - 1] - arr[0], minn = arr[0], maxx = arr[n - 1];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] >= k && arr[n - 1] >= k)
        {
            minn = min(arr[0] + k, arr[i] - k);
            maxx = max(arr[i - 1] + k, arr[n - 1] - k);

            ans = min(ans, maxx - minn);
        }
    }

    return ans;
}

/*

Analysis: 

Time Complexity: O(NlogN)
Space Complexity: O(1)

This was really hard for me and I had to understand the editorial (https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/) in order to solve it. Not totally crystal clear, I intend to come back to this because I have been really bored by this problem since I have been trying this for more than 5 hours.
Not a interesting problem according to me.

*/