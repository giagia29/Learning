.global sumU16_32
.global sumS32
.global isStrSame
.global countInRange
.global strConcatenate
.global uint32ToBinaryString
.global rightStringFull
.global rightStringTrunc
.global decimalStringToUint16
.global decimalStringToInt8
.text


sumU16_32:
	MOV R2, R0
	MOV R0, #0

sumU16_32_loop:
	CMP R1, #0
	BEQ sumU16_32_write
	LDRH R3, [R2], #2
	ADD R0, R0, R3
	SUB R1, R1, #1
	B sumU16_32_loop

sumU16_32_write:
	BX LR


sumS32:
	MOV R2, R0
	MOV R0, #0

sumS32_loop:
	CMP R1, #0
	BEQ sumS32_write
	LDR R3, [R2], #4
	ADD R0, R0, R3
	SUB R1, R1, #1
	B sumS32_loop

sumS32_write:
	BX LR



isStrSame:
	PUSH {R4, R5}
	MOV R2, R0
	MOV R3, R1
	MOV R0, #0

isStrSame_loop:
	LDRSB R4, [R2], #1
	LDRSB R5, [R3], #1
	CMP R4, #0
	BNE isStrSame_next

isStrSame_next:
	CMP R4, R5
	BNE isStrSame_write
	MOV R0, #1
	BEQ isStrSame_loop

isStrSame_write:
	POP {R4, R5}
	BX LR



countInRange:
	PUSH {R4, R5}
	MOV R4, R0
	MOV R0, #0

countInRange_loop:
	CMP R3, #0
	BEQ countInRange_write
	LDR R5, [R4], #4
	SUB R3, R3, #1
	CMP R5, R1
	BLT countInRange_loop
	CMP R5, R2
	BGT countInRange_loop
	ADD R0, R0, #1
	B countInRange_loop
	
countInRange_write:
	POP {R4, R5}
	BX LR



strConcatenate:
	LDRSB R2, [R0], #1
	CMP R2, #0
	BNE strConcatenate
	SUB R0, R0, #1
	LDRSB R3, [R1], #1
	STRB R3, [R0], #1
	CMP R3, #0
	BNE strConcatenate
	MOV R3, #0
	STRB R3, [R0]
	BX LR



uint32ToBinaryString:
        MOV R2, #0x80000000

uint32ToBinaryString_loop:
        TST R1, R2
        MOVNE R3, #'1'
        MOVEQ R3, #'0'
        STRB R3, [R0]
        ADD R0, R0, #1
        MOVS R2, R2, LSR #1
        BNE uint32ToBinaryString_loop
        MOV R3, #0
        STRB R3, [R0]
        BX LR



rightStringFull:
	PUSH {R4, R5, R6, R7}
	MOV R4, #0
	MOV R7, #0
	MOV R6, R1

rightStringFull_loop:
	LDRSB R3, [R1], #1
	CMP R3, #0
	BNE rightstringlength
	CMP R4, R2
	BLT rightStringFull_first
	BGT rightStringFull_second

rightStringFull_first:
	STRB R7, [R0]
	B rightStringFull_write

rightStringFull_second:
	LDRSB R5, [R6, #1]
	STRB R5, [R0], #1
	ADD R6, R6, #1
	SUB R4, R4, #1
	CMP R4, #0
	BNE rightStringFull_second

rightstringlength:
	ADD R4, R4, #1
	B rightStringFull_loop

rightStringFull_write:
	POP {R4, R5, R6, R7}
	BX LR




rightStringTrunc:
        PUSH {R4, R5, R6, R7, R8}
        MOV R4, #0
        MOV R8, #0
        MOV R6, R1

rightStringTrunc_loop:
        LDRSB R3, [R1], #1
        CMP R3, #0
        BNE rightstringL
        CMP R4, R2
        BLT rightStringTrunc_first
        BGT rightStringTrunc_second

rightStringTrunc_first:
        LDRSB R7, [R6], #1
        STRB R7, [R0], #1
        SUB R4, R4, #1
        CMP R4, #0
        BNE rightStringTrunc_first
        STRB R8, [R0]
        B rightStringTrunc_write

rightStringTrunc_second:
        LDRSB R5, [R6, #1]
        STRB R5, [R0], #1
        ADD R6, R6, #1
        SUB R4, R4, #1
        CMP R4, #0
        BNE rightStringTrunc_second

rightstringL:
        ADD R4, R4, #1
        B rightStringTrunc_loop

rightStringTrunc_write:
        POP {R4, R5, R6, R7, R8}
        BX LR   



decimalStringToUint16:
	PUSH {R4, R5, R6, R7}
	MOV R1, R0
	MOV R0, #0
	MOV R4, R1
	MOV R6, #10
	MOV R3, #0
	MOV R7, #0

decimalStringToUint16_loop:
	LDRSB R2, [R1], #1
	CMP R2, #57
	BGT decimalStringToUint16_write
	CMP R2, #0
	BNE StringLength
	SUB R3, R3, #1
	B decimalStringToUint16_sum

StringLength:
	ADD R3, R3, #1
	B decimalStringToUint16_loop

decimalStringToUint16_sum:
	LDRSB R5, [R4], #1
	SUB R5, R5, #48
	ADD R0, R0, R5
	CMP R7, R3
	BEQ decimalStringToUint16_write
	BNE increment

increment:
	MUL R0, R0, R6
	ADD R7, R7, #1
	B decimalStringToUint16_sum

decimalStringToUint16_write:
	POP {R4, R5, R6, R7}
	BX LR



decimalStringToInt8:
        PUSH {R4, R5, R6, R7, R8, R9}
        MOV R1, R0
        MOV R0, #0
        MOV R4, R1
        MOV R6, #10
        MOV R3, #0
        MOV R7, #0
        MOV R8, #1
        MVN R9, #0

decimalStringToInt8_loop:
        LDRSB R2, [R1], #1
        CMP R2, #0
        BNE StringLength8
        SUB R3, R3, #1
        B decimalStringToInt8_sum

StringLength8:
        ADD R3, R3, #1
        B decimalStringToInt8_loop

decimalStringToInt8_sum:
        LDRSB R5, [R4], #1
        CMP R5, #45
        BEQ negative
        SUB R5, R5, #48
        ADD R0, R0, R5
        CMP R7, R3
        BEQ decimalStringToInt8_write
        BNE increment8

negative:
        LDRSB R5, [R4], #1
        SUB R5, R5, #48
        ADD R0, R0, R5
        CMP R8, R3
        BEQ negresult
        BNE incrementnegative

increment8:
        MUL R0, R0, R6
        ADD R7, R7, #1
        B decimalStringToInt8_sum

incrementnegative:
        MUL R0, R0, R6
        ADD R8, R8, #1
        B negative

negresult:
        MUL R0, R0, R9

decimalStringToInt8_write:
        POP {R4, R5, R6, R7, R8, R9}
        BX LR
