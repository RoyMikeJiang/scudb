SELECT GROUP_CONCAT(ProductName,', ') AS ProductNames
FROM 'Order' AS o
	LEFT OUTER JOIN OrderDetail AS od
	ON o.Id = od.OrderId 
	LEFT OUTER JOIN Product AS p
	ON od.ProductId = p.Id 
	LEFT OUTER JOIN Customer AS c
	ON o.CustomerId = c.Id 
WHERE c.CompanyName = 'Queen Cozinha'
	AND o.OrderDate LIKE '2014-12-25 __:__:__';