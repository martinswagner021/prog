-- Aluno: Wagner Martins de Lima Filho
-- Disciplina: PBD


1)
select employees.emp_no, last_name, first_name, gender, salary from employees inner join salaries where employees.emp_no = salaries.emp_no;

-- 2)
select first_name, last_name, hire_date from employees where year(hire_date) = 1986;

-- 3)
select * from departments;
select * from dept_manager;
select departments.dept_no, dept_name, employees.emp_no, last_name, first_name 
	from dept_manager inner join employees on employees.emp_no = dept_manager.emp_no
    inner join departments on dept_manager.dept_no = departments.dept_no;

-- 4)
select dept_emp.emp_no, last_name, first_name, dept_name
	from dept_emp inner join employees on dept_emp.emp_no = employees.emp_no
    inner join departments on dept_emp.dept_no = departments.dept_no;
    
-- 5)
select first_name, last_name, gender from employees where first_name = 'Hercules' and last_name like 'B%';

--  6)
select dept_emp.emp_no, last_name, first_name, dept_name
	from dept_emp inner join employees on dept_emp.emp_no = employees.emp_no
    inner join departments on dept_emp.dept_no = departments.dept_no
    where dept_name = 'Sales';
    
--  7)
select dept_emp.emp_no, last_name, first_name, dept_name
	from dept_emp inner join employees on dept_emp.emp_no = employees.emp_no
    inner join departments on dept_emp.dept_no = departments.dept_no
    where dept_name = 'Sales' or dept_name = 'Development';
    
-- 8)
select count(last_name), last_name from employees group by last_name order by count(last_name) desc;
