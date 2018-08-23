.name "chp_sti"
.comment "Le sti c'est la vie"

first:		sti r1, %100, %1
		sti r1, %100, %1
		sti r1, %-100, %-1
		sti r1, %-300, %-1
		sti r1, %-600, %-1
		sti r1, %300, %-1
		#sti r1, %600, %-1
		sti r1, %344, %1
		sti r1, %344, %2
		sti r1, 5, %0
		sti r1, 5, %1
		sti r1, 5, %2
		sti r1, 5, %3
		sti r1, 5, %-1
		sti r1, 5, %-2
		sti r1, -5, %1
		sti r1, -5, %1
		sti r1, -5, %2
		sti r1, 5, %2
		sti r1, %258, %1
		sti r1, 0, %0
		sti r1, %0, %1
		sti r1, %:first, %200
		sti r1, %:first, %200
