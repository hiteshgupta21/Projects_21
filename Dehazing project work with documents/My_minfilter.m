
function [output] = My_minfilter(I,window_size)

    I_new = I;
    [height,width] = size(I);
    
    for i = 1:height
        for j = 1:width
  
            i_down = i-window_size;
            i_up = i+window_size;
            j_down = j-window_size;
            j_up = j+window_size;
            if(i_down<=0)
                i_down = 1;
            end
            if(j_down<=0)
                j_down = 1;
            end
            if(i_up>height)
                i_up = height;
            end
            if(j_up>width)
                j_up = width;
            end
           
            I_new(i,j) =  min (min(I(i_down:i_up,j_down:j_up)) );
        end
    end

    output = I_new;
end