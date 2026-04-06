"""
Travelling Salesman Problem - GREEDY APPROACH
Always picks the nearest unvisited city next.
Fast but often not optimal.
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


def greedy_tsp(cities):
	n = len(cities)
	visited = [False] * n
	route = []

	current = 0
	route.append(current)
	visited[current] = True

	for _ in range(n - 1):
		nearest = None
		nearest_dist = float("inf")

		for j in range(n):
			if not visited[j]:
				d = euclidean_distance(cities[current], cities[j])
				if d < nearest_dist:
					nearest_dist = d
					nearest = j

		route.append(nearest)
		visited[nearest] = True
		current = nearest

	return route


if __name__ == "__main__":
	random.seed(42)
	cities = [(random.randint(0, 100), random.randint(0, 100)) for _ in range(10)]

	print("Cities:", cities)
	route = greedy_tsp(cities)
	print("\n[GREEDY] Route:", route)
	print(f"[GREEDY] Total Distance: {total_distance(route, cities):.2f}")
