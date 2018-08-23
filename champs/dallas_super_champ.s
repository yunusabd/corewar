.name "dallas_super_champ"
.comment "we are the champignon my friend"

first:		sti r1, %100, %1
            sti r1, %:ok, r6
            sti r1, %:wok, r6
            ld 40, r6

wok:    live %54568
	st		r2, -6
	st		r2, -15
	st		r2, -24
	st		r2, -33
	st		r2, -42
	st		r2, -51
	st		r2, -60
	st		r2, -69
	st		r2, -78
	st		r2, -87
	st		r2, -96
 	st		r2, -105
	st		r2, -132
	st		r2, -141
	st		r2, -168
	st		r2, -177
	st		r2, -186
	st		r2, -195
	st		r2, -204
	st		r2, -213
	st		r2, -222
	st		r2, -231
	st		r2, -240
	st		r2, -249
	st		r2, -258
	st		r2, -267
	st		r2, -276
	st		r2, -285
	st		r2, -321
	st		r2, -330
	st		r2, -339
	st		r2, -348
	st		r2, -357
	st		r2, -366
	st		r2, -375
	st		r2, -378
	st		r2, -384
	st		r2, -393
	st		r2, -398
	st		r2, -402
	st		r2, -429
	st		r2, -433
	st		r2, -438
	st		r2, -447
	st		r2, -451
	st		r2, -456
	st		r2, -460
	st		r2, -465
	st		r2, -474
	st		r2, -483
	st		r2, -510
	st		r2, -515
	st		r2, -519
	st		r2, -510
	st		r2, -528
	st		r2, -531
	st		r2, -537
	st		r2, -546
	st		r2, -555
	st		r2, -564
	st		r2, -573
	st		r2, -582
	st		r2, -591
	st		r2, -600
	st		r2, -609
	st		r2, -618
    zjmp    %:wok

ok:         live %36346
            st  r1, 250
            zjmp %:first
fork1:
	live	%4
	fork	%:fork2
    fork    %:wok
	ld 		%0, r16

fork2:
	live	%4
    fork    %:wok
	zjmp	%:fork1
