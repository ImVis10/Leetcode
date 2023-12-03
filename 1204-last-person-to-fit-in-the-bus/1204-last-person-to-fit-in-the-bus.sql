# Write your MySQL query statement below
SELECT person_name
FROM (SELECT person_name, turn, SUM(weight) OVER(ORDER BY turn) as total_weight FROM Queue) Cumulative_queue
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1