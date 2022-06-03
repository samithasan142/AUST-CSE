.MODEL SMALL
.STACK 100H  
.DATA     
.CODE  

MAIN PROC   
      
    ;overflow happens when  a number cannot be represented        
    
    ; + + = -    
        ; 0101 0000
        ; 0010 0010  (+)
        ; 1000 0010
        
    ; - - = +
    ;OF=1 
    MOV cl,-127 ;2^7= -128 - +127
    ADD cl,-2
    
    MOV AH,4CH
    INT 21H   
    
MAIN ENDP
END MAIN
    
    