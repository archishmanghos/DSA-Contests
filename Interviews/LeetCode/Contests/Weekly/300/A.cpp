class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mp;
        char c = 'a';
        for(char ch : key){
        	if(mp.find(ch) == mp.end()){
        		if(ch != ' ') mp[ch] = c++;
        	}
        }

        string ans = "";
        for(char ch : message){
        	if(ch == ' ') ans += ' ';
        	else ans += mp[ch];
        }

        return ans;
    }
};