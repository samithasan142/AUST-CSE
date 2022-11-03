SET VERIFY OFF;
SET SERVEROUTPUT ON;

declare 
	A money.ID%type := &X;
	B money.name%type := '&X';
	C money.taka%type := &X;
	
BEGIN

	FOR i IN 1..5 LOOP
		INSERT INTO MONEY VALUES (A, B, C);
		A := A + 1;
		
	END LOOP;
END;
/

