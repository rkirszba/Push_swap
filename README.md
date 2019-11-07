# Push_swap
42 Project Push_swap

## Description
<img src="https://github.com/rkirszba/Push_swap/blob/master/media/Quick_sort.gif">

### Push_swap program
Push_swap program aims to sort a stack A, using another stack B and a limited instructions set. <br />
The goal is to sort the stack using as less instructions as possible. <br />
The following instructions are at our disposal : <br />
sa : swap a - swap the first 2 elements at the top of stack a <br />
sb : swap b - swap the first 2 elements at the top of stack b. <br />
ss : sa and sb at the same time. <br/>
pa : push a - take the first element at the top of b and put it at the top of a. <br />
pb : push b - take the first element at the top of a and put it at the top of b. <br />
ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one. <br />
rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one. <br />
rr : ra and rb at the same time. <br/>
rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one. <br/>
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one. <br />
rrr : rra and rrb at the same time.

### Checker program

Checker program excutes push_swap output instructions and, as indicated by its name, checks if the stack A is finally sorted.

## Solution

push_swap program is an implementation of quick sort algorithm : https://en.wikipedia.org/wiki/Quicksort

## Installation

Clone the repository and launch the ```make``` command 

## Run

### Without visualizer

```ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG```

The output of the program will be ```OK``` if the stack is sorted, otherwise it will be ```KO```

## Installation

```ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG```

The stack will sparkle if sorted, ortherwise it will turn black and white.

<img src="https://github.com/rkirszba/Push_swap/blob/master/media/Quick_sort.gif">

<img src="https://github.com/rkirszba/Push_swap/blob/master/media/Error.gif">



