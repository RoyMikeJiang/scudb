SELECT f.RegionDescription,
	f.FirstName,
	f.LastName,
	f.BirthDate
FROM (SELECT e.FirstName,
		e.LastName,
		e.BirthDate,
		r.Id,
		r.RegionDescription
	FROM Employee AS e 
	LEFT OUTER JOIN EmployeeTerritory AS et
	ON e.Id = et.EmployeeId
	LEFT OUTER JOIN Territory AS t
	ON et.TerritoryId = t.Id 
	LEFT OUTER JOIN Region AS r
	ON t.RegionId = r.Id
	ORDER BY e.BirthDate DESC) AS f
GROUP BY f.id
ORDER BY f.id;