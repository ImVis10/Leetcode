# Write your MySQL query statement below
WITH prev_day_temp AS (
    SELECT id, temperature, recordDate, LAG(recordDate) OVER (ORDER BY recordDate) as prev_date, LAG(temperature) OVER(ORDER BY recordDate) as prev_temp
    FROM Weather
)

SELECT id FROM prev_day_temp WHERE DATEDIFF(recordDate, prev_date) = 1 and temperature > prev_temp