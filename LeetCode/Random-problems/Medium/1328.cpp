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

/*

Analysis:
Time Complexity: O(N/2)
Space Complexity: O(1)

Easy greedy solution, take care of situations where all characters are same.

*/