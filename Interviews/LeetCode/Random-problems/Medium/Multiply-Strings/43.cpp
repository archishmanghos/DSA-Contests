string multiply(string num1, string num2) {
    if(num1 < num2) swap(num1, num2);
    int n = num1.size(), m = num2.size();
    vector<string> toAdd;

    reverse(num2.begin(), num2.end());
    reverse(num1.begin(), num1.end());
    for(int i = 0; i < m; i++){
        string prod = "";
        for(int j = 1; j <= i; j++) prod += '0';
        int carry = 0;
        for(int j = 0; j < n; j++){
            int currentProd = (num1[j] - '0') * (num2[i] - '0') + carry;
            prod += (currentProd % 10) + '0';
            carry = currentProd / 10;
        }
        while(carry) {
            prod += (carry % 10) + '0';
            carry /= 10;
        }
        toAdd.push_back(prod);
    }

    int carry = 0;
    string ans = "";
    for(int i = 1; i <= (n + m); i++){
        int currentAdd = carry;
        for(int j = 0; j < toAdd.size(); j++){
            if(toAdd[j].size() >= i) currentAdd += (toAdd[j][i - 1] - '0');
        }

        ans += ((currentAdd % 10) + '0');
        carry = currentAdd / 10;
    }

    while(carry) {
        ans += (carry % 10) + '0';
        carry /= 10;
    }

    while(ans.size() > 1 and ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}