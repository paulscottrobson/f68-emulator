; ***********************************************************************************************************
;
; 										Simple assembly program.
;
;		Originally written by pweingar
;		Extended by Paul Robson
;
; ***********************************************************************************************************
;
;	To run me, make asample or f68.exe asample\sample.a68 and run with F5, press F1 when the command line appears
;

				org 	$10000

start:          									; start tells us where to run from, because of -exec=start in the command line.
				;
				; 		Write Hello world using the O/S
				;
				move.l #$13,d0                      ; sys_chan_write command #
                clr.l d1                            ; Channel #0 (the display)
                move.l #greet,d2                    ; Pointer to message
                move.l #greet_end-greet+1,d3        ; Length of message
                trap #15 							; handles system functions
                ;
                ;		Write Hello world by writing straight to text memory
                ;		do it 32 times from the screen top.
                ;
                lea.l 	$FECA0000,a0 				; screen text memory here
                move.w 	#32,d0 						; do it 32 times.
repeatmessage:  lea.l 	greet,a1 					; message here
copymessage:
				move.b 	(a1)+,(a0)+ 				; copy byte over.
				tst 	(a1) 						; is it zero.
				bne 	copymessage 				; do until trailing 0 found.
				dbne 	d0,repeatmessage 			; do it again !
				;
				; 		Exit the program.
				;
done:           clr.l d0                            ; sys_exit
                clr.l d1                            ; Return value = 0
                trap #15

greet:          dc.b "Hello, world!"
greet_end:      dc.b 0

