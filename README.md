# Myshell
This is a self-developed UNIX-like shell, coded in C-language.

--------------
What is this ?
--------------

This is a self-developed UNIX-like shell, coded in C. This shell have this specifications:

-Interactive and Batchmode

-Accept a commandline with a variety of commands, separated with semicolon ';'

-In case of command 'quit', ends program an shell quits

-In case of 'quit' presence among commands, 'quit' gonna be executed last
e.g. $> ls ; quit ; mkdir FILE_NAME -> ls ; mkdir FILE_NAME ; quit

-Maximum number of characters of a single command line = 512

------
Bugs :
------

-Many times you have to write full-path so as to execute the command

-Because of the nature of program, you can't execute some commands 
e.g cd, help etc

-Pressing up-arrow from keyboard for previous situation,
does not work.

---------------
How to use it ?
---------------

1.Open in terminal the folder "my_exercise" which contains:
-Makefile
-my_shell.c
-(This) README.txt
-An indicative batchfile name "batch_sample"

--For INTERACTIVE MODE:

1.Write 'make' in terminal, an executable called "my_shell" appears in folder called "my_exercise"

2.Write './my_shell'and press enter and a 'prompt' appears

3.Write a command e.g. ls, ls -l, mkdir FILE_NAME etc
or a variety of commands with semicolon ';' 
between them and press enter (ATTENTION: maybe need to write full path, see Bugs paragraph)

--For BATCH MODE:

1.Write 'make' in terminal, an executable called "my_shell" appears in folder called "my_exercise"

2.Write './my_shell /BATCHFILE ' , press enter and a 'prompt' appears with executed commands of batchfile

3.Also you can create your own batchfile in .txt 

------------
About author
------------
- Basian Roni Lesi
- lroni10094@gmail.com
- 2016-2017
