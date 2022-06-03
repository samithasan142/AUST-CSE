.MODEL SMALL
.STACK 100H  
.DATA     
.CODE  

MAIN PROC   
      
    MOV cl,00001111b
    ADD cl,00000001b  
    ;Auxilary Flag turns 1 when there is a carry bit from 4th to 5th position, AX=1
    
    MOV AH,4CH
    INT 21H   
    
MAIN ENDP
END MAIN
    
    