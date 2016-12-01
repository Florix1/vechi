function [X,t] = preprocess(cale,cum,nr)


%concatenarea cailor catre fisiere (USO style)
cale1 = strcat(cale,"cats/*.jpg");
cale2 = strcat(cale,"not_cats/*.jpg"); 
pisi = dir(cale1);
nope = dir(cale2);
l = length(pisi);
cale1 = strcat(cale,"cats/");
cale2 = strcat(cale,"not_cats/"); 
X=zeros(l+length(nope),3*nr);
t=zeros(l+length(nope),1);

%concatenare vectorilor obtinuti din prelucrarea imaginilor
for i=1:l
	t(i)=1;
	if (cum == "RGB")
		X(i,:)=rgbHistogram(strcat(cale1,pisi(i).name),nr);
	endif
	if ( cum == "HSV")
		X(i,:)=hsvHistogram(strcat(cale1,pisi(i).name),nr);
	endif
endfor

for j=1:length(nope)
	t(j+l)=-1;
	if (cum == "RGB")
		X(j+l,:)=rgbHistogram(strcat(cale2,nope(j).name),nr);
	endif
	if (cum == "HSV")
		X(j+l,:)=hsvHistogram(strcat(cale2,nope(j).name),nr);
	endif
endfor



















