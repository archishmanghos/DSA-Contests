int stepsTaken(char c1, char c2) {
  char to = max(c1, c2), from = min(c1, c2);
  int steps = (to - 'a') - (from - 'a');
  return steps;
}
int minimum_difference(int n, vector<string> &words) {
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n and i != j; j++) {
      int steps = 0;
      for (int k = 0; k < words[i].size(); k++) {
        steps += stepsTaken(words[i][k], words[j][k]);
      }
      cout << words[i] << ' ' << words[j] << ' ' << steps << '\n';
      ans = min(ans, steps);
    }
  }
  return ans;
}