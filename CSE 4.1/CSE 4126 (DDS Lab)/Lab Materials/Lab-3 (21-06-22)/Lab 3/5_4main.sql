SET SERVEROUTPUT ON;

DECLARE
	NUM number;

BEGIN
	NUM := mytest;
	DBMS_OUTPUT.PUT_LINE(NUM);
END;
/