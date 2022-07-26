string vowels(string s) {
    set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    for (char c : s) {
        if (vowels.find(c) != vowels.end()) count += 1;
    }

    return (count % 2 == 0 ? "Yes" : "No");
}
