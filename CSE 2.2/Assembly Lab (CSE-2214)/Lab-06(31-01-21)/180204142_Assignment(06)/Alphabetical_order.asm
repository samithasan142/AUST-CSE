.MODEL SMALL 
.STACK 100H 
.CODE   
.DATA 
msg1 DB 'Enter the first character : $' 
msg2 DB 0DH,0AH,'Enter the second character : $' 
msg3 DB 0DH,0AH,'The Letters in Alphabetical order is : $' 
 
MAIN PROC 
    MOV AX,@DATA 
    MOV DS,AX 
    
    MOV AH,9 
    LEA DX,msg1 
    INT 21H
     
    MOV AH,1 
    INT 21H 
    MOV BL,AL  
     
    MOV AH,9 
    LEA DX,msg2 
    INT 21H 
     
    MOV AH,1 
    INT 21H 
    MOV BH,AL      
     
    CMP BL,BH 
     
    JG NEXT_: 
     
    MOV CL,BL 
    MOV CH,BH 
    JMP NEXT_2: 
    NEXT_: 
     
    MOV CL,BH 
    MOV CH,BL 
    NEXT_2: 
     
    MOV AH,9 
    LEA DX,msg3 
    INT 21H 
 
    MOV AH,2 
    MOV DL,CL 
    INT 21H 
    
    MOV DL,CH 
    INT 21H  
    
    MOV AX,4C00H 
    INT 21H 
    MAIN ENDP 
END MAIN 