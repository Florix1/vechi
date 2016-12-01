function value = lerp(v, x)
    % Interpolare liniara unidimensionala
    %
    % Inputs
    % ------
    % v: un vector cu valorile functie
    % x: o noua pozitie in care sa se calculeze valoarea functiei

	[m n] = size(v);
	if     ( n < x )  ||  ( x < 1 )   
		value = 0;
	else
		if (x == n)
			value = v(n);
		else
			xmin = floor(x);
			xmax = xmin + 1;
			value = v(xmin) + (x - xmin)*( v(xmax) - v(xmin) );
		endif
	endif
		
		
end
