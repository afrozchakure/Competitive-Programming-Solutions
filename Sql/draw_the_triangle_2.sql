-- P(R) represents a pattern drawn by Julia in R rows. The following pattern represents P(5):

-- * 
-- * * 
-- * * * 
-- * * * * 
-- * * * * *

-- Write a query to print the pattern P(20).

SET @number = 0;
SELECT REPEAT('* ', @number := @number + 1) from information_schema.tables where @number < 20;