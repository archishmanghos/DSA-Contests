int ladderLength(string beginWord, string endWord, vector <string> &wordList) {
    set <string> unVisited;
    for (string word: wordList) {
        unVisited.insert(word);
    }

    queue <string> q;
    q.push(beginWord);
    int ans = 2;

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 1; i <= sz; i++) {
            string curWord = q.front();
            q.pop();
            string changedWord = curWord;

            for (int j = 0; j < curWord.size(); j++) {
                for (char k = 'a'; k <= 'z'; k++) {
                    if (k != curWord[j]) {
                        changedWord[j] = k;
                    }
                    if (unVisited.find(changedWord) != unVisited.end()) {
                        if (changedWord == endWord) {
                            return ans;
                        }
                        q.push(changedWord);
                        unVisited.erase(changedWord);
                    }
                }
                changedWord = curWord;
            }
        }
        ans += 1;
    }
    return 0;
}