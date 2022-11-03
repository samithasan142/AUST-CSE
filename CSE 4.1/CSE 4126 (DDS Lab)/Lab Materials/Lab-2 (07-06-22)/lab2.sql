SET VERIFY OFF;
SET SERVEROUTPUT ON;
DECLARE
	A varchar2(20) := &Enter_my_name;
	B varchar2(20) := &Enter_address;
		
BEGIN
	DBMS_OUTPUT.PUT_LINE(A || ' ' || B);
END;
/
/*
DECLARE
	NUM money.id%TYPE := 0;
	
BEGIN
  select count(id) into NUM from money;
  
  FOR i IN 1..5 LOOP
	NUM := NUM + 1;
	insert into money values (NUM, 'D', 300);
  END LOOP;
END;
/


DECLARE
	NUM int := 5;
	
BEGIN
  FOR i IN 1..NUM LOOP
	DBMS_OUTPUT.PUT_LINE(i);
  END LOOP;
END;
/

DECLARE
	NUM int := 0;
	
BEGIN
  WHILE NUM < 5
	LOOP
		NUM := NUM + 1;
		DBMS_OUTPUT.PUT_LINE(NUM);
	END LOOP;
END;
/

DECLARE
	NUM int := 0;
	
BEGIN
	LOOP
		NUM := NUM + 1;
		DBMS_OUTPUT.PUT_LINE(NUM);
		EXIT WHEN NUM = 5;
	END LOOP;
END;
/

DECLARE
	NUM money.taka%TYPE;
BEGIN
	select taka into NUM from money where id = 1;
	CASE MOD(NUM, 3)
		WHEN 0 THEN
			DBMS_OUTPUT.PUT_LINE('ZERO');
		
		WHEN 1 THEN
			DBMS_OUTPUT.PUT_LINE('ONE');
		ELSE
			DBMS_OUTPUT.PUT_LINE('TWO');
	END CASE;
		
END;
/


DECLARE
	NUM money.taka%TYPE;
BEGIN
	select taka into NUM from money where id = 1;
	CASE
		WHEN MOD(NUM, 3) = 0 THEN
			DBMS_OUTPUT.PUT_LINE('ZERO');
		
		WHEN MOD(NUM, 3) = 1 THEN
			DBMS_OUTPUT.PUT_LINE('ONE');
		ELSE
			DBMS_OUTPUT.PUT_LINE('TWO');
	END CASE;
		
END;
/

DECLARE
	NUM money.taka%TYPE;
BEGIN
	select taka into NUM from money where id = 1;
	IF MOD(NUM, 3) = 0 THEN
		DBMS_OUTPUT.PUT_LINE('ZERO');
	ELSIF MOD(NUM, 3) = 1 THEN
		DBMS_OUTPUT.PUT_LINE('ONE');
	ELSE
		DBMS_OUTPUT.PUT_LINE('TWO');
	END IF;
END;
/

BEGIN
		DBMS_OUTPUT.PUT_LINE(NUM);
END;
/


DECLARE
	t_name money.name%TYPE;
	t_taka money.taka%TYPE := 700;
BEGIN
	--t_taka := 500;
	update money set taka = t_taka where id = 1;
	--DBMS_OUTPUT.PUT_LINE(t_name);
	DBMS_OUTPUT.PUT_LINE(t_taka);
END;
/
commit;

DECLARE
	t_name money.name%TYPE;
	t_taka money.taka%TYPE;
BEGIN
	SELECT name, taka into t_name, t_taka FROM money where id = 1;
	DBMS_OUTPUT.PUT_LINE(t_name);
	DBMS_OUTPUT.PUT_LINE(t_taka);
END;
/
*/
/*
BEGIN
	DBMS_OUTPUT.PUT_LINE('HELLO WORLD');

END;
/

BEGIN
	NULL;
END;
/

BEGIN
	insert into money values(4,'D',500);
END;
/

DECLARE
	t_name  varchar2(20);
	t_taka number;
BEGIN
	SELECT name, taka into t_name, t_taka FROM money where id = 1;
	DBMS_OUTPUT.PUT_LINE(t_name);
	DBMS_OUTPUT.PUT_LINE(t_taka);
END;
/
*/








