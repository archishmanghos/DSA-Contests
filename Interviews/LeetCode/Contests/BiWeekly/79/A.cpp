bool digitCount(string num) {
    vector<int> count(10, 0);
    for(int i = 0; i < num.size(); i++){
        count[num[i] - '0'] += 1;
    }
    
    for(int i = 0; i < num.size(); i++){
        if(count[i] == (num[i] - '0')) continue;
        return false;
    }
    
    return true;
}