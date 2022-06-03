.MODEL SMALL
.STACK 100H
.DATA
A DB 'ENTER FIRST NUMBER:$'
B DB 'ENTER SECOND NUMBER:$'
C DB 'THE SUM IS:$'
 
.CODE
MAIN PROC
    ;INITIALIZE DS
    MOV AX,@DATA
    MOV DS,AX
    
    ;FIRST MESSAGE
    MOV AH,9
    LEA DX,A
    INT 21H
    
    ;NEW LINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    ;FIRST INPUT
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    ;NEW LINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    ;SECOND MESSAGE
    MOV AH,9
    LEA DX,B
    INT 21H
    
    ;NEW LINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    ;SECOND INPUT
    MOV AH,1
    INT 21H
    MOV BH,AL 
    
    ;NEW LINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    ;THIRD MESSAGE
    MOV AH,9
    LEA DX,C
    INT 21H
    
    ;NEW LINE
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H 
    
    ;CALCULATION AND DISPLAY
    ADD BL,BH
    SUB BL,48
    MOV DL,BL
    INT 21H
    
    ;RETURN
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
    
      
    