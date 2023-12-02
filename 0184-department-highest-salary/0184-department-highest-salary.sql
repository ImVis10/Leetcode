# Write your MySQL query statement below
# SELECT d.Name AS Department, e.name AS Employee, e.salary AS Salary
# FROM Department d JOIN Employee e ON e.departmentId = d.id
# WHERE(departmentId, salary) IN
# (SELECT departmentId, MAX(salary) FROM Employee GROUP BY departmentId)

SELECT d.Name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee e, Department d
WHERE e.departmentId = d.id AND e.salary = (SELECT MAX(salary) FROM Employee e1 WHERE e1.departmentId = d.id)