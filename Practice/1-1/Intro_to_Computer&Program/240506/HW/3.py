import random
board = [[''for x in range(10)] for y in range(10)]
def isBomb():
    if random.random() > 0.3:
        return False
    else:
        return True

for i in range(10):
    for j in range(10):
        if isBomb():
            board[i][j] = '#'
        else:
            board[i][j] = '.'

for i in range(10):
    for j in range(10):
        print(board[i][j], end = ' ')
    print()