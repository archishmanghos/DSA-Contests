class Solution 
{
public:
    bool checkAlmostEquivalent(string word1, string word2)
    {
        int freq[30] = {0};
        for(char c : word1)
            freq[c - 'a'] += 1;
        for(char c : word2)
            freq[c - 'a'] -= 1;
        
        for(char i = 'a'; i <= 'z'; i++)
        {
            if(abs(freq[i - 'a']) > 3)
                return false;
        }
        return true;
    }
};