,				; read char and store it in p1
------------------------------------------------ ; return ascii to Dec (p1 - 48)
>				; move pointer to p2 (second byte)
,				; read char and store it in p2
------------------------------------------------ ; return ascii to Dec (p2 - 48)
<				; move to p1
[				; enter loop
>+				; move to p2 increment p2
<-				; move to p1 decrement p1
]				; we exit the loop when p1 is 0
>				; go back to p2
+++++++++++++++++++++++++++++++++++++++++++++++++ ; return Dec to ascii (p1 + 49)
.				; print p2
