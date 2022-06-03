.MODEL SMALL
.STACK 100H 

.DATA
CR EQU 0DH
LF EQU 0AH

B EQU 5 
C DB 2

MSG1 DB "THE VALUE OF A IS: "
A DB ?, "$"

.CODE
MAIN PROC 
    
    ;INITIALIZING DS
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV BH,B
    SUB BH,C
    ADD BH,70 
    
    MOV AH,2 
    MOV DL,A
    INT 21H
    
    LEA DX,MSG1
    MOV AH,9
    INT 21H    
     
    
    ;RETURN STATEMENT
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN