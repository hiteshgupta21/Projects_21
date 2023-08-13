clc
close all;
clear
cd IMAGES
[K,P]=uigetfile('*.*','select the Hazed Image');
I=imread(strcat(P,K));
cd ..
I=imresize(I,[512,512]);
I = double(I)./255;
figure,imshow(I,[]);title('Haze Image');
window_size=7;
dc=My_darkchannel(I,window_size);
figure,imshow(dc,[]);title('Dark channel Image');
tr=wlsFilter(dc);
figure,imshow(tr,[]);title('Transfer function of filter');
p=I;
q2 = zeros(size(I));
q2 = gguidedfilter(dc(:, :, 1), tr(:, :, 1),16, 1e-3);
figure,imshow(q2,[]);title('proposed GGIF');