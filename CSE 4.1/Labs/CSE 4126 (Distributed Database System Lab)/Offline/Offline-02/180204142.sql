-- ID: 180204142
/*
Question :
Select the students from different majors who are eligible to vote (age must be greater than or equal to 21)
*/
clear screen;
SET VERIFY OFF;
SET SERVEROUTPUT ON;

DECLARE

x student.sname%TYPE;
y student.major%TYPE;
z student.age%TYPE;

cse VARCHAR2(10) := 'CSE';
me VARCHAR2(10) := 'ME';
eee VARCHAR2(10) := 'EEE';

BEGIN

	FOR dept IN(SELECT sname,major,age FROM student where age >= 21)

	LOOP
		IF dept.major='CSE' THEN
	
			DBMS_OUTPUT.PUT_LINE(dept.sname || '  ' || cse || '  ' || dept.age);
		
		ELSIF dept.major='ME' THEN

			DBMS_OUTPUT.PUT_LINE(dept.sname || '  ' || me || '  ' || dept.age);
		
		ELSE

			DBMS_OUTPUT.PUT_LINE(dept.sname || '  ' || eee || '  ' || dept.age);
		
		END IF;

	END LOOP;
END;
/  