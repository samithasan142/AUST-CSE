TITLE   8086 Code Template (for EXE file)

;       AUTHOR          emu8086
;       DATE            ?
;       VERSION         1.00
;       FILE            ?.ASM

; Note: Set the delay to 100 ms in Emu 8086 and to 10 ms 
;       in I/O Emulation Kit to get best results for this sample
;       (i.e., the delay of I/O Emulation Kit is much smaller than
;        the delay of Emu8086).

; 8086 Code Template

; Directive to make EXE output:
       #MAKE_EXE#

DSEG    SEGMENT 'DATA'

; TODO: add your data here!!!!

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


	MOV DX, 2070h
	MOV AL, 01h

MAINLOOP:  

   ;R2+Y(ON)-G(ON)-Y(OFF)-R1(ON) 
    
	R2+Y(ON):
	    MOV AL, 0AH
	    OUT DX, AL
	    
	    MOV CX,0100H
        L0:LOOP L0
        
    G(ON):
	    MOV AL, 0EH
	    OUT DX, AL
	    
	    MOV CX,0100H
        L1:LOOP L1
        
    Y(OFF):
	    MOV AL, 0CH
	    OUT DX, AL
	    
	    MOV CX,0100H
        L2:LOOP L2
        
    R1(ON):
	    MOV AL, 0DH
	    OUT DX, AL
	    
	    MOV CX,0100H
        L3:LOOP L3
	
	JMP MAINLOOP
	

; return to operating system:
	RET
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point.

