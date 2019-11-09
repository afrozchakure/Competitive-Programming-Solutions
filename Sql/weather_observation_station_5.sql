-- Query the two cities in STATION with the shortest and longest CITY names, 
-- as well as their respective lengths (i.e.: number of characters in the name). 
-- If there is more than one smallest or largest city, 
-- choose the one that comes first when ordered alphabetically.

SELECT CITY, CHAR_LENGTH(CITY) 
    FROM STATION 
        WHERE LENGTH(CITY) = 
        (SELECT MIN(CHAR_LENGTH(CITY)) FROM STATION)
        ORDER BY CITY LIMIT 1;
SELECT CITY, CHAR_LENGTH(CITY) 
    FROM STATION 
        WHERE LENGTH(CITY) = 
        (SELECT MAX(CHAR_LENGTH(CITY)) FROM STATION)
        ORDER BY CITY LIMIT 1

-- Sample Input

-- Let's say that CITY only has four entries: DEF, ABC, PQRS and WXY

-- Sample Output

-- ABC 3
-- PQRS 4
