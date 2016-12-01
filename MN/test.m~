function [x] = test(path,count_bins)
im=double(imread(path));
[m n]=size(im);
H=zeros(1,count_bins);
S=zeros(1,count_bins);
V=zeros(1,count_bins);
x=zeros(1,3*count_bins);
for i=1:m
  for j=1:n/3
    R1=im(i,j,1)/255;
    G1=im(i,j,2)/255;
    B1=im(i,j,3)/255;
    Cmax=max([R1,G1,B1]);
    Cmin=min([R1,G1,B1]);
    delta=Cmax-Cmin;
    if delta == 0
      H=0;
    else
      if Cmax == R1
        H=60*(mod((G1-B1)/delta,6));
      endif
      if Cmax == G1
        H=60*((B1-R1)/delta+2);
      endif
      if Cmax == B1
        H=60*((R1-G1)/delta+4);
      endif
    endif
    H=H/360;
	R(i,j)=H;
    if Cmax == 0
      S=0;
    else
      S=delta/Cmax;
    endif
	G(i,j)=S;
    V=Cmax;
	B(i,j)=V;
    H=1+floor(100*H*count_bins/101);
    S=1+floor(100*S*count_bins/101);
    V=1+floor(100*V*count_bins/101);
    %x(1,H)=x(1,H)+1;
    %x(1,S+count_bins)=x(1,S+count_bins)+1;
    %x(1,V+2*count_bins)=x(1,V+2*count_bins)+1;
    endfor
endfor
x=R;
endfunction

