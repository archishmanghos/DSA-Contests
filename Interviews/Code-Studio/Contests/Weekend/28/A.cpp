int mangoes(vector<int> &v){
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < v.size(); i++){
		if(i % 2 == 0) ans1 += v[i];
		else ans2 += v[i];
	}

	return min(ans1, ans2);
}