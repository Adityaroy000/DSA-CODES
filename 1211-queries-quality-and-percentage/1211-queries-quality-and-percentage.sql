# Write your MySQL query statement below
select q.query_name, round( sum(q.rating/q.position)/count(q.query_name) ,2) as quality, round(sum(q.rating<3) / count(q.query_name) * 100, 2) as poor_query_percentage 
from Queries as q
group by q.query_name