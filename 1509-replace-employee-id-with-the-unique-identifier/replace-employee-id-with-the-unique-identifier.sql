select u.unique_id,v.name
from Employees v
left join EmployeeUNI u
      on v.id = u.id