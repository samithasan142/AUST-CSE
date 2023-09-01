
-- ID: 180204142

SET SERVEROUTPUT ON;
SET VERIFY OFF;

CREATE OR REPLACE PACKAGE mypack AS
    FUNCTION searchh(ID IN int, PASSWORD IN varchar, status IN OUT int) 
    RETURN int;

    PROCEDURE printStatus(status2 IN int, PASSWORD2 IN varchar);
END mypack;
/

CREATE OR REPLACE PACKAGE BODY mypack AS

    FUNCTION searchh(ID IN int, PASSWORD IN varchar, status IN OUT int) 
    RETURN int
    IS 

    BEGIN 
        
        FOR I IN (select * from supplier where sid=ID) LOOP
            status :=1;
        END LOOP;

        FOR I IN (select * from supplier where sid=ID and sname=PASSWORD) LOOP
            status :=2;
        END LOOP;

        return status;

    END searchh; 
    

    PROCEDURE printStatus(status2 IN int, PASSWORD2 IN varchar)
    IS

    BEGIN
        IF (status2 = 2) THEN 
            dbms_output.put_line('Welcome back ' || PASSWORD2 || '!'); 
        ELSIF (status2 = 1) THEN 
			dbms_output.put_line('Invalid credentials');
        ELSE 
            dbms_output.put_line('Account not Found. Please Sign up.'); 
        END IF;

    END printStatus;
    
END mypack;
/



DECLARE
    ID supplier.sid%TYPE;
    PASSWORD supplier.sname%TYPE;
    status int := 0;
    checkStatus int := 0;

    handle EXCEPTION;
    handle1 EXCEPTION;
    handle2 EXCEPTION;

BEGIN
    ID := &ID;
    PASSWORD := '&PASSWORD';
    checkStatus := mypack.searchh(ID,PASSWORD,status);

    IF checkStatus=2 THEN
        RAISE handle2;
    ELSIF checkStatus=1 THEN
        RAISE handle1;
    ELSE
        RAISE handle;

    END IF;

    EXCEPTION
        WHEN handle THEN
           mypack.printStatus(checkStatus,PASSWORD);
        WHEN handle1 THEN
            mypack.printStatus(checkStatus,PASSWORD);
        WHEN handle2 THEN
           mypack.printStatus(checkStatus,PASSWORD);
END;
/

CREATE OR REPLACE TRIGGER selectFrom 
BEFORE UPDATE
ON supplier
DECLARE
BEGIN
	DBMS_OUTPUT.PUT_LINE('HELLO');
END;
/