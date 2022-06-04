TITLE   8086 Code Template (for EXE file)

;       AUTHOR          emu8086
;       DATE            ?
;       VERSION         1.00
;       FILE            ?.ASM

; 8086 Code Template

; Directive to make EXE output:
       #MAKE_EXE#

DSEG    SEGMENT 'DATA'
    
t1  DB  01H, 01H, 01H, 01H, 01H
t2  DB  03H, 07H, 0FH, 1FH, 3FH, 7FH    
    
a1  DB  40H, 60H, 70H, 78H, 7CH, 7EH
a2  DB  01H, 01H, 01H
a3  DB  02H, 06H, 0EH, 1EH, 3EH, 7EH
a4  DB  09H, 09H, 09H

s1  DB  02H, 01H, 01H, 01H, 02H                      
s2  DB  06H, 09H, 09H, 09H, 12H
s3  DB  32H, 49H, 49H, 49H, 26H

n1  DB  40H, 60H, 70H, 78H, 7CH, 7EH, 7FH
n2  DB  02H, 04H, 08H
n3  DB  40H, 60H, 70H, 78H, 7CH, 7EH, 7FH 

i1  DB  01H, 01H, 01H
i2  DB  03H, 07H, 0FH, 1FH, 3FH
i3  DB  41H, 7FH, 41H

m1  DB  40H, 60H, 70H, 78H, 7CH, 7EH, 7FH
m2  DB  02H, 04H, 02H
m3  DB  01H, 03H, 07H, 0FH, 1FH, 3FH, 7FH 

u1  DB  01H, 03H, 07H, 0FH, 1FH, 3FH 
u2  DB  40H, 40H, 40H
u3  DB  20H, 30H, 38H, 3CH, 3EH, 3FH

l1  DB  01H, 03H, 07H, 0FH, 1FH, 3FH, 7FH   
l2  DB  40H, 40H, 40H, 40H


SSD1 DB 02H, 06H
SSD2 DB 20H, 60H, 62H, 66H
SSD3 DB 01H, 03H, 43H, 53H, 5BH 

DSEG    ENDS

SSEG    SEGMENT STACK   'STACK'
        DW      100h    DUP(?)
SSEG    ENDS

CSEG    SEGMENT 'CODE'

;*******************************************

START   PROC    FAR

; Store return address to OS:
    PUSH    DS
    MOV     AX, 0
    PUSH    AX

; set segment registers:
	MOV     AX, DSEG
    MOV     DS, AX
    MOV     ES, AX 
    
;DOT MATRIX:

 ;T
  
 MOV DX,2000H
 MOV CX,05H 
 
@T1:
	MOV AL,t1[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @T1
	    
 MOV DX,2002H
 MOV CX, 06h
 MOV SI, 0

@T2:
	MOV AL,t2[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @T2 
   
 ;A
   
 MOV DX,2005H
 MOV CX, 6
 MOV SI, 0

@A1:
	MOV AL,a1[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @A1

 MOV DX,2006H
 MOV CX,3
 MOV SI,0 
 
@A2:
	MOV AL,a2[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @A2
	    
 MOV DX,2009H
 MOV CX, 6
 MOV SI, 0	
	
@A3:
	MOV AL,a3[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @A3
	
 MOV DX,2006H
 MOV CX,3
 MOV SI,0 
 
@A4:
	MOV AL,a4[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @A4 
	
 ;S
 
 MOV DX,200EH
 MOV CX,5
 MOV SI,0 
 
@S1:
	MOV AL,s1[SI]
	OUT DX,AL
	INC SI
	DEC DX   
	LOOP @S1
	
 MOV DX,200AH
 MOV CX,5
 MOV SI,0 
 
@S2:
	MOV AL,s2[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @S2
	
 MOV DX,200EH
 MOV CX,5
 MOV SI,0 
 
@S3:
	MOV AL,s3[SI]
	OUT DX,AL
	INC SI
	DEC DX   
	LOOP @S3
	  
 ;N
 
 MOV DX,200FH
 MOV CX, 7
 MOV SI, 0

@N1:
	MOV AL,n1[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @N1
	
 MOV DX,2010H
 MOV CX,3
 MOV SI,0 
 
@N2:
	MOV AL,n2[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @N2	 
	
 MOV DX,2013H
 MOV CX, 7
 MOV SI, 0

@N3:
	MOV AL,n3[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @N3 		
   
;I
 
 MOV DX,2015H
 MOV CX,3
 MOV SI,0 
 
@I1:
	MOV AL,i1[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @I1
	
 MOV DX,2016H
 MOV CX,5
 MOV SI,0 
 
@I2:
	MOV AL,i2[SI]
	OUT DX,AL
	INC SI   
	LOOP @I2 
	
 MOV DX,2015H
 MOV CX,3
 MOV SI,0 
 
@I3:
	MOV AL,i3[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @I3 
	
 ;M
 	
 MOV DX,2019H
 MOV CX, 7
 MOV SI, 0

 @M1:
	MOV AL,m1[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @M1 
	
 MOV DX,201AH
 MOV CX,3
 MOV SI,0 
 
 @M2:
	MOV AL,m2[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @M2	
	
		
 MOV DX,201DH
 MOV CX, 7
 MOV SI, 0

 @M3:
	MOV AL,m3[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @M3
	
 ;U
	         
 MOV DX,201EH
 MOV CX, 6
 MOV SI, 0	
	
@U1:
	MOV AL,u1[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @U1
	
 MOV DX,201FH
 MOV CX,3
 MOV SI,0 
 
@U2:
	MOV AL,u2[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @U2
	
 MOV DX,2022H
 MOV CX, 6
 MOV SI, 0	
	
@U3:
	MOV AL,u3[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @U3
		
;L
	
 MOV DX,2023H
 MOV CX, 7
 MOV SI, 0

 @L1:
	MOV AL,l1[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @L1
	
 MOV DX,2024H
 MOV CX,4
 MOV SI,0 
 
 @L2:
	MOV AL,l2[SI]
	OUT DX,AL
	INC SI
	INC DX   
	LOOP @L2		
	
	
;SSD

 ;1

 MOV DX,2030H
 MOV CX, 2
 MOV SI, 0

@SS1:
	MOV AL,SSD1[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @SS1  
	
 ;4
 	
 MOV DX,2031H
 MOV CX, 4
 MOV SI, 0

@SS2:
	MOV AL,SSD2[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @SS2
	 
 ;
 
 MOV DX,2032H
 MOV CX, 5
 MOV SI, 0

@SS3:
	MOV AL,SSD3[SI]
	OUT DX,AL
	INC SI 
	LOOPNE @SS3   	
	           
	
; return to operating system:
    RET
    
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point