function y = Apartenenta(x, val1, val2)
	if  (x < val1)
		y=0;
		
	 else if  (x > val2)
		y=1;
	else 	
		y=x/(val2-val1)-val1/(val2-val1);
	endif 
	endif
end
