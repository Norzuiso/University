;
; Practica8.asm
;
; Created: 6/9/2021 6:07:30 PM
; Author : josue
;


; Replace with your application code

.CSEG
.ORG 0


start:
    LDI R16, 0xFF
	OUT DDRB, R16

	OUT DDRB, R16
	LDI R16, 0B00000001
	OUT PORTB, R16

RESTART:
	LDI R20, 0B00000000

COUNTER:
	OUT PORTB, R20
	INC R20
	LDI R17, 0B00100001
	CP R20, R17
	BRNE COUNTER
	RJMP RESTART

    rjmp start
