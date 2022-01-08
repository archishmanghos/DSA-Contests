string capitalizeTitle(string title)
{
    title += ' ';
    int n = title.size();
    string ans = "";
    string word = "";
    for(int i = 0; i < n; i++)
    {
        if(title[i] == ' ')
        {
            if(word.size() >= 1 and word.size() <= 2)
            {
                for(int j = 0; j < word.size(); j++)
                    word[j] = tolower(word[j]);
            }
            else if(word.size() > 2)
            {
                word[0] = toupper(word[0]);
                for(int j = 1; j < word.size(); j++)
                    word[j] = tolower(word[j]);
            }
            if(ans.size())
                ans += ' ';
            ans += word;
            word = "";
        }
        else
            word += title[i];
    }
    return ans;
}