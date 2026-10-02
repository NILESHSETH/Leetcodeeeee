-- # Write your MySQL query statement below
-- select  distinct contest_id ,round(count(contest_id)/count(*),2)*100 precentage from users
-- inner join register r
-- on u.user_id = r.user_id
select contest_id , 
round(count(user_id)*100/(select count(*) from users), 2) as percentage
from Register
group by contest_id 
order by percentage desc , contest_id asc;

