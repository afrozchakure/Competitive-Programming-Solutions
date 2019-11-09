-- Query the list of CITY names from STATION that either do not start with vowels or do not end with vowels. 
-- Your result cannot contain duplicates.

SELECT distinct(CITY) FROM STATION 
WHERE CITY NOT RLIKE '^[AEIOUaeiou].*[AEIOUaeiou]$';