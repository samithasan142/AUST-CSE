tupleList1 = [('parent', 'Shakib', 'Tamim'),
              ('parent', 'Tamim', 'Shohan'),
              ('parent', 'Tamim', 'Mushfiq'),
              ('parent', 'Riad', 'Shakib'),
              ('parent', 'Riad', 'Sabbir'),
              ('parent', 'Shohan', 'Afif')]
X = str(input("Grandchildren:"))
print('Grandparent:', end=' ')
i, j = 0, 0
for i in range(6):
    if (tupleList1[i][0] == 'parent') & (tupleList1[i][2] == X):
        for j in range(6):
            if (tupleList1[j][0] == 'parent') & (tupleList1[i][1] == tupleList1[j][2]):
                print(tupleList1[j][1], end=' ')
