long long stringtointeger(string x){
    long long ans = 0, j = 1;
    for (long long i = x.size() - 1; i >= 0; i--){
        ans += (x[i] - '0') * j;
        j *= 10;
    }

    return ans;
}
string integertostring(long long x){
    string ans = "";
    while (x > 0){
        ans += (x % 10) + '0';
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<long long> kthPalindrome(vector<int> &queries, int intLength){
    long long maxIterations = 1, toStart = 1;
    for(long long i = 1; i <= (intLength - 1) / 2; i++){
        maxIterations *= 10;
    }
    maxIterations *= 9;
    for(long long i = 1; i <= (intLength - 1) / 2; i++){
        toStart *= 10;
    }
    
    toStart -= 1;
    vector<long long> ans;
    for(long long i = 0; i < queries.size(); i++){
        if(queries[i] > maxIterations){
            ans.push_back(-1);
            continue;
        }
        
        long long pal = toStart + queries[i];
        string part1 = integertostring(pal), part2;
        if((long long)intLength % 2){
            part2 = integertostring(pal / 10);
        }else{
            part2 = integertostring(pal);
        }
        reverse(part2.begin(), part2.end());
        
        string finalAns = part1 + part2;
        ans.push_back(stringtointeger(finalAns));
    }
    
    return ans;
}