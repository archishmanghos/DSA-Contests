<h2>459. Repeated Substring Pattern </h2>

[Link to Problem](https://leetcode.com/problems/repeated-substring-pattern/description/)

```java

// Solution 1 using Divisors

public class LC459 {
	private boolean checkCycle(String s, int cycle) {
		int n = s.length();
		for (int i = 0; i < n; i++) if (s.charAt(i % cycle) != s.charAt(i)) return false;
		return true;
	}

	public boolean repeatedSubstringPattern(String s) {
		int n = s.length();
		if (n == 1) return false;
		if (checkCycle(s, 1)) return true;

		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				if (checkCycle(s, i)) return true;
				if (n / i != i && checkCycle(s, n / i)) return true;
			}
		}

		return false;
	}
}

// Solution 2 using concatenation

class Solution {
	public boolean repeatedSubstringPattern(String s) {
		StringBuilder concatenated_s = new StringBuilder();
		int n = s.length();
		for (int i = 1; i < n; i++) concatenated_s.append(s.charAt(i));
		for (int i = 0; i < n - 1; i++) concatenated_s.append(s.charAt(i));

		return concatenated_s.toString().contains(s);
	}
}

```