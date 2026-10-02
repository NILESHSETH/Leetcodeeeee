-- # Write your MySQL query statement below
-- select id, name ,
-- if(sex = 'f', 'm','f') as sex, salary from Salary; 

update Salary 
set sex =
case 
when sex = 'f' then 'm'
else 'f'
end;