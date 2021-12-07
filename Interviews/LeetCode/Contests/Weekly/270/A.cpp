vector<int> findEvenNumbers(vector<int> &digits)
{
    vector<int> ans;
    set<int> anss;
    for(int i = 0; i < digits.size(); i++)
    {
        if(digits[i] == 0)
            continue;
        for(int j = 0; j < digits.size(); j++)
        {
            if(i != j)
            {
                for(int k = 0; k < digits.size(); k++)
                {
                    if(i != k && j != k)
                    {
                        if(digits[k] % 2 != 0)
                            continue;
                        int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                        anss.insert(number);
                    }
                }
            }
        }
    }
    for(int i : anss)
        ans.push_back(i);
    return ans;
}