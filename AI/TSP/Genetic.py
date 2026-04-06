"""
Travelling Salesman Problem - GENETIC ALGORITHM
Evolves a population of routes with selection, crossover, and mutation.
Finds very good near-optimal solutions.
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


def fitness(route, cities):
	return 1 / total_distance(route, cities)


def create_population(n_cities, pop_size):
	return [random.sample(range(n_cities), n_cities) for _ in range(pop_size)]


def selection(population, cities, tournament_size=5):
	tournament = random.sample(population, tournament_size)
	return max(tournament, key=lambda r: fitness(r, cities))


def ordered_crossover(parent1, parent2):
	n = len(parent1)
	start, end = sorted(random.sample(range(n), 2))

	child = [None] * n
	child[start:end] = parent1[start:end]

	pointer = end
	for gene in parent2[end:] + parent2[:end]:
		if gene not in child:
			if pointer >= n:
				pointer = 0
			child[pointer] = gene
			pointer += 1

	return child


def mutate(route, mutation_rate=0.02):
	for i in range(len(route)):
		if random.random() < mutation_rate:
			j = random.randint(0, len(route) - 1)
			route[i], route[j] = route[j], route[i]
	return route


def genetic_algorithm_tsp(cities, pop_size=100, generations=500, mutation_rate=0.02):
	n = len(cities)
	population = create_population(n, pop_size)

	best_route = min(population, key=lambda r: total_distance(r, cities))
	best_distance = total_distance(best_route, cities)

	for gen in range(generations):
		new_population = [best_route]

		while len(new_population) < pop_size:
			parent1 = selection(population, cities)
			parent2 = selection(population, cities)
			child = ordered_crossover(parent1, parent2)
			child = mutate(child, mutation_rate)
			new_population.append(child)

		population = new_population

		current_best = min(population, key=lambda r: total_distance(r, cities))
		current_dist = total_distance(current_best, cities)
		if current_dist < best_distance:
			best_distance = current_dist
			best_route = current_best

		if (gen + 1) % 100 == 0:
			print(f"  Generation {gen + 1}: Best Distance = {best_distance:.2f}")

	return best_route, best_distance


if __name__ == "__main__":
	random.seed(42)
	cities = [(random.randint(0, 100), random.randint(0, 100)) for _ in range(10)]

	print("Cities:", cities)
	print("\nRunning Genetic Algorithm...")
	route, dist = genetic_algorithm_tsp(cities, pop_size=100, generations=500)
	print("\n[GENETIC ALGORITHM] Route:", route)
	print(f"[GENETIC ALGORITHM] Total Distance: {dist:.2f}")
