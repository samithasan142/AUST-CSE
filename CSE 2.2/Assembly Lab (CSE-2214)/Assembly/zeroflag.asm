.MODEL SMALL
.STACK 100H  
.DATA     
.CODE  

MAIN PROC   
      
    MOV cl,255
    ADD cl,1          
    
    ;in the result when last 8 bit is zero, zero flag turns on, ZF=1
    
    MOV cl,8
    SUB cl,8
    
    MOV AH,4CH
    INT 21H   
    
MAIN ENDP
END MAIN
    
    