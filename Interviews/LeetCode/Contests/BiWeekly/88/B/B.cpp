class LUPrefix {
public:
    vector<int> val;
    int curMex = 1;
    LUPrefix(int n) {
        val.assign(n + 2, -1);
    }

    void upload(int video) {
        val[video] = 1;
        while (val[curMex] != -1) curMex += 1;
    }

    int longest() {
        return curMex - 1;
    }
};