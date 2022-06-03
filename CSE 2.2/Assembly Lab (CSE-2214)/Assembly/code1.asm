.MODEL SMALL
.STACK 100H  
.DATA   

    NUM1 DB ?
    NUM2 DB 5
    
.CODE  

MAIN PROC
    MOV BH,4
    MOV BL,5
    ADD BH,10
    
    MOV AH,4CH
    INT 21H
MAIN ENDP
END MAIN
    
    