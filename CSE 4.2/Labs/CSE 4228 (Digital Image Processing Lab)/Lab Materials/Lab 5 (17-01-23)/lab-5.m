S=rgb2gray(imread('E:\AUST CSE\4.2 (Origin-42)\CSE 4228 (DIP Lab)\Lab 5 (17-01-23)\Images\input.jpg'));
T=rgb2gray(imread('E:\AUST CSE\4.2 (Origin-42)\CSE 4228 (DIP Lab)\Lab 5 (17-01-23)\Images\template_whole\chartemp1.jpg'));
%% converting to [0,1]
S = im2double(S);
T = im2double(T);
%% taking dimentions
[sRow, sCol] = size(S);
[tRow, tCol] = size(T);
%% R is the output image matching
R = S;
%% x and y will hold the coordinate where matching found
x = 0;
y = 0;
%% flag will be 1 whenever matching
flag = 0;

meanT = mean(T(:));
meanS = mean(S(:));

for i = 1:sRow - tRow
    for j = 1:sCol - tCol
        a = S(i : i+tRow-1, j : j+tCol-1);
       
        meanA = mean(a(:));
        r1 = a - meanA;
        r2 = T - meanT;
        c1 = r1.^2;
        c2 = r2.^2;
        c = (sum(c1(:))*sum(c2(:)))^0.5;
        t = sum(sum(r1.*r2))/c;
       
        if t > 0.97
            disp(strcat('correlation result:', num2str(t)));
           
           
            x = i;
            y = j;
           
            flag = 1;
           
            break;
        end
    end
   
    if flag == 1
        break;
    end
end

R(x:x+tRow-1, y:y+tCol-1) = 0;

figure;
subplot(3,1,1);
imshow(S, [0,1]);
title('Input image');
subplot(3,1,2);
imshow(T, [0,1]);
title('Template image');
subplot(3,1,3);
imshow(R, [0,1]);
title('Template matching result');