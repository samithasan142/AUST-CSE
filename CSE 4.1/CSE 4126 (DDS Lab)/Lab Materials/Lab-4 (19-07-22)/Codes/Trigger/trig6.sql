SET SERVEROUTPUT ON;

CREATE OR REPLACE TRIGGER HELLO4 
AFTER UPDATE 
OF TAKA
ON MONEY
DECLARE
BEGIN
	DBMS_OUTPUT.PUT_LINE('HELLO4');
END;
/
