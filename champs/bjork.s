.name "bjork"
.comment "I feel"
        ld  %7,r3
l2:     sti r1, %:live, %1
        and r1, %0, r1
live:   live %1
        zjmp %:live
