-- Query the list of CITY names from STATION which 
-- have vowels (i.e., a, e, i, o, and u) as both their first and last characters. 
-- Your result cannot contain duplicates.

--^ and $ anchor the match to the beginning and end of the value.

select DISTINCT(CITY) FROM STATION WHERE 
CITY RLIKE '^[aeiouAEIOU].*[aeiouAEIOU]$'