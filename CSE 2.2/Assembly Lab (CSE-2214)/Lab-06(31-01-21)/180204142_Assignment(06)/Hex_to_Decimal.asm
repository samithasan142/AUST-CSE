 .MODEL SMALL
 .STACK 100H
 .DATA
   PROMPT     DB  'Enter a HEX digit 0-9 or A-F: $'
   DECIMAL    DB  'The equivalent Decimal digit is : $'
   CONT       DB  'If you want to do it again then press Y else press N : $'
   ILLEGAL    DB  'Illegal Character - Enter 0..9 or A..F : $'
   NEXT_LINE  DB  0DH,0AH,"$"
 
 .CODE
   MAIN PROC
     MOV AX, @DATA                
     MOV DS, AX

     START_1:                    
       MOV AH, 9                  
       LEA DX, PROMPT             
       INT 21H

     START_2:                    
       MOV AH, 1                  
       INT 21H

       MOV BL, AL                 

       CMP BL, "A"                
       JB SINGLE_DIGIT           ; jump to label if BL<A

       CMP BL, "F"                
       JA ILLEGAL_CHARACTER      ; jump to label if BL>F

       JMP GREATER_THAN_NINE     

     SINGLE_DIGIT:               
       CMP BL, "0"                
       JB ILLEGAL_CHARACTER      ; jump to label if BL<0

       CMP BL, "9"                
       JA ILLEGAL_CHARACTER      ; jump to label if BL>9

       JMP LESS_THAN_TEN         

     ILLEGAL_CHARACTER:          
       MOV AH, 9                  

       LEA DX, NEXT_LINE          
       INT 21H

       LEA DX, ILLEGAL            
       INT 21H

       JMP START_2               

     LESS_THAN_TEN:              
       MOV AH, 9                  

       LEA DX, NEXT_LINE          
       INT 21H

       LEA DX, DECIMAL            
       INT 21H

       MOV AH, 2                  ; print the contents of BL
       MOV DL, BL
       INT 21H

       JMP CONTINUE              

     GREATER_THAN_NINE:          
       MOV AH, 9                  

       LEA DX, NEXT_LINE          
       INT 21H

       LEA DX, DECIMAL            
       INT 21H

       MOV AH, 2                  ; display the digit 1
       MOV DL, 31H
       INT 21H

       SUB BL, 11H                ; subtract 11H from BL to find 2nd digit

       MOV DL, BL                 ; display the 2nd digit
       INT 21H

     CONTINUE:                   
       MOV AH, 9                  

       LEA DX, NEXT_LINE          
       INT 21H
       INT 21H

       LEA DX, CONT           
       INT 21H
 
       MOV AH, 1                  
       INT 21H


       CMP AL, "Y"                ; compare AL with "Y"
       JE JUMP                    ; jump to label if AL=Y

       JMP END                   

     JUMP:                       
       LEA DX, NEXT_LINE          
       MOV AH, 9
       INT 21H
       INT 21H

       JMP START_1               

     END:                        

     MOV AH, 4CH                  
     INT 21H
   MAIN ENDP
 END MAIN