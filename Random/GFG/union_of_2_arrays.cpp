int doUnion(int a[], int n, int b[], int m)  
{
    set<int> ans;
    for(int i = 0; i < n; i++)
        ans.insert(a[i]);
    for(int i = 0; i < m; i++)
    ans.insert(b[i]);
    
    return (int)ans.size();
}

/*

Analysis:

Time complexity: O(N + M)
Space Complexity: O(unique elements of AUB)

Complexity is generous enough to just store all elements in set and output it.

*/