image = imread('Input_3.jpeg');
figure;
imshow(image);

flipped =image(:, end : -1 : 1, :);
figure;
imshow(flipped);
 
mergedImage = [image flipped];
figure;
imshow(mergedImage);

imwrite(mergedImage, 'Output_Q1.jpg');