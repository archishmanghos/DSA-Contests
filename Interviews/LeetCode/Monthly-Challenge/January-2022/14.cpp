long long int stringtointeger(string x)
{
    long long int ans = 0, j = 1;

    for (int i = x.size() - 1; i >= 0; i--)
    {
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}
int myAtoi(string s)
{
    int lowerBound = -2147483648, upperBound = 2147483647;
    string lowerBoundd = "-2147483648", upperBoundd = "2147483647";
    int ans = 0;
    bool negative = false;
    string toBeRead = "";
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' && toBeRead.size() > 0)
            break;
        if(s[i] != ' ')
        {
            if(s[i] == '-' || s[i] == '+')
            {
                if(toBeRead.size() > 0)
                    break;
                toBeRead += s[i];
            }
            else if(s[i] >= '0' and s[i] <= '9')
                toBeRead += s[i];
            else
                break;
        }
    }

    bool ifOk = true;
    if(toBeRead.size() == 0)
        ifOk = false;

    string temp = "";
    bool startreadingzeroes = false;
    int start = ((toBeRead[0] == '+' or toBeRead[0] == '-') ? 1 : 0);
    if(start == 1)
        temp += toBeRead[0];
    for(int i = start; i < toBeRead.size(); i++)
    {
        if(toBeRead[i] == '0')
        {
            if(startreadingzeroes)
                temp += toBeRead[i];
        }
        else
        {
            temp += toBeRead[i];
            startreadingzeroes = true;
        }
    }
    toBeRead = temp;

    if((toBeRead[0] == '-' || toBeRead[0] == '+') and (toBeRead.size() == 1))
        ifOk = false;

    if(ifOk)
    {
        if(toBeRead[0] == '-' || toBeRead[0] == '+')
        {
            negative = (toBeRead[0] == '-' ? true : false);
            if(toBeRead.size() > 11)
                return (negative ? lowerBound : upperBound);
            if(toBeRead.size() == 11)
            {
                if(toBeRead[0] == '-')
                {
                    for(int i = 1; i < toBeRead.size(); i++)
                    {
                        if(toBeRead[i] < lowerBoundd[i])
                            break;
                        if(toBeRead[i] == lowerBoundd[i])
                            continue;
                        return lowerBound;
                    }
                    return stringtointeger(toBeRead.substr(1)) * -1;
                }
                else
                {
                    for(int i = 1; i < toBeRead.size(); i++)
                    {
                        if(toBeRead[i] < upperBoundd[i])
                            break;
                        if(toBeRead[i] == upperBoundd[i])
                            continue;
                        return upperBound;
                    }
                    return stringtointeger(toBeRead.substr(1));
                }
            }
            else
            {
                string ans = toBeRead.substr(1);
                int anss = stringtointeger(ans);
                anss = (negative ? -anss : anss);
                return anss;
            }
        }
        else
        {
            if(toBeRead.size() > 10)
                return upperBound;
            if(toBeRead.size() == 10)
            {
                for(int i = 0; i < toBeRead.size(); i++)
                {
                    if(toBeRead[i] < upperBoundd[i])
                        break;
                    if(toBeRead[i] == upperBoundd[i])
                        continue;
                    return upperBound;
                }
                return stringtointeger(toBeRead);
            }
            else
                return stringtointeger(toBeRead);
        }
    }

    return 0;
}