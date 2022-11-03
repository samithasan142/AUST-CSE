/* user defined exception */

SET SERVEROUTPUT ON;
SET VERIFY OFF;

DECLARE
	A money.taka%TYPE;
	B number := &x;
	res number;
	myExp EXCEPTION;
	
BEGIN
	SELECT taka into A from money where id = 1;
	
	IF B < 0 THEN
		RAISE myExp;
	END IF;
	
	res := A/B;
	
	EXCEPTION
		WHEN myExp THEN
			DBMS_OUTPUT.PUT_LINE('cannot be -ve');
		WHEN TOO_MANY_ROWS THEN
			DBMS_OUTPUT.PUT_LINE('Many rows detected');
		WHEN NO_DATA_FOUND THEN
			DBMS_OUTPUT.PUT_LINE('No data found');
		WHEN ZERO_DIVIDE THEN
			DBMS_OUTPUT.PUT_LINE('Cannot divide by zero');
		WHEN OTHERS THEN
			DBMS_OUTPUT.PUT_LINE('Other errors');
END;
/