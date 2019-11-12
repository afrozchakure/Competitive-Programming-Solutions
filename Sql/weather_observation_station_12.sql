-- http://www.tutorialspoint.com/mysql/mysql-regexps.htm

-- '.' is to specify a character and '*' is to mention zero or more of the preceding character
-- [...] -->  Any character listed between the square brackets
-- [^...] --> Any character not listed between the square brackets

SELECT distinct(CITY) FROM STATION 
WHERE CITY RLIKE '^[^aeiouAEIOU].*[^AEIOUaeiou]$';  

-- SELECT distinct(CITY) FROM STATION 
-- WHERE CITY REGEXP '^[^aeiouAEIOU].*[^AEIOUaeiou]$'  