function in = mat2gray (in, scale)

  if (nargin < 1 || nargin > 2)
    print_usage;
  elseif (! isnumeric (in) && ! islogical (in))
    error ("mat2gray: IN must be a matrix");
  elseif (nargin == 2 && (!isvector (scale) || numel (scale) != 2))
    error ("mat2gray: second argument must be a vector with 2 elements");
  endif

  if (nargin == 1)
    out_min = min (in(:));
    out_max = max (in(:));
  else
    ## see more at the end for the cases where max and min are swapped
    out_min = min (scale (1), scale (2));
    out_max = max (scale (1), scale (2));
  endif

  ## since max() and min() return a value of same class as input,
  ## need to make this values double or the calculations later may fail
  out_min = double (out_min);
  out_max = double (out_max);

  ## if max and min are the same, matlab seems to simple truncate the input
  ## between 0 and 1, and ignores the min/max values set. Don't get the logic
  ## but hey! Matlab compatibility
  if (out_min == out_max)
    in(in>1) = 1;
    in(in<0) = 0;
    return
  endif

  ## we are editing the input matrix rather than creating a new one to save
  ## memory. We need to make sure it's double though
  in = double(in);

  ## it's faster to get the index of values between max and min only once
  ## than to have it calculated on both sides of the assignment later on. We
  ## need to get the index before starting editing
  idx = (in > out_min & in < out_max);

  idx_max = (in >= out_max);
  in(in <= out_min) = 0;
  in(idx_max) = 1;
  in(idx) = (1/(out_max - out_min)) * (double(in(idx)) - out_min);

  ## if the given min and max are in the inverse order...
  if (nargin > 1 && scale(1) > scale (2))
    ## matlab seems to allow setting the min higher than the max but not by
    ## checking which one is actually correct. Seems to just invert it
    in = abs (in - 1);
  endif

endfunction

