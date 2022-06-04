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
    	
    	
       ;C4-R1-R3
       
    	MOV DX, 2004h         ;C4
    	MOV AL, 0FFh
    	OUT DX, AL
    	
    	MOV CX,0100H
        L1:LOOP L1 
        
        
        
        MOV DX, 2000h         ;R1
        MOV AL, 00000010b
        OUT DX, AL
        
        MOV DX, 2001h
        MOV AL, 00000010b
        OUT DX, AL
        
        MOV DX, 2002h
        MOV AL, 00000010b
        OUT DX, AL
        
        MOV DX, 2003h
        MOV AL, 00000010b
        OUT DX, AL
        
        MOV CX,0100H
        L2:LOOP L2  
        
        
        
        MOV DX, 2000h         ;R3
        MOV AL, 00001010b
        OUT DX, AL
        
        MOV DX, 2001h
        MOV AL, 00001010b
        OUT DX, AL
        
        MOV DX, 2002h
        MOV AL, 00001010b
        OUT DX, AL
        
        MOV DX, 2003h
        MOV AL, 00001010b
        OUT DX, AL
        



; return to operating system:
    RET
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point.

