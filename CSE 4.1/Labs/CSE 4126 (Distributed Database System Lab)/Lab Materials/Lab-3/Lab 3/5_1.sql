SET SERVEROUTPUT ON;

CREATE OR REPLACE FUNCTION test1
RETURN number
IS

BEGIN
	DBMS_OUTPUT.PUT_LINE(2);
	return 10;
END test1;
/

DECLARE
	NUM number;
BEGIN
	NUM := test1;
	DBMS_OUTPUT.PUT_LINE(NUM);
END;
/