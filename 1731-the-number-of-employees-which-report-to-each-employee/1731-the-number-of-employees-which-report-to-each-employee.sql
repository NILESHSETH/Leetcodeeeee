-- # Write your MySQL query statement below

-- select employee_id ,
-- (select name from Employees e2 where e2.reports_to   = e1.employee_id ) as 'name',
-- (select count(*) from Employees e3 where e3.reports_to   = e1.employee_id ) as 'reports_count',
-- (select AVG(age) from Employees e4 where e4.reports_to   = e1.employee_id ) as 'average_age' from Employees e1

select
  employee_id,
  (select name from Employees e2 where e2.employee_id = e1.employee_id) as 'name',
  (select count(*) from Employees e3 where e3.reports_to = e1.employee_id) as 'reports_count',
  (select round(avg(age)) from Employees e4 where e4.reports_to = e1.employee_id) as 'average_age'
from Employees e1
where employee_id in (select distinct reports_to from Employees where reports_to is not null)
order by employee_id asc;