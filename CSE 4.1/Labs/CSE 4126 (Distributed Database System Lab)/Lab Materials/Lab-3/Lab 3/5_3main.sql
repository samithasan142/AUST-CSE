SET SERVEROUTPUT ON;

DECLARE
	NUM number;

BEGIN
	NUM := test1(10);
	DBMS_OUTPUT.PUT_LINE(NUM);
END;
/