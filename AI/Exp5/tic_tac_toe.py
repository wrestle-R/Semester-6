import math


def print_board(board):
    for row in board:
        print(' | '.join(row))
        print('-' * 9)


def check_winner(board, player):
    for row in board:
        if all(cell == player for cell in row):
            return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)):
        return True
    if all(board[i][2 - i] == player for i in range(3)):
        return True
    return False


def is_board_full(board):
    return all(cell != ' ' for row in board for cell in row)


def minimax(board, depth, is_maximizing):
    if check_winner(board, 'X'):
        return 10 - depth
    if check_winner(board, 'O'):
        return depth - 10
    if is_board_full(board):
        return 0

    if is_maximizing:
        best = -math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == ' ':
                    board[i][j] = 'X'
                    best = max(best, minimax(board, depth + 1, False))
                    board[i][j] = ' '
        return best
    else:
        best = math.inf
        for i in range(3):
            for j in range(3):
                if board[i][j] == ' ':
                    board[i][j] = 'O'
                    best = min(best, minimax(board, depth + 1, True))
                    board[i][j] = ' '
        return best


def find_best_move(board):
    best_val = -math.inf
    best_move = (-1, -1)
    for i in range(3):
        for j in range(3):
            if board[i][j] == ' ':
                board[i][j] = 'X'
                move_val = minimax(board, 0, False)
                board[i][j] = ' '
                if move_val > best_val:
                    best_val = move_val
                    best_move = (i, j)
    return best_move


def play_game():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    print('Tic-Tac-Toe: You are O, AI is X')
    print_board(board)

    while True:
        row, col = map(int, input('Enter row and col (0-2): ').split())
        if board[row][col] != ' ':
            print('Invalid move!')
            continue
        board[row][col] = 'O'
        print_board(board)

        if check_winner(board, 'O'):
            print('You win!')
            break
        if is_board_full(board):
            print('Draw!')
            break

        print('AI is thinking...')
        ai_row, ai_col = find_best_move(board)
        board[ai_row][ai_col] = 'X'
        print(f'AI plays at ({ai_row}, {ai_col})')
        print_board(board)

        if check_winner(board, 'X'):
            print('AI wins!')
            break
        if is_board_full(board):
            print('Draw!')
            break


play_game()
