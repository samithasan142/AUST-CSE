SET VERIFY OFF;
SET SERVEROUTPUT ON;

DECLARE
	A money.taka%type := &X;
	B money.taka%type := &X;
	C money.taka%type;
BEGIN 
	C := A+B;
	
	IF C < 170 THEN 
		INSERT INTO MONEY VALUES (7, 'A', C+10);
	ELSIF (C > 170 AND C < 210) THEN 
		INSERT INTO MONEY VALUES (7, 'B', C+30);
	ELSE 
		INSERT INTO MONEY VALUES (7, 'C', C);
	END IF;
END;
/
select * from money;
