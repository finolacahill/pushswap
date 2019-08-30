# **Push_swap**
_________________________________
Final grade 125/100

### The Challenge 
This project involves sorting data on two stacks, with a limited set of instructions, and the smallest number of moves. To make this happen, I had have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.
All data starts in stack A. We can push the top element between stack A and stack B, or vice versa, rotate and reverse rotate both stacks individually or together, and swap the first and second element of either or both stacks. In order to obtain full marks we needed to sort 5 integers in a maximum of 12 moves, 100 integers in under 700 moves, and 500 integers in under 5500 moves. For extra credit we could create a visualizer to demonstrate the sorting process. 

### Learning objectives 
This project enabled me to learn about complexity, big O notation and the basic sorting algorithms. Due to the fixed nature of the moves we were allowed to use, we could not use a simple merge sort, or quick sort, and instead had to use pieces of different algorithms, to create the most efficient sorting process possible. I used a mix of insertion sort, merge sort, and quick sort. 

### Usage
The *make* command will result in two executables: checker and pushswap. Run ```make```.

The **checker** program is used as follows:
```c
  ./checker 5 2 3 1 4
```
```c
  ./checker "-50 -400 -20 -1 -100"
```
```c
  ./checker "-22" "35" "40" "-15" "75"
```

The **push_swap** program is used in the same way
```c
  ./push_swap 5 2 3 1 4
```

You can run the two together using:
```c
  ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```

Checker reads the arguments, checks for errors and then prints the moves necessary to sort onto the stdout. Pushswap then reads the moves and executes them, printing "ok" if sorted and "ko" if not. 

The -h flag will launch usage instructions on either executable. 

The -v flag will launch the visualizer when used with the pushswap executible. (You need to have the SDL 2 framework installed and may need to edit the path to the framework in the Makefile)

The -c flag will tell you how many moves were made. 


Should there be any input error (a non-int as an argument, an incorrect instruction, a duplicate number), both programs will print "Error" to the stderror. 
You can find further details [here](https://github.com/finolacahill/pushswap/blob/master/push_swap.en.pdf).

