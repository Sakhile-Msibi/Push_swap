##  Push_swap

The aim of this project is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Sorting instructions](#sorting-instructions)
* [Setup](#setup)
* [Concepts learned](#concepts-learned)

## General info
Push_swap is the third project that software engineering trainees do at WeThinkCode_. In this project you have to write two programs:

* Checker:
You have to write a program named checker, which will get as an argument the
stack a formatted as a list of integers. Checker will then wait and read instructions on the standard input, each instruction
will be followed by ’\n’. Once all the instructions have been read, checker will
execute them on the stack received as an argument. If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" followed by a ’\n’ on the standard output. In every
other case, checker must display "KO" followed by a ’\n’ on the standard output.

* Push_swap:
You have to write a program named push_swap which will receive as an argument
the stack a formatted as a list of integers. The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top. Instructions must be separaed by a ’\n’ and nothing else. 

## Technologies
Technologies are used in this project are C programming language and vim as a text editor.

## Sorting instructions

These are the only "actions" allowed to sort the stack.

| Code | Instruction | Action |
| --- | --- | --- |
| sa   | swap a     |  swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.    |
| sb   | swap b     |  Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.    |
| ss   | swap a and swap b     | sa and sb at the same time.    |
| pa   | push a     | Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.   |
| pb   | push b     | Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.    |
| ra   | rotate a     | Shift up all elements of stack a by 1. The first element becomes the last one.    |
| rb   | rotate b     | Shift up all elements of stack b by 1. The first element becomes the last one.    |
| rr   | rotate a and rotate a     | ra and rb at the same time.    |
| rra   | reverse rotate a     | Shift down all elements of stack a by 1. The last element becomes the first one.    |
| rrb   | reverse rotate b     | Shift down all elements of stack b by 1. The last element becomes the first one.    |
| rrr   | reverse rotate a and reverse rotate b     |  rra and rrb at the same time.   |

## Setup
To run this project, install it locally
```
$ git clone https://github.com/Sakhile-Msibi/Push_swap
$ cd Push_swap
$ make
$ ./checker <NUMBERS>
$ ./push_swap <NUMBERS>
$ ./push_swap <NUMBERS> | ./checker <NUMBERS>
```

## Concepts learned
* Makefiles: To make a makefile compile another makefile.
* Link lists (Double link list).
* Sorting algorithms (Quick sort algorithm).
