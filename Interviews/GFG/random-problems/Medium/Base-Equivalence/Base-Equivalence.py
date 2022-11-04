import math


class Solution:
    def baseEquiv(self, n, m):
        for i in range(2, 33):
            if (int(math.floor(math.log(n, i))) + 1) == m:
                return "Yes"

        return "No"
