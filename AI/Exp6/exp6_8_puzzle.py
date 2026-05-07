import heapq
from collections import deque

GOAL_ASTAR = (1, 2, 3, 8, 0, 4, 7, 6, 5)
GOAL_BFS = (7, 2, 3, 4, 6, 5, 1, 8, 0)

NEIGHBORS = {
    0: [1, 3],
    1: [0, 2, 4],
    2: [1, 5],
    3: [0, 4, 6],
    4: [1, 3, 5, 7],
    5: [2, 4, 8],
    6: [3, 7],
    7: [4, 6, 8],
    8: [5, 7],
}


def misplaced_tiles(state, goal):
    return sum(1 for s, g in zip(state, goal) if s != 0 and s != g)


def successors(state):
    blank = state.index(0)
    result = []
    for nxt in NEIGHBORS[blank]:
        arr = list(state)
        arr[blank], arr[nxt] = arr[nxt], arr[blank]
        result.append(tuple(arr))
    return result


def reconstruct(parent, end_state):
    path = []
    cur = end_state
    while cur is not None:
        path.append(cur)
        cur = parent[cur]
    path.reverse()
    return path


def solve_astar(initial, goal=GOAL_ASTAR):
    h0 = misplaced_tiles(initial, goal)
    pq = [(h0, 0, initial)]  # (f, g, state)
    parent = {initial: None}
    g_cost = {initial: 0}
    closed = set()

    while pq:
        f, g, state = heapq.heappop(pq)
        if state in closed:
            continue
        closed.add(state)

        if state == goal:
            return reconstruct(parent, state)

        for nxt in successors(state):
            tentative_g = g + 1
            if nxt in closed:
                continue
            if nxt not in g_cost or tentative_g < g_cost[nxt]:
                g_cost[nxt] = tentative_g
                parent[nxt] = state
                h = misplaced_tiles(nxt, goal)
                heapq.heappush(pq, (tentative_g + h, tentative_g, nxt))

    return None


def solve_greedy(initial, goal=GOAL_ASTAR):
    pq = [(misplaced_tiles(initial, goal), initial)]
    parent = {initial: None}
    visited = set()

    while pq:
        h, state = heapq.heappop(pq)
        if state in visited:
            continue
        visited.add(state)

        if state == goal:
            return reconstruct(parent, state)

        for nxt in successors(state):
            if nxt not in visited and nxt not in parent:
                parent[nxt] = state
                heapq.heappush(pq, (misplaced_tiles(nxt, goal), nxt))

    return None


def solve_bfs(initial, goal=GOAL_BFS):
    q = deque([initial])
    parent = {initial: None}

    while q:
        state = q.popleft()
        if state == goal:
            return reconstruct(parent, state)

        for nxt in successors(state):
            if nxt not in parent:
                parent[nxt] = state
                q.append(nxt)

    return None


def print_state(state):
    print(f"{state[0]} {state[1]} {state[2]}")
    print(f"{state[3]} {state[4]} {state[5]}")
    print(f"{state[6]} {state[7]} {state[8]}")
    print("---")


def print_solution(path):
    if not path:
        print("No solution found.")
        return
    for st in path:
        print_state(st)


def main():
    # From your experiment PDF
    initial_a = (2, 8, 3, 1, 6, 4, 7, 0, 5)
    initial_b = (1, 2, 3, 8, 0, 4, 7, 6, 5)

    print("A* Search")
    sol_a = solve_astar(initial_a, GOAL_ASTAR)
    print("Steps(A*):", len(sol_a) if sol_a else 0)

    print("Greedy Best-First Search")
    sol_g = solve_greedy(initial_a, GOAL_ASTAR)
    print("Steps(Greedy):", len(sol_g) if sol_g else 0)

    print("BFS (No Heuristic)")
    sol_b = solve_bfs(initial_b, GOAL_BFS)
    print("Steps(BFS):", len(sol_b) if sol_b else 0)


if __name__ == "__main__":
    main()
