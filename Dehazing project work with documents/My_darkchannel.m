function [output] = My_darkchannel(I,window_size)

    
    [height,width,~] = size(I);
   
    dark_channel = ones(height,width);
    
 
    for i = 1:height
        for j = 1:width
         
            dark_channel(i,j) = min( I(i,j,:) );
 
        end
    end 
    
    min_dark_channel = My_minfilter(dark_channel,window_size);
    

    output = min_dark_channel;
    
end