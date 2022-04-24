[Link to problem on Leetcode](https://leetcode.com/problems/design-underground-system/)

My Solution: TC = O(logN), SC = O(N)

* Take 3 maps. <br>

> Map 1: Stores the time taken to travel from station1 to station2. <br>
> Map 2: Stores the number of times someone has travelled from station1 to station2. <br>
> Map 3: Stores the check in station and time of a particular person. <br>
>

* The rest is easy implementation. <br>
* In the check in function, use `Map 3` to store the time and station of this id. <br>
* In the check out function, use `Map 3` to get the checkin time and station of this id and use this information to store time taken to travel from checkin station to current station in `Map 1` and increment the count in `Map 2`. <br>
* In the getAverageTime function, use values in `Map 1` and `Map 2` to calculate the required time. <br>

Runtime: `203 ms`, faster than `55.53%`<br>
Memory Usage: `59.5 MB`, less than `31.15%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/1396.png)

</details>