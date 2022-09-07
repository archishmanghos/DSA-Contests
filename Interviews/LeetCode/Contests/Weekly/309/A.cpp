bool checkDistances(string s, vector<int>& distance) {
	for (int i = 0; i < 26; i++) {
		int dist = distance[i], prevPos = -1;
		for (int j = 0; j < s.size(); j++) {
			if ((s[j] - 'a') == i) {
				if (prevPos != -1) {
					dist = (j - prevPos - 1);
					break;
				}
				prevPos = j;
			}
		}

		distance[i] -= dist;
	}

	for (int i = 0; i < 26; i++) {
		if (distance[i] != 0) return false;
	}

	return true;
}