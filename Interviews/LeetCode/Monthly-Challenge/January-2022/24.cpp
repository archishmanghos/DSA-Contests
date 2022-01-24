bool detectCapitalUse(string word)
{
    bool allUpper = true, allLower = true, other = true;
    for(int i = 0; i < word.size(); i++)
    {
        int asciiVal = (int)word[i];
        allUpper &= (asciiVal >= 65 and asciiVal <= 90);
        allLower &= (asciiVal >= 97 and asciiVal <= 122);
        if(i == 0)
        {
            other &= (asciiVal >= 65 and asciiVal <= 90);
        }
        else
        {
            other &= (asciiVal >= 97 and asciiVal <= 122);
        }
    }

    return (allUpper or allLower or other);
}