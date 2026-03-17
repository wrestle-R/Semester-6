def dfs(graph, node, goal, visited, path):
    visited.add(node)
    print(f"Visiting node: {node}")
    path.append(node)

    if node == goal:
        print(f"\nGoal {goal} found!")
        print(f"Path taken: {path}")
        return True

    for i in range(len(graph)):
        if graph[node][i] == 1 and i not in visited:
            if dfs(graph, i, goal, visited, path):
                return True
    
    path.pop() 
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
    visited = set()
    path = []
    
    print(f"DFS Traversal starting from node {start_node} to find goal {goal_node}")
    dfs(graph, start_node, goal_node, visited, path)
