convert: convert.c convertNum.c convertNum.h convertUsageHelp.c convertUsageHelp.h
	gcc -o convert --coverage convert.c convertNum.c convertUsageHelp.c

