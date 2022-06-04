TITLE   8086 Code Template (for EXE file)

;       AUTHOR          emu8086
;       DATE            ?
;       VERSION         1.00
;       FILE            ?.ASM

; 8086 Code Template

; Directive to make EXE output:
       #MAKE_EXE#

DSEG    SEGMENT 'DATA'

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
    
;DOT MATRIX: 
   
    MOV DX, 2003H
    MOV AL, 00000001b
	OUT DX, AL
	
	MOV CX, 100H
    L1:LOOP L1
    
    
    MOV DX, 2003H	
	MOV AL, 00000011b
	OUT DX, AL 
	
	MOV CX, 100H
    L2:LOOP L2 
	   
	  
    MOV DX, 2003H
    MOV AL, 00000111b
    OUT DX, AL 
    
    MOV CX, 100H
    L3:LOOP L3 
               
    MOV DX, 2002H
    MOV AL, 00000100b
    OUT DX, AL
    
    MOV CX, 100H
    L4:LOOP L4            
               
    
    MOV DX, 2001H
    MOV AL, 00000100b
    OUT DX, AL
    
    MOV CX, 100H
    L5:LOOP L5 
    
    MOV DX, 2001H
    MOV AL, 00001100b
    OUT DX, AL
    
    MOV CX, 100H
    L6:LOOP L6 
    
    MOV DX, 2001H
    MOV AL, 00011100b
    OUT DX, AL
    
    MOV CX, 100H
    L7:LOOP L7 
    
    MOV DX, 2002H
    MOV AL, 00010100b
    OUT DX, AL
    
    MOV CX, 100H
    L8:LOOP L8
    
    MOV DX, 2003H
    MOV AL, 00010111b
    OUT DX, AL
    
    MOV CX, 100H
    L9:LOOP L9 
    
    
    MOV DX, 2003H
    MOV AL, 00110111b
    OUT DX, AL
    
    MOV CX, 100H
    L10:LOOP L10
    
    
    MOV DX, 2003H
    MOV AL, 01110111b
    OUT DX, AL
    
    MOV CX, 100H
    L11:LOOP L11
    
    
    MOV DX, 2004H
    MOV AL, 01000000b
    OUT DX, AL
    
    MOV CX, 100H
    L12:LOOP L12
    
    
    MOV DX, 2005H
    MOV AL, 01000000b
    OUT DX, AL
    
    MOV CX, 100H
    L13:LOOP L13
    
    
    MOV DX, 2005H
    MOV AL, 01100000b
    OUT DX, AL
    
    MOV CX, 100H
    L14:LOOP L14
    
    MOV DX, 2005H
    MOV AL, 01110000b
    OUT DX, AL
    
    MOV CX, 100H
    L15:LOOP L15 
    
    
    MOV DX, 2006H
    MOV AL, 00010000b
    OUT DX, AL
    
    MOV CX, 100H
    L16:LOOP L16
    
    
    MOV DX, 2007H
    MOV AL, 00010000b
    OUT DX, AL
    
    MOV CX, 100H
    L17:LOOP L17
    
    MOV DX, 2007H
    MOV AL, 00011000b
    OUT DX, AL
    
    MOV CX, 100H
    L18:LOOP L18
    
    MOV DX, 2007H
    MOV AL, 00011100b
    OUT DX, AL
    
    MOV CX, 100H
    L19:LOOP L19
    
    MOV DX, 2006H
    MOV AL, 00010100b
    OUT DX, AL
    
    MOV CX, 100H
    L20:LOOP L20 
    
    MOV DX, 2005H
    MOV AL, 01110100b
    OUT DX, AL
    
    MOV CX, 100H
    L21:LOOP L21 
    
    MOV DX, 2005H
    MOV AL, 01110110b
    OUT DX, AL
    
    MOV CX, 100H
    L22:LOOP L22
    
    MOV DX, 2005H
    MOV AL, 01110111b
    OUT DX, AL 
    
    MOV CX, 100H
    L23:LOOP L23
    
    MOV DX, 2004H
    MOV AL, 01000001b
    OUT DX, AL 
    
    MOV CX, 100H
    L24:LOOP L24
    
     
    
    
    MOV DX, 2030h	    ; 1st Seven Segment Display
	MOV AL, 01110011b
	OUT DX, AL
	
	MOV CX, 100H
    L25:LOOP L25     
	
	MOV DX, 2031h	    ; 2nd Seven Segment Display
	MOV AL, 01101101b
	OUT DX, AL  
	
	MOV CX, 100H
    L26:LOOP L26
    
; return to operating system:
    RET
    
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point