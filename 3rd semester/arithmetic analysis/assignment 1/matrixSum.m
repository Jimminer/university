## Dimitrios Gkoumas (cs04502)
##
## Χρήση: matrixSum(matrix)
##
## Προσθέτει όλα τα στοιχεία του πίνακα και επιστρέφει το αποτέλεσμα

function elemSum = matrixSum (matrix)

  ## Παίρνουμε τις γραμμές και τις στήλες του πίνακα χρησιμοποιώντας το function
  ## size και τις αποθηκεύουμε στις μεταβλητές rows και cols αντίστοιχα
  [rows, cols] = size(matrix);

  ## Ελέγχουμε εάν ο πίνακας έχει τουλάχιστον μια γραμμή και μια στήλη. Εαν δεν
  ## έχει, επιστρέφουμε σφάλμα
  if (rows <= 0 || cols<= 0)
    error("Ο πίνακας που δόθηκε δεν είναι έγκυρος!")
  endif

  ## Ορίζουμε μεταβλητή στην οποία θα προσθέσουμε ένα-ένα τα στοιχεία και την
  ## οποία στο τέλος θα επιστρέψουμε
  elemSum = 0


  ## Για την πρόσθεση, χρησιμοποιούμε 2 δομές επανάληψης for
  ## Η πρώτη γίνεται από 1 έως τον αριθμό των γραμμών
  ## Και η δεύτερη γίνεται από 1 έως τον αριθμό των στηλών

  ## Έτσι καταφέρνουμε να προσθέσουμε τα στοιχεία στην μεταβλητή "elemSum"
  for i = 1:rows
    for m = 1:cols
      elemSum += matrix(i, m);
    endfor
  endfor

endfunction
