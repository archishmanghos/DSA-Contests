bool ifUnique(string check)
{
    int N = check.size();
    set<char> s;

    for(char c : check)
        s.insert(c);
    int N1 = s.size();

    return N == N1;
}
void rec(string output, int index, vector<string> &arr, int &ans)
{
    if(index == arr.size())
        return;

    string ans1 = output + arr[index];
    string ans2 = output;

    if(ifUnique(ans1))
    {
        ans = max(ans, (int)ans1.size());
        rec(ans1, index + 1, arr, ans);
    }

    if(ifUnique(ans2))
    {
        ans = max(ans, (int)ans2.size());
        rec(ans2, index + 1, arr, ans);
    }

    return;
}
int maxLength(vector<string> &arr)
{
    int ans = 0;
    string input = "";

    rec(input, 0, arr, ans);

    return ans;
}

/*

Analysis: 

Time Complexity: O(2^N)
Space Complexity: O(N)

Recursion easy problem, this is slow though, bit manipulation would make it much faster, but I am weak at that :)

*/