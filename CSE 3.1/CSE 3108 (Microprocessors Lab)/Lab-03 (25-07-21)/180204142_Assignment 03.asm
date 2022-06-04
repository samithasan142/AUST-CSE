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
 	
MAINLOOP:
 
        MOV DX, 2030h	   ; first seven segment display
	     
        MOV AL,00000110b   ; show 1
	    OUT DX, AL 
         
    	
    	MOV DX, 2070h
    	 
    		
    	MOV AL, 0AH        ;R2+Y(ON)
	    OUT DX, AL
	    
	    MOV CX,0100H
        L0:LOOP L0
        
    	     
    	
    	MOV DX, 2031h	   ; second seven segment display
	     
        MOV AL,01101101b   ; show S
	    OUT DX, AL
	     
        
        MOV DX, 2070h
         
        
    	MOV AL, 0EH        ; R2+Y(ON)-G(ON)
	    OUT DX, AL
	    
	    MOV CX,0100H
        L1:LOOP L1
    	
    	
    	   
        MOV DX, 2032h	   ; third seven segment display
	     
        MOV AL,01100110b   ; show 4
	    OUT DX, AL
	    
        
        MOV DX, 2070h
         
           
        MOV AL, 0CH        ; R2+Y(ON)-G(ON)-Y(OFF)
	    OUT DX, AL
	    
	    MOV CX,0100H
        L2:LOOP L2 
	    
	      
	    
	    MOV DX, 2033h	   ; forth seven segment display 
	     
        MOV AL,01111000b   ; show T
	    OUT DX, AL
	     
        
        MOV DX, 2070h
        
        
    	MOV AL, 0DH        ; R2+Y(ON)-G(ON)-Y(OFF)-R1(ON) 
	    OUT DX, AL
	    
	    MOV CX,0100H
        L3:LOOP L3
	    
	    
        
	    MOV DX, 2034h	   ; fifth seven segment display
	     
        MOV AL,01011011b   ; show 2
	    OUT DX, AL
	    
	    
; return to operating system:

	RET
	
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point