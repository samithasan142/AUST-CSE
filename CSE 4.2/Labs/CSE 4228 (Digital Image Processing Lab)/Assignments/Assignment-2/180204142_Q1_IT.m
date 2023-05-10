% ------- 1 -------
R= imread('img_2.jpg');

% ------- 2 -------
I= rgb2gray(R);
T1=I;
T2=I;
T3=I;
T4=I;

figure;
imshow(I);

% ------- 3 -------
[row,col] = size(I);
X = zeros(1,256);

for i = 1:row
     for j = 1:col
         temp = I(i,j)+1;
         X(temp) = X(temp)+1;
     end
end
figure;
bar(X);

% ------- 4 -------
T1= im2double(T1);
Y = 2.5;
% ------- 5 -------
c = 1.5;

for i= 1:row
     for j= 1:col
         T1(i,j)= c*(T1(i,j).^Y);
     end
end

% ------- 6 -------
X= zeros(1,256);
for i= 1:row
     for j= 1:col
         temp= round(255*(T1(i,j)))+1;
         if(temp>255)
             temp = 255;
         end
         X(temp)= X(temp)+1;
     end
end
figure;
bar(X);

% ------- 7 -------
sum3 = 0;
A=200;
% ------- 8 -------
for i= 1:row
     for j= 1:col
         if T2(i,j) <= A
            T2(i,j) = (0.5* T2(i,j)) + T2(i,j);
         else
             T2(i,j) = T2(i,j) - (0.25* T2(i,j));
        end
     end
end

% ------- 9 -------
X= zeros(1,256);
for i= 1:row
     for j= 1:col
         temp= T2(i,j)+1;
         X(temp)= X(temp)+1;
     end
end
figure;
bar(X);

% ------- 10 -------
T3 = im2double(T3);
[row,col] = size(T3);
B = zeros(row,col);
c = 1.9;

for i = 1:row
     for j = 1:col
         B(i,j) = c*log(1+T3(i,j));
     end
end

% ------- 11 -------
X = zeros(1,256);
for i = 1:row
     for j = 1:col
         temp = round(255*(B(i,j)))+1;
         if(temp>255)
             temp = 255;
         end
         X(temp) = X(temp)+1;
     end
end
figure;
bar(X);

% ------- 12 -------
[row,col]= size(T4);
T41= uint8(zeros(row,col));

for i= 1:row
    for j= 1:col
        T41(i,j)= 255- T4(i,j);
    end
end

% ------- 13 -------
for i= 1:row
     for j= 1:col
         temp= 255 - I(i,j) + 1;
         X(temp)= X(temp)+1;
     end
end
figure;
bar(X);