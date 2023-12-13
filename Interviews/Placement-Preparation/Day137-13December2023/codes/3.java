package codeforces;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class G_1676 {
	static final Map<Integer, List<Integer>> adj = new HashMap<>();
	static String colour;
	static int answer;

	static int getBalanced(int node, int parent) {
		int balance = colour.charAt(node - 1) == 'W' ? 1 : -1;
		for (int child : adj.getOrDefault(node, new ArrayList<>())) {
			if (child != parent) {
				balance += getBalanced(child, node);
			}
		}

		answer += balance == 0 ? 1 : 0;
		return balance;
	}

	public static void main(String[] semicolonised) {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);

		int tt = fs.nextInt();
		for (int ii = 1; ii <= tt; ii++) {
			int n = fs.nextInt();
			for (int i = 1; i <= n; i++) adj.getOrDefault(i, new ArrayList<>()).clear();
			answer = 0;

			for (int i = 2; i <= n; i++) {
				int j = fs.nextInt();
				adj.computeIfAbsent(j, f -> new ArrayList<>()).add(i);
			}

			colour = fs.next();
			getBalanced(1, 1);
			System.out.println(answer);
		}
		out.close();
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}
}