import collections

def bfs(graph, start, goal):
    visited = set()
    queue = collections.deque([start])
    visited.add(start)
    path = []
    
    print(f"BFS Traversal starting from node {start} to find goal {goal}")

    while queue:
        vertex = queue.popleft()
        print(f"Visiting node: {vertex}")
        path.append(vertex)

        if vertex == goal:
            print(f"\nGoal {goal} found!")
            print(f"Path taken: {path}")
            return True

        for i in range(len(graph)):
            if graph[vertex][i] == 1 and i not in visited:
                visited.add(i)
                queue.append(i)
    
    print("\nGoal not found")
    return False

if __name__ == "__main__":
    graph = [
        [0,1,1,0,0,0,0,0,0,0],
        [1,0,0,1,0,0,0,0,0,0],
        [1,0,0,1,1,0,0,0,0,0],
        [0,1,1,0,0,1,0,0,0,0],
        [0,0,1,0,0,1,1,0,0,0],
        [0,0,0,1,1,0,0,1,0,0],
        [0,0,0,0,1,0,0,1,1,0],
        [0,0,0,0,0,1,1,0,0,1],
        [0,0,0,0,0,0,1,0,0,1],
        [0,0,0,0,0,0,0,1,1,0]
    ]
    
    start_node = 0
    goal_node = 9
    
    bfs(graph, start_node, goal_node)
