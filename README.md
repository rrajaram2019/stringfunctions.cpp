3.1 Word Strings
Write a function is_word with the following signature:

bool is_word(string s)
that returns true is s is a word, and false otherwise.

A word is defined as

only having the characters a-zA-Z and nothing else,
 all lowercase, capitalized or all uppercase (eg. test, Test, TEST),
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

3.4 Converting base representation

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
