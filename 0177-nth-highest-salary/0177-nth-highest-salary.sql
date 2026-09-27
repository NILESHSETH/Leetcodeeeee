CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
select(select salary from Employee e1
                   where salary = (select distinct salary from Employee
                   order by salary desc limit N ,1)
                   limit 1) 
as SecondHighestSalary

  );
END


