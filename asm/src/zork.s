.name		"helltrain"
.comment	"choo-choo, motherf*****s !"

entry:
	sti		r1, %:beegees_gen, %1
	

wall_prep:
	ld		%0, r2
	ld		%0, r16

wall:
	st		r2, -483
	st		r2, -492
	zjmp	%:wall

beegees_gen:
	live	%4239423
	fork	%:beegees_gen
	ld		%0, r16

cc_spawn:
	live	%4320423
	fork	%:cc_spawn

