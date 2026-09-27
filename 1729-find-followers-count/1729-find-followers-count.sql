# Write your MySQL query statement below
select distinct user_id, (select count(*) from Followers f2 where f1.user_id = f2.user_id) as 'followers_count' from Followers  f1
order by user_id;
