int percentageLetter(string s, char letter) {
    int cnt = 0, n = s.size();
    for(char c : s) cnt += c == letter;
    return (cnt * 100) / n;
}