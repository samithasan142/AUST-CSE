.MODEL SMALL
.STACK 100H
.DATA
    PROMPT_1   DB  'The Class Marks are as follows : ',0DH,0AH,'$'
    PROMPT_2   DB  0DH,0AH,'The Average Marks of Students are as follows : ',0DH,0AH,'$'

    AVERAGE  DW  4 DUP(0)
     CLASS   DB  'MARY ALLEN  ',67,45,98,33
             DB  'SCOTT BAYLIS',70,56,87,44
             DB  'GEORGE FRANK',82,72,89,40
             DB  'SAM WONG    ',78,76,92,60 

.CODE
   MAIN PROC
     MOV AX, @DATA                ; initialize DS
     MOV DS, AX

 
     LEA SI, CLASS                ; set SI=offset address of variable CLASS
     MOV BH, 4                    ; set BH=4
     MOV BL, 16                   ; set BL=16


     LEA DI, AVERAGE              ; set DI=offset address of variable AVERAGE
     LEA SI, CLASS                ; set SI=offset address of variable CLASS 
     ADD SI, 12                   ; set SI=SI+12
     MOV CX, 4                    ; set CX=4

     @COMPUTE_AVERAGE:            
       XOR AX, AX                 ; clear AX
       MOV DX, 4                  ; set DX=4

       @SUM:                      
         XOR BH, BH               ; clear BH
         MOV BL, [SI]             ; set BL=[SI]

         ADD AX, BX               ; set AX=AX+BX

         INC SI                   ; set SI=SI+1
         DEC DX                   ; set DX=DX-1
       JNZ @SUM                   ; jump to label @SUM if DX!=0

       MOV BX, 4                  ; set BX=4
       DIV BX                     ; set AX=DX:AX/BX , DX=DX:AX%BX

       MOV [DI], AX               ; set [DI]=AX
       ADD DI, 2                  ; set DI=DI+2
       ADD SI, 12                 ; set SI=SI+12
     LOOP @COMPUTE_AVERAGE        ; jump to label @COMPUTE_AVERAGE while CX!=0

     LEA DX, PROMPT_2             ; load and print the string PROMPT_2
     MOV AH, 9                     
     INT 21H

     LEA SI, AVERAGE              ; set SI=offset address of variable AVERAGE
     LEA DI, CLASS                ; set DI=offset address of variable CLASS
     MOV CX, 4                    ; set CX=4

     @PRINT_RESULT:              
       MOV BX, 12                 ; set BX=12
       MOV AH, 2                  ; set output function

       @NAME:                    
         MOV DL, [DI]             ; set DL=[DI]
         INT 21H                  ; print a character

         INC DI                   ; set DI=DI+1
         DEC BX                   ; set BX=BX-1
       JNZ @NAME                  ; jump to label @NAME if BX!=0

       MOV DL, 20H                ; set DL=20H
       INT 21H                    ; print a character

       MOV DL, ":"                ; set DL=":"
       INT 21H                    ; print a character

       MOV DL, 20H                ; set DL=20H
       INT 21H                    ; print a character

       XOR AH, AH                 ; clear AH
       MOV AL, [SI]               ; set AL=[SI]

       CALL OUTDEC                ; call the procedure OUTDEC

       MOV AH, 2                  ; set output function
       MOV DL, 0DH                ; carriage return
       INT 21H                    

       MOV DL, 0AH                ; line feed
       INT 21H

       ADD SI, 2                  ; set SI=SI+2
       ADD DI, 4                  ; set DI=DI+4
     LOOP @PRINT_RESULT           ; jump to label @PRINT_RESULT while CX!=0

     MOV AH, 4CH                  ; return control to DOS
     INT 21H
   MAIN ENDP


 ;OUTDEC Procedure
 OUTDEC PROC
   ; this procedure will display a decimal number
   ; input : AX
   ; output : none

   PUSH BX                        ; push BX onto the STACK
   PUSH CX                        ; push CX onto the STACK
   PUSH DX                        ; push DX onto the STACK

   XOR CX, CX                     ; clear CX
   MOV BX, 10                     ; set BX=10

   @OUTPUT:                       
     XOR DX, DX                   ; clear DX
     DIV BX                       ; divide AX by BX
     PUSH DX                      ; push DX onto the STACK
     INC CX                       ; increment CX
     OR AX, AX                    ; take OR of Ax with AX
   JNE @OUTPUT                    ; jump to label @OUTPUT if ZF=0

   MOV AH, 2                      ; set output function

   @DISPLAY:                      
     POP DX                       ; pop a value from STACK to DX
     OR DL, 30H                   ; convert decimal to ascii code
     INT 21H                      ; print a character
   LOOP @DISPLAY                  ; jump to label @DISPLAY if CX!=0

   POP DX                         ; pop a value from STACK into DX
   POP CX                         ; pop a value from STACK into CX
   POP BX                         ; pop a value from STACK into BX

   RET                            ; return control to the calling procedure
 OUTDEC ENDP
END MAIN