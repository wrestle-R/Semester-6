"""
Travelling Salesman Problem - DYNAMIC PROGRAMMING (Held-Karp)
Uses bitmask DP to explore all subsets and guarantees the optimal solution.
Time complexity: O(n^2 * 2^n), so keep n small.
"""

import math
import random


def euclidean_distance(city1, city2):
	return math.sqrt((city1[0] - city2[0]) ** 2 + (city1[1] - city2[1]) ** 2)


def dp_tsp(cities):
	n = len(cities)

	dist = [[0.0] * n for _ in range(n)]
	for i in range(n):
		for j in range(n):
			dist[i][j] = euclidean_distance(cities[i], cities[j])

	inf = float("inf")
	full_mask = (1 << n) - 1

	dp = [[inf] * n for _ in range(1 << n)]
	parent = [[-1] * n for _ in range(1 << n)]

	dp[1][0] = 0

	for mask in range(1 << n):
		for u in range(n):
			if dp[mask][u] == inf:
				continue
			if not (mask >> u) & 1:
				continue

			for v in range(n):
				if (mask >> v) & 1:
					continue

				new_mask = mask | (1 << v)
				new_dist = dp[mask][u] + dist[u][v]

				if new_dist < dp[new_mask][v]:
					dp[new_mask][v] = new_dist
					parent[new_mask][v] = u

	best_dist = inf
	last_city = -1
	for u in range(1, n):
		cost = dp[full_mask][u] + dist[u][0]
		if cost < best_dist:
			best_dist = cost
			last_city = u

	route = []
	mask = full_mask
	current = last_city
	while current != -1:
		route.append(current)
		prev = parent[mask][current]
		mask ^= 1 << current
		current = prev
	route.reverse()

	return route, best_dist


if __name__ == "__main__":
	random.seed(42)
	cities = [(random.randint(0, 100), random.randint(0, 100)) for _ in range(10)]

	print("Cities:", cities)
	print("\nRunning Held-Karp DP (optimal but exponential)...")
	route, dist = dp_tsp(cities)
	print("\n[DYNAMIC PROGRAMMING] Optimal Route:", route)
	print(f"[DYNAMIC PROGRAMMING] Optimal Distance: {dist:.2f}")
