int stringtointeger(string x){
    int ans = 0, j = 1;
    for (int i = x.size() - 1; i >= 0; i--){
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}
long prodRet(string exp){
    long ans = 0, repeat = 1, multiSecond = 0;
    string tillNow = "";
    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == '('){
            if(tillNow.size() > 0){
                repeat = stringtointeger(tillNow);
            }
            tillNow = "";
        }else if(exp[i] == '+'){
            multiSecond += stringtointeger(tillNow);
            tillNow = "";
        }else if(exp[i] == ')'){
            multiSecond += stringtointeger(tillNow);
            tillNow = "";
        }else{
            tillNow += exp[i];
        }
    }
    
    if(tillNow.size() > 0){
        ans += multiSecond * (repeat *stringtointeger(tillNow));
    }else{
        ans += repeat * multiSecond;
    }
    
    return ans;
}
string minimizeResult(string expression){
    int posFirst, posSecond;
    long long minn = 1e18;
    string ans = "";
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] == '+'){
            break;
        }
        posFirst = i;
    }
    for(int i = expression.size() - 1; i >= 0; i--){
        if(expression[i] == '+'){
            break;
        }
        posSecond = i;
    }
    
    for(int i = 0; i <= posFirst; i++){
        string newExp = expression.substr(0, i);
        newExp += '(';
        for(int j = i; j < expression.size(); j++){
            if(expression[j] == '+'){
                break;
            }
            newExp += expression[j];
        }
        newExp += '+';
        for(int j = expression.size() - 1; j >= posSecond; j--){
            string addOn = newExp;
            for(int k = posSecond; k <= j; k++){
                addOn += expression[k];
            }
            addOn += ')';
            for(int k = j + 1; k < expression.size(); k++){
                addOn += expression[k];
            }
            if(prodRet(addOn) < minn){
                minn = prodRet(addOn);
                ans = addOn;
            }
        }
    }
    
    return ans;
}