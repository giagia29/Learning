.global dotpF32
.global prodF64
.global minF64
.global int32ToFloat
.text

dotpF32:
    MOV R3, #0
    VMOV S0, R3

dotpF32_loop:
   	CMP R2, #0
    BEQ dotpF32_write
    VLDR S1, [R0]
    VLDR S2, [R1]
    VMUL.F32 S3, S1, S2
    VADD.F32 S0, S0, S3
    ADD R0, R0, #4
    ADD R1, R1, #4
    SUB R2, R2, #1
	B dotpF32_loop

dotpF32_write:
	BX LR




prodF64:
    PUSH {R4, R5}
    MOV R4, #0
    VMOV D0, R4, R4
    MOV R5, R0

prodF64_loop:
    CMP R3, #0
    BEQ prodF64_write
    VLDR D1, [R1]
    VLDR D2, [R2]
    VMUL.F64 D0, D1, D2
    VSTR D0, [R5]
    ADD R1, R1, #8
    ADD R2, R2, #8
    ADD R5, R5, #8
    SUB R3, R3, #1
    B prodF64_loop

prodF64_write:
    POP {R4, R5}
    BX LR




minF64:
    MOV R2, R0
    VLDR D0, [R0]

minF64_loop:
    CMP R1, #0
    BEQ minF64_write
    VLDR D1, [R2, #8]
    VCMP.F64 D1, D0
    VMRS APSR_nzcv, FPSCR
    VMOVMI S0, S2
    VMOVMI S1, S3
    SUB R1, R1, #1
    B minF64_loop

minF64_write:
	BX LR



int32ToFloat:
	VMOV S0, R0
	VCVT.F32.S32 S0, S0
	BX LR
