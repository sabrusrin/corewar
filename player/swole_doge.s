.name "swole_doge"
.comment "you'll never see where the muscles are"

		ld %2, r2
		ld %47, r3
l2:		sti r2, r2, r3
		add r2, r3, r2
		and r1, %0, r5

live:	live %1
		zjmp %:l2
