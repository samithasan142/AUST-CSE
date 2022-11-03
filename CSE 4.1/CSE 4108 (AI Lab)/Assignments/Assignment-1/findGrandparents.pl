parent('Shakib' , 'Tamim').
parent('Tamim' , 'Shohan').
parent('Tamim' , 'Mushfiq').
parent('Riad' , 'Shakib').
parent('Riad' , 'Sabbir').
parent('Shohan', 'Afif').

grandparent(X, Z) :-
    parent(X, Y), parent(Y, Z).

findGp :-
    write(' Grandchildren: '), read(Z), write('Grandparent: '),
    grandparent(Gp,Z), write(Gp), tab(5), fail.

findGp.
