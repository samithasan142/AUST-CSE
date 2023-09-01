-- ID: 180204142

clear screen;
DROP TABLE Flights1;
CREATE TABLE Flights1(
     flno INT,
     fromm VARCHAR2(30),
     too VARCHAR2(30),
     distance INT,
     departs VARCHAR2(30),
     arrives VARCHAR2(30),
     price REAL);
			
INSERT INTO Flights1 VALUES (1,'Los Angeles','Honolulu',2558,'08:30:00','12:00:00',50000);
INSERT INTO Flights1 VALUES(2,'Chicago','New York',2000,'09:30:00','12:30:00',15000);
INSERT INTO Flights1 VALUES(3,'New York','Boston',3500,'02:15:00','04:25:00',20000);
INSERT INTO Flights1 VALUES(4,'Houston','San Francisco',4500,'10:15:00','12:15:00',35000);
INSERT INTO Flights1 VALUES(5,'Los Angeles','Honolulu',2558,'01:15:00','03:30:00',90000);
INSERT INTO Flights1 VALUES(6,'Atlanta','Dallas',3500,'10:00:00','04:45:00',65000);
INSERT INTO Flights1 VALUES(7,'Denver','Columbus',2300,'09:45:00','11:30:00',75000);
INSERT INTO Flights1 VALUES(8,'Austin','Portland',4000,'11:30:00','01:30:00',70000);

SELECT * FROM Flights1;

DROP TABLE Aircraft;
CREATE TABLE Aircraft(
     aid INT,
     aname VARCHAR2(30),
     cruisingrange INT);

INSERT INTO Aircraft VALUES (110,'Airbus A320',2000);
INSERT INTO Aircraft VALUES (115,'Airbus A330',2500);
INSERT INTO Aircraft VALUES (204,'Concorde',1000);
INSERT INTO Aircraft VALUES (319,'Douglas DC3',800);
INSERT INTO Aircraft VALUES (508,'Boeing 787',4000);
INSERT INTO Aircraft VALUES (518,'Boeing 767',3500);
INSERT INTO Aircraft VALUES (602,'Piper J3 Cub',1800);
INSERT INTO Aircraft VALUES (820,'Martin M130',3000);

SELECT * FROM Aircraft;


DROP TABLE Employees;
CREATE TABLE Employees(
     eid INT,
     ename VARCHAR2(30),
     salary INT);

INSERT INTO Employees VALUES (1,'Tamim',75000);
INSERT INTO Employees VALUES (2,'Liton',45000);
INSERT INTO Employees VALUES (3,'Shakib',80000);
INSERT INTO Employees VALUES (4,'Mushfiq',70000);
INSERT INTO Employees VALUES (5,'Shanto',25000);
INSERT INTO Employees VALUES (6,'Riad',70000);
INSERT INTO Employees VALUES (7,'Afif',35000);
INSERT INTO Employees VALUES (8,'Taskin',50000);

SELECT * FROM Employees;


DROP TABLE Certified;
CREATE TABLE Certified(
     eid INT,
     aid INT);

INSERT INTO Certified VALUES (1,110);
INSERT INTO Certified VALUES (1,508);
--INSERT INTO Certified VALUES (2,110);
INSERT INTO Certified VALUES (2,319);
INSERT INTO Certified VALUES (3,115);
INSERT INTO Certified VALUES (3,508);
INSERT INTO Certified VALUES (4,115);
INSERT INTO Certified VALUES (4,508);
INSERT INTO Certified VALUES (5,319);
--INSERT INTO Certified VALUES (5,518);
INSERT INTO Certified VALUES (6,518);
INSERT INTO Certified VALUES (6,204);
INSERT INTO Certified VALUES (7,602);
INSERT INTO Certified VALUES (7,204);
INSERT INTO Certified VALUES (8,602);
INSERT INTO Certified VALUES (8,319);

SELECT * FROM Certified;


--> 1

SELECT DISTINCT e.ename
    FROM Employees e
    WHERE e.salary < (SELECT MIN(f.price)
    FROM Flights1 f
    WHERE f.fromm='Los Angeles' AND f.too='Honolulu');
	
--> 2

SELECT DISTINCT e.ename
    FROM Employees e, Aircraft a, Certified c
    WHERE e.eid=c.eid AND c.aid=a.aid
    AND a.aname LIKE 'Boeing%';
	
--> 3

SELECT e.ename 
    FROM Employees e, Aircraft a, Certified c 
	WHERE e.eid=c.eid AND c.aid=a.aid 
	GROUP BY e.ename, a.cruisingrange 
	HAVING a.cruisingrange > 1000 AND COUNT (*) > 1;
	
commit;