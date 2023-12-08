# Write your MySQL query statement below
SELECT DISTINCT num as ConsecutiveNums
FROM Logs
WHERE (id + 1, num) in (SELECT * FROM Logs) and (id + 2, num) in (SELECT * FROM Logs)