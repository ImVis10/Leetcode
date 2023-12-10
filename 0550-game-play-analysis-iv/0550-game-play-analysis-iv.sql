# Write your MySQL query statement below
WITH PlayerLogging AS (
    SELECT player_id, event_date,
    ROW_NUMBER() OVER(PARTITION BY player_id ORDER BY event_date) AS loginId
    FROM Activity
),
ConsecutiveLogins AS (
    SELECT p2.player_id
    FROM PlayerLogging p1 JOIN PlayerLogging p2
    ON p1.player_id = p2.player_id AND DATEDIFF(p2.event_date, p1.event_date) = 1 AND p1.loginId = 1 and p2.loginId = 2
)

SELECT ROUND(
    (SELECT COUNT(DISTINCT player_id)
    FROM ConsecutiveLogins)
    /
    COUNT(DISTINCT player_id), 2
    ) AS fraction
FROM Activity