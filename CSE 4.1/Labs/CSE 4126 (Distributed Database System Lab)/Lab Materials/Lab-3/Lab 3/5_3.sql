SET SERVEROUTPUT ON;

CREATE OR REPLACE FUNCTION test1(A IN money.id%TYPE)
RETURN number
IS

BEGIN
	DBMS_OUTPUT.PUT_LINE(A);
	return A+10;
END test1;
/

--SELECT test1(20) from dual;