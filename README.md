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
The Wait system calls will suspend a process until its child process is terminated. Depending on the specific version of the wait function you used you can wait on a child with a specific PID or just wait for the first one. You can also receive the exit status of the child by passing the adresss of a variable to receive it in.
###  Exec
Exec is used for executing a program on a process. In C there are different versions of this. This shell uses `excevp`, which specifies that the PATH environment variable shall be passed on to the program.
This allows the shell to run any program referenced in PATH.
###  Pipe
Pipe is used for giving the output of a process to the input of another process. What the actual pipe system call does is it creates two files and returns the filedescriptors for both in an array. The unique thing about these files is what you write to the first file can be read in the second. This makes this function very useful for sharing data between processes. 

###  Dup2
Files have integer identifiers referred to as File descriptors. These are unique to each file and are used when reading and writing to files. What dup2 does is it takes two file descriptors as input and modifies the second filedescriptor to be identical to the first. What this achieves is that when you attempt to write using the second filedescriptor you will end up writing to the file associated with the first file descriptor. This is used in our piping functionality to connect the stdin and stout of two processes using pipes; this works since stdin and stdout are also filedescriptors.

### I/O- redirection
3 standard streams
standard input (stdin); The stdin stream is numbered as stdin (0). The bash shell takes input from stdin. keyboard is used as input
standard output (stdout); The stdout stream is numbered as stdout (1). The bash shell sends output to stdout. Outout goes to display
standard error (stderr); The stderr stream is numbered as stderr(2). The bash shell sends error message to stderr. Error message goes to display

### Program environment
An integrated development environment (IDE) is used VS code

### Background program execution
The background process usually is a child process for processing a computing task. After creation, the child process will run on its own, performing the task indenpendent of the control process, freeing the control process of performing that task

# Write about this and then we done! 🙂 🕗 
- I/O-redirection
- Program environment
- Background program execution. 