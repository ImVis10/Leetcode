# Write your MySQL query statement below
SELECT e.name AS Employee from Employee e  WHERE e.salary > (SELECT e1.salary FROM Employee e1 WHERE e1.id = e.managerId)