# Write your MySQL query statement below
WITH ClassCount AS (
    SELECT class, COUNT(student) as studentCount
    FROM Courses
    GROUP BY class
)

SELECT class
FROM ClassCount
WHERE studentCount >= 5
