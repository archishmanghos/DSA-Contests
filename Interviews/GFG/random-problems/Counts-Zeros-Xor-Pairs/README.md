Optimal Solution: TC = `O(N)`, SC = `O(N)`

We know that the xor values of 2 elements will only result is 0, when both of them are same. <br>
Hence, we maintain a count array and traverse the original array and add count[arr[i] - 1] instances of our answer, since those are the ones contributing. <br>

Total Time Taken: `0.0/2.2`

Another Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

We can delete the count array and instead maintain a count variable which will reduce our space complexity to constant value. <br>
However, to make that bargain, we have to bring together the same values, which can be done using sorting. <br>
Hence, we sort the array and when we reach a number that is not equal to the previous element, we add [cnt x (cnt-1)/2] to our answer. <br>

Total Time Taken: `0.0/2.2`