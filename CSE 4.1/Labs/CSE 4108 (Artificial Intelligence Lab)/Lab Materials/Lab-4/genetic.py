import random


def calc_attacking(grid, row, col):
    ans = 0
    for i in range(col + 1, 8):
        if grid[row][i] == 1:
            ans += 1
        
    i = row - 1
    j = col + 1
    while(i >= 0 and j < 8):
        if grid[i][j] == 1:
            ans += 1
        i -= 1
        j += 1

    i = row + 1
    j = col + 1
    while(i < 8 and j < 8):
        if grid[i][j] == 1:
            ans += 1
        i += 1
        j += 1
    return ans
    
    
def find_attacking(positions):
    grid = [[0]*8 for i in range(8)]
    for i in range(8):
        grid[positions[i]][i] = 1

    ans = 0;

    for i in range(8):
        for j in range(8):
            if grid[i][j] == 1:
                ans += calc_attacking(grid, i, j)
    return ans


def crossover(comb1, comb2):
    new_comb1 = comb1[0:4] + comb2[4:8]
    new_comb2 = comb2[0:4] + comb1[4:8]

    return new_comb1, new_comb2


def scramble(comb1, comb2):
    sub_lst1 = comb1[3:8]
    sub_lst2 = comb2[3:8]
    random.shuffle(sub_lst1)
    random.shuffle(sub_lst2)
    return comb1[0:3] + sub_lst1, comb2[0:3] + sub_lst2


def inversion(comb1, comb2):
    sub_lst1 = comb1[3:8]
    sub_lst2 = comb2[3:8]
    sub_lst1.reverse()
    sub_lst2.reverse()
    return comb1[0:3] + sub_lst1, comb2[0:3] + sub_lst2


def swap(comb):
    r1 = random.randint(0, 7)
    while(True):
          r2 = random.randint(0, 7)
          if r1 != r2:
              break

    temp = comb[r1]
    comb[r1] = comb[r2]
    comb[r2] = temp

    return comb


positions = [3, 2, 7, 5, 2, 4, 1, 1]
ans = find_attacking(positions)
print(ans)

combinations = [
                [[6, 3, 7, 0, 5, 3, 1, 4], 1000],
                [[3, 6, 0, 2, 7, 7, 1, 1], 1000],
                [[1, 5, 7, 2, 6, 1, 3, 5], 1000],
                [[6, 3, 6, 5, 2, 4, 6, 7], 1000],
                [[2, 1, 3, 3, 7, 0, 3, 3], 1000],
                [[1, 0, 1, 0, 7, 4, 2, 6], 1000],
                [[1, 7, 1, 1, 6, 4, 4, 0], 1000],
                [[0, 7, 3, 6, 0, 6, 2, 6], 1000],
                [[0, 3, 5, 1, 4, 3, 2, 2], 1000],
                [[0, 7, 2, 3, 0, 1, 2, 5], 1000],
                [[5, 1, 1, 3, 3, 4, 5, 3], 1000],
                [[6, 5, 0, 5, 3, 3, 0, 5], 1000],
                [[0, 2, 2, 3, 5, 1, 0, 1], 1000],
                [[4, 2, 7, 3, 4, 4, 7, 3], 1000],
                [[2, 3, 6, 3, 0, 5, 2, 5], 1000]
                ]
mini = 1000000
comb = []

for ite in range(10000):
    for i in range(len(combinations)):
        combinations[i][1] = find_attacking(combinations[i][0])
        ## print(combinations[i])

    ## print("--------------------------")
    combinations = sorted(combinations, key = lambda x : x[1])

    
    if combinations[0][1] < mini:
        mini = combinations[0][1]
        comb = combinations[0][0]
        
    x, y = crossover(combinations[0][0], combinations[1][0])
    x, y = scramble(x, y)
    combinations[0][0] = x
    combinations[1][0] = y
    
    
print(mini)
print(comb)
