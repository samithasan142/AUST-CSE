 TITLE   8086 Code Template (for EXE file)

;       AUTHOR          emu8086
;       DATE            ?
;       VERSION         1.00
;       FILE            ?.ASM

; 8086 Code Template

; Directive to make EXE output:
       #MAKE_EXE#

DSEG    SEGMENT 'DATA'
     
DM  DB  49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H
    DB  49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H
    DB  49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H
    DB  72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H
    DB  01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H
    DB  01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H
    DB  7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H
    DB  01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH
    DB  01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H
    DB  08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H
    DB  7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H
    DB  0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH
    DB  0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH
    DB  08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH
    DB  31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H
    DB  49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H
    DB  49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H
    DB  49H, 46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H
    DB  46H, 40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H
    DB  40H, 40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H
    DB  40H, 7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H
    DB  7FH, 42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H
    DB  42H, 44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH
    DB  44H, 46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H
    DB  46H, 49H, 49H, 49H, 72H, 01H, 01H, 7FH, 01H, 01H, 08H, 7FH, 0AH, 0CH, 08H, 31H, 49H, 49H, 49H, 46H, 40H, 40H, 7FH, 42H, 44H
    
    
SSD DB 06H, 6DH, 66H, 78H, 5BH    
        
    
DSEG    ENDS

SSEG    SEGMENT STACK   'STACK'
        DW      100h    DUP(?)
SSEG    ENDS

CSEG    SEGMENT 'CODE'

;*******************************************

START   PROC    FAR

; Store return address to OS:
    PUSH    DS
    MOV     AX, 0
    PUSH    AX

; set segment registers:
	MOV     AX, DSEG
    MOV     DS, AX
    MOV     ES, AX
    
    ;1
	
    MOV DX, 2000H
    MOV AL, 00000100b
    OUT DX, AL           
              
    MOV DX, 2001H
    MOV AL, 00000010b
    OUT DX, AL  
    
    MOV DX, 2002H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2002H
    MOV AL, 00000011b
    OUT DX, AL
    
    MOV DX, 2030H         ; 1st Seven Segment Display
	MOV AL, 00000010b
	OUT DX, AL
               
    MOV DX, 2070H         ; 1st LED Display
	MOV AL, 01h
	OUT DX, AL 	              
    
    MOV DX, 2002H
    MOV AL, 00000111b
    OUT DX, AL
   
    MOV DX, 2002H
    MOV AL, 00001111b
    OUT DX, AL
    
    MOV DX, 2002H
    MOV AL, 00011111b
    OUT DX, AL 
    
    MOV DX, 2002H
    MOV AL, 00111111b
    OUT DX, AL
    
    MOV DX, 2030H         ; 1st Seven Segment Display
	MOV AL, 00000110b
	OUT DX, AL   
    
    MOV DX, 2000H
    MOV AL, 01000100b
    OUT DX, AL
    
    MOV DX, 2001H
    MOV AL, 01000010b
    OUT DX, AL
    
    MOV DX, 2002H
    MOV AL, 01111111b
    OUT DX, AL
    
    MOV DX, 2003H
    MOV AL, 01000000b
    OUT DX, AL
    
    MOV DX, 2004H
    MOV AL, 01000000b
    OUT DX, AL 
    
        
    ;S
        
    MOV DX, 2009H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2008H
    MOV AL, 00000001b
    OUT DX, AL
    
    MOV DX, 2007H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2031H
    MOV AL, 00000001b
    OUT DX, AL   
    
    MOV DX, 2006H
    MOV AL, 00000001b
    OUT DX, AL  
    
    MOV DX, 2005H
    MOV AL, 00000010b
    OUT DX, AL 
    
    MOV DX, 2031H
    MOV AL, 00100001b
    OUT DX, AL
    
    MOV DX, 2005H
    MOV AL, 00000110b
    OUT DX, AL 
    
    MOV DX, 2006H
    MOV AL, 00001001b
    OUT DX, AL
    
    MOV DX, 2031H
    MOV AL, 01100001b
    OUT DX, AL
    
    MOV DX, 2070H         
	MOV AL, 01h
	OUT DX, AL
              
    MOV DX, 2007H
    MOV AL, 00001001b
    OUT DX, AL
    
    MOV DX, 2008H
    MOV AL, 00001001b
    OUT DX, AL 
    
    MOV DX, 2031H
    MOV AL, 01100101b
    OUT DX, AL
    
    MOV DX, 2009H
    MOV AL, 00010001b
    OUT DX, AL 
    
    MOV DX, 2009H
    MOV AL, 00110001b
    OUT DX, AL  
    
    MOV DX, 2008H
    MOV AL, 01001001b
    OUT DX, AL
    
    MOV DX, 2031H
    MOV AL, 01101101b
    OUT DX, AL
    
    MOV DX, 2007H
    MOV AL, 01001001b
    OUT DX, AL
    
    MOV DX, 2006H
    MOV AL, 01001001b
    OUT DX, AL   
    
    MOV DX, 2005H
    MOV AL, 01000110b
    OUT DX, AL
    
    
    ;4
    
    MOV DX, 200DH
    MOV AL, 00000001b
    OUT DX, AL
    
    MOV DX, 200CH
    MOV AL, 00000010b
    OUT DX, AL
    
    MOV DX, 200BH
    MOV AL, 00000100b
    OUT DX, AL
    
    MOV DX, 2032H
    MOV AL, 00100000b
    OUT DX, AL      
              
    MOV DX, 200AH
    MOV AL, 00001000b
    OUT DX, AL
    
    MOV DX, 200BH
    MOV AL, 00001100b
    OUT DX, AL          
    
    MOV DX, 200CH
    MOV AL, 00001010b
    OUT DX, AL
    
    MOV DX, 2032H
    MOV AL, 01100000b
    OUT DX, AL
    
    MOV DX, 200DH
    MOV AL, 00001001b
    OUT DX, AL          
    
    MOV DX, 200EH
    MOV AL, 00001000b
    OUT DX, AL
    
    MOV DX, 200DH
    MOV AL, 00001011b
    OUT DX, AL
    
    MOV DX, 2032H
    MOV AL, 01100010b
    OUT DX, AL
    
    MOV DX, 2070H
    MOV AL, 05h
    OUT DX, AL          
    
    MOV DX, 200DH
    MOV AL, 00001111b
    OUT DX, AL
    
    MOV DX, 200DH
    MOV AL, 00011111b
    OUT DX, AL
    
    MOV DX, 200DH
    MOV AL, 00111111b
    OUT DX, AL
    
    MOV DX, 2032H
    MOV AL, 01100110b
    OUT DX, AL
    
    MOV DX, 200DH
    MOV AL, 01111111b
    OUT DX, AL
               
    
    ;T         
              
    MOV DX, 200FH
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2010H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2033H
    MOV AL, 00100000b
    OUT DX, AL
    
    MOV DX, 2011H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2012H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2033H
    MOV AL, 00110000b
    OUT DX, AL
    
    MOV DX, 2013H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2011H
    MOV AL, 00000011b
    OUT DX, AL
    
    MOV DX, 2033H
    MOV AL, 00111000b
    OUT DX, AL
    
    MOV DX, 2070H
    MOV AL, 0Dh
    OUT DX, AL
              
    MOV DX, 2011H
    MOV AL, 00000111b
    OUT DX, AL
    
    MOV DX, 2011H
    MOV AL, 00001111b
    OUT DX, AL 
    
    MOV DX, 2033H
    MOV AL, 01111000b
    OUT DX, AL
    
    MOV DX, 2011H
    MOV AL, 00011111b
    OUT DX, AL 
    
    MOV DX, 2011H
    MOV AL, 00111111b
    OUT DX, AL 
    
    MOV DX, 2011H
    MOV AL, 01111111b
    OUT DX, AL
    
    
    ;2
    
    MOV DX, 2014H
    MOV AL, 00000010b
    OUT DX, AL 
    
    MOV DX, 2015H
    MOV AL, 00000001b
    OUT DX, AL 
    
    MOV DX, 2016H
    MOV AL, 00000001b
    OUT DX, AL
              
    MOV DX, 2034H
    MOV AL, 00000001b
    OUT DX, AL
                        
    MOV DX, 2017H
    MOV AL, 00000001b
    OUT DX, AL
    
    MOV DX, 2018H
    MOV AL, 00000010b
    OUT DX, AL
    
    MOV DX, 2018H
    MOV AL, 00000110b
    OUT DX, AL 
    
    MOV DX, 2070H
    MOV AL, 0Dh
    OUT DX, AL                  
    
    MOV DX, 2034H
    MOV AL, 00000011b
    OUT DX, AL    
    
    MOV DX, 2017H
    MOV AL, 00001001b
    OUT DX, AL
    
    MOV DX, 2016H
    MOV AL, 00001001b
    OUT DX, AL
    
    MOV DX, 2015H
    MOV AL, 00001001b
    OUT DX, AL
    
    MOV DX, 2034H
    MOV AL, 01000011b
    OUT DX, AL    
              
    MOV DX, 2014H
    MOV AL, 00010010b
    OUT DX, AL 
    
    MOV DX, 2014H
    MOV AL, 00110010b
    OUT DX, AL     
    
    MOV DX, 2034H
    MOV AL, 01010011b
    OUT DX, AL
    
    MOV DX, 2014H
    MOV AL, 01110010b
    OUT DX, AL
    
    MOV DX, 2015H
    MOV AL, 01001001b
    OUT DX, AL 
    
    MOV DX, 2016H
    MOV AL, 01001001b
    OUT DX, AL
    
    MOV DX, 2034H
    MOV AL, 01011011b
    OUT DX, AL
    
    MOV DX, 2017H
    MOV AL, 01001001b
    OUT DX, AL 
    
    MOV DX, 2018H
    MOV AL, 01000110b
    OUT DX, AL
        
    
    
    MOV SI,5
    PUSH SI
    
        
    SLIDESHOW:   
        MOV BX,0
    
    MAINLOOP:
        MOV SI,0    
        MOV CX,25
        MOV DX,2018H
        
    ROTATE:
        MOV AL,DM[BX][SI]
        OUT DX,AL
        DEC DX
        INC SI
        
        CMP SI,25
        LOOPNE ROTATE 
        
        
        ADD BX,25
        CMP BX,625    
        JL MAINLOOP 
        
        MOV DX,2070H
        MOV AL,00H
        OUT DX,AL 
        
        MOV BX,0
        MOV DX,2030H
        
    SEVENSEGMENT:  
        MOV AL,00H
        OUT DX,AL
        INC DX
        
        ADD BX,1
        CMP BX,5
        JL SEVENSEGMENT
        
        MOV DX,2070H
        MOV AL,0DH
        OUT DX,AL   
        
        MOV BX,0
        MOV DX,2030H 
        
    SSD_LED_REPEAT:
      
        MOV AL,SSD[BX]
        OUT DX,AL
        INC DX
        
        ADD BX,1
        CMP BX,5
        JL SSD_LED_REPEAT
                  
          
        POP SI
        DEC SI
        PUSH SI
        CMP SI,0
        JNZ SLIDESHOW
        
     ;ALL SEGEMENTS CLEAR
       
     MOV AL,00H       
     MOV DX,2070H
     OUT DX,AL
     
     MOV CX,5
     MOV DX,2030H
     
     SSDZERO:
        MOV AL,00H
        OUT DX,AL
        
        INC DX
        DEC CX
        CMP CX,0
        JNZ SSDZERO  
        
     MOV CX,25
     MOV DX,2000H   
     
     DMZERO:
        MOV AL,00H
        OUT DX,AL
        
        INC DX
        DEC CX
        CMP CX,0
        JNZ DMZERO
    
; return to operating system:
    RET
    
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point