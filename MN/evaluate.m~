function [r] = evaluate(cale,w,cum,nr)

corect=0;
cale1 = strcat(cale,"cats/*.jpg");
cale2 = strcat(cale,"not_cats/*.jpg"); 
pisi = dir(cale1);
nope = dir(cale2);
cale1 = strcat(cale,"cats/");
cale2 = strcat(cale,"not_cats/"); 
for i=1:length(pisi)
		if (cum == "RGB")
		x=rgbHistogram(strcat(cale1,pisi(i).name),nr);
		endif
		if (cum == "HSV")
		x=hsvHistogram(strcat(cale1,pisi(i).name),nr);
		endif
		x=[x ones(1,1)];
		if (dot(w',x) > 0)
			corect++;
			endif	
endfor
%similar cu preprocess dar stabileste accuratetea
for j=1:length(nope)
		if ( cum == "RGB" )
		x=rgbHistogram(strcat(cale2,nope(j).name),nr);
		endif
		if ( cum == "HSV" )
		x=hsvHistogram(strcat(cale2,nope(j).name),nr);
		endif
		x=[x ones(1,1)];
		if (dot(w',x) < 0)
			corect++;
			endif
endfor

r=corect*100/(length(nope)+length(pisi));















