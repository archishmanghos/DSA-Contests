int rec(int lb, int ub)
{
    int mid = lb + (ub - lb) / 2;
    if(guess(mid) == 0)
        return mid;
    else if(guess(mid) == 1)
        return rec(mid + 1, ub);
    else
        return rec(lb, mid);
}
int guessNumber(int n)
{
    int ans = rec(1, n);
    return ans;
}

/*

Analysis: 
Time-Complexity: O(logN)
Space-Complexity: O(1)

Problem Statement is very confusing, other than that, it's simple binary-search.

*/