.MODEL SMALL
.STACK 100H
.CODE      
PRIME DW 2, 3, 5, 7, 11, 13, 17, 19, 23, 29
SUM DW ?

MAIN PROC
    
    while:  
    CALL INDEC
    CMP AX,11
    JGE while
    CMP AX,-11
    JLE while
    
    LEA SI,PRIME
    
    MOV CX,AX
    XOR AX,AX
    
    FOR:
   
    ADD AX,[SI]
    INC SI
    LOOP FOR  
    
    PUSH AX 
    
    MOV AH,2
    MOV DL,0DH
    INT 21H
    MOV DL,0AH
    INT 21H  
    
    POP AX
    CALL OUTDEC

    MOV AH,4CH
    INT 21H
    MAIN ENDP
    INCLUDE PGM9_1.ASM
    INCLUDE PGM9_3.ASM 
    END MAIN