# ☎️ 42-Minitalk

## 📑 About
The purpose of this project is to code a small data exchange program using UNIX signals.
 

## Prerequisites

This project is written in C, you need to have a gcc compiler to run the program.
 

## 💻 Instructions

### Prerequisites

### Compilation

To compile, go to the project folder and run the makefile : 

`make`

### 🕹 Testing

#### Manual

To test the program, you need two terminals, one for the server and one for the client.

Run the server executable first :

`./server`

It will show you its PID

Then run the client executable in the second terminal, using the PID you received from the server and a string of your choice : 

`./client "PID" "Your string"`

#### Test script

To check if the program run in particular case and how much time takes, you can use these shell script :

[to do list : insert test.sh file]

## 💡 Project details

This project needs to be familiar with UNIX signals and bitwise operation.

