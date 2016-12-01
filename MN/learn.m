function [w]= learn(X,t)

[m n]=size(X);
y=ones(m,1);
%adaugare coloanei de 1
X=[X y];

Y=X'*X;
%aplicare inversei si a algoritmului din enunt
Z=crout("Y");
w=Z*X'*t;










