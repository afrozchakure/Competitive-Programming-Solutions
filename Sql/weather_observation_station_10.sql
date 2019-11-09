-- Query the list of CITY names from STATION that do not end with vowels. 
-- Your result cannot contain duplicates.

SELECT distinct(CITY) FROM STATION 
WHERE CITY NOT RLIKE '^.*[AEIOUaeiou]$'