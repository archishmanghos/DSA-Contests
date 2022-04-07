Optimal Solution: TC = `O(NlogN)`, SC = `O(N)`

We have to take a priority queue here. <br>
This is because we have to take the greatest 2 elements each time and destroy them. <br>
This is also optimal, since the closer the 2 stones are to each other in respect to weight, the smaller the stone will become after destruction. <br>
Hence, we put all the stones in the priority queue.<br>
We then take the top 2 elements each time, destroy them. If the difference is 0, we dont put back anything to the priority queue, else we put back to the queue the difference. <br>
We go on till the size of the queue is > 1. <br>
Finally, we check if the queue is empty or not. <br>
> If it's empty, we return 0. <br>
> If it's not empty, we return the top of the queue. <br>
>

Runtime: `3 ms`, faster than `55.52%` <br>
Memory Usage: `7.5 MB`, less than `97.59%`