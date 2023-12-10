# Write your MySQL query statement below
WITH PlayerLogging AS (
    SELECT player_id, event_date,
    ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY event_date) AS loginId
    FROM Activity
)

SELECT player_id, event_date AS first_login
FROM PlayerLogging
WHERE loginId = 1