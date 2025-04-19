use northwind;

-- 1)
select EmployeeID, LastName, FirstName, TitleOfCourtesy, Extension from employees limit 3;

-- 2)
select FirstName, LastName, HireDate from employees where year(HireDate) = 1986;

-- 3)
select * from employees;