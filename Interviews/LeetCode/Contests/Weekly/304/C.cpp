void findDis(int startNode, vector<int> &edges, vector<int> &dist) {
	queue<int> q;
	q.push(startNode);
	dist[startNode] = 0;
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		if (edges[curNode] != -1) {
			if (dist[edges[curNode]] > dist[curNode] + 1) {
				dist[edges[curNode]] = dist[curNode] + 1;
				q.push(edges[curNode]);
			}
		}
	}
}
int closestMeetingNode(vector<int>& edges, int node1, int node2) {
	int n = edges.size();
	vector<int> dist1(n, 10001000), dist2(n, 10001000);
	findDis(node1, edges, dist1);
	findDis(node2, edges, dist2);

	int ans = 10001000, node = -1;
	for (int i = 0; i < n; i++) {
		int commonDist = max(dist1[i], dist2[i]);
		if (commonDist < ans) {
			ans = commonDist;
			node = i;
		}
	}

	return node;
}