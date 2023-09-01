/* Multiple rows return problem */

SET SERVEROUTPUT ON;

DECLARE
	A money.taka%TYPE;
BEGIN
	SELECT taka into A from money;
	
	EXCEPTION
		WHEN TOO_MANY_ROWS THEN
			DBMS_OUTPUT.PUT_LINE('Many rows detected');
		
END;
/