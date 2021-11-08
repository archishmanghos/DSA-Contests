int rangeBitwiseAnd(int left, int right)
{
    int toBeShifted = 0;
    while(left != right)
    {
        left >>= 1;
        right >>= 1;
        toBeShifted += 1;
    }
    int ans = left << toBeShifted;
    return ans;
}

/*

Analysis:
Time-Complexity: O(logN)
Space-Complexity: O(1)

The observation here is the traverse from the MSB bitwise, and when both bits of left and right differ, break and print the left shift of the number, number of times it has been right shifted. An easy explanation is available here: https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/592288/100-memory!-C%2B%2B-solution-with-explanation

*/