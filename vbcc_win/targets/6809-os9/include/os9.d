.ifndef	OS9_D
.set OS9_D,1

.set true,1
.set false,0

.macro os9 code
	swi2
	.byte	\code
.endm

.macro __os9funcs org
.set __os9offs,\org
.endm

.macro __os9skip cnt
.set __os9offs,__os9offs+\cnt
.endm

.macro __os9d nam
.set \nam,__os9offs
.set __os9offs,__os9offs+1
.endm


; System Service Request Code Definitions
__os9funcs	0
	__os9d	F$Link		;Link to Module
	__os9d	F$Load		;Load Module from File
	__os9d	F$UnLink	;Unlink Module
	__os9d	F$Fork		;Start New Process
	__os9d	F$Wait		;Wait for Child Process to Die
	__os9d	F$Chain		;Chain Process to New Module
	__os9d	F$Exit		;Terminate Process
	__os9d	F$Mem		;Set Memory Size
	__os9d	F$Send		;Send Signal to Process
	__os9d	F$Icpt		;Set Signal Intercept
	__os9d	F$Sleep		;Suspend Process
	__os9d	F$SSpd		;Suspend Process
	__os9d	F$ID		;Return Process ID
	__os9d	F$SPrior	;Set Process Priority
	__os9d	F$SSWI		;Set Software Interrupt
	__os9d	F$PErr		;Print Error
	__os9d	F$PrsNam	;Parse Pathlist Name
	__os9d	F$CmpNam	;Compare Two Names
	__os9d	F$SchBit	;Search Bit Map
	__os9d	F$AllBit	;Allocate in Bit Map
	__os9d	F$DelBit	;Deallocate in Bit Map
	__os9d	F$Time		;Get Current Time
	__os9d	F$STime		;Set Current Time
	__os9d	F$CRC		;Generate CRC ($17)
__os9skip	11
	__os9d	F$Debug		;Drop the system into the debugger

; NitrOS-9 common system calls
__os9funcs	39
	__os9d	F$VIRQ		;Install/Delete Virtual IRQ
	__os9d	F$SRqMem	;System Memory Request
	__os9d	F$SRtMem	;System Memory Return
	__os9d	F$IRQ		;Enter IRQ Polling Table
	__os9d	F$IOQu		;Enter I/O Queue
	__os9d	F$AProc		;Enter Active Process Queue
	__os9d	F$NProc		;Start Next Process
	__os9d	F$VModul	;Validate Module
	__os9d	F$Find64	;Find Process/Path Descriptor
	__os9d	F$All64		;Allocate Process/Path Descriptor
	__os9d	F$Ret64		;Return Process/Path Descriptor
	__os9d	F$SSvc		;Service Request Table Initialization
	__os9d	F$IODel		;Delete I/O Module

; I/O Service Request Code Definitions
__os9funcs	128
	__os9d	I$Attach	;Attach I/O Device
	__os9d	I$Detach	;Detach I/O Device
	__os9d	I$Dup		;Duplicate Path
	__os9d	I$Create	;Create New File
	__os9d	I$Open		;Open Existing File
	__os9d	I$MakDir	;Make Directory File
	__os9d	I$ChgDir	;Change Default Directory
	__os9d	I$Delete	;Delete File
	__os9d	I$Seek		;Change Current Position
	__os9d	I$Read		;Read Data
	__os9d	I$Write		;Write Data
	__os9d	I$ReadLn	;Read Line of ASCII Data
	__os9d	I$WritLn	;Write Line of ASCII Data
	__os9d	I$GetStt	;Get Path Status
	__os9d	I$SetStt	;Set Path Status
	__os9d	I$Close		;Close Path
	__os9d	I$DeletX	;Delete from current exec dir


; file modes and permissions
.set S_IFDIR,0x80
.set S_ISHARE,0x40
.set S_IOEXEC,0x20
.set S_IOWRITE,0x10
.set S_IOREAD,0x08
.set S_IEXEC,0x04
.set S_IWRITE,0x02
.set S_IREAD,0x01

; GetStt system calls
.set SS_OPT,0
.set SS_READY,1
.set SS_SIZE,2
.set SS_POS,5
.set SS_EOF,6

.endif	; OS9_D
