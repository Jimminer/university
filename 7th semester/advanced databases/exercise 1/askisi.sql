CREATE TABLE Movie (
    mID INT PRIMARY KEY,
    title TEXT,
    year INT,
    director TEXT
);

CREATE TABLE Reviewer (
    rID INT PRIMARY KEY,
    name TEXT
);

CREATE TABLE Rating (
    rID INT,
    mID INT,
    stars INT,
    ratingDate DATE
);

-- 1. Δημιουργείστε κατάλληλο ερώτημα SQL που να εντοπίζει τους τίτλους των ταινιών με σκηνοθέτη τον Steven Spielberg.
SELECT Movie.title FROM Movie
WHERE Movie.director = "Steven Spielberg";

-- 2. Δημιουργείστε κατάλληλο ερώτημα SQL που να εντοπίζει και να εμφανίζει με αύξουσα ταξινόμηση, όλα τα έτη κατά τα οποία κάποια ταινία έλαβε 4 ή 5 αστέρια.
SELECT DISTINCT YEAR(Rating.ratingDate) AS year
FROM Movie, Rating
WHERE Movie.mID = Rating.mID AND Rating.stars >= 4 AND YEAR(Rating.ratingDate) IS NOT 
ORDER BY Movie.year;

-- 3. Δημιουργείστε κατάλληλο ερώτημα SQL που να εντοπίζει τους τίτλους των ταινιών που δεν έχουν αξιολογηθεί.
SELECT Movie.title
FROM Movie
WHERE Movie.mID NOT IN (
    SELECT mID
    FROM Rating
);

-- 4. Δημιουργείστε κατάλληλο ερώτημα SQL που να εντοπίζει τα ονόματα των κριτικών που δεν καταχώρησαν ημερομηνία αξιολόγησης.
SELECT Reviewer.name
FROM Reviewer
WHERE Reviewer.rID IN (
    SELECT rID
    FROM Rating
    WHERE ratingDate IS NULL
);

-- 5. Δημιουργείστε κατάλληλο ερώτημα SQL που να επιστρέφει τις αξιολογήσεις σε πιο ευανάγνωστη μορφή. Δηλαδή να εμφανίζονται τα ονόματα των κριτικών, ο τίτλος της ταινίας, τα αστέρια της, και η ημερομηνία αξιολόγησης. Τα αποτελέσματα να εμφανίζονται ταξινομημένα με πρώτο κριτήριο τον κριτικό μετά τον τίτλο της ταινίας και τελευταίο τον αριθμό αστεριών που έλαβε.
SELECT Reviewer.name, Movie.title, Rating.stars, Rating.ratingDate
FROM Reviewer, Movie, Rating
WHERE Rating.rID = Reviewer.rID AND Rating.mID = Movie.mID
ORDER BY Reviewer.name, Movie.title, Rating.stars

-- 6. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει όλες τις περιπτώσεις κατά τις οποίες ο ίδιος κριτικός αξιολόγησε για δεύτερη φορά την ίδια ταινία και τη δεύτερη φορά έδωσε περισσότερα αστέρια. Το ερώτημα να εμφανίζει τον κριτικό και τον τίτλο της ταινίας.
SELECT Reviewer.name, Movie.title
FROM Reviewer, Movie, Rating
WHERE Rating.rID = Reviewer.rID AND Rating.mID = Movie.mID AND Rating.stars > (
    SELECT stars
    FROM Rating
    WHERE rID = Reviewer.rID AND mID = Movie.mID
    ORDER BY ratingDate DESC
    LIMIT 1, 1
);

-- 7. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει ταξινομημένα με το όνομα της ταινίας, τις ταινίες που έχουν αξιολογηθεί τουλάχιστον μια φορά, βρίσκοντας την υψηλότερη αξιολόγησή της.
SELECT Movie.title, MAX(Rating.stars)
FROM Movie, Rating
WHERE Movie.mID = Rating.mID
GROUP BY Movie.title
HAVING COUNT(Rating.stars) > 1
ORDER BY Movie.title;

-- 8. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τον τίτλο της ταινίας και το εύρος αξιολόγησής της, που είναι η διαφορά της χαμηλότερης από την υψηλότερη βαθμολόγησή της. Τα αποτελέσματα να είναι ταξινομημένα, με φθίνουσα σειρά, του εύρους και στη συνέχεια με τον τίτλο της ταινίας.
SELECT Movie.title, MAX(Rating.stars) - MIN(Rating.stars) AS range
FROM Movie, Rating
WHERE Movie.mID = Rating.mID
GROUP BY Movie.title
ORDER BY range DESC, Movie.title;

-- 9. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τη διαφορά στις μέσες τιμές αξιολόγησης των ταινιών πριν το 1980 από τις ταινίες που είναι μετά το 1980. Για τον υπολογισμό των μέσω όρων πρέπει να υπολογίζεται πρώτα η μέση αξιολόγηση στις ταινίες που έχουν αξιολογηθεί περισσότερες από μία φορές και στη συνέχεια ο μέσος όρος των ταινιών κάθε εποχής. Μην υπολογίζετε απλά τον μέσο όρο όλων των αξιολογήσεων των ταινιών της εποχής.
SELECT AVG(rating) AS avg_rating, CASE WHEN year < 1980 THEN 'before 1980' ELSE 'after 1980' END AS year_range
FROM (
    SELECT mID, AVG(stars) AS rating
    FROM Rating
    GROUP BY mID
    HAVING COUNT(stars) > 1
) AS avg_rating_table, Movie
WHERE avg_rating_table.mID = Movie.mID
GROUP BY year_range;

-- 10. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τα ονόματα των κριτών που έχουν αξιολογήσει το Gone with the Wind.
SELECT Reviewer.name
FROM Reviewer, Movie, Rating
WHERE Reviewer.rID = Rating.rID AND Movie.mID = Rating.mID AND Movie.title = 'Gone with the Wind';

-- 11. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τον κριτή, τον τίτλο της ταινίας καθώς και τα αστέρια της ταινίας για τις αξιολογήσεις στις οποίες ο κριτής ταυτίζεται με τον σκηνοθέτη της ταινίας.
SELECT Reviewer.name, Movie.title, Rating.stars
FROM Reviewer, Movie, Rating
WHERE Reviewer.rID = Rating.rID AND Movie.mID = Rating.mID AND Movie.director = Reviewer.name;

-- 12. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τα ονόματα των κριτικών με τα ονόματα των ταινιών που έχουν αξιολογήσει ταξινομημένα αλφαβητικά με βάση το όνομα του κριτικού και στη συνέχεια τον τίτλο της ταινίας.
SELECT Reviewer.name, Movie.title
FROM Reviewer, Movie, Rating
WHERE Reviewer.rID = Rating.rID AND Movie.mID = Rating.mID
ORDER BY Reviewer.name, Movie.title;

-- 13. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τους τίτλους όλων των ταινιών που δεν αξιολογήθηκαν από τον Chris Jackson.
SELECT Movie.title
FROM Movie
WHERE Movie.mID NOT IN (
    SELECT mID
    FROM Rating
    WHERE rID = (
        SELECT rID
        FROM Reviewer
        WHERE name = 'Chris Jackson'
    )
);

-- 14. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τα ονόματα των κριτικών που αξιολόγησαν την ίδια ταινία. Να μην εμφανίζονται οι περιπτώσεις που ο ίδιος κριτής αξιολόγησε δεύτερη φορά την ίδια ταινία, και να εμφανίζεται κάθε ζευγάρι κριτικών μια και μόνο φορά. Για κάθε δε ομάδα κριτικών τα ονόματά τους να εμφανίζονται ταξινομημένα με αλφαβητική σειρά.
SELECT DISTINCT R1.name, R2.name
FROM Reviewer R1, Reviewer R2, Rating R1R, Rating R2R
WHERE R1R.rID = R1.rID AND R2R.rID = R2.rID AND R1R.mID = R2R.mID AND R1R.rID < R2R.rID
ORDER BY R1.name, R2.name;

-- 15. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τον κριτικό, τον τίτλο της ταινίας και τα αστέρια της για τις ταινίες με πολλαπλές κριτικές στις χειρότερες περιπτώσεις της βάσης δεδομένων.
SELECT Reviewer.name, Movie.title, Rating.stars
FROM Reviewer, Movie, Rating
WHERE Reviewer.rID = Rating.rID AND Movie.mID = Rating.mID AND Rating.stars = (
    SELECT MIN(stars)
    FROM Rating
    WHERE mID = Movie.mID
    GROUP BY mID
    HAVING COUNT(stars) > 1
);

-- 16. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τους τίτλους των ταινιών και τη μέση κριτική τους. Τα αποτελέσματα να είναι ταξινομημένα από την υψηλότερη προς τη χαμηλότερη αξιολόγηση και σε περίπτωση που δύο ή περισσότερες ταινίες έχουν την ίδια μέση αξιολόγηση τότε η κατάταξή τους σε αυτές να γίνεται με βάση την αλφαβητική τους σειρά.
SELECT Movie.title, AVG(Rating.stars) AS avg_rating
FROM Movie, Rating
WHERE Movie.mID = Rating.mID
GROUP BY Movie.title
ORDER BY avg_rating DESC, Movie.title;

-- 17. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τα ονόματα των κριτών που έχουν τουλάχιστον τρεις κριτικές. (Προσπαθήστε, αν μπορείτε, να συντάξετε το ερώτημα χωρίς τη χρήση των HAVING ή του COUNT.)
SELECT Reviewer.name
FROM Reviewer, Rating
WHERE Reviewer.rID = Rating.rID
GROUP BY Reviewer.rID
HAVING COUNT(Rating.stars) >= 3;

-- 18. Ορισμένοι σκηνοθέτες δεν έχουν μία μόνο ταινία, για τους σκηνοθέτες αυτούς δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τους τίτλους των ταινιών τους και τα ονόματά τους. Να ταξινομηθούν τα αποτελέσματα με βάση τους σκηνοθέτες και ύστερα με τον τίτλο των ταινιών τους. (Προσπαθήστε, αν μπορείτε, να συντάξετε το ερώτημα με την χρήση του COUNT, αλλά και χωρίς αυτό.)
SELECT Movie.title, Movie.director
FROM Movie
WHERE Movie.director IN (
    SELECT Movie.director
    FROM Movie
    GROUP BY Movie.director
    HAVING COUNT(Movie.mID) > 1
)
ORDER BY Movie.director, Movie.title;

-- 19. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τους τίτλους των ταινιών και τη μέση αξιολόγησή τους για τις ταινίες με την καλύτερη κριτική. (Υπόδειξη: βρείτε πρώτα την ταινία με την υψηλότερη μέση αξιολόγηση και στη συνέχεια εντοπίστε τις ταινίες με την αξιολόγηση αυτή.)
SELECT Movie.title, AVG(Rating.stars) AS avg_rating
FROM Movie, Rating
WHERE Movie.mID = Rating.mID
GROUP BY Movie.mID
HAVING AVG(Rating.stars) = (
    SELECT MAX(avg_rating)
    FROM (
        SELECT AVG(Rating.stars) AS avg_rating
        FROM Movie, Rating
        WHERE Movie.mID = Rating.mID
        GROUP BY Movie.mID
    )
);

-- 20. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει τον τίτλο της ταινίας και το μέσο όρο αξιολόγησής της με την χειρότερη κριτική.(Υπόδειξη προσδιορίστε πρώτα την ελάχιστη μέση αξιολόγηση και στη συνέχεια εντοπίστε την ταινία με αυτή τη μέση αξιολόγηση.)
SELECT Movie.title, AVG(Rating.stars) AS avg_rating
FROM Movie, Rating
WHERE Movie.mID = Rating.mID
GROUP BY Movie.mID
HAVING AVG(Rating.stars) = (
    SELECT MIN(avg_rating)
    FROM (
        SELECT AVG(Rating.stars) AS avg_rating
        FROM Movie, Rating
        WHERE Movie.mID = Rating.mID
        GROUP BY Movie.mID
    )
);

-- 21. Δημιουργείστε κατάλληλο ερώτημα SQL που να εμφανίζει το όνομα του σκηνοθέτη , τον τίτλο της ταινίας του που έχει επιτύχει με την καλύτερη κριτική μαζί με τα αστέρια της. Να αγνοηθούν οι ταινίες των οποίων δεν έχει καταχωρηθεί σκηνοθέτης.
SELECT Movie.director, Movie.title, AVG(Rating.stars) AS avg_rating
FROM Movie, Rating
WHERE Movie.mID = Rating.mID
GROUP BY Movie.mID
HAVING AVG(Rating.stars) = (
    SELECT MAX(avg_rating)
    FROM (
        SELECT AVG(Rating.stars) AS avg_rating
        FROM Movie, Rating
        WHERE Movie.mID = Rating.mID
        GROUP BY Movie.mID
    )
) AND Movie.director IS NOT NULL;

-- 22. Προσθέστε τον κριτικό Roger Ebert to στην βάση δεδομένων, με rID 209.
INSERT INTO Reviewer (rID, name)
VALUES (209, 'Roger Ebert');

-- 23. Να καταχωρήσετε σε όλες τις ταινίες της βάσης δεδομένων αξιολόγηση 5 αστέρων, από τον James Cameron. Η ημερομηνία αξιολόγησης να είναι NULL.
INSERT INTO Rating (rID, mID, stars, ratingDate)
SELECT 209, mID, 5, NULL
FROM Movie;

-- 24. Για όλες τις ταινίες που έχουν μέσο όρο αξιολόγησης ίσο ή υψηλότερο των 4 αστεριών προσθέστε το 25 στο έτος δημιουργίας τους. Προσοχή πρέπει να ενημερωθούν οι πλειάδες του πίνακα όχι να δημιουργηθούν νέες πλειάδες.
UPDATE Movie
SET year = year + 25
WHERE mID IN (
    SELECT mID
    FROM Rating
    GROUP BY mID
    HAVING AVG(stars) >= 4
);

-- 25. Να διαγραφούν όλες οι αξιολογήσεις των ταινιών που είναι παλαιότερες του 1970 και νεότερες του 2000 και η αξιολόγησή τους είναι χαμηλότερη των 4 αστέρων.
DELETE FROM Rating
WHERE mID IN (
    SELECT mID
    FROM Movie
    WHERE year < 1970 OR year > 2000
) AND stars < 4;