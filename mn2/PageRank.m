function [R1 R2 R3] = PageRank(nume, d, eps)

R1 = Iterative(nume,d,eps);

R2 = Algebraic(nume,d);

R3 = Power(nume, d, eps);

out = strcat(nume,".out");
N = length(R1);
f = fopen(out,'w');
fprintf(f,"%d\n\n",N);
R = R1;
for i = 1 : 3
	for j = 1 : N
	fprintf(f,"%f\n",R(j,1));
	endfor
	fprintf(f,"\n");
	if ( i == 3)
		R = R3;
	endif
	if ( i == 2)
		R = R2;
	endif
end

z = textread(nume);
val1 = z(length(z)-1,1);
val2 = z(length(z),1);
nr = [ 1 : N]';
PR = zeros(N,1);
R = R2;
for i = 1 : N-1
	for j = 1+i : N
		if ( R(i,1) < R(j,1) )
		aux = R(i,1);
		R(i,1) = R(j,1);
		R(j,1) = aux;
		aux = nr(i,1);
		nr(i,1) = nr(j,1);
		nr(j,1) = aux;
		endif
	endfor
endfor

for i = 1 : N
	PR(i,1) = Apartenenta(R(i,1),val1,val2);
	endfor
for i = 1 : N-1
	for j = i+1 : N
		if ( PR(i,1) < PR(j,1) )
		aux = PR(i,1);
		PR(i,1) = PR(j,1);
		PR(j,1) = aux;
		aux = nr(i,1);
		nr(i,1) = nr(j,1);
		nr(j,1) = aux;
		endif
	endfor
endfor
for i = 1 : N
	fprintf(f,"%d %d %f\n",i,nr(i,1),PR(i,1));
	endfor
fclose(f);
end


