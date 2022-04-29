[Link to Problem on Leetcode](https://leetcode.com/problems/is-graph-bipartite/)

Optimal Solution: TC = `O(N)`, SC = `O(N)`

* We try to make every alternate node 0 and 1, so that we can differentiate them into 2 different sets. <br>
* Take a colour array and initialise with -1. <br>
* Traverse all the nodes and call for dfs() function if colour of the node is -1. <br>
* In the dfs() function, check if the current node is already coloured. <br>

> 1. If already coloured, check if it is the opposite colour of its immediate ancestor. <br>
>> 1. If it is, return true. <br>
>> 2. If it isn't, return false. <br>
>>
> 2. If not already coloured, colour it in the opposite colour of it's immediate ancestor. <br>
>

* Traverse for all childs of the node and call dfs() function for them as well. <br>
* If all nodes satisfy, we can say the graph is bipartite. <br>
* Note that the graph may not be a fully connected graph, so account for all the components of the graph. <br>

[Video that explains similar thing visually](https://www.youtube.com/watch?v=uC884ske2uQ) <br>

Runtime: `28 ms`, faster than `68.64%`<br>
Memory Usage: `13.5 MB`, less than `81.82%`<br>


<details><summary>Clean Code</summary>

![](https://github.com/archishmanghos/code-images/blob/master/Leetcode/785.png)

</details>