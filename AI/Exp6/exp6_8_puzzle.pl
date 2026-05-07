% EXP 6: 8-Puzzle in Prolog using A* search
% Includes post-lab variants: Greedy Best-First Search and BFS

% -------------------------
% Goal states
% -------------------------
goal([1,2,3,8,0,4,7,6,5]).
goal_b([7,2,3,4,6,5,1,8,0]).

% -------------------------
% Utility predicates
% -------------------------
blank_pos(State, Pos) :-
    nth0(Pos, State, 0).

% Valid blank moves (0-indexed positions)
move(0,1). move(0,3).
move(1,0). move(1,2). move(1,4).
move(2,1). move(2,5).
move(3,0). move(3,4). move(3,6).
move(4,1). move(4,3). move(4,5). move(4,7).
move(5,2). move(5,4). move(5,8).
move(6,3). move(6,7).
move(7,4). move(7,6). move(7,8).
move(8,5). move(8,7).

% Replace element at index I in list
replace([_|T], 0, X, [X|T]).
replace([H|T], I, X, [H|R]) :-
    I > 0,
    I1 is I - 1,
    replace(T, I1, X, R).

% Swap elements at indices I and J
swap(List, I, J, Result) :-
    nth0(I, List, VI),
    nth0(J, List, VJ),
    replace(List, I, VJ, Temp),
    replace(Temp, J, VI, Result).

% Generate successor states
successor(State, Next) :-
    blank_pos(State, Blank),
    move(Blank, NewBlank),
    swap(State, Blank, NewBlank, Next).

% -------------------------
% Heuristic (misplaced tiles)
% -------------------------
misplaced([], [], 0).
misplaced([0|T1], [_|T2], N) :-
    misplaced(T1, T2, N).
misplaced([H|T1], [H|T2], N) :-
    H =\= 0,
    misplaced(T1, T2, N).
misplaced([H|T1], [G|T2], N) :-
    H =\= 0,
    H =\= G,
    misplaced(T1, T2, N1),
    N is N1 + 1.

heuristic(State, H) :-
    goal(Goal),
    misplaced(State, Goal, H).

% -------------------------
% A* search (f = g + h)
% Node form: f(F,G,State,Path)
% -------------------------
astar([f(_,_,State,Path)|_], _, State, Path) :-
    goal(State), !.

astar([f(_,G,State,Path)|Rest], Closed, GoalState, GoalPath) :-
    findall(
        f(F1, G1, Next, [Next|Path]),
        ( successor(State, Next),
          \+ member(Next, Closed),
          G1 is G + 1,
          heuristic(Next, H),
          F1 is G1 + H
        ),
        Successors
    ),
    append(Rest, Successors, Unsorted),
    sort(0, @=<, Unsorted, Open1),
    astar(Open1, [State|Closed], GoalState, GoalPath).

solve(Initial, Solution) :-
    heuristic(Initial, H0),
    astar([f(H0, 0, Initial, [Initial])], [], _, RevPath),
    reverse(RevPath, Solution).

% -------------------------
% Greedy Best-First Search
% Node form: f(H,State,Path)
% -------------------------
gbfs([f(_,State,Path)|_], _, State, Path) :-
    goal(State), !.

gbfs([f(_,State,Path)|Rest], Closed, GoalState, GoalPath) :-
    findall(
        f(H1, Next, [Next|Path]),
        ( successor(State, Next),
          \+ member(Next, Closed),
          heuristic(Next, H1)
        ),
        Successors
    ),
    append(Rest, Successors, Unsorted),
    sort(0, @=<, Unsorted, Open1),
    gbfs(Open1, [State|Closed], GoalState, GoalPath).

solve_greedy(Initial, Solution) :-
    heuristic(Initial, H0),
    gbfs([f(H0, Initial, [Initial])], [], _, RevPath),
    reverse(RevPath, Solution).

% -------------------------
% BFS (no heuristic) for post-lab goal_b/1
% -------------------------
bfs([[State|Path]|_], State, [State|Path]) :-
    goal_b(State), !.

bfs([[State|Path]|Rest], _, Solution) :-
    findall(
        [Next,State|Path],
        ( successor(State, Next),
          \+ member(Next, [State|Path])
        ),
        Children
    ),
    append(Rest, Children, Queue),
    bfs(Queue, _, Solution).

solve_bfs(Initial, Solution) :-
    bfs([[Initial]], _, RevPath),
    reverse(RevPath, Solution).

% -------------------------
% Output formatting
% -------------------------
print_state([A,B,C,D,E,F,G,H,I]) :-
    format('~w ~w ~w~n~w ~w ~w~n~w ~w ~w~n---~n', [A,B,C,D,E,F,G,H,I]).

print_solution([]).
print_solution([H|T]) :-
    print_state(H),
    print_solution(T).

% Example queries:
% ?- solve([2,8,3,1,6,4,7,0,5], Sol), length(Sol, Len), format('Steps(A*): ~w~n', [Len]), print_solution(Sol).
% ?- solve_greedy([2,8,3,1,6,4,7,0,5], Sol), length(Sol, Len), format('Steps(Greedy): ~w~n', [Len]), print_solution(Sol).
% ?- solve_bfs([1,2,3,8,0,4,7,6,5], Sol), length(Sol, Len), format('Steps(BFS): ~w~n', [Len]), print_solution(Sol).
