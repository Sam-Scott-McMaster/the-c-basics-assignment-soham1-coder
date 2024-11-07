convert: convert.c convertNum.c convertNum.h convertUsageHelp.c convertUsageHelp.h
	gcc -o --coverage convert convert.c convertNum.c convertUsageHelp.c

