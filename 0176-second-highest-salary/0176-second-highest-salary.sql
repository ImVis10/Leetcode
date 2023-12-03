# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM Employee e
WHERE e.salary < (SELECT MAX(salary) FROM Employee e1 WHERE e1.salary > e.salary)