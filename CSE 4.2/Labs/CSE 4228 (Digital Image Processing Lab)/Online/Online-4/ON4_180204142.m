
I = [ 0 0 0 0 0 0 0;
    0 0 0 0 0 0 0;
    0 0 1 0 1 0 0;
    0 0 1 0 1 0 0;
    0 0 1 1 1 0 0;
    0 0 0 0 0 0 0;
    0 0 0 0 0 0 0;
    ];
figure;
subplot(1,2,1);
imshow(I);

nhood = [0 1 0; 1 1 1; 0 1 0 ];
SE = strel(nhood);
I2 = imdilate(I, SE);
I2 = I2-I;

subplot(1,2,2);
imshow(I2);