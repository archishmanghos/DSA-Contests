int countAsterisks(string s) {
    bool barContinue = false;
    int ans = 0;
    for(char c : s){
    	if(c == '*'){
    		if(barContinue) continue;
    		ans += 1;
    	}else if(c == '|'){
    		barContinue = !barContinue;
    	}
    }

    return ans;
}