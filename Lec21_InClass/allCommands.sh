#!/bin/sh
make all
echo ' '
echo '***************Running testDateStr...******************'
valgrind --leak-check=full exe/./testDateStr > testDateStr.out
echo 'Writing to testDateStr.out...'
echo ' '
echo '***************Running testDataCla...******************'
valgrind --leak-check=full exe/./testDateCla > testDateCla.out
echo 'Writing to testDateCla.out'
echo ' '
echo '***************Running testBottleStr...******************'
valgrind --leak-check=full exe/./testBottleStr testBottle.txt > testBottleStr.out
echo 'Writing to testBottleStr.out...'
echo ' '
echo '***************Running testBottleCla...******************'
valgrind --leak-check=full exe/./testBottleStr testBottle.txt > testBottleStr.out
echo 'Writing to testBottleCla.out...'
echo ' '
echo '***************Running testQueueStr...******************'
valgrind --leak-check=full exe/./testQueueStr testRowDS.txt > testQueueStr.out
echo 'Writing to testBottleStr.out...'
echo ' '
echo '***************Running testQueueCla...******************'
valgrind --leak-check=full exe/./testQueueCla testRowDS.txt > testQueueCla.out
echo 'Writing to testBottleStr.out...'
echo ' '
echo '***************Running make clean******************'
make clean