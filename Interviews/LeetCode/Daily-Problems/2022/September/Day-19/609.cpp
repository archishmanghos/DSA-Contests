vector<vector<string>> findDuplicate(vector<string>& paths) {
    map<string, vector<string>> filePaths;
    for (string path : paths) {
        int i = 0, n = path.size();
        string directoryPath = "";
        while (path[i] != ' ') {
            directoryPath += path[i++];
        }

        directoryPath += '/';
        string fileName = directoryPath, content = "";
        while (i < n) {
            if (path[i] == ' ') {
                fileName = directoryPath;
                content = "";
                i += 1;
            } else if (path[i] == '(') {
                while (i < n and path[i] != ')') {
                    content += path[i++];
                }
                filePaths[content].push_back(fileName);
                i += 1;
            } else {
                while (i < n and path[i] != '(') {
                    fileName += path[i++];
                }
            }
        }
    }

    vector<vector<string>> ans;
    for (auto i : filePaths) {
        if (i.second.size() > 1) {
            vector<string> temp;
            for (string j : i.second) {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
    }

    return ans;
}