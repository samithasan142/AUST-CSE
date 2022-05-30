CREATE DATABASE Hotel

CREATE TABLE Booking11
(
	bookingId int IDENTITY (1,1) PRIMARY KEY,
	arrivalDate date,
	departureDate date,
	noOfAdult int,
	noOfChild int,
	noOfRooms int
)
select * from Booking11