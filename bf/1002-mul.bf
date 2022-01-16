,------------------------------------------------	; input saved in cell 0
>							; move pointer to cell 1
,------------------------------------------------	; input saved in cell 1
<							; move pointer to cell 0
[							; start loop
	>[						; moves to cell 1 and starts loop
		->+>+<<					; sub 1 to cell 1, add 1 to cells 2 and 3
	]						; end loop
	>>						; move pointer to cell 3
	[						; start loop
		-<<+>>					; sub 1 to cell 3 and add 1 to cell 1
	]						; end loop
	<<<-						; move pointer to cell 0
]							; end loop
>>							; move pointer to cell 2
++++++++++++++++++++++++++++++++++++++++++++++++.	; print result
