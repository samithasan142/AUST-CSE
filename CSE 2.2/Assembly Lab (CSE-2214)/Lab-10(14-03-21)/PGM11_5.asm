.MODEL SMALL 
.STACK 100H 
.DATA 
MSG1 DB 'ENTER SUBSTRING',0DH,0AH,'$' 
MSG2 DB 0DH,0AH,'ENTER MAINSTRING',0DH,0AH,'$' 
MAINST DB 80 DUP (0) 
SUBST DB 80 DUP (0) 
STOP DW ?
START DW ?
SUB_LEN DW ?
YESMSG DB 0DH,0AH,'SUBSTRING IS A SUBSTRING OF MAINSTSTRING $' 
NOMSG DB 0DH,0AH,'SUBSTRING IS NOT A SUBSTRING OF MAINSTRING $' 

.CODE 
MAIN PROC
    MOV AX,@DATA 
    MOV DS,AX
    MOV ES,AX
    ;prompt for SUBSTRING 
    MOV AH,9
    LEA DX,MSG1
    INT 21H
    ;read SUBSTRING
    LEA DI,SUBST
    CALL READ_STR
    MOV SUB_LEN,BX
    ;prompt for MAINSTRING
    LEA DX,MSG2
    INT 21H
    ;read MAINSTRING
    LEA DI,MAINST
    CALL READ_STR
    ;see if string null or SUBSTRING longer than MAINSTRING
    OR BX,BX
    JE NO
    CMP SUB_LEN,0
    JE NO
    CMP SUB_LEN,BX
    JG NO
    ;see if SUBSTRING is a substring of MAINSTRING
    LEA SI,SUBST
    LEA DI,MAINST
    CLD
    ;compute STOP
    MOV STOP,DI
    ADD STOP,BX
    MOV CX,SUB_LEN
    SUB STOP,CX
    ;initialize start
    MOV START,DI
    REPEAT:
    ;compare characters
    MOV CX,SUB_LEN
    MOV DI,START
    LEA SI,SUBST
    REPE CMPSB
    JE YES
    ;substring not found yet
    INC START
    ;see if start <= stop
    MOV AX,START
    CMP AX,STOP
    JNLE NO
    JMP REPEAT
    ;display results
    YES:
    LEA DX,YESMSG
    JMP DISPLAY
    NO:
    LEA DX,NOMSG
    DISPLAY:
    
    MOV AH,9  
    INT 21H
    ;DOS exit
    MOV AH,4CH
    INT 21H
    MAIN ENDP
INCLUDE PGM11_1.ASM
END MAIN             


