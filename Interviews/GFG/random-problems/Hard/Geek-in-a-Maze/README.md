Optimal Solution: TC = `O(N x M)`, SC = `O(N x M)`

Since, we have to count total possible cells we can visit, we can just use a simple BFS. <br>
We use a queue of pair of pairs. The 1st pair contains the current cell we are in and the second pair contains the remaining number of up and down moves we can avail right now. <br>
We run the loop till the queue is empty. <br>
If the current cell is not a valid address or if the cell has already been visited or the cell contains a block, we don't do any operations. <br>
Else, we increase our answer and we put the left and right cell without any cost and the upper and lower cell by checking if we are allowed to move up and down respectively and pushing if we are allowed. <br>
Finally we come out of the loop and return the answer. <br>

Total Time Taken: `0.25/2.2`