.MODEL SMALL 
.STACK 
.DATA 
STRING DB 80 DUP (0) 
CRLF DB 0DH,0AH,'$' 

.CODE 
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    MOV ES,AX
    ;read a string
    LEA DI,STRING
    CALL READ_STR
    ;go to a new line
    LEA DX,CRLF
    MOV AH,9
    INT 21H
    ;print string
    LEA SI,STRING
    MOV BX,10
    CALL DISP_STR
    ;dos exit
    MOV AH,4CH
    INT 21H
    MAIN ENDP
INCLUDE PGM11_1.ASM
INCLUDE PGM11_2.ASM
END MAIN