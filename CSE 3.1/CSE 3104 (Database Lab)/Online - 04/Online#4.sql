create table branch
(
BranchNo int primary key,
Street varchar(50),
City varchar(50) default 'Dhaka',
Postcode varchar(50));



insert into branch values(10, 'Mohammadpur', 'Dhaka', '1204');
insert into branch values(20, 'Atibazar', 'Chittagong', '1302');
insert into branch values(30, 'Dhanmondi', 'Dhaka', '1402');
insert into branch values(40, 'Hair Street', 'Sylhet', '1203');

create table PropertyForRent
(
PropertyNo int primary key,
Property_type varchar(50),
Rooms int,
Rent money,
Address_of_property varchar(50),
OwnerNo int NOT NULL FOREIGN KEY REFERENCES PrivateOwner (OwnerNo),
StaffNo int FOREIGN KEY REFERENCES Staff (StaffNo),
BranchNo int NOT NULL FOREIGN KEY REFERENCES branch (BranchNo),
);



insert into PropertyForRent values(621, 'Flat', 4, 3500, 'Gulshan', 2, 7372, 20);
insert into PropertyForRent values(623, 'House', 5, 6400, 'Dhanmondi', 2, 7374, 30);
insert into PropertyForRent values(625, 'House', 6, 8000, 'Mohammadpur', 1, 7372, 10);
insert into PropertyForRent values(627, 'Flat', 3, 4650, 'Wari', 3, 7369, 20);
insert into PropertyForRent values(629, 'Flat', 2, 2500, 'Motijheel', 1, 7375, 30);
insert into PropertyForRent values(631, 'House', 5, 7900, 'Hair Street', 3, 7374, 40);
insert into PropertyForRent values(633, 'House', 4, 9300, 'Zigatola', 3, null, 30);


create table PrivateOwner
(
OwnerNo int primary key,
FirstName varchar(50),
LastName varchar(50),
ContactNo varchar(50));



insert into PrivateOwner values(1, 'Kazi', 'Hasan', '01912584349');
insert into PrivateOwner values(2, 'Kamran', 'Rashid', '01677515829');
insert into PrivateOwner values(3, 'Khan', 'Tahmeed', '01688370555');
insert into PrivateOwner values(4, 'Elon', 'Mask', '01551182170');
insert into PrivateOwner values(5, 'Chris', 'Evans', '01745698532');




create table Staff
(
StaffNo int primary key,
FirstName varchar(50),
LastName varchar(50),
Position varchar(50),
Sex varchar(10),
DateOfBirth date,
AnnualSalary money,
BranchNo int not null FOREIGN KEY REFERENCES branch (BranchNo));



insert into Staff values(7369, 'Rahim', 'Khan', 'Manager', 'M', '12/17/1989', 800, 40);
insert into Staff values(7370, 'Khan', 'Tahmeed', 'Assistant', 'M', '02/20/1980', 1600, 30);
insert into Staff values(7371, 'Karim', 'Rahman', 'Supervisor', 'F', '04/04/1976', 2850, 30);
insert into Staff values(7372, 'Kazi', 'Hasan', 'Assistant', 'M', '05/15/1995', 2750, 20);
insert into Staff values(7373, 'Hasan', 'Shahriar', 'Manager', 'M', '06/10/1996', 2200, 30);
insert into Staff values(7374, 'Kazi', 'Maruf', 'Assistant', 'F', '02/22/2000', 1250, 40);
insert into Staff values(7375, 'Kamran', 'Rashid', 'Assistant', 'F', '11/25/1999', 1400, 10);