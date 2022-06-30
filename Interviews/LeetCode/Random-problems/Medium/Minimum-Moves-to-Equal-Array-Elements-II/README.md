[Link to problem on Leetcode](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

<details><summary>Sub-Optimal Solution</summary>

Sub-Optimal Solution: TC = `O(N + NlogN)`, SC = `O(1)`

- If you observe, once all the numbers are sorted, the minimum moves required to make all array elements equal is by moving up, i.e. increasing the numbers from the left end and moving down, i.e. decreasing the numbers from the right end until all the numbers become equal.
- You will notice that all the numbers become equal mid-way. Hence, the intuition is that you must make all numbers equal to the middle number in the sorted array for the minimum number of moves.
- Hence, the absolute difference of the current number and the middle number is the number of moves required for this number.
- The sum of absolute difference for all the numbers is your answer.

Lets' take this for example: [1, 2, 3, 4, 5]
Middle number = 3

This is kind of a brute force approach where we are incrementing or decrementing numbers one-by-one until they become equal to the middle number, a.k.a. median.

Move 1: [2, 2, 3, 4, 5], count = 1
Move 2: [3, 2, 3, 4, 5], count = 2
Move 3: [3, 3, 3, 4, 5], count = 3
Move 4: [3, 3, 3, 3, 5], count = 4
Move 5: [3, 3, 3, 3, 4], count = 5
Move 6: [3, 3, 3, 3, 3], count = 6 ---> answer

This is same as the absolute difference logic explained above:

For the array: [1, 2, 3, 4, 5]:

Step 1: abs (1 - 3) = 2, count = 0+2 = 2
Step 2: abs (2 - 3) = 1, count = 2+1 = 3
Step 3: abs (3 - 3) = 0, count = 3+0 = 3
Step 4: abs (4 - 3) = 1, count = 3+1 = 4
Step 5: abs (5 - 3) = 2, count = 4+2 = 6 ---> answer

[Editorial Credits](<https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/1217473/C%2B%2BPythonJava-2-Solutions-(w-and-wo-Median)-Explained-with-Example-implementation>)

Runtime: `16 ms`, faster than `55.47%`<br>
Memory Usage: `10.8 MB`, less than `59.74%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/462-A.png)

</details>

</details>

<details><summary>Optimal Solution</summary>

Optimal Solution: TC = `O(N/2 + NlogN)`, SC = `O(1)`

- In the previous method, after sorting the array, we were finding the absolute difference of every number with the middle number.
- In this method, we will simultaneously increase numbers from the left end and decrease numbers from the right end.
- This will help us in simplifying the calculation by excluding mid from the equation. See the below example for reference, taking the same sample array: [1, 2, 3, 4, 5]:

left = 0
right = length (nums) - 1

For nums [right], moves = nums [right] - nums [mid]
For nums [left], moves = nums [mid] - nums [left]

Hence, adding the above 2 equations, we get:

Total Moves = nums [right] - nums [mid] + nums [mid] - nums [left]
Total Moves = nums [right] - nums [left]

Hence, we iterate until left < right and keep adding the difference of corresponding numbers at the left and right positions. Keep incrementing left and decrementing right pointers respectively.

So, for our sample array [1, 2, 3, 4, 5]:

Step 1: left = 0, right = 4: moves = 0 + (5 - 1) = 4
Step 2: left = 1, right = 3: moves = 4 + (4 - 2) = 6
Step 3: left = 2, right = 2: break, moves = 6 ---> answer

[Editorial Credits](<https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/1217473/C%2B%2BPythonJava-2-Solutions-(w-and-wo-Median)-Explained-with-Example-implementation>)

Runtime: `11 ms`, faster than `86.97%`<br>
Memory Usage: `10.7 MB`, less than `92.09%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/462-B.png)

</details>

</details>
