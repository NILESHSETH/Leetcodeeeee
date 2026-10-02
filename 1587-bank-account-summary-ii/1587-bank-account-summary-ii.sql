-- # Write your MySQL query statement below
-- select u.name,
-- select sum(amount) 


-- from Users u
-- inner join Transaction t 
-- on u.account = t.account

-- having amount > 10000;
select u.name, 
sum(t.amount) as balance
from Users u 
inner join 
Transactions t  
on u.account = t.account
group by u.name,u.account
having balance > 10000;