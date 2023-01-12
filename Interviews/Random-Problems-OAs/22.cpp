#include <bits/stdc++.h>
using namespace std;

string solution(int N) {
    string answer(N, '.');
    for (int i = 0; i < N; i++) answer[i] = (i % 2 == 0 ? '+' : '-');
    return answer;
}