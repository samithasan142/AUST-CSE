I = imread('C:\Users\User\Desktop\New folder\Input.jpg');
I = rgb2gray(I);

T3=I;

figure;
imshow(I);
imwrite(I, 'C:\Users\User\Desktop\New folder\Output_1.jpg');

% log transformation
T3 = im2double(T3);
[row,col] = size(T3);
B = zeros(row,col);
c = 1.9;

for i = 1:(2*row/3)
     for j = 1:col/2
         B(i,j) = c*log(1+T3(i,j));
     end
end

for i = 2row/3: row
     for j = 1:col
         B(i,j) = I(i,j);
     end
end

figure;
imshow(B);
