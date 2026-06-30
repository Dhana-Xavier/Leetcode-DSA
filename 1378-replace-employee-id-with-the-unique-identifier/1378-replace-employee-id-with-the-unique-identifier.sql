SELECT u.unique_id , e.name
from employees e LEFT JOIN EmployeeUNI u
on e.id=u.id ;