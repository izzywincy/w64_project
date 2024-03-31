section .text
bits 64
default rel
global dotproduct

dotproduct:

	MOV	R11, 0
	dotloop:
	MOVSS XMM1, dword[RDX+R11*4]
	MOVSS XMM2, dword[R8+R11*4]
	MULSS XMM1, XMM2
	ADDSS XMM0, XMM1
	INC R11
	CMP R11, R9
	JNE dotloop

	ret
