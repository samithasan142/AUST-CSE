SET SERVEROUTPUT ON;
SET VERIFY OFF;

ACCEPT X NUMBER PROMPT "Number of oranges: "
ACCEPT Y NUMBER PROMPT "Number of people: "

CREATE OR REPLACE FUNCTION div(n IN NUMBER,p in NUMBER)
RETURN NUMBER
IS

BEGIN
	IF MOD(n,p)=0 THEN
		return 1;
	ELSE
		return 0;
	END IF;
END div;
/

CREATE OR REPLACE PROCEDURE printt(XY in NUMBER)
IS

BEGIN
	IF XY=1 THEN
		DBMS_OUTPUT.PUT_LINE('Oranges divisible');
	ELSE 
		DBMS_OUTPUT.PUT_LINE('Oranges not divisible');
	END IF;
END printt;
/

DECLARE
	A NUMBER;
	B NUMBER;
	
BEGIN
	A:=&X;
	B:=&Y;
	printt(div(A,B));
END;
/