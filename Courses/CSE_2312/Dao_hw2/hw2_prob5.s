.global addS64
.global addU32_U64
.global maxU32
.global isGreaterThanU16
.global isGreaterThanS16
.text

addS64:
        ADDS R0, R0, R2
        ADC R1, R1, R3  
        BX LR

addU32_U64:
        ADDS R0, R0, R1
        MOV R1, #0
        ADC R1, R1, #0
        BX LR

maxU32:
        CMP R0, R1
        MOVMI R0, R1
        BX LR
maxS16:
		CMP R0, R1
		MOVPL R0, R0
		MOVMI R0, R1
		BX LR

isGreaterThanU16:
        CMP R0, R1
        MOVGT R0, #1
        MOVLE R0, #0
        BX LR

isGreaterThanS16:
        CMP R0, R1
        MOVGE R0, #1
        MOVLT R0, #0
        BX LR

isEqualU16:
		CMP R0, R1
		MOVEQ R0, #1
		MOVNE R0, #0
		BX LR

