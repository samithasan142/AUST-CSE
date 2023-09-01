/* no data found problem */

SET SERVEROUTPUT ON;

DECLARE
	A money.taka%TYPE;
BEGIN
	SELECT taka into A from money where id = 4;
	
	EXCEPTION
		WHEN TOO_MANY_ROWS THEN
			DBMS_OUTPUT.PUT_LINE('Many rows detected');
		WHEN NO_DATA_FOUND THEN
			DBMS_OUTPUT.PUT_LINE('No data found');
		
END;
/