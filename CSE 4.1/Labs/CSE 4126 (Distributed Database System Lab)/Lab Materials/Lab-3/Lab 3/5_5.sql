SET SERVEROUTPUT ON;

CREATE OR REPLACE PROCEDURE mytest
IS

A money.id%TYPE;
B money.taka%TYPE;
C money.taka%TYPE;

BEGIN
	C := 0;
	FOR R IN (SELECT * FROM money) LOOP
		A := R.id;
		B := R.taka;
		C := C + B;
	END LOOP;
	DBMS_OUTPUT.PUT_LINE(C);
END mytest;
/
