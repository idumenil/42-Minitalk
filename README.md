# 42-Minitalk

## About
The purpose of this project is to code a small data exchange program using UNIX signals.

## Mandatory Part
Produce server & client executables

Client must communicate a string passed as a parameter to server (referenced by its process ID) which then displays it

Only SIGUSR1 & SIGUSR2 signals can be used

## Bonus Part
Add reception acknowledgement system
Support Unicode characters

## Allowed Functions
◦ write

◦ ft_printf (personnal printf)

◦ signal

◦ sigemptyset

◦ sigaddset

◦ sigaction

◦ kill

◦ getpid

◦ malloc

◦ free

◦ pause

◦ sleep

◦ usleep

◦ exit


# Compilation
Clone repo including libft submodule via git clone --recursive https://github.com/hanshazairi/42-minitalk.git.
Compile files into server & client executables via make -C 42-minitalk.
