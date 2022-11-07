class Solution:
    def maximum69Number(self, num: int) -> int:
        n, pos = [int(x) for x in str(num)], -1
        for idx, i in enumerate(n):
            if i == 6:
                pos = idx
                break

        if pos != -1:
            n[pos] = 9
        return int("".join([str(i) for i in n]))
