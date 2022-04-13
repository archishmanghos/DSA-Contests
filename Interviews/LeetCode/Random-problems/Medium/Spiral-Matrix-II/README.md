Optimal Solution: TC = `O(N x N)`, SC = `O(1)`

We can observe a pattern in the spiral matrix. <br>
First, we start traversing from the [0, 0]th cell to the right towards the [0, n - 1]th cell. <br>
When we hit the last cell, we have to go down. Notice, if there was no condition and we could move freely, the only cell we could have moved is the down cell. <br>
<details><summary>Why?</summary>

This is because, we cannot go top and right as we will move out of the grid. The only valid directions are left and down. There is no reason to visit left cell as we came from that cell only. Thus the only cell which is reasonable and valid to visit is the down cell.

</details>
Okay, so now we are in the [1, n - 1]th cell. We move down till we can, to the [n - 1, n - 1]th cell. Let's analyse again if we had no conditions. <br>
The result is the same, we can only visit the left cell from here that is the [n - 1, n - 2]th cell. <br>
This is the pattern that we have to observe. <br>
We again move left till we can, to the [n - 1, 0]th cell. <br>
Do we have any option other than visit the upper cell? No, we don't.<br>
We move up till the [1, 0]th cell. This is because, we already have visited [0, 0]th cell. <br>
We carry on in the same pattern till we run out of empty cells.<br>
This pattern also leads us to another pattern, which we can use to make our code shorter. <br>
<details><summary>Pattern</summary>

Notice, we first go right, then down, then left and then up.<br>
Hence, we can use 2 array of 4 integers which will determine our next x and y co-ordinates. The array will contain integers such that it corresponds to the pattern above. <br>
Thus, when we reach a dead end, we can just increment the index of the array and we can continue filling. Make sure to take the modulus of the new index by 4.

</details>
Finally, we return our grid when there is no cell left to be filled. <br>

Runtime: `0 ms`, faster than `100.00%`<br>
Memory Usage: `6.5 MB`, less than `63.66%`<br>

<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode-59.png)

</details>