SELECT e.name ,b.bonus 
from Employee e Left join Bonus b
on e.empId=b.empId
WHERE b.bonus IS NULL or b.bonus<1000; 
