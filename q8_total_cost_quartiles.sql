SELECT CompanyName,
    CustomerId,
    TPrice
FROM (SELECT IFNULL(c.CompanyName, "MISSING_NAME") AS CompanyName,
    	co.CustomerId,
    	co.TPrice,
    	NTILE(4) OVER(ORDER BY CAST(co.TPrice AS float)) AS Bucket
    FROM (SELECT o.CustomerId ,
    		printf("%.2f",SUM((od.UnitPrice*od.Quantity))) AS TPrice
    	FROM "Order" AS o 
    		LEFT OUTER JOIN OrderDetail AS od 
    		ON o.Id = od.OrderId
    	GROUP BY o.CustomerId) AS co
    	LEFT OUTER JOIN Customer AS c 
    	ON co.CustomerId = c.Id) AS f
WHERE Bucket=1
ORDER BY CAST(TPrice AS float);