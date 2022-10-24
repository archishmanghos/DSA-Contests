class Solution:
    def helper (self, idx, s, arr) -> int:
        if idx < 0:
            return 0

        ans = self.helper (idx - 1, s, arr)
        cnt, ok = [0 for i in range(26)], True
        for c in s:
            cnt[ord(c) - 97] += 1
            ok &= cnt[ord(c) - 97] == 1
        for c in arr[idx]:
            cnt[ord(c) - 97] += 1
            ok &= cnt[ord(c) - 97] == 1
        if ok:
            ans = max(ans, self.helper (idx - 1, s + arr[idx], arr) + len(arr[idx]))
            
        return ans
        
    def maxLength (self, arr: List[str]) -> int:
        n = len(arr)
        return self.helper (n - 1, "", arr)