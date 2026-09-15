# Write your MySQL query statement below
select e.name
from Employee as e
join Employee as em
    on e.id = em.managerId
group by e.id
having count(e.id) >= 5