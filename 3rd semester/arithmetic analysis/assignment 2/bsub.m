
function [matrix, b] = bsub (matrix, b)

  [rows, cols] = size(matrix);
  [bRows, bCols] = size(b);

  if (rows != cols)
    error("Ο πίνακας που δόθηκε δεν είναι τετραγωνικός!")
  endif

  if (bRows != cols || bCols != 1)
    error("Το διάνυσμα b έχει λανθασμένες διαστάσεις!")
  endif

  for i = 1:rows-1
    for m = i+1:rows
      L(m, i) = matrix(m, i)/matrix(i, i);

      for n = i:rows
        matrix(m, n) = matrix(m, n) - L(m, i)*matrix(i, n);
      endfor

      b(m) = b(m) - L(m, i)*b(i);

    endfor
  endfor

endfunction
