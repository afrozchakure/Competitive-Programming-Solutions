-- Write your MySQL query statement below
SELECT name, population, area 
FROM World 
WHERE area > 3000000 or population > 25000000;


-- / Other Solution
-- Write your MySQL query statement below
SELECT name, population, area 
from World 
WHERE area > 3000000 
UNION 
SELECT name, population, area
FROM World 
WHERE
population > 25000000;