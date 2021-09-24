# Group 7 - Mandatory Assignment 1 🖥 




This is a simple shell developed for the Operating Systems course at the Technical University of Denmark



## Introduction
This simple shell enables you to type in commands to start any program that is included in your PATH environment variable or using absolute paths.


## How to use the shell on Linux/Mac

 Run the shell by typing in `./Shell` in your terminal of choice.
 Then you can write in any command, for example `ls`, in the shell and it will run the given program while passing the arguments to the process that is created.

## System calls
The UNIX kernel has a range of so called 'System Calls', that can be called from a program. Many of these are used for creating new processes and managing them. 
###  Fork
Fork creates an exact copy of the calling parent process and then gives it a unique process id (PID)
###  Wait
The Wait system calls will suspend a process until its child process is terminated. 
###  Exec
Exec is used for executing a program on a process. In C there are different versions of this. This shell uses `excevp`, which specifies that the PATH environment variable shall be passed on to the program.
This allows the shell to run any program referenced in PATH.
###  Pipe
Pipe is used for giving the output of a process to the input of another process. 

###  Dup2

# Write about this and then we done! 🙂 🕗 
- Dup2
- I/O-redirection
- Program environment
- Background program execution. 