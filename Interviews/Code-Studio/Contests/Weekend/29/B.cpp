#include<bits/stdc++.h>
int find_max(queue<int> q){
	int ans = 0;
	while(!q.empty()){
		ans = max(ans, q.front());
		q.pop();
	}

	return ans;
}

vector<int> hotels(int n, int k,vector<int>& a) {
	queue<int> q;
	int maxVal = 0;
	vector<int> ans;
	for(int i = n - 1; i >= n - k; i--){
		q.push(a[i]);
		if(a[i] > maxVal){
			ans.push_back(i);
			maxVal = a[i];
		}
	}

	for(int i = n - k - 1; i >= 0; i--){
		int x = q.front();
        q.pop();
        q.push(a[i]);
        if (a[i] > maxVal) {
            ans.push_back(i);
            maxVal = a[i];
        }
        else {
            if (x == maxVal) {
                maxVal = find_max(q);
            }
        }
	}

	sort(ans.begin(), ans.end());
	return ans;
}