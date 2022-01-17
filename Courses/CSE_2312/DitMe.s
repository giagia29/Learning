.global add32
.global minU16
.global minS32
.global isLessThanU16
.global isLessThanS16
.global shiftLeftU16
.global shiftU32
.global isEqualU16
.text

add32:
        ADDS R0, R0, R1
        MOV R1, #0
        ADC R1, R1, #0
        BX LR
minU16:
        CMP R0, R1
        MOVMI R0, R0
        BX LR
minS32:
		CMP R0, R1
		MOVPL R0, R1
		MOVMI R0, R0
		BX LR

isLessThanU16:
        CMP R0, R1
        MOVGT R0, #0
        MOVLE R0, #1
        BX LR

isLessThanS16:
        CMP R0, R1
        MOVGE R0, #0
        MOVLT R0, #1
        BX LR

isEqualU32:
		CMP R0, R1
		MOVEQ R0, #1
		MOVNE R0, #0
		BX LR

shiftLeftU16:
		MOV R0, R0, LSL R1
		BX LR

shiftU32:
		CMP R1, #0
		MOVMI R0, R0, LSR R1
		MOV R0, R0, LSL R1
		BX LR

isEqualU16:
		CMP R0, R1
		MOVEQ R0, #1
		MOVNE R0, #0
		BX LR