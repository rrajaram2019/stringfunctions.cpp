# stringfunctions.cpp
Assignment 4
String Functions

EC327 Summer 2019

1 Introduction
1.1 Assignment Goals
1.2 Group Size
1.3 Due Date
1.4 Assignment Value
1.5 Late policy
1.6 Submission Link
2 Background on Bases
3 String Functions
3.1 Word Strings
3.2 Palindromic Number Strings
3.3 Adding big integers
3.4 Converting base representation.
3.5 Palindromic numbers in other bases
4 Further specifications
4.1 How main() works
4.2 Restrictions
5 Downloads
5.1 Template
5.2 Checker
1 Introduction
1.1 Assignment Goals
The assignment goals are to help you learn about

functions
indexing
representation of numbers and text
and to give more practice with iteration, conditions

1.2 Group Size
The maximum group size is 2 students.

1.3 Due Date
This assignment is due Thursday June 6th at 23:59 (i.e. 11:59pm) (extended by 2 days)

1.4 Assignment Value
This assignment is worth 10 points, with equal weighting to each of the 5 functions.

Style counts for 20% of the grade.

1.5 Late policy
Late assignments will be accepted until the beginning of the lecture immediately following the due date (lectures are Monday through Thursday mornings.)

If the natural grade on the assignment is 
g
, the number of hours late is 
h
, and the number of hours between the assignment due time and the next class is 
H
, the new grade will be

(h > H) ? 0 : g * (1- h/(2*H))
If the same assignment is submitted ontime and late, the grade for that component will be the maximum of the ontime submission grade and the scaled late submission grade.

1.6 Submission Link
You can submit here: stringfunctions submit link

2 Background on Bases
Every number, when written or represented in text, uses a base representation. For example, the number 255 means

2
×
10
2
+
5
×
10
1
+
5
×
10
0

because we are using base-10 representation.

When a number 
y
 is written in base 
n
 as

d
m
d
m
-
1
.
.
.
d
2
d
1
d
0

then 
y
 can be calculated as

y
=
i
=
m
?
i
=
0
 
d
i
n
i

and in addition, we restrict the values of the digits as follows:

The first digit satisfies 
0
<
d
m
<
n
 and all others have 
0
=
d
i
<
n

3 String Functions
This assignment has a different structure than the first two. Instead of writing main(), you will be provided main() and your task is to write functions to complete the required functionality. The functions calculate properties of strings or numbers as strings, and are described below.

The starting file is available on the website as stringfunctions_original.cpp

The submitted file must be called stringfunctions.cpp.

3.1 Word Strings
Write a function is_word with the following signature:

bool is_word(string s)
that returns true is s is a word, and false otherwise.

A word is defined as

only having the characters a-zA-Z and nothing else
all lowercase, capitalized or all uppercase (eg. test, Test, TEST)
at least one character long
3.2 Palindromic Number Strings
Write a function is_palindrome with the following signature:

bool is_palindrome(string num, bool * error)
that returns true if num is a palindromic number string in base 10, and false otherwise.

The function also must set the error condition *error, which should be true if num is not a valid positive integer.

So, if num contains any character other than 0-9 or if num contains leading zeros, *error should be true and false otherwise.

The number “0” should return true and *error as false.

3.3 Adding big integers
Write a function that adds two non-negative integers represented as strings, returning the result as a string.

The function must use the following signature:

string add(const string& num1, const string& num2)
The values num1 and num2 can represent arbitrarily long integers, so all the calculations must be done without using integer types (except for calculating each digit.)

There is no need to check for or deal with strings that do not represent non-negative integers.

3.4 Converting base representation.
Write a function convertbase which converts a number, represented as a string in one base, to a new string representing that number in a new base. You may assume that the number can be stored in an int without overflow.

string convertbase(const string& numstr, const int frombase, const int tobase)
The character to represent a digit with value digitvalue is the ASCII character digitvalue+'0'.

The values of frombase and tobase will always be in the range 2 to 200 inclusive.

3.5 Palindromic numbers in other bases
Write a function multibase which returns all the bases in which an integer is a palindrome.

Consider the number 21, which in base 10 is not a palindrome. However, if we write 21 in base 2, the result is 10101, which is a palindrome.

In base 4, 21 is written as 111.

In base 6, 21 is written as 33.

In base 20, 21 is written as 11.

Hence, the function multibase(21) returns the string “2 4 6 20” since these are the bases in which the number 21 is a palindrome.

Here is the function signature

string multibase(int x) 
The function multibase returns all the bases in which x is palindromic, from 2 to x-1 inclusive. Each palindromic base should be separated from the previous one by a space.

4 Further specifications
4.1 How main() works
The main() function provided runs a sequence of tests, and outputs to the standard error stream if it detects any problems.

The error messages are coded using the first letter of each function:

w for is_word()
p for is_palindrome()
a for add()
c for convertbase()
m for multibase()
It then goes into an interactive mode, waiting for one of the commands:

w for test is_word()
p for test is_palindrome()
a for test add()
c for test convertbase()
m for test multibase()
The program then reads in the parameters from cin and outputs the results to cout.

When a command other than wpacm is entered, the program quits.

4.2 Restrictions
In your submitted work (any of the functions you write) you should not print out anything to cout or cerr, and you should not use terminal input cin.

You may only include the libraries iostream and string. No other includes are permitted.

You may not make any modifications to main(). The checker will enforce this rule, and your submitted program will be evaluated using the original main().

Any modifications to main() will be ignored, and there will be penalty for this violation.

5 Downloads
5.1 Template
This is the starting file: stringfunctions_original.cpp

It runs tests on each of the five functions you need to complete for this assignment.

5.2 Checker
The checker is now complete and is available here:

stringfunctions_checker.py
Use it by typing

python stringfunctions_checker.py
in the directory that has your programs in it.
