
mother(marge, bart).
mother(marge, lisa).
mother(marge, maggie).

mother(maude, rod).
mother(maude, todd).

mother(luann, milhouse).

father(homer, bart).
father(homer, lisa).
father(homer, maggie).

father(nad, rod).
father(nad, todd).

father(kirk, milhouse).













sibling(X, Y) :- mother(Z, X), mother(Z, Y), X \== Y.
sibling(X, Y) :- father(Z, X), father(Z, Y), X \== Y.


