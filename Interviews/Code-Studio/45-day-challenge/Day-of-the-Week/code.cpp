#include <bits/stdc++.h>
using namespace std;

string dayOfTheWeek(int day, int month, int year)  {
    int m = (month > 2 ? month : month + 12);
    if (m > 12) year--;
    int y = year % 100, c = year / 100;

    string answer[7] = {"Satur", "Sun", "Mon", "Tues", "Wednes", "Thurs", "Fri"};
    int idx = (day + (13 * (m + 1)) / 5 + y + y / 4 + c / 4 + 5 * c) % 7;
    string finalAns = answer[idx] + "day";
    return finalAns;
}