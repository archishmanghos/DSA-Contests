Process-1 -> You can always use the inbuilt sort() function
             in C++. TC will be O(NlogN) and SC will be O(1).
             Not recommended for interviews.

Process-2 -> You can store the count of 0s,1s and 2s in a         vector of size 3 and then traverse again
             to replace the array elements with current i (0 to 3).
             TC will be O(2N) and SC will be O(3). 
             Interviewer may ask for a one pass solution.

Process-3 -> Take 3 pointers, low, mid and high, pointing to 
             0, 0 and the last element respectively. 
             Traverse the array till mid <= high, and there will be
             3 cases:

             Case 1: the element pointed by mid is 0. 
                     In that case, swap the low and mid elements
                     and increase both low and mid pointers by 1.

             Case 2: the element pointed by mid is 1. 
                     In that case, just increase the mid pointer by 1.

             Case 3: the element pointed by mid is 2. 
                     In that case, swap the high and mid elements
                     and decrease the high pointer by 1.

            TC will be O(N) and SC will be O(3).