function value = bilerp(img, row, col)
    % Folositi interpolare biliniara pentru a estima intensitatea imaginii
    % in pozitia row, col

    [m n] = size(img);
    x = lerp( img(1,:), row )
    	if ( x == 0 )
    	value = 0;
    	else
    		y = lerp( (:,x), col );
    		if ( y == 0 )
    			value = 0;
    		else
    			value = img(x,y);
    		endif
    	endif
end
