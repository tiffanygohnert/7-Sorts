###############################################################
# Program:
#     Week 11, Sorts
#     Brother JonesL, CS235
# Author:
#     John Vehikite, Tiffany Gohnert
# Summary:
#     Algorithms for seven different sorts.
# Time:
#     10 hrs
# Hardest Part:
#     We never completed Binary Sort in week 9, so that gave
#     us an issue this week. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week11.o
	g++ -o a.out week11.o -g
	tar -cf week11.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week11.o     : the driver program
##############################################################
week11.o: bnode.h bst.h stack.h week11.cpp sortValue.h \
		sortBinary.h sortInsertion.h sortHeap.h sortBubble.h \
		sortSelection.h sortMerge.h sortQuick.h
	g++ -c week11.cpp -g

