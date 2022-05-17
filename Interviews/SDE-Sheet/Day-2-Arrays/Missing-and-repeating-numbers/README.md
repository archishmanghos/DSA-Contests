[Link to Striver's SDE Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)

[Link to problem on Code Studio](https://www.codingninjas.com/codestudio/problems/missing-and-repeating-numbers_873366)


<details><summary>Hints</summary>

* I can't think of a hint because I could never come up with this algorithm by myself :).

</details>


<details><summary>Full Solution</summary>

Optimal Solution: TC = `O(N)`, SC = `O(1)`

* This algorithm employs 8 steps: <br>

> 1. Take `XOR` of every element in the array and store it in a variable. <br>
> 2. Take the variable of point 1 and use it to store `XOR` of every integer from 1 to N. <br>
> 3. So now the variable contains xor of [arr[0], arr[1], ..., arr[n - 1], 1, 2, ..., N]. <br>
> 4. Find the position of the rightmost set bit of the variable in point 3. This position will be used to segregate the elements into buckets. Let us call this position `p`. <br>
> 5. For every element of the array, if the element's p-th bit is set, we put it in bucket 1, else we put it in bucket 2. <br>
> 6. Repeat the process of point 5, except the elements will be 1 to N. <br>
> 7. Xor all the values of bucket 1. Xor all the values of bucket 2. Either the value of xor of bucket 1 is the missing value or the repeating value. If it's missing, value of xor of bucket 2 will be repeating, else vice-versa. <br>
> 8. The values can be checked in linear time if it's missing or repeating. <br>

</details>


Runtime: `175ms`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Code-Studio/Missing-and-repeating-numbers.png)

</details>