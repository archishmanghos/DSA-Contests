int longestCycle(vector<int>& edges) {
	int n = edges.size(), ans = -1, cnt = 0;
	vector<int> visited(n, 0), dist(n, -1);

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int startNode = i, startCnt = cnt;
			while (startNode != -1) {
				cnt++;
				visited[startNode] = 1;
				dist[startNode] = cnt;
				startNode = edges[startNode];
				if (startNode != -1 and visited[startNode]) {
					if (dist[startNode] > startCnt) {
						ans = max(ans, cnt - dist[startNode] + 1);
					}
					break;
				}
			}
		}
	}

	return ans;
}