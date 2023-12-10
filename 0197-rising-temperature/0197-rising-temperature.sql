# Write your MySQL query statement below
SELECT w2.id as id
FROM Weather w1 JOIN Weather w2
ON w2.temperature > w1.temperature AND DATEDIFF(w2.recordDate, w1.recordDate) = 1