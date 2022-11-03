SET SERVEROUTPUT ON;

CREATE OR REPLACE PACKAGE mypack AS

	FUNCTION F1(A1 IN NUMBER)
	RETURN NUMBER;
	
	PROCEDURE P1(B1 IN NUMBER);
END mypack;
/

CREATE OR REPLACE PACKAGE BODY mypack AS

	FUNCTION F1(A1 IN NUMBER)
	RETURN NUMBER
	IS 
	
	BEGIN
		IF MOD(A1, 2) = 0 THEN
			RETURN 1;
		ELSE
			RETURN 0;
		END IF;
	END F1;
	
	PROCEDURE P1(B1 IN NUMBER)
	IS
	
	BEGIN
		IF MOD(B1, 2) = 0 THEN
			DBMS_OUTPUT.PUT_LINE('EVEN');
		ELSE
			DBMS_OUTPUT.PUT_LINE('ODD');
		END IF;
	END P1;
	
END mypack;
/

--SELECT mypack.F1(20) FROM DUAL;
--EXEC mypack.P1(21);

DECLARE
	D number;
BEGIN
	D := mypack.F1(21);
	DBMS_OUTPUT.PUT_LINE(D);
	mypack.P1(20);
END;
/