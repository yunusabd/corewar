.name "Agent Smith"
.comment "Surprised to see me Mr. Anderson?"

			fork %:oracle

oracle:		live %42
			sti r1, %:oracle, %1
			sti r1, %:live, %1

random:		add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12
			add r10, r11, r12

live:		live %42
			fork %:oracle
			zjmp %511
