select(select salary from Employee e1
   where salary = (select distinct salary from Employee
                   order by salary desc limit 1,1)
   limit 1) as SecondHighestSalary;