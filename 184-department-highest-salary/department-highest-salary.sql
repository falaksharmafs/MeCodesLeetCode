SELECT d.name as "Department", e.name as "Employee", e.salary
FROM employee e JOIN department d ON e.departmentId = d.id
WHERE (e.departmentId, e.salary) IN (
SELECT departmentId, MAX(salary)
FROM employee
GROUP BY departmentId
)