.global addU32_U64
.global addS64
.global convertS8ToS32
.global convertU16ToS32
.global maxS16


.text

addU32_U64:
	ADDS R0, R0, R2
	BX LR

addS64:
	ADDS R0, R0, R2
	ADC R1, R1, R3
	BX LR
convertS8ToS32:
	
convertU16ToS32:
	
maxS16:
	CMP R0, R1
	MOVGE R0
	BX LR

maxU32:
	CMP R0, R1
	MOVGT R0
	BX LR





