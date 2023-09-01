from random import randint
from random import shuffle

dataset = []

data_tuple = ()


# calculating Fitness Score
def fitness_score(ds):
    k, kj, score = 0, 0, 0
    while k < len(ds) - 1:
        kj = k + 1
        while kj < len(ds):
            if k != kj and ds[k] == ds[kj] or abs(k - kj) == abs(ds[k] - ds[kj]):
                score = score + 1
            kj = kj + 1

        k = k + 1

    return score


# taking sorting key
def sort_key(ds):
    return ds[4]


# assigning Fitness Score
def cal_fit_score():
    dex = 0
    while dex < len(dataset):
        f_score = fitness_score(dataset[dex])
        d_list = list(dataset[dex])
        d_list[4] = f_score
        dataset[dex] = tuple(d_list)
        # print(dataset[dex], f_score)
        dex = dex + 1

    dataset.sort(key=sort_key)


# doing normal mutation here
def mutation(d_index):
    index = randint(0, 3)
    val = randint(0, 3)

    m_list = list(dataset[d_index])
    m_list[index] = val
    dataset[d_index] = tuple(m_list)


# doing swap mutation here
def swap_mutation(d_index):
    index1 = randint(0, 3)
    index2 = randint(0, 3)

    m_list = list(dataset[d_index])
    temp_val = m_list[index1]
    m_list[index1] = m_list[index2]
    m_list[index2] = temp_val
    dataset[d_index] = tuple(m_list)


# doing inversion mutation here
def inversion_mutation(d_index):
    start_index = randint(0, 2)
    end_index = randint(start_index + 1, 3)

    m_list = list(dataset[d_index])
    temp_val = m_list[start_index:end_index]

    temp_val = temp_val[::-1]
    m_list = m_list[:start_index] + temp_val + m_list[end_index:]
    dataset[d_index] = tuple(m_list)


# doing inversion mutation here
def scramble_mutation(d_index):
    start_index = randint(0, 2)
    end_index = randint(start_index + 1, 3)

    m_list = list(dataset[d_index])
    temp_val = m_list[start_index:end_index]

    # print('before', m_list, start_index, end_index)

    shuffle(temp_val)
    m_list = m_list[:start_index] + temp_val + m_list[end_index:]
    dataset[d_index] = tuple(m_list)

    # print('after', m_list)


i, j = 0, 0

# taking initial population
while i < 15:
    while j < 4:
        value = randint(0, 3)
        data_tuple = data_tuple + (value,)
        j = j + 1

    data_tuple = data_tuple + (0,)
    dataset.append(data_tuple)
    data_tuple = tuple()
    j = 0
    i = i + 1

print(dataset)

cal_fit_score()

print(dataset)

i = 1

while dataset[0][4] != 0:
    # cross over here
    temp1 = dataset[0][:2] + dataset[1][2:]
    temp2 = dataset[1][:2] + dataset[0][2:]

    dataset[0] = temp1
    dataset[1] = temp2

    print('before mutation', dataset)

    # mutation(0)       # 215
    # mutation(1)

    # swap_mutation(0)        # 653
    # swap_mutation(1)

    inversion_mutation(0)       # 285
    inversion_mutation(1)

    # scramble_mutation(0)      # 31
    # scramble_mutation(1)

    print(temp1, temp2)
    print('after mutation', dataset)

    cal_fit_score()

    print('Iterations', i, dataset)
    i = i + 1

print('\nSolution: ', dataset[0], end='\n')
