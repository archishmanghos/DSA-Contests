Optimal Solution: TC = `O(NlogN)`, SC = `O(1)`

We need to find the longest common prefix. <br>
We sort the array of strings first. <br>
We traverse for the 1st string since that is the string of least length, as the array has been sorted. <br>
We compare each character of the 1st string with the last string of the array. This is because the array is sorted, so if the last string contains a `'g'` at a particular position, every string before that will contain character <= `'g'` at that position. <br>
We check if the current character of the 1st string is equal to the current character of the last string or not. <br>
> If it's equal, then all the other strings are bound to contain the same character and hence this character can be included in the common prefix. <br>
> If it's not equal, we break out of the loop since we cannot increase the length of the prefix anymore. <br>
>
Finally, if the size of the string is 0, we return -1, else we return the string itself. <br>

Total Time Taken: `0.01 / 2.2`