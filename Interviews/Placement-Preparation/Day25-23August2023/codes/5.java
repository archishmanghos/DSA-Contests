class Pair {
	private int first, second;

	public Pair(int first, int second) {
		this.first = first;
		this.second = second;
	}

	public int getFirst() {
		return first;
	}

	public int getSecond() {
		return second;
	}
}

class Solution {
	public String reorganizeString(String s) {
		PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> y.getFirst() - x.getFirst());
		int[] cnt = new int[26];
		for (int i = 0; i < s.length(); i++) {
			cnt[((int) s.charAt(i) - 97)]++;
		}

		for (int i = 0; i < 26; i++) if (cnt[i] > 0) pq.offer(new Pair(cnt[i], i + 97));

		List<Character> answer = new ArrayList<>();
		while (pq.size() > 1) {
			var it1 = pq.poll();
			char x1 = (char) it1.getSecond();

			if (answer.isEmpty() || answer.get(answer.size() - 1) != x1) {
				answer.add(x1);
				int k = it1.getFirst() - 1;
				if (k > 0) pq.offer(new Pair(k, it1.getSecond()));
			} else {
				var it2 = pq.poll();
				char x2 = (char) it2.getSecond();
				answer.add(x2);
				int k = it2.getFirst() - 1;
				if (k > 0) pq.offer(new Pair(k, it2.getSecond()));
				pq.offer(new Pair(it1.getFirst(), it1.getSecond()));
			}
		}

		boolean clear = pq.isEmpty();
		if (!clear) {
			var it = pq.poll();
			char x = (char) it.getSecond();
			if (it.getFirst() == 1 && (answer.isEmpty() || answer.get(answer.size() - 1) != x)) {
				answer.add(x);
				clear = true;
			}
		}

		if (clear) {
			StringBuilder finalAnswer = new StringBuilder();
			for (var i : answer) finalAnswer.append(i);
			return finalAnswer.toString();
		}
		return "";
	}
}