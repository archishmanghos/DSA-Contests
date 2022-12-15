#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

vector<int> find_country(vector<int> survery_rating_arr, int survey_len, int total_provinces, int month_number) {
	int n = survey_len / total_provinces;
	vector<vector<int>> countries(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < total_provinces; j++) {
			countries[i].push_back(survery_rating_arr[i * total_provinces + j]);
		}
		countries[i].push_back(i + 1);
	}

	sort(countries.begin(), countries.end());
	int country = (month_number + total_provinces - 1) / total_provinces;
	month_number %= total_provinces;
	month_number = (month_number == 0 ? total_provinces : month_number);
	vector<int> ans = {countries[country - 1].back(), countries[country - 1][month_number - 1]};

	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n; cin >> c >> n;
	vector<int> v(c * n);
	for (int i = 0; i < c * n; i++) {
		cin >> v[i];
	}

	int p, mn; cin >> p >> mn;
	vector<int> ans = find_country(v, c * n, p, mn);
	cout << ans[0] << ' ' << ans[1];
	return 0;
}