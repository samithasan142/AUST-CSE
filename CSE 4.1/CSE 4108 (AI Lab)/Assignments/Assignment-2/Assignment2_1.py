queenPos = [[0,0,0,0,0,0,1,0],
       [0,0,0,1,0,0,0,0],
       [1,0,0,0,0,0,0,0],
       [0,0,1,0,0,0,0,0],
       [0,0,0,0,1,0,0,0],
       [0,0,0,0,0,1,0,0],
       [0,0,0,0,0,0,0,0],
       [0,1,0,0,0,0,0,1]]

row, col = 8, 8

def rowAttack(queenPos):
    count = 0
    attacking_pair = 0
    for i in range(8):
        for j in range(8):
            if(queenPos[i][j] == 1):
                count = count + 1
        if (count > 1):
            attacking_pair = attacking_pair + ((count*(count-1))/2)
        count = 0
    return attacking_pair

def diagonallyUp(queenPos):
    attacking_pair = 0
    for k in range(0, 8):
        i=7
        j=k
        count=0
        for l in range(0, k+1):
            if(queenPos[i][j] == 1):
                count = count + 1
            j=j-1
            i=i-1
        if (count > 1):
            attacking_pair = attacking_pair + ((count*(count-1))/2)

    for k in range(0, 7):
        i=k
        j=7
        count=0
        for l in range(0, k+1):
            if(queenPos[i][j] == 1):
                count = count + 1
            j=j-1
            i=i-1
        if (count > 1):
            attacking_pair = attacking_pair + ((count*(count-1))/2)
    return attacking_pair

def diagonallyDown(queenPos):
    attacking_pair = 0
    for i in range(1, (row+col)):
        start_col = max(0, i-row)
        temp = min(i, (col-start_col), row)
        count = 0
        for j in range(0, temp):
            if(queenPos[min(row, i) - j -1][start_col+j] == 1):
                count = count + 1
        if (count > 1):
            attacking_pair = ((count*(count-1))/2)
    return attacking_pair

total = rowAttack(queenPos) + diagonallyUp(queenPos) + diagonallyDown(queenPos)
print('Total Number of Attacking pairs: ' ,total)