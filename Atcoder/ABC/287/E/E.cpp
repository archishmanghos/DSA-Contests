#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <G:\DSA-Contests\archidebug.h>
#else
#define debug(x)
#endif

#define int long long
using namespace std;

struct Node {
	Node *links[26];
	int countEnd = 0;
	bool containsKey(char ch) {
		return links[ch - 'a'] != NULL;
	}
	void createKey(char ch) {
		links[ch - 'a'] = new Node();
	}
	Node *getReferenceTrie(char ch) {
		return links[ch - 'a'];
	}
	void setEnd() {
		countEnd += 1;
	}
};

class Trie {
private: Node *root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node *dummy = root;
		for (int i = 0; i < word.size(); i++) {
			if (!dummy->containsKey(word[i])) {
				dummy->createKey(word[i]);
			}
			dummy = dummy->getReferenceTrie(word[i]);
			dummy->setEnd();
		}
	}

	int maxLength(string word) {
		Node *dummy = root;
		int answer = 0;
		for (int i = 0; i < word.size(); i++) {
			dummy = dummy->getReferenceTrie(word[i]);
			if (dummy->countEnd > 1) {
				answer = i + 1;
			} else break;
		}
		return answer;
	}
};

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	string S[N + 2];
	Trie obj;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		obj.insert(S[i]);
	}

	for (int i = 1; i <= N; i++) cout << obj.maxLength(S[i]) << '\n';
	return 0;
}