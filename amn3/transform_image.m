function img_out = transform_image(img_in, k)
    % Scalati imaginea cu un factor k prin aplicarea interpolarii
    % triliniare
    %
    % Inputs
    % ------
    % img_in: imaginea care trebuie transformata.
    %      k: factorul cu care trebuie scalata imaginea.
    %
    % Outputs
    % -------
    % img_out: imaginea transformata 

    I = imread(img_in);
    I = rgb2gray(I);
end
