string addPaddingOfZeroes(string x, int length)
{
    int n = x.size();
    if(n == length)
        return x;

    for(int i = 1; i <= (length - n); i++)
        x = '0' + x;

    return x;
}
string addBinary(string a, string b)
{
    int n = a.size(), m = b.size();
    a = addPaddingOfZeroes(a, max(n, m));
    b = addPaddingOfZeroes(b, max(n, m));
    int carry = 0;
    string ans = "";

    for(int i = max(n, m) - 1; i >= 0; i--)
    {
        int add1 = a[i] - '0';
        int add2 = b[i] - '0';
        int add = add1 + add2 + carry;

        if(add == 1)
        {
            add = 1;
            carry = 0;
        }
        else if(add == 2)
        {
            add = 0;
            carry = 1;
        }
        else if(add == 3)
            add = carry = 1;

        ans += (add + '0');
    }

    if(carry)
        ans += '1';

    reverse(ans.begin(), ans.end());
    return ans;
}