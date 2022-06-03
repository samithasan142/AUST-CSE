.MODEL SMALL
.STACK 100H  
.DATA     
.CODE  

MAIN PROC   
      
    MOV cl,-3
    ADD cl,-2   
          
    ;when the result is negative SF=1
    ;when the result is positive SF=0
    
    MOV AH,4CH
    INT 21H   
    
MAIN ENDP
END MAIN
    
    