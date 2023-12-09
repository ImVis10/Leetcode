# Write your MySQL query statement below
WITH SalariesByDepartment AS (
    SELECT name, salary, departmentId,
    DENSE_RANK() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS salaryRank
    FROM Employee
)

SELECT d.name AS Department, s.name AS Employee, s.salary AS Salary
FROM Department d JOIN SalariesByDepartment s
ON d.id = s.departmentId
WHERE s.salaryRank <= 3
ORDER BY d.name