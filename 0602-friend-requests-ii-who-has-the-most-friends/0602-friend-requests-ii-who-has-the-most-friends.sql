# Write your MySQL query statement below
WITH FriendsCount AS (
    SELECT requester_id as user_id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id
    FROM RequestAccepted
)

SELECT user_id AS id, COUNT(user_id) AS num
FROM FriendsCount
GROUP BY id
ORDER BY num DESC
LIMIT 1
