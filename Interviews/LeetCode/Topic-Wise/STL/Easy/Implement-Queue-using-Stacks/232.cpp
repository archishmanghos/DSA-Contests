#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    vector<int> inputStack, outputStack;
public:
    MyQueue() {
        inputStack.clear();
        outputStack.clear();
    }

    void push(int x) {
        inputStack.push_back(x);
    }

    int pop() {
        int ans;
        if (outputStack.size()) {
            ans = outputStack.back();
            outputStack.pop_back();
        } else {
            while (inputStack.size()) {
                outputStack.push_back(inputStack.back());
                inputStack.pop_back();
            }
            ans = outputStack.back();
            outputStack.pop_back();
        }

        return ans;
    }

    int peek() {
        if (outputStack.size()) {
            return outputStack.back();
        }

        while (inputStack.size()) {
            outputStack.push_back(inputStack.back());
            inputStack.pop_back();
        }

        return outputStack.back();
    }

    bool empty() {
        return inputStack.size() == 0 and outputStack.size() == 0;
    }
};