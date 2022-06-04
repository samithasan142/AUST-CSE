-- Online: 02
-- Name: S.M. Tasnimul Hasan
-- ID: 180204142 
-- Group: B (B2)

-->1
SELECT * FROM PRODUCTS WHERE ProductPrice > 30 

-->2
SELECT * FROM PRODUCTS WHERE ProductTypeID <> 2 

-->3
SELECT * FROM ORDERS WHERE OrderDateTime BETWEEN '2006-01-10 00:00:00' AND '2006-01-13 00:00:00'

-->4
SELECT SUM(Tax) as 'Total Tax' FROM Orders

-->5
SELECT COUNT(OrderId) as NumberOfOrders FROM Orders 

-->6
SELECT ProductPrice as 'RegularPrice', ProductPrice-5 as 'SalePrice' FROM Products

-->7
SELECT MAX(ProductPrice) as MostExpensiveItem FROM Products

-->8
SELECT AVG(ProductPrice) as AverageCost FROM Products

-->9
SELECT * FROM Customers WHERE FirstName LIKE 'J%'

-->10
SELECT * FROM Customers WHERE StateProvince IN ('IL', 'KS', 'PA')

-->11
SELECT * FROM Customers ORDER BY LastName

-->12
SELECT CustomerID, SUM(Shipping) as 'Total Shipping Amount' FROM Orders GROUP BY CustomerID

-->13
SELECT CustomerID, SUM(Shipping) as 'Total Shipping Amount' FROM Orders GROUP BY CustomerID HAVING COUNT(CustomerID) >= 3

-->14
SELECT TOP 3 * FROM Customers

-->15
SELECT MAX(Tax) as 'Maximum Tax' FROM Orders

