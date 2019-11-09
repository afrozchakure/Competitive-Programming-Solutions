-- Query the list of CITY names from STATION that do not start with vowels. 
-- Your result cannot contain duplicates.

select distinct(CITY) FROM STATION 
WHERE CITY NOT RLIKE '^[AEIOUaeiou].*$'