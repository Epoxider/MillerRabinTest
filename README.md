# HOMEWORK 4
# Matthew Fritz
# matthew.fritz@wsu.edu

PROBLEM 1:
    Program takes 3 integers: a, b, m and prints out the result of: a^b mod m. 
PROBLEM 2:
    Program takes 2 integer: n, a/s. The "-n" flag tells the program the input "n" is the number you want to check for primality. For the second input, if given flag "-a" it will specify a possible witness a to test using the Witness procedure.
    If given flag "-s" it will specify a number s of random witnesses for the Miller–Rabin test to check.

TO COMPILE PROBLEM 1:
    make fastexpo
TO COMPILE PROBLEM 2:
    make mill
TO CLEAN:
    make clean

TO RUN PROBLEM 1:
    ./fastexpo input1 input2 input3
TO RUN PROBELM 2:
    ./mill -n input1 -a/s input2

