"""
Travelling Salesman Problem - HEURISTIC (2-OPT) APPROACH
Starts with a random route, then improves it by swapping edges.
Near-optimal solution, much better than greedy.
"""

import math
import random


def euclidean_distance(city1, city2):
	return math.sqrt((city1[0] - city2[0]) ** 2 + (city1[1] - city2[1]) ** 2)


def total_distance(route, cities):
	dist = 0
	for i in range(len(route)):
		dist += euclidean_distance(cities[route[i]], cities[route[(i + 1) % len(route)]])
	return dist


def two_opt_swap(route, i, k):
	new_route = route[:i] + route[i : k + 1][::-1] + route[k + 1 :]
	return new_route


def heuristic_2opt_tsp(cities, max_iterations=1000):
	n = len(cities)
	route = list(range(n))
	random.shuffle(route)

	best_distance = total_distance(route, cities)
	improved = True
	iteration = 0

	while improved and iteration < max_iterations:
		improved = False
		iteration += 1

		for i in range(1, n - 1):
			for k in range(i + 1, n):
				new_route = two_opt_swap(route, i, k)
				new_distance = total_distance(new_route, cities)

				if new_distance < best_distance:
					route = new_route
					best_distance = new_distance
					improved = True
					break

			if improved:
				break

	return route, best_distance


if __name__ == "__main__":
	random.seed(42)
	cities = [(random.randint(0, 100), random.randint(0, 100)) for _ in range(10)]

	print("Cities:", cities)
	route, dist = heuristic_2opt_tsp(cities)
	print("\n[HEURISTIC 2-OPT] Route:", route)
	print(f"[HEURISTIC 2-OPT] Total Distance: {dist:.2f}")
