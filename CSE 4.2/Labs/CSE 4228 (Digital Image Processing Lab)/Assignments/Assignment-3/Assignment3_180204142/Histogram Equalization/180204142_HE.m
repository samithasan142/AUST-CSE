
%%%%% Part - a  %%%%%

I=imread('cameraman.png');
hist=zeros(1,256);
if size(I,3)>1
    I=rgb2gray(I);
end
[row,col]=size(I);
B=max(max(I));
L = 2 ^ (floor(log2(double(B))) + 1);
disp(L)


%%%%% Part - b  %%%%%

for i=1:row
    for j=1:col
       hist(I(i,j))=hist(I(i,j))+1;     
    end
end    
disp(sum(hist));


%%%%% Part - c  %%%%%

PDF = hist / sum(hist);


%%%%% Part - d  %%%%%

CDF=zeros(1,L);
CDF(1)=PDF(1);
for i=2:L
  CDF(i)=PDF(i)+CDF(i-1);
end


%%%%% Part - e & f  %%%%%

CDF = round(CDF * (L - 1));

% Histogram Plot
newI=I;
for i = 1 : row
    for j = 1 : col
        newI(i, j) = CDF(I(i, j) + 1);
    end
end
hist1 = zeros(1, L);
for i = 1 : row
    for j = 1 : col
        hist1(newI(i, j) + 1) = hist1(newI(i, j) + 1) + 1;
    end
end


%%%%% Part - g  %%%%%

figure
subplot(2, 2, 1);
imshow(I);
title('Original Image');
subplot(2, 2, 2);
imshow(newI);
imwrite(newI, 'Output_HE.jpg');
title('Modified Image');


%%%%% Part - h  %%%%%

subplot(2, 2, 3);
bar(hist);
title('Original Image Histogram');
subplot(2, 2, 4);
bar(hist1);
title('Modified Image Histogram');
