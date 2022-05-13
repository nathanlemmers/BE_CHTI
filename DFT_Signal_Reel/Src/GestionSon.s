	PRESERVE8
	THUMB 

	include DriverJeuLaser.inc
		
	import Son
	import LongueurSon
	import SortieSon
	import PWM_Set_Value_TIM3_Ch3
		
	export CallbackSon
	export StartSon
	


; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		
index dcd 0 
	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

CallbackSon proc
	push {r4, r5, r6, r7, r8, lr}	
	ldr r1, =LongueurSon 
	ldr r7, [r1]			;r7=LongueurSon
	ldr r2, =index			
	ldr r5, [r2]			;r5=index
	cmp r5, r7				;if r5<=r7 then
	ble ok
	
	;mov r5, #0				;else index=0
	;str r5, [r2]
	b fin
	
ok
	ldr r6, =Son			;then 
	ldrsh r0, [r6,r5, lsl 1]		;r0=Son[index]
			
	add r0, #32768			
	mov r8, #719					;ro=(ro+32768)*719/2^16
	mul r0, r8
	lsr r0, #16
	ldr r3, =SortieSon
	str r0, [r3]	;SortieSon=r0
	push{r2}
	bl PWM_Set_Value_TIM3_Ch3
	pop {r2}
	add r5, #1
	str r5, [r2]				;index++
fin
	pop {r4, r5, r6, r7, r8, lr}
	bx lr
	endp
	




StartSon proc
	mov r0, #0
	ldr r1, =index
	str r0, [r1]
	bx lr
	endp
	
		
	END	