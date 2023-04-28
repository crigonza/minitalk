# minitalk

minitalk is a project at 42 that aims to create a communication program between a client and a server using UNIX signals.

## Getting Started

To use this program, you need to clone this repository and compile it with `make`. This will generate two executable files: `server` and `client`.

## Usage

To use this program in your own project, you need to run the `server` program first and note its PID. Then you can run the `client` program with two arguments: the server PID and the string to send. For example:

```bash
./server
Server PID: 1234
```

```bash
./client 1234 "Hello world!"
```

The server will display the string received from the client using only UNIX signals. The communication protocol uses one bit per signal: SIGUSR1 for 0 and SIGUSR2 for 1.

## Requirements

The project has the following requirements:

- The client must communicate the string passed as argument to the server
- The server must display the string received as fast as possible
- The server must be able to receive strings from several clients in a row without restarting
- Only two signals are allowed: SIGUSR1 and SIGUSR2
- The program must handle errors properly

# Bonus
The project has the following bonus features:

- The server sends a confirmation signal to the client after receiving each bit
- The program supports unicode characters by using more than one byte per character

## Functions

In the project you can use the following functions from the standard C library and the UNIX system calls:

- write
- ft_printf (my own printf function)
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit
