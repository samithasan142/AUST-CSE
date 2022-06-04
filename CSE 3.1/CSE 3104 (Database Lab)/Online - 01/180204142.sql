-- Online: 01
-- Name: S.M. Tasnimul Hasan
-- ID: 180204142 
-- Group: B (B2)

CREATE DATABASE SampleDB


CREATE TABLE SALESMAN
(
SalesmanId int IDENTITY(1001,1) PRIMARY KEY,
FirstName varchar(50) NOT NULL,
LastName varchar(50) NOT NULL,
Area varchar(15) NOT NULL,
YearOfService int NOT NULL,
Salary numeric(7,2),
)

CREATE TABLE CUSTOMER(CustomerId int IDENTITY(2001,1) PRIMARY KEY,CustomerName varchar(50) NOT NULL,Location varchar(15) NOT NULL,PinCode numeric(8),Class char(1) DEFAULT  'C',)CREATE TABLE ORDERS(OrderId int IDENTITY(3001,1) PRIMARY KEY,CustomerId int NOT NULL FOREIGN KEY REFERENCES CUSTOMER (CustomerId),SalesmanId int NOT NULL FOREIGN KEY REFERENCES SALESMAN (SalesmanId),OrderDate date NOT NULL,OrderAmount Numeric(8,2) CHECK(OrderAmount>9))

INSERT INTO SALESMAN (LastName, FirstName, Area, YearOfService, Salary) 
VALUES ('Khan', 'Rahim', 'Gulshan', 5, 10000),
       ('Rahman', 'Karim', 'Dhanmondi', 4, 20000),
       ('Abir', 'Hasan', 'Motijheel', 3, 30000),
	   ('Saif', 'Hassan', 'Gulshan', 7, 40000),
	   ('Nazmul', 'Ahmned', 'Banasree', 8, 50000)


SELECT * FROM SALESMAN

INSERT INTO CUSTOMER (CustomerName, Location, PinCode, Class) VALUES ('Rahim Khan', 'Gulshan', 1219 , 'A'),       ('Kahim Rahman','Dhanmondi',1220, 'C'),       ('Mehedi Hasan', 'Motijheel',1224, 'B'),	   ('Khan Rahim', 'Banasree',1230, 'C'),       ('Rahman Ahmed','Dhanmondi',1240, 'B')SELECT * FROM CustomerINSERT INTO ORDERS (CustomerId,SalesmanId,OrderDate, OrderAmount) VALUES (2001, 1002, '20210701' , 1000),       (2004,1004,'20210702', 2500),       (2005, 1005,'20210703', 200),	   (2003, 1003,'20210703', 300),       (2002,1001,'20210708', 10)SELECT * FROM ORDERS-->1SELECT FirstName + ' ' + LastName as 'Salesman Name',Area as 'City',YearOfService as 'Year Of Dervice',Salary as 'Salary Earned' FROM SALESMAN

-->2SELECT FirstName + ' ' + LastName as 'Salesman Name',Area as 'City',YearOfService as 'Servicing Year',Salary as 'Salary Earned' FROM SALESMAN WHERE Area <> 'Dhanmondi'-->3SELECT CustomerName, Location FROM CUSTOMER WHERE Class='A'-->4SELECT Area as 'City' FROM SALESMAN-->5UPDATE CUSTOMER set Class='A' where Location='Gulshan'-->6SELECT CustomerName, Location FROM CUSTOMER WHERE Location='Banani'-->7SELECT FirstName + ' ' + LastName as 'Salesman Name' FROM SALESMAN WHERE Salary > 20000-->8UPDATE ORDERS set OrderAmount=1000 where OrderId=3004-->9SELECT FirstName + ' ' + LastName as 'Salesman Name',Area as 'City' FROM SALESMAN ORDER BY Salary

-->10SELECT * FROM ORDERS WHERE CustomerId=2003 ORDER BY OrderDate desc-->11UPDATE SALESMAN set Salary=Salary+1500 where YearOfService>1-->12UPDATE SALESMAN set Salary=Salary+Salary*0.05 where YearOfService>2-->13SELECT Location as 'Areas' FROM CUSTOMER-->14UPDATE ORDERS set OrderAmount=OrderAmount-OrderAmount*0.045 where OrderAmount>10000-->15DELETE FROM ORDERS where OrderAmount<50

