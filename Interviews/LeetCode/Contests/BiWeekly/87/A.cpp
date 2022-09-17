#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE

#include <G:\DSA-Contests\archidebug.h>

#else
#define debug(x)
#endif

using namespace std;


class Solution {
public:
	int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
		int monthAA = (arriveAlice[0] - '0') * 10 + (arriveAlice[1] - '0');
		int monthAL = (leaveAlice[0] - '0') * 10 + (leaveAlice[1] - '0');
		int monthBA = (arriveBob[0] - '0') * 10 + (arriveBob[1] - '0');
		int monthBL = (leaveBob[0] - '0') * 10 + (leaveBob[1] - '0');
		if (monthAL<monthBA or monthAA>monthBL) return 0;

	}
};


int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Solution leetcode2IDE;
	string arriveAlice1 = "08-15";
	string leaveAlice1 = "08-18";
	string arriveBob1 = "08-16";
	string leaveBob1 = "08-19";
	int output_1 = 3;
	if (leetcode2IDE.countDaysTogether(arriveAlice1, leaveAlice1, arriveBob1, leaveBob1) == output_1) {
		cout << "Sample #1 : Accepted" << endl;
	} else {
		cout << "Sample #1 : Wrong Answer" << endl;
	}

	string arriveAlice2 = "10-01";
	string leaveAlice2 = "10-31";
	string arriveBob2 = "11-01";
	string leaveBob2 = "12-31";
	int output_2 = 0;
	if (leetcode2IDE.countDaysTogether(arriveAlice2, leaveAlice2, arriveBob2, leaveBob2) == output_2) {
		cout << "Sample #2 : Accepted" << endl;
	} else {
		cout << "Sample #2 : Wrong Answer" << endl;
	}




	return 0;
}
