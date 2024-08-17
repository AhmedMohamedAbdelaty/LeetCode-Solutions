select unique_id, name
from Employees e
    left join EmployeeUNI eu on eu.id = e.id