vector<int> topoSort(int V, vector<int> adj[]) {
	vector<int> inDegree(V, 0);
	for (int i = 0; i < V; i++) {
		for (int j : adj[i]) {
			inDegree[j] += 1;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	vector<int> topo(V);
	int i = 0;
	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		topo[i++] = curNode;
		for (int j : adj[curNode]) {
			inDegree[j] -= 1;
			if (inDegree[j] == 0) q.push(j);
		}
	}

	return topo;
}