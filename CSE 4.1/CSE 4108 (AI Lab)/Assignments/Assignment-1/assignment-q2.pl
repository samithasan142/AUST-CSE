male('Shakib').
male('Tamim').
male('Liton').
male('Shohan').
male('Afif').
female('Zenia').
female('Tanjin').
female('Ayesha').

parent('Shakib' , 'Tamim').
parent('Tamim' , 'Liton').
parent('Tamim' , 'Shohan').
parent('Tamim' , 'Ayesha').
parent('Afif' , 'Shakib').
parent('Shohan' , 'Zenia').
parent('Shohan' , 'Riad').
parent('Shohan' , 'Tanjin').
parent('Riad' , 'Mustafiz').

brother(Y, Z) :-
   parent(X, Y), parent(X, Z), male(Y), not(Y=Z).
sister(Y, Z) :-
   parent(X, Y), parent(X, Z), female(Y), not(Y=Z).
uncle(Y, U) :-
   parent(X, Y), parent(X, Z), parent(Z,U), male(Y), not(Y=U), not(Y=Z).
aunt(Y, U) :-
   parent(X, Y), parent(X, Z), parent(Z,U), female(Y), not(Y=U), not(Y=Z).

findBrother :-
   write(' Siblings: '), read(Z), write('Brother: '),
   brother(Brother,Z), write(Brother), tab(5),fail.
findBrother.

findSister :-
   write(' Siblings: '), read(Z), write('Sister: '),
   sister(Sister,Z), write(Sister), tab(5),fail.
findSister.

findUncle:-
   write(' Niece/Nephew: '), read(Z), write('Uncle: '),
   uncle(Uncle,Z), write(Uncle), tab(5),fail.
findUncle.

findAunt:-
   write(' Niece/Nephew: '), read(Z), write('Aunt: '),
   aunt(Aunt,Z), write(Aunt), tab(5),fail.
findAunt.