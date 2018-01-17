clear all
clc

%%

I1 = imread('startIII.ppm');
I2 = imread('goalIII.ppm');

I1 = imrotate(I1, 180);
I2 = imrotate(I2, 180);
I1 = flipdim(I1, 2);
I2 = flipdim(I2, 2);

% % Environment III
I1 = imcrop(I1, [1 70 992-1 800-70]);
I2 = imcrop(I2, [1 70 992-1 800-70]);

I1 = imresize(I1, [380 610]);
I2 = imresize(I2, [380 610]);

imshow(I1)
%%

for j = 0:3
    for i = 1:size(I1,2)
        I1(1+j,i,:) = [0 0 0];
        I1(end-j,i,:) = [0 0 0];
        I2(1+j,i,:) = [0 0 0];
        I2(end-j,i,:) = [0 0 0];
    end
    
    for i = 1:size(I1,1)
        I1(i,1+j,:) = [0 0 0];
        I1(i,end-j,:) = [0 0 0];
        I2(i,1+j,:) = [0 0 0];
        I2(i,end-j,:) = [0 0 0];
    end
end

I = [I1 I2];

I = insertText(I,[0 -10],'(e)','FontSize',60,'BoxColor',...
    'w','BoxOpacity',0,'TextColor','black');

imshow(I);

imwrite(I, 'envV.png');

