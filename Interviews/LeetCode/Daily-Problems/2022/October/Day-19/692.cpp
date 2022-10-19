class Solution {
private:
    struct Word {
        int frequency;
        string content;
    };

    struct cmp {
        bool operator()(Word const &w1, Word const &w2) {
            if (w1.frequency != w2.frequency) {
                return w1.frequency > w2.frequency;
            }
            return w1.content < w2.content;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> ump;
        priority_queue<Word, vector<Word>, cmp> pq;

        for (string s : words) {
            ump[s] += 1;
        }

        for (auto i : ump) {
            Word w = {i.second, i.first};
            pq.push(w);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans(k);
        while (k--) {
            ans[k] = pq.top().content;
            pq.pop();
        }

        return ans;
    }
};