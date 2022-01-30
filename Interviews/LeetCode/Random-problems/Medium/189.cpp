void reverse(vector<int> &nums, int l, int r)
{
    while(l < r)
    {
        swap(nums[l], nums[r]);
        l += 1;
        r -= 1;
    }
}
void rotate(vector<int> &nums, int k)
{
    int N = nums.size();
    k %= N;
    reverse(nums, 0, N - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, N - 1);
}