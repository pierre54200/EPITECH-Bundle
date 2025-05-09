# Minishell 1

Shell working with basic command like ls.

Custom prompt with color:
[return value] user@username:actualpath$>

built-in exit:
exit [option] 
- "exit" = exit 0
- "exit NB" = exit NB

built-in cd:
cd [path]
- "cd .." = father folder
- "cd -" = last open folder
- "cd ." = current folder
- "cd ~" = home/usr
- "cd" = home/usr
- "cd path" = ~/path
- "cd incorrect-path" = path: No such file or directory.
- "cd path1 path2" = cd: Too many arguments.

built-in env:
- "env" = display env

built-in setenv:
setenv [NAME] [function]
- "setenv" = error
- "setenv NAME" = create NAME= in env
- "setenv NAME function" = create NAME=function in env

built-in unsetenv:
unsetenv [NAME]
- "unsetenv" = error
- "unsetenv NAME" = remove the NAME line in env

Makefile
"make test_run" = test the program
