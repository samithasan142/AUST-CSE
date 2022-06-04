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
  
MOV DX, 2004H     ; For S
MOV AL, 02H
OUT DX, AL

MOV DX, 2003H
MOV AL, 01H
OUT DX, AL

MOV DX, 2002H
MOV AL, 01H
OUT DX, AL

MOV DX, 2001H
MOV AL, 01H
OUT DX, AL

MOV DX, 2000H
MOV AL, 02H
OUT DX, AL

MOV DX, 2000H
MOV AL, 06H
OUT DX, AL

MOV DX, 2001H
MOV AL, 09H
OUT DX, AL

MOV DX, 2002H
MOV AL, 09H
OUT DX, AL

MOV DX, 2003H
MOV AL, 09H
OUT DX, AL

MOV DX, 2004H
MOV AL, 012H
OUT DX, AL

MOV DX, 2004H
MOV AL, 032H
OUT DX, AL

MOV DX, 2003H
MOV AL, 049H
OUT DX, AL

MOV DX, 2002H
MOV AL, 049H
OUT DX, AL

MOV DX, 2001H
MOV AL, 049H
OUT DX, AL

MOV DX, 2000H
MOV AL, 026H
OUT DX, AL



MOV DX, 2008H     ; For 4
MOV AL, 01H
OUT DX, AL

MOV DX, 2007H
MOV AL, 02H
OUT DX, AL

MOV DX, 2006H
MOV AL, 04H
OUT DX, AL

MOV DX, 2005H
MOV AL, 08H
OUT DX, AL

MOV DX, 2006H
MOV AL, 0CH
OUT DX, AL

MOV DX, 2007H
MOV AL, 0AH
OUT DX, AL

MOV DX, 2008H
MOV AL, 09H
OUT DX, AL

MOV DX, 2009H
MOV AL, 08H
OUT DX, AL

MOV DX, 2008H
MOV AL, 0BH
OUT DX, AL

MOV DX, 2008H
MOV AL, 0FH
OUT DX, AL

MOV DX, 2008H
MOV AL, 01FH
OUT DX, AL

MOV DX, 2008H
MOV AL, 03FH
OUT DX, AL

MOV DX, 2008H
MOV AL, 07FH
OUT DX, AL



	           
	
; return to operating system:
    RET
    
START   ENDP

;*******************************************

CSEG    ENDS 

        END    START    ; set entry point