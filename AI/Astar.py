import heapq


def reconstruct_path(came_from, current):
	path = [current]
	while current in came_from:
		current = came_from[current]
		path.append(current)
	path.reverse()
	return path


def astar(graph, start, goal, heuristic):
	open_set = []
	heapq.heappush(open_set, (heuristic[start], start))

	came_from = {}
	g_score = {i: float("inf") for i in range(len(graph))}
	g_score[start] = 0

	visited = set()

	print(f"A* Traversal starting from node {start} to find goal {goal}")

	while open_set:
		_, current = heapq.heappop(open_set)

		if current in visited:
			continue

		visited.add(current)
		print(f"Visiting node: {current}")

		if current == goal:
			path = reconstruct_path(came_from, goal)
			print(f"\nGoal {goal} found!")
			print(f"Path taken: {path}")
			return True

		for neighbor in range(len(graph)):
			if graph[current][neighbor] == 1:
				tentative_g = g_score[current] + 1

				if tentative_g < g_score[neighbor]:
					came_from[neighbor] = current
					g_score[neighbor] = tentative_g
					f_score = tentative_g + heuristic[neighbor]
					heapq.heappush(open_set, (f_score, neighbor))

	print("\nGoal not found")
	return False


if __name__ == "__main__":
	graph = [
		[0, 1, 1, 0, 0, 0, 0, 0, 0, 0],
		[1, 0, 0, 1, 0, 0, 0, 0, 0, 0],
		[1, 0, 0, 1, 1, 0, 0, 0, 0, 0],
		[0, 1, 1, 0, 0, 1, 0, 0, 0, 0],
		[0, 0, 1, 0, 0, 1, 1, 0, 0, 0],
		[0, 0, 0, 1, 1, 0, 0, 1, 0, 0],
		[0, 0, 0, 0, 1, 0, 0, 1, 1, 0],
		[0, 0, 0, 0, 0, 1, 1, 0, 0, 1],
		[0, 0, 0, 0, 0, 0, 1, 0, 0, 1],
		[0, 0, 0, 0, 0, 0, 0, 1, 1, 0],
	]

	# Estimated cost from each node to goal node 9.
	heuristic = [4, 4, 3, 3, 2, 2, 1, 1, 1, 0]

	start_node = 0
	goal_node = 9

	astar(graph, start_node, goal_node, heuristic)
