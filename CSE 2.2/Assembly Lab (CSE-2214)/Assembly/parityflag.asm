.MODEL SMALL
.STACK 100H  
.DATA     
.CODE  

MAIN PROC   
      
    MOV cl,01010101b
    ADD cl,10101010b  
    ;when the operation has even number is 1 PF=1
    ;when the operation has odd number of 1 PF=0
    ;value of carry flag isn't considered in PF
    
    MOV AH,4CH
    INT 21H   
    
MAIN ENDP
END MAIN
    
    