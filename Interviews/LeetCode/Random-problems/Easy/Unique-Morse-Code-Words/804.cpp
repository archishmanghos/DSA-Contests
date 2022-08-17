int uniqueMorseRepresentations(vector<string>& words) {
    map<char, string> morse;
    morse['a'] = ".-", morse['b'] = "-...", morse['c'] = "-.-.", morse['d'] = "-..", morse['e'] = ".", morse['f'] = "..-.", morse['g'] = "--.", morse['h'] = "....", morse['i'] = "..", morse['j'] = ".---", morse['k'] = "-.-", morse['l'] = ".-..", morse['m'] = "--", morse['n'] = "-.", morse['o'] = "---", morse['p'] = ".--.", morse['q'] = "--.-", morse['r'] = ".-.", morse['s'] = "...", morse['t'] = "-", morse['u'] = "..-", morse['v'] = "...-", morse['w'] = ".--", morse['x'] = "-..-", morse['y'] = "-.--", morse['z'] = "--..";

    set<string> uniqueCodes;
    for (string s : words) {
        string morseCode = "";
        for (char c : s) {
            morseCode += morse[c];
        }
        uniqueCodes.insert(morseCode);
    }

    return uniqueCodes.size();
}