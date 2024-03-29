; x86_64 assembly program

section .text
bits 64
default rel

global dotproduct

dotproduct:
    push rbp            ; Function prologue
    mov rbp, rsp

    ; Initialize accumulator (result) to 0
    xorps xmm0, xmm0

    ; Load the length of the vectors into ecx
    mov ecx, dword [rdi]

dotproduct_loop:
    ; Compare loop counter with vector length
    cmp ecx, 0
    je dotproduct_end   ; If vector length is 0, exit loop

    ; Load A[i] into xmm1
    movss xmm4, dword [rbp + 32]


    ; Load B[i] into xmm2
    movss xmm4, dword [rbp + 40]


    ; Multiply A[i] by B[i] and accumulate the result
    mulss xmm1, xmm2
    addss xmm0, xmm1

    ; Decrement loop counter
    dec ecx
    jmp dotproduct_loop ; Jump to the beginning of the loop

dotproduct_end:
    pop rbp             ; Function epilogue
    ret
