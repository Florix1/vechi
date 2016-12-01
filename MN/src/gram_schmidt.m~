function [Q, R] = Gram_Schmidt(A)
	[m n] = size(A);
	Q = zeros(m,n);
	R = zeros(n);
	
	for j = 1 : n
		for i = 1 : j-1
			R(i,j) = Q(:,i)' * A(:,j);
		endfor
		
		s = zeros(m,1);
		
		s = Q(:, 1:j-1) * R(1:j-1, j);
		
		aux = A(:,j) - s;		
		
		R(j,j) = norm(aux,2);
		Q(:,j) = aux/R(j,j);
	endfor
endfunction
