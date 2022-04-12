![](https://github.com/archishmanghos/DSA-Contests/blob/master/Interviews/LeetCode/Random-problems/Medium/Game-of-Life/carbon.png)

Optimal Solution: TC = `O(N x M)`, SC = `O(1)`

The idea of the problem is very easy, if we can use extra space. <br>
We can traverse every cell of the board, count the number of dead and live neighbour cells, and update the new board with the changed values. <br>
But we cannot use extra space. <br>
Thus, we can hash the values in their place if we have to change them. <br>
For example, if a dead cell becomes live, we can change 0 to -1 and if  a live cell becomes dead, we can change 1 to 2. <br>
When this cell is a neighbour, we can detect if it originally was dead or live using the values, if the value is <= 0, it means it was dead and if the value is > 1, it means it was alive. <br>
After we are done, we can traverse the board and change the values of -1 to 1 and 2 to 0, so that we get our correct answer. <br>

Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `7 MB`, less than `20.27%`