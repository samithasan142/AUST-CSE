.MODEL SMALL
.STACK 100H
.DATA
CR EQU 0DH
LF EQU 0AH
MSG1 DB 'ENTER A UPPERCASE LETTER:$'
MSG2 DB 0DH,0AH,'IN LOWERCASE IT IS:'
CHAR DB ?,'$'

.CODE
MAIN PROC
    ;INITIALIZE DS
    MOV AX,@DATA
    MOV DS,AX
    
    ;PRINT USER PROMPT
    LEA DX,MSG1
    MOV AH,9
    INT 21H
    
    ;INPUT A CHARACTER AND CONVERT TO LOWERCASE
    MOV AH,1
    INT 21H
    ADD AL,20H
    MOV CHAR,AL
    
    ;DISPLAY ON THE NEXT LINE
    LEA DX,MSG2
    MOV AH,9
    INT 21H
    
    ;DOS EXIT
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN