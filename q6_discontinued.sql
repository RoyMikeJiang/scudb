SELECT ProductName,
    CompanyName,
    ContactName
FROM (SELECT *
    FROM (SELECT * 
            FROM 'Order' 
            ORDER BY OrderDate) as OOrder
        LEFT OUTER JOIN OrderDetail
        ON OOrder.Id=OrderId
        LEFT OUTER JOIN Customer
        ON CustomerId=Customer.Id 
        LEFT OUTER JOIN Product
        ON ProductId=Product.Id
    WHERE Discontinued = 1)
GROUP BY ProductId
ORDER BY ProductName;