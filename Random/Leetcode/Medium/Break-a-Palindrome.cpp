string breakPalindrome(string palindrome)
{
    if(palindrome.size() == 1)
        return "";
    int i = 0, N = palindrome.size();
    while(i < (N / 2))
    {
        if(palindrome[i] > 'a')
        {
            palindrome[i] = 'a';
            return palindrome;
        }
        i += 1;
    }

    palindrome[N - 1] = 'b';
    return palindrome;
}