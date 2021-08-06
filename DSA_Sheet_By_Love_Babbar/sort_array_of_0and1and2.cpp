void sort012(int a[], int n)
{
    int cnt[3] = {0};
    for(int i = 0; i < n; i++)
        cnt[a[i]] += 1;
    int k = 0;
    for(int i = 0; i <= 2; i++)
    {
        for(int j = 1; j <= cnt[i]; j++)
           a[k++] = i;
    }
}

/*

Analysis:

Time Complexity: O(N)
Space Complexity: O(3) (Since we have taken cnt of 3 elements).

Take the count of 0,1,2 and place each individully in the array. Priority Queue should AC too.

*/