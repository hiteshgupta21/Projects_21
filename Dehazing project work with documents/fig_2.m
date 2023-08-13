% this is the code for figu 1
clc
close all;
clear
cd IMAGES
[K,P]=uigetfile('*.*','select the Hazed Image');
I=imread(strcat(P,K));
cd ..
I=imresize(I,[512,512]);
I = double(I)./255;
figure,imshow(I,[]);title('original Image');

p = I;
r = [7 15 30 60]; %change values
eps = 0.1^2;
figure,
for ii=1:length(r)
wg=zeros(size(I));
wg(:,:,1)=gguidedfilter(I(:,:,1),p(:,:,1),r(ii),eps);
wg(:,:,2)=gguidedfilter(I(:,:,2),p(:,:,2),r(ii),eps);
wg(:,:,3)=gguidedfilter(I(:,:,3),p(:,:,3),r(ii),eps);
I_enhanced_w = (I - wg) * 5 + wg; 
subplot(1,4,ii),imshow(I_enhanced_w);title(['With sigma =',num2str(r(ii))]);
end


