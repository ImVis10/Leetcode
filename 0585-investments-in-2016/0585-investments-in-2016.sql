# Write your MySQL query statement below
WITH Counts AS (
    SELECT *,
    COUNT(*) OVER(PARTITION BY tiv_2015) AS  count_2015,
    COUNT(*) OVER(PARTITION BY lat, lon) AS location_count
    FROM Insurance
)

SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Counts
WHERE count_2015 >= 2 AND location_count = 1