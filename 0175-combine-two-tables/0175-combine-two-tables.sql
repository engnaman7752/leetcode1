# Write your MySQL query statement below
select FirstName, LastName, City, State
FROM Person AS p left JOIN Address AS a ON a.personId=p.personId;