function B = GramSchmidt(A)
	[m n] = size(A);
	Q = zeros(m,n);
	R = zeros(n);
	
	for j = 1 : n
		for i = 1 : j-1
			R(i,j) = Q(:,i)' * A(:,j);
		endfor
		
		
	  	s = Q(:, 1:j-1) * R(1:j-1, j);
		
		aux = A(:,j) - s;		
		
		R(j,j) = norm(aux,2);
		Q(:,j) = aux/R(j,j);
	endfor
B=zeros(n);
Q=Q';
for j = 1 : n
	B(n,j) = Q(n,j) / R(n,n);
	for i = n-1 : - 1 : 1
		 B(i,j) = ( Q(i,j)-R(i,i+1 : n)* B(i+1 : n,j) ) / R(i,i);
		 endfor
	endfor
end

	
