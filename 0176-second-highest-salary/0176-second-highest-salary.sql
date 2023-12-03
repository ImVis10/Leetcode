# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM Employee e
WHERE e.salary < (SELECT MAX(salary) FROM Employee)