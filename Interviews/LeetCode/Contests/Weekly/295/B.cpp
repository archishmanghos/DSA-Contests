long stringtointeger(string x) {
    long ans = 0, j = 1;
    for (int i = x.size() - 1; i >= 0; i--){
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}

string integertostring(long x) {
    if(x == 0) return "0";
    string ans = "";
    while (x > 0) {
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string putDecimal(string beforeDecimal) {
    string ans = "";
    int n = beforeDecimal.size();
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 3) ans += '.';
        ans += beforeDecimal[i];
    }
    
    if(ans.size() == 1) ans += "0.0";
    else if(ans.size() == 2) ans += ".0";
    reverse(ans.begin(), ans.end());
    return ans;
}

string applyDiscountAndRoundOff(long amount, int discount){
    long double discountAmount = ((long double)discount / 100.0) * amount;
    long double newAmount = (long double)amount - discountAmount;
    long amountForRoundOff = (long)(newAmount * 100 + 0.5);
    string ansAmount = integertostring(amountForRoundOff);
    string ansAfterPuttingDecimal = putDecimal(ansAmount);
    return ansAfterPuttingDecimal;
}

string discountPrices(string sentence, int discount){
    string ans = "";
    int i = 0, n = sentence.size();
    while(i < n){
        if(sentence[i] != '$'){
            ans += sentence[i];
            i += 1;
            continue;
        }
        
        string canBeInteger = "";
        int j = i + 1;
        while(j < n and sentence[j] != ' ') canBeInteger += sentence[j], j += 1;
        
        bool isItAInteger = true;
        for(char c : canBeInteger){
            if(c<'0' or c>'9'){
                isItAInteger = false;
                break;
            }
        }
        
        if(!isItAInteger or canBeInteger.size() == 0){
            ans += "$";
            ans += canBeInteger;
            i = j;
            continue;
        }
        
        long newInteger = stringtointeger(canBeInteger);
        string afterDiscount = applyDiscountAndRoundOff(newInteger, discount);
        ans += '$';
        ans += afterDiscount;
        i = j;
    }

    return ans;
}