/* unknown exception problem */

SET SERVEROUTPUT ON;
SET VERIFY OFF;

DECLARE
	A money.taka%TYPE;
	B number := &x;
	res number;
	
BEGIN
	SELECT taka into A from money where id = 1;
	res := A/B;
	
	EXCEPTION
		WHEN TOO_MANY_ROWS THEN
			DBMS_OUTPUT.PUT_LINE('Many rows detected');
		WHEN NO_DATA_FOUND THEN
			DBMS_OUTPUT.PUT_LINE('No data found');
		WHEN OTHERS THEN
			DBMS_OUTPUT.PUT_LINE('Other errors');
END;
/