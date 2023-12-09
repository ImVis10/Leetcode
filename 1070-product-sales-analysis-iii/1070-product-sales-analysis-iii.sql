# Write your MySQL query statement below
WITH YearlySales AS (
    SELECT product_id, year, quantity, price,
    RANK() OVER(PARTITION BY product_id ORDER BY year) as salesByYear
    FROM Sales
)

SELECT product_id, year AS first_year, quantity, price 
FROM YearlySales
WHERE salesByYear = 1