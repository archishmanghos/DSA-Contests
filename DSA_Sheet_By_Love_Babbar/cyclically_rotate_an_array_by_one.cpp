void rotate(int arr[], int n)
{
    int x = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
        arr[i + 1] = arr[i];
    arr[0] = x;
}

/*

Analysis:

Time Complexity: O(N)
Space Complexity: O(1)

Simple solution, easy enough to AC in one go. If you can't, you better brush up some basics.

*/