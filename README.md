# Olympics-Datasets

## Purpose
The purpose of this assignment is for you to:
• Increase your proficiency in C programming, your dexterity with dynamic memory allocation
and your understanding of linked data structures, through programming a dictionary.
• Increase your understanding of how computational complexity can affect the performance of an
algorithm by conducting orderly experiments with your program and comparing the results of
your experimentation with theory.
• Increase your proficiency in using UNIX utilities.

## Background
A dictionary is an abstract data type that stores and supports lookup of key, value pairs. For example,
in a telephone directory, the (string) key is a person or company name, and the value is the phone
number. In a student record lookup, the key would be a student ID number and the value would be a
complex structure containing all the other information about the student.
A dictionary can be implemented in C using a number of underlying data structures. Any implementation
must support the operations: makedict a new dictionary; insert a new item (key, value
pair) into a dictionary; search for a key in the dictionary, and return the associated value. Most
dictionaries will also support the operation delete an item.

## Task
In this assignment, you will create a simplified UNIX Information Retrieval system, a search engine as a
concrete instance of a dictionary, and we’ll use it to look up information about Olympic athletes. You’ll
search how many medals an athlete won overall the competitions.
There are two stages in this project. In each stage you will code a dictionary in the C programming
language. A binary search tree will be the underlying data structure for both stages.
In this assignment the search keys are not guaranteed to be unique. In this assignment we use variants
of the binary search tree designed to handle duplicates, i.e. by either dividing nodes using <= >,
or by using < > and a linked list for items with same key. You will use a Makefile to direct the
compilation of two separate executable programs, one for Stage 1 and one for Stage 2, each of which
uses a different variant of the binary search tree.
In both stages of the assignment, you will insert records into the dictionary from a file. You will then
look up and output the records (data) contained by the dictionary, counting and outputting the number
of key comparisons used in the search.
1
You will report on the number of key comparisons used for search, compare the number of key comparisons
used by each stage, and analyse what would have been expected theoretically. The report
should cover each file used to initialize the dictionary.