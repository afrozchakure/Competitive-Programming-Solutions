-- Query the smallest Northern Latitude (LAT_N) from STATION that is greater than 38.7780. 
-- Round your answer to 4 decimal places.

SELECT ROUND(LAT_N, 4) FROM STATION WHERE LAT_N = (SELECT MIN(LAT_N) FROM STATION WHERE LAT_N > 38.7780);