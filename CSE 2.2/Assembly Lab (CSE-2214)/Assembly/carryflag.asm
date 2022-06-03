.MODEL SMALL
.STACK 100H  
.DATA     
.CODE  

MAIN PROC   
      
    MOV AH,2
    MOV CX,65535
    ADD CX,1
    
    MOV AH,4CH
    INT 21H   
    
MAIN ENDP
END MAIN
    
    