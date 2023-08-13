% this is the code for figure 1
clc
close all;
clear
cd IMAGES
[K,P]=uigetfile('*.*','select the Hazed Image');
I=imread(strcat(P,K));
cd ..
I=imresize(I,[512,512]);
I = double(I)./255;
figure,subplot(151),imshow(I,[]);title('original Image');

p = I;
r = 16;
eps = 0.1^2;


q = zeros(size(I));
q(:, :, 1) = guidedfilter(I(:, :, 1), p(:, :, 1), r, eps);
q(:, :, 2) = guidedfilter(I(:, :, 2), p(:, :, 2), r, eps);
q(:, :, 3) = guidedfilter(I(:, :, 3), p(:, :, 3), r, eps);
I_enhanced = (I - q) * 5 + q;

subplot(152),imshow(q);title('Guided Image');
subplot(153),imshow(I_enhanced);title('Dehaze by GIF');

wg=zeros(size(I));
wg(:,:,1)=weightedguidedfilter(I(:,:,1),p(:,:,1),r,eps);
wg(:,:,2)=weightedguidedfilter(I(:,:,2),p(:,:,2),r,eps);
wg(:,:,3)=weightedguidedfilter(I(:,:,3),p(:,:,3),r,eps);
I_enhanced_w = (I - wg) * 5 + wg; 
subplot(154),imshow(I_enhanced_w);title('Dehaze by WGIF');

q2 = zeros(size(I));
q2(:, :, 1) = gguidedfilter(I(:, :, 1), p(:, :, 1), r, eps);
q3(:,:,1) = wlsFilter(q2(:,:,1),.01);
q2(:, :, 2) = gguidedfilter(I(:, :, 2), p(:, :, 2), r, eps);
q3(:,:,2) = wlsFilter(q2(:,:,2),.01);
q2(:, :, 3) = gguidedfilter(I(:, :, 3), p(:, :, 3), r, eps);
q3(:,:,3) = wlsFilter(q2(:,:,3),.01);
I_enhanced2 = (I - q3) * 5 + q3; 
subplot(155),
imshow(I_enhanced2);title('Dehaze with GGIF');
addpath('support');
[D1,D_map]=FADE_overlapped(uint8(I_enhanced));
[D2,D_map]=FADE_overlapped(uint8(I_enhanced_w));
[D3,D_map]=FADE_overlapped(uint8(I_enhanced2));
