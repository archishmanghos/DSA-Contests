string kPeriodic(string s, int K){
    vector<int> cnt(26, 0);
    for(char c : s) cnt[c - 'a'] += 1;

    vector<int> characterCount;
    int distinctCharacters = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] > 0){
            characterCount.push_back(cnt[i]);
            distinctCharacters += 1;
        }
    }

    if(distinctCharacters == 1) return s;

    int maxLengthOfRepeatingSubString = 0, gcdd = *characterCount.begin();
    for(int i : characterCount) gcdd = __gcd(gcdd, i);
    for(int i : characterCount) maxLengthOfRepeatingSubString += (i / gcdd);
    if(K % maxLengthOfRepeatingSubString != 0) return "-1";

    int maxToJoin = __gcd(K, (int)s.size()) / maxLengthOfRepeatingSubString;
    string repeat = "", ans = "";
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < (cnt[i] / gcdd)*maxToJoin; j++) repeat += (i + 'a');
    }
    
    for(int i = 1; i <= (gcdd / maxToJoin); i++) ans += repeat;

    return ans;
}