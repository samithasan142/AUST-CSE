
--ID:180204142

CREATE DATABASE DatabaseMid

CREATE TABLE BRANCH
(
BranchNo int IDENTITY(10,10) PRIMARY KEY,
Street varchar(50) NOT NULL,
City varchar(50) NOT NULL DEFAULT  'Dhaka',
Postcode int NOT NULL,
)

SELECT * FROM BRANCH

INSERT INTO BRANCH(Street, City, Postcode) 
VALUES ('Mohammadpur','Dhaka',1204)

INSERT INTO BRANCH(Street, City, Postcode) 
VALUES ('AtiBazar','Chittagong',1302)

INSERT INTO BRANCH(Street, City, Postcode) 
VALUES ('Dhanmondi','Dhaka',1402)

INSERT INTO BRANCH(Street, City, Postcode) 
VALUES ('Hair Street','Sylhet',1203)

SELECT * FROM BRANCH
---------------------------------------------------------------------------------------------


CREATE TABLE PropertyForRent
(
PropertyNo int IDENTITY(621,2) PRIMARY KEY,
Property_Type varchar(50) NOT NULL,
Rooms int NOT NULL,
Rent int NOT NULL CHECK(Rent>3000),
Address_of_property varchar(200) NULL,
OwnerNo int NOT NULL FOREIGN KEY REFERENCES PrivateOwner (OwnerNo),
StaffNo int NOT NULL FOREIGN KEY REFERENCES STAFF (StaffNo),
BranchNo int NOT NULL FOREIGN KEY REFERENCES BRANCH (BranchNo),
)

INSERT INTO PropertyForRent VALUES ('Flat', 4, 3500, 'Gulshan',2,7372,20)
INSERT INTO PropertyForRent VALUES ('House', 5, 6400, 'Dhanmondi',2,7374,30)
INSERT INTO PropertyForRent VALUES ('House', 6, 8000, 'Mohammadpur',1,7372,10)
INSERT INTO PropertyForRent VALUES ('Flat', 3, 4650, 'Wari',3,7369,20)
INSERT INTO PropertyForRent VALUES ('Flat', 2, 2500, 'Motijheel',1,7375,30)
INSERT INTO PropertyForRent VALUES ('House', 5, 7900, 'Hair Street',3,7374,40)

SELECT * FROM PropertyForRent

---------------------------------------------------------------------------------------------

CREATE TABLE PrivateOwner(
    OwnerNo    int IDENTITY(1,1) PRIMARY KEY,
    FirstName      VARCHAR(20),
	LastName       VARCHAR(20),
    ContactNo      CHAR(11)
)

SELECT * FROM PrivateOwner

INSERT INTO PrivateOwner VALUES ('kazi','Hasan','01912584949')
INSERT INTO PrivateOwner VALUES ('Kamran','Rashid','01677515829')
INSERT INTO PrivateOwner VALUES ('Khan','tahmeed','01688370555')
INSERT INTO PrivateOwner VALUES ('Elon','Mask','01551182170')

---------------------------------------------------------------------------------------------

CREATE TABLE STAFF
(
StaffNo int IDENTITY(7369,1) PRIMARY KEY,
FirstName varchar(50) NOT NULL,
LastName varchar(50) NOT NULL,
Position varchar(50) NOT NULL,
Sex varchar(10) NOT NULL,
DateofBirth date NOT NULL,
AnnualSalary float Null,
BranchNo int NOT NULL FOREIGN KEY REFERENCES BRANCH (BranchNo),
)

SELECT * FROM STAFF

INSERT INTO STAFF VALUES ('Rahim','Khan','Manager','M','19891217',800,40)
INSERT INTO STAFF VALUES ('Khan','Tahmeed','Asistant','M','19800220',1600,30)
INSERT INTO STAFF VALUES ('Karim','Rahman','Supervisor','F','19760404',2850,30)
INSERT INTO STAFF VALUES ('kazi','Hasan','Asistant','M','19950515',2750,20)
INSERT INTO STAFF VALUES ('Hasan','Shahriar','Manager','M','19960610',2200,30)
INSERT INTO STAFF VALUES ('Kazi','Maruf','Asistant','F','20000222',1250,40)
INSERT INTO STAFF VALUES ('kamran','Rashid','Asistant','F','19991125',1400,10)

---------------------------------------------------------------------------------------------

--> 1
SELECT * FROM STAFF

--> 2
SELECT StaffNo, FirstName + ' ' + LastName AS 'Name of the staff' , AnnualSalary FROM STAFF

--> 3
SELECT StaffNo, FirstName + ' ' + LastName AS 'Name of the Employee', (AnnualSalary/12) AS 'Monthly Salary' from STAFF

-->4
SELECT Street + ',' + City AS 'Full Address' FROM BRANCH WHERE City IN ( 'Dhaka', 'Sylhet' ) 

-->5
SELECT * FROM STAFF WHERE AnnualSalary BETWEEN '2000' AND '3000'

-->6
SELECT FirstName + ' ' + LastName AS 'Name' FROM STAFF WHERE Position IN ( 'Manager', 'Supervisor' ) 

-->7
UPDATE STAFF SET FirstName=lower(FirstName), LastName=lower(LastName)

-->8

SELECT * FROM STAFF ORDER BY AnnualSalary DESC, LastName ASC

-->9

SELECT * FROM STAFF WHERE len(FirstName)>4 AND FirstName LIKE 'K%' AND (FirstName LIKE '%m'OR FirstName LIKE '%n')

-->10

SELECT * FROM STAFF WHERE BranchNo = 30 AND (DateOfBirth BETWEEN '02/20/1980' AND '02/22/2000')

-->11

SELECT COUNT(*) FROM PropertyForRent WHERE Rent>3500

--> 12
SELECT COUNT(*) AS 'Number of Manager', SUM(AnnualSalary) AS 'Total Salary' FROM STAFF WHERE Position = 'Manager'

-->13

SELECT COUNT(StaffNo) as 'Number of Staff',SUM(AnnualSalary) as 'Sum of Staff Salary',BranchNo FROM STAFF GROUP BY BranchNo ORDER BY BranchNo

-->14

SELECT COUNT(StaffNo) as 'Number of Staff',SUM(AnnualSalary) as 'Sum of Staff Salary',BranchNo FROM STAFF GROUP BY BranchNo HAVING COUNT(StaffNo) > 1

-->15

SELECT s.LastName FROM STAFF s JOIN BRANCH b on s.BranchNo = b.BranchNo WHERE b.City LIKE 'Dhaka'

-->16

SELECT Property_Type FROM PropertyForRent pr JOIN PrivateOwner po ON pr.OwnerNo = po.OwnerNo WHERE po.ContactNo LIKE '01677515829'

-->17

INSERT INTO PropertyForRent (Property_Type, Rooms, Rent, Address_of_property, OwnerNo, BranchNo) 
VALUES ('House', 4, 9300,'Zigatola', 4, 30)
SELECT p.PropertyNo, s.FirstName FROM PropertyForRent p LEFT OUTER JOIN STAFF s ON p.StaffNo = s.StaffNo

-->18

SELECT TOP 3 * FROM STAFF  ORDER BY AnnualSalary DESC

-->19

SELECT COUNT(s.StaffNo),City FROM STAFF s JOIN BRANCH b ON s.BranchNo = b.BranchNo GROUP BY City

-->20

Select Lastname,Address_of_property FROM PrivateOwner left join PropertyforRent on PrivateOwner.OwnerNo=PropertyforRent.OwnerNo