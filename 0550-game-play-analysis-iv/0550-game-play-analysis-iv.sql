# Write your MySQL query statement below
select 
    round(count(f.player_id)/(select count(distinct player_id) from Activity), 2) as fraction  
from (
    select player_id, min(event_date) as first_login
    from Activity a
    group by player_id
) f
join Activity as a
    on a.player_id = f.player_id
    and a.event_date = date_add(f.first_login, interval 1 day)