/*
The brute method can be calculating every permutaion
and then manually selecting the permutation given in the problem.
The better method is using the STL function next_permutation().
However, the interviewer may not entertain that method lol.

The most optimal and the one that should satisfy the interviewer
follows 4 steps.

-> Find the position in the vector, where nums[position] is less than nums[position+1],
  or in other words, the position where the vector is first ascending.
  If such a position, doesn't exist, reverse the vector
  since we have reached the last permutation.

-> If we find a breakpoint, traverse from the back
   and find the position where the element is greater than nums[breakpoint],
   or, nums[position]>nums[breakpoint]. 
   Since, breakpoint exist, this position will always exist.

-> Swap the elements at the breakpoint and the position where the element is greater than nums[breakpoint].

-> Reverse the subarray starting from breakpoint+1 till the end of the vector.*/

void nextPermutation(vector<int> &nums)
{
    int breakpoint1 = -1, breakpoint2, n = nums.size();
    for(int i = n - 2; i >= 0; i--)
    {
        if(nums[i] < nums[i + 1])
        {
            breakpoint1 = i;
            break;
        }
    }
    if(breakpoint1 != -1)
    {
        for(int i = n - 1; i >= 0; i--)
        {
            if(nums[i] > nums[breakpoint1])
            {
                breakpoint2 = i;
                break;
            }
        }

        swap(nums[breakpoint1], nums[breakpoint2]);
    }

    reverse(nums.begin() + breakpoint1 + 1, nums.end());
}