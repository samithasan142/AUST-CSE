INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA

ENCODE_KEY DB 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,
           DB 40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,'XQPOGHZBCADEIJWFMNKLRSTVUY',                                                     
           DB 91,92,93,94,95,96,'xqpoghzbcadeijwfmnklrstvuy',123,124,125,126,127,128
                                                      

CODED DB 80 DUP('$')

CRLF DB 0DH,0AH,'$'  
MSG DB "ENTER A MESSAGE:$"
MSG2 DB "OUTPUT MESSAGE:$"


.CODE
MAIN PROC     
    
    MOV AX,@DATA
    MOV DS,AX

     
    MOV AH,9
    LEA DX, MSG
    INT 21H
    
    MOV AH,2
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H 

    MOV AH,1
    LEA BX,ENCODE_KEY
    LEA DI,CODED
    
    LOOP_:
        INT 21H
        CMP AL,0DH
        JE END

        XLAT
        MOV [DI],AL
        INC DI
        JMP LOOP_  
        
    END:
    
   
    MOV AH,9
    LEA DX,CRLF
    INT 21H

    MOV AH,9
    LEA DX, MSG2
    INT 21H

    LEA DX,CODED
    INT 21H 
   

    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN