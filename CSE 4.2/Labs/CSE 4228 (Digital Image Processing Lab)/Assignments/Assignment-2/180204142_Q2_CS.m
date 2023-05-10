% ------- a -------
I = imread('img_2.jpg');
I = rgb2gray(I);

mx = max(I(:));
L = 2^(floor(log2(double(mx)))+1);
figure();
subplot(2,2,1);
imshow(I);
title('Input Image');

[row,col] = size(I);
histogram_in = zeros(1,L);
for i = 1:row
    for j = 1:col
        histogram_in(I(i,j)) = histogram_in(I(i,j))+1;
    end
end
subplot(2,2,3);
bar(histogram_in);
title('Histogram of I');

I = im2double(I);
% ------- b -------
A = min(I(:));
% ------- c -------
B = max(I(:));

% ------- d -------
D = B-A;
M = L-1;

% ------- e -------
R = I-A;
R = R./D;
R = R.*M;
R = R+A;
R = uint8(R);

% ------- f -------
subplot(2,2,2);
imshow(R);
title('Output image R');

% ------- g -------
[row1,col1] = size(R);
histogram_out = zeros(1,L);
for i = 1:row1
    for j = 1:col1
        histogram_out(R(i,j)+1) = histogram_out(R(i,j)+1)+1;
    end
end
subplot(2,2,4);
bar(histogram_out);
title('Histogram of R');
imwrite(R, 'Output_CS.jpg');