#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string sortVowels(string s) {
		string answer = s;
		set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
		vector<char> v;
		for (char i : answer) {
			if (vowels.find(i) != vowels.end()) v.push_back(i);
		}

		sort(v.begin(), v.end());
		for (int i = 0, j = 0; i < answer.size(); i++) {
			if (vowels.find(answer[i]) != vowels.end()) answer[i] = v[j++];
		}

		return answer;
	}
};