# Write your MySQL query statement below
select 
a1.machine_id,
round(avg(a1.timestamp-a2.timestamp),3) as processing_time 
from activity a1
join activity a2 on (a1.process_id=a2.process_id and a1.machine_id=a2.machine_id && a1.activity_type='end' && a2.activity_type='start') group by machine_id;
