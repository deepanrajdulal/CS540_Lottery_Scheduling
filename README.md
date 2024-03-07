# CS540_Lottery_Scheduling


CS540 Programming Assignment 2: Implementing a Lottery Scheduler

## Brief Description

This program is written in C++ and implements Lottery Scheduler. The implemented header are:

- iostream: Input/Output stream
- vector: vector class
- random: generate random numbers

The implemented user-defined classes are:

- Process: containing the Process class
- Scheduler: containing the Schduler class

## Layout

The program consists of the two classes that implement the Process class consisting of its ID and amount of tickets and other functions. The Scheduler class consist of functions to assign a process randomly, hence scheduling a process

## Driver Code

The driver code displays three processes initialized with an ID and lottery tickets. These processes are pushed to a Scheduler class where a process is selected randomly as a winner and displayed.

## Classes:

### Process:

#### Private variables/functions: 
- ID: integer variable type that contains process ID
- tickets: integer variable type that contains number of process

#### Public variables/functions:
- Process(): Constructor for Process Class
- getId(): function with return type integer that returns ID value
- getTickets(): function with return type integer that returns number of tickets.

### Scheduler:

#### Private variables/functions:
- processes: vector type that consists of all process
- rd: random device type that generates a random number
- rng: mt19937 type that is a pseudo-random number generator

#### Public variables/functions:
- Scheduler(): Constructor for Scheduler Class
- addProcess(): function to add process to the scheduler class
- allocateTickets(): function to compress total tickets between 0 and 100
- scheduleWinner(): function with return type Process that returns winning process

                          

## Usage Instruction
- Compilation: Compile the program using a C++ program.
- Execution: Execute the compiled program.
- Interaction: Re-run program to find out winner process

## Error Handling
The program includes error handling for failure in compilation. If the lottery ticket is not in range(which is impossible), it will throw an error.
