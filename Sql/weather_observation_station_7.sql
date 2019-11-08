-- Query the list of CITY names ending with vowels (a, e, i, o, u) from STATION. 
-- Your result cannot contain duplicates.

select DISTINCT(CITY) from STATION 
where CITY LIKE '%A' 
or CITY LIKE '%E' 
or CITY LIKE '%I' 
or CITY LIKE '%O' 
or CITY LIKE '%U';