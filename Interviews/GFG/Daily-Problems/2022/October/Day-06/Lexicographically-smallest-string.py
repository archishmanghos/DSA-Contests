def lexicographicallySmallest(ob, S, k):
    n = len(S)
    if n & (n - 1):
        k <<= 1
    else:
        k >>= 1

    if k >= n: return "-1"
    ans = ""
    for c in S:
        while k > 0 and len(ans) and ans[-1] > c:
            ans = ans[:-1]
            k -= 1
        ans += c

    while k > 0:
        ans = ans[:-1]
        k -= 1

    return ans
