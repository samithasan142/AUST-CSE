img1 = imread('Input_1.jpeg');
img2 = imread('Input_2.jpeg');

a = 6;
b = 100;
imgsize = a*b;

img1 = imresize(img1, [imgsize imgsize]);
img2 = imresize(img2, [imgsize imgsize]);

img1 = rgb2gray(img1);
img2 = rgb2gray(img2);

figure;
imshow(img1);
figure;
imshow(img2);

outputimg = uint8(ones(imgsize,imgsize));
for i = 2 : 2 : a
    outputimg(:, b * (i - 2) + 1 : b * (i-1), :) = img1(:, b * (i - 2) + 1 : b * (i - 1), :);
    outputimg(:, b * (i - 1) + 1 : b * i, :) = img2(:, b * (i - 1) + 1 : b * i, :);
end

figure;
imshow(outputimg);

imwrite(outputimg, 'Output_Q2.jpg');