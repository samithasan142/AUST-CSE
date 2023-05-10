I = imread('C:\Users\User\Downloads\Lab2\Images\p1.jpg');
J = imread('C:\Users\User\Downloads\Lab2\Images\p2.jpg');
I = imresize(I, [512, 512]);
J = imresize(J, [512, 512]);
figure;
imshow(I);
figure;
imshow(J);

[row, col, cha] = size(I);
x = row/2
y = col/2
K=I;

for i=x: row
    for j=1: y
        for k=1: cha
            
            K(i,j,k)=J(i,j,k);
           
        end
    end
    y=y-1
end
figure;
imshow(K);