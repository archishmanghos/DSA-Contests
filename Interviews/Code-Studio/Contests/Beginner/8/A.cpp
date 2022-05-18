string maximumNum(int n, string num, vector<int> &a) {
    string ans = "";
	bool done = false, preContinue = false;
	for(int i = 0; i < num.size(); i++){
		int x = num[i] - '0';
		int y = a[num[i] - '0'];
		if(y > x){
			if(!done){
				ans += (y + '0');
				done = preContinue = true;
			}else{
				if(preContinue){
					ans += (y + '0');
				}else{
					ans += num[i];
				}
			}
		}else if(x == y){
			if(preContinue){
				ans += (y + '0');
			}else{
				ans += num[i];
			}
		}else{
			ans += num[i];
			preContinue = false;
		}
	}
	
	return ans;
}