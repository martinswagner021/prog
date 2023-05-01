/* ESTE CODIGO TEM AUTENTICIDADE DO GRUPO FRANK & GIL */

avo(X,Z) :- genitor(X,Y), genitor(Y,Z), homem(X).

madrasta(X,Z) :- casado(X,Y), genitor(Y,Z), not(genitor(X,Z)).
irma(X,Y) :- genitor(Z,X), genitor(Z,Y), mulher(X), not(X=Y).
irmao(X,Y) :- genitor(Z,X),genitor(Z,Y), homem(X), not(X=Y).
tia(X,Y) :- irma(X,Z), genitor(Z,Y), mulher(X).
tio(X,Y) :- irmao(X,Z), genitor(Z,Y), homem(X).
primo(X,Y) :- genitor(Z,Y), (tia(Z,X);tio(Z,X)).
sobrinho(Y,X) :- (irmao(X,Z); irma(X,Z)), genitor(Z,Y).

mulher(ana).
mulher(maria).
mulher(bia).
mulher(marta).
homem(joaquim).
homem(caio).

casado(ana,joaquim).
casado(joaquim,ana).

genitor(joaquim,marta).
genitor(joaquim,maria).
genitor(ana,maria).

genitor(maria, bia).
genitor(marta, caio).
