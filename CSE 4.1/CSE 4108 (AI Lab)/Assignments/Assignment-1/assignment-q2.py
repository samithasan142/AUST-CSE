tupleList1=[('parent', 'Shakib', 'Tamim'),
            ('parent', 'Tamim', 'Liton'),
            ('parent', 'Tamim', 'Shohan'),
            ('parent', 'Tamim', 'Ayesha'),
            ('parent', 'Afif', 'Shakib'),
            ('parent', 'Shohan', 'Zenia'),
            ('parent', 'Shohan', 'Riad'),
            ('parent', 'Shohan', 'Tanjin'),
            ('parent', 'Riad', 'Mustafiz')]
tupleList2=[('gender', 'Shakib', 'male'),
            ('gender', 'Tamim', 'male'),
            ('gender', 'Liton', 'male'),
            ('gender', 'Shohan', 'male'),
            ('gender', 'Ayesha', 'female'),
            ('gender', 'Afif', 'male'),
            ('gender', 'Zenia', 'female'),
            ('gender', 'Riad', 'male'),
            ('gender', 'Tanjin', 'female'),
            ('gender', 'Mustafiz', 'male')]


X=str(input("Sibling:"))
print('Brother:', end=' ')
i,j,k=0,0,0
for i in range(9):
    if ((tupleList1[i][0] == 'parent') & ( tupleList1[i][2] == X)):
        for j in range(9):
            if ((tupleList1[j][0] == 'parent') & ( tupleList1[i][1] == tupleList1[j][1]) & ( tupleList1[j][2] != tupleList1[i][2])) :
                for k in range (10) :
                    if((tupleList1[j][2] == tupleList2[k][1]) & (tupleList2[k][2] == 'male')) :
                        print(tupleList1[j][2], end=' ')
print("\n")
X=str(input("Sibling:"))
print('Sister:', end=' ')
i,j,k=0,0,0
for i in range(9):
    if ((tupleList1[i][0] == 'parent') & ( tupleList1[i][2] == X)):
        for j in range(9):
            if ((tupleList1[j][0] == 'parent') & ( tupleList1[i][1] == tupleList1[j][1]) & ( tupleList1[j][2] != tupleList1[i][2])) :
                for k in range (10) :
                    if((tupleList1[j][2]== tupleList2[k][1]) & (tupleList2[k][2] == 'female')) :
                        print(tupleList1[j][2], end=' ')
print("\n")
X=str(input("Niece/Nephew:"))
print('Uncle:', end=' ')
i,j,k,l=0,0,0,0
for i in range(9):
    if ((tupleList1[i][0] == 'parent') & ( tupleList1[i][2] == X)):
        for j in range(9):
            if ((tupleList1[j][0] == 'parent') & ( tupleList1[i][1] == tupleList1[j][2]) & ( tupleList1[j][2] != tupleList1[i][2])) :
                for k in range (9) :
                    if((tupleList1[j][0] == 'parent') & (tupleList1[j][1] == tupleList1[k][1]) & (tupleList1[i][1] != tupleList1[k][2])):
                        for l in range (10) :
                            if((tupleList1[k][2] == tupleList2[l][1]) & (tupleList2[l][2] == 'male')) :
                                print(tupleList1[k][2], end=' ')
print("\n")
X=str(input("Niece/Nephew:"))
print('Aunt:', end=' ')
i,j,k,l=0,0,0,0
for i in range(9):
    if ((tupleList1[i][0] == 'parent') & ( tupleList1[i][2] == X)):
        for j in range(9):
            if ((tupleList1[j][0] == 'parent') & ( tupleList1[i][1] == tupleList1[j][2]) & ( tupleList1[j][2] != tupleList1[i][2])) :
                for k in range (9) :
                    if((tupleList1[j][0] == 'parent') & (tupleList1[j][1] == tupleList1[k][1]) & (tupleList1[i][1] != tupleList1[k][2])) :
                        for l in range (10) :
                            if((tupleList1[k][2]== tupleList2[l][1]) & (tupleList2[l][2] == 'female') ) :
                                print(tupleList1[k][2], end=' ')
print("\n")