Optimal Solution: TC = `O(N)`, SC = `O(1)`

> We create a dummy node and point it to the head node. <br>
> We check if the next node and the next to next node are equal or not. <br>
> If equal, we start a while loop and start deleting till they are not equal and make the the next point to the end node's next. <br>
> If not equal, we make the pointer move to the next node. <br>

Runtime: `7 ms`, faster than `83.62%` <br>
Memory Usage: `11.2 MB`, less than `59.49%`