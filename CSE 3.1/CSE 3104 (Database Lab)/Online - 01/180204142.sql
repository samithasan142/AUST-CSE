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

CREATE TABLE CUSTOMER

INSERT INTO SALESMAN (LastName, FirstName, Area, YearOfService, Salary) 
VALUES ('Khan', 'Rahim', 'Gulshan', 5, 10000),
       ('Rahman', 'Karim', 'Dhanmondi', 4, 20000),
       ('Abir', 'Hasan', 'Motijheel', 3, 30000),
	   ('Saif', 'Hassan', 'Gulshan', 7, 40000),
	   ('Nazmul', 'Ahmned', 'Banasree', 8, 50000)


SELECT * FROM SALESMAN

INSERT INTO CUSTOMER (CustomerName, Location, PinCode, Class) 

-->2

-->10
