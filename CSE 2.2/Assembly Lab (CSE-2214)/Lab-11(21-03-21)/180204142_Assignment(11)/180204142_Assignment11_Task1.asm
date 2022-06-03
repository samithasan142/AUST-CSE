.MODEL SMALL
.STACK 100H     
.DATA
MSG1 DB 0AH,0DH,'Enter a string : ','$'     
MSG2 DB 0AH,0DH,'The forward string is : ','$'
MSG3 DB 0AH,0DH,'The backward string is : ','$'
PRINT_PALINDROME DB 0AH,0DH,'The string is palindrome$'
PRINT_NOT_PALINDROME DB 0AH,0DH,'The string is not palindrome$'

TEXT1 DB 100 DUP('$')
TEXT2 DB 100 DUP('$')

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX 
    MOV ES,AX
        
    CLD            ;clear direction flag
    
    MOV AH,9 
    LEA DX,MSG1
    INT 21H    
             
    XOR CX,CX 
    
    MOV AH,1
    
    
    LEA SI,TEXT1
    
    WHILE_: 
    INT 21H
    CMP AL,0DH
    JE END_WHILE
    
    CMP AL,33D
    JE WHILE_:
    
    CMP AL,34D
    JE WHILE_:
    
    CMP AL,39D
    JE WHILE_:
    
    CMP AL,' '
    JE WHILE_:
    
    CMP AL,44D
    JE WHILE_:
              
              
    CMP AL,45D
    JE WHILE_:
    
    CMP AL,46D
    JE WHILE_:
    
    CMP AL,58D
    JE WHILE_:
    
    
    CMP AL,59D
    JE WHILE_:
    
    
    CMP AL,95D
    JE WHILE_:
    
    CMP AL,96D
    JE WHILE_:                          
    
    PUSH AX
    INC CX
    MOV [SI], AL
    INC SI  
       
    JMP WHILE_
    
    END_WHILE:


    JCXZ EXIT       ; if CX register is 0
    
    LEA DI,TEXT2
    MOV BX,CX        
    
    MOV AH,2
    TOP:
    POP DX    
    MOV [DI],DL
    INC DI
    
    LOOP TOP

    MOV AH,9
    LEA DX,MSG2
    INT 21H   
    
    MOV AH,9
    LEA DX,TEXT1
    INT 21H           
    
    MOV AH,9
    LEA DX,MSG3
    INT 21H       
    
    MOV AH,9
    LEA DX,TEXT2
    INT 21H           
    
    CALL NEWLINE
            
    LEA SI,TEXT1
    LEA DI,TEXT2
    
    MOV CX,BX
    REPE CMPSW      ; repeat while equal compare string word
    
    JZ PALINDROME        
    
    MOV AH,9
    LEA DX,PRINT_NOT_PALINDROME
    INT 21H  
        
    JMP EXIT
    PALINDROME:
    
    MOV AH,9
    LEA DX,PRINT_PALINDROME
    INT 21H  
    
    EXIT:
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP       
    
    NEWLINE PROC
    
    PUSH AX
    PUSH DX
    
    MOV AH,2
    MOV DL,0DH
    INT 21H
            
    MOV DL,0AH
    INT 21H
    
    POP DX
    POP AX
    
    RET
    NEWLINE ENDP            
      
    
END MAIN 
 
