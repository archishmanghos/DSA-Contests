class MedianFinder {
public:
    priority_queue<int> lowPart;
    priority_queue<int, vector<int>, greater<int>> highPart;
    MedianFinder() {
        lowPart = priority_queue <int>();
        highPart = priority_queue <int, vector<int>, greater<int>>();
    }
    
    void addNum(int num) {
        lowPart.push(num);
        int n1 = lowPart.size(), n2 = highPart.size();
        if (n1 - n2 > 1) {
            int ele = lowPart.top();
            lowPart.pop();
            highPart.push(ele);
        }
        if (n1 and n2 and lowPart.top() > highPart.top()) {
            int ele = lowPart.top();
            lowPart.pop();
            highPart.push(ele);
            if (n1 == n2) {
                ele = highPart.top();
                highPart.pop();
                lowPart.push(ele);
            }
        }
    }
    
    double findMedian() {
        int n1 = lowPart.size(), n2 = highPart.size();
        double ans;
        if (n1 == n2) {
            ans = lowPart.top() + highPart.top();
            ans /= 2;
        } else {
            if (n1 > n2) {
                ans = lowPart.top();
            } else {
                ans = highPart.top();
            }
        }
        return ans;
    }
};