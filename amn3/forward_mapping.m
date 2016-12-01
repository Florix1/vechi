function img_out = forward_mapping(img_in, T)
    % Creati o noua imagine prin aplicarea transformarii T pe imaginea
    % img_in (grayscale image), folosind forward mapping.
    %
    % Inputs
    % ------
    % img_in: imaginea care trebuie sa fie transformata.
    %      T: transformarea care trebuie aplicata asupra imaginii.
    %         matrice de 2x2.
    %
    % Outputs
    % -------
    % img_out: imaginea transformata (grayscale).

    rgb = imread(img_in); 
    G = 0.2989 * rgb(:,:,1) + 0.5870 * rgb(:,:,2) + 0.1140 * rgb(:,:,3)
end
