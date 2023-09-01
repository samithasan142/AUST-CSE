SET SERVEROUTPUT ON;
SET VERIFY OFF;

ACCEPT P NUMBER PROMPT "Enter 1st number: "
ACCEPT Q NUMBER PROMPT "Enter 2nd number: "
ACCEPT R NUMBER PROMPT "Enter 3rd number: "
ACCEPT S NUMBER PROMPT "Enter 4th number: "

CREATE OR REPLACE FUNCTION maxx(P IN NUMBER, Q IN NUMBER, R IN NUMBER, S IN NUMBER)
RETURN NUMBER
IS

BEGIN
	IF P>Q AND P>R AND P>S THEN
		RETURN 1;
	ELSIF Q>P AND Q>R AND Q>S THEN
		RETURN 2;
	ELSIF R>P AND R>Q AND R>S THEN
		RETURN 3;
	ELSE
		RETURN 4;
	END IF;
	
END maxx;
/

CREATE OR REPLACE PROCEDURE printt(XY in NUMBER, n1 IN NUMBER, n2 IN NUMBER, n3 IN NUMBER, n4 IN NUMBER)
IS

BEGIN
	IF XY=1 THEN
		DBMS_OUTPUT.PUT_LINE('Maximum number is' || ' '||n1);
	ELSIF XY=2 THEN
		DBMS_OUTPUT.PUT_LINE('Maximum number is' || ' '||n2);
	ELSIF XY=3 THEN
		DBMS_OUTPUT.PUT_LINE('Maximum number is' || ' '||n3);
	ELSIF XY=4 THEN
		DBMS_OUTPUT.PUT_LINE('Maximum number is' || ' '||n4);
	END IF;
	
END printt;
/

DECLARE
	A NUMBER;
	B NUMBER;
	C NUMBER;
	D NUMBER;
	res NUMBER;
BEGIN
	A:=&P;
	B:=&Q;
	C:=&R;
	D:=&S;
	
	res := maxx(A,B,C,D);
	printt(res,A,B,C,D);
END;
/