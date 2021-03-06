#!/bin/bash
#!/bin/bash
echo -e "\n---------------\n"
echo -e "\033[0;31m### TEST 0: push 1 2 3 ###\033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo -e "3\n2\n1"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0push123.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 1: push with spaces ###\033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo -e "3\n2\n1\n6\n5\n4\n3\n2\n1"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0pushpallspace.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 2: push with multiple args and blank lines ###\033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo -e "3\n2\n1\n6\n5\n4\n3\n2\n1"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0lotsOfargsAndBlankLines.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 3: push 1, push with no int arg ###\033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "L2: usage: push integer"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0missingArg.m
echo -e "\n---------------\n"

echo -e "\033[0;31m### TEST 4: push 1, push 2, pu 3 ###\033[0;37m"
echo -e "\033[0;31m# 0unknownInstr.m  #\033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "L3: unknown instruction pu"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0unknownInstr.m 
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 5: push 0, push 1, push 2 ###\033[0;37m"
echo -e "\033[0;31m 0push0.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo -e "2\n1\n0"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0push0.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 6: blanklines ###\033[0;37m"
echo -e "\033[0;31m 0nothing.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0nothing.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 7: pint ###\033[0;37m"
echo -e "\033[0;31m 1pint.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo -e "1\n2\n3"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 1pint.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 8: pop ###\033[0;37m"
echo -e "\033[0;31m 2pop.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo -e "3\n2\n1\n2\n1\n1"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 2pop.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 9: push 24abc ###\033[0;37m"
echo -e "\033[0;31m 0push24abc.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "L1: usage: push integer"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0push24abc.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 10: push 1 pall 67 ###\033[0;37m"
echo -e "\033[0;31m . \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "1"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0pall67.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 11: pusha ###\033[0;37m"
echo -e "\033[0;31m . \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "L1: unknown instruction pusha"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0pusha.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 12: more spaces ###\033[0;37m"
echo -e "\033[0;31m 0spaces.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "1"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0spaces.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 13: push  ###\033[0;37m"
echo -e "\033[0;31m 0push3.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "L4: usage: push integer"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0push3.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 14: push ###\033[0;37m"
echo -e "\033[0;31m 0push6.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "L6: usage: push integer"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 0push6.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 15: single pint ###\033[0;37m"
echo -e "\033[0;31m 1pintempty.m \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "L1: can't pint, stack empty"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 1pintempty.m
echo -e "---------------\n"

echo -e "\033[0;31m### TEST 16: pop stuff ###\033[0;37m"
echo -e "\033[0;31m . \033[0;37m"
echo -e "\033[0;34m>>>>> EXPECTED <<<<<\033[0;32m"
echo "1\n2\n3"
echo -e "\033[0;34m>>>>> GOT <<<<<\033[0;37m"
../monty 2pop3.m
echo -e "---------------\n"
