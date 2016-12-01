function R = Algebraic(nume ,d)
[a] = textread(nume, "%f");
N = a(1,1);
A = zeros(N);
z = 3;
one = ones(N,1);
K = zeros(N);
for i = 1 : N
	for j = 1 : k
	A(i ,a(z+1, 1) )++;
	z++;
	endfor
z += 2 ;
A(i,i) = 0;
endfor
for i = 1 : N
	K(i,i) = 1 / sum(A(i,:));
	endfor
M = (K * A)';
X = eye(N) - d*M;
Y = GramSchmidt(X);
R = Y*(1-d) /N *ones(N,1);
