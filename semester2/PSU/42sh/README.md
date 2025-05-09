# 42sh
Custom shell made for an EPITECH project made by :

| HEMMER Julian | MALFILATRE Gauthier | MARTIN Hugo | MARCOT Romain | MACIEJEWSKI Pierre |

---
# BUILT IN
cd [PATH] - navigate into the computer

env - display the current environment

setenv [NAME] [OPTIONS] - add a new environment variable

unsetenv [NAME] - delete the environement variable

exit [NUMBER] - exit with an exit code

color [PROMPT] [COLOR] - change prompt color

alias [NAME] [OTIONS] - add a new alias

unalias [NAME] - remove an already existing alias

---
# SEPARATOR
; - separator to execute multiple command

&& - separator to execute multiple command if the command exit code is > 0 stop

|| - separator to execute multiple command if the command exit code is = 0 stop

| - pipe to execute a command in another one

\> - redirect the exit of a command into a new file

\>> - redirect the exit of a command into a file

< - redirect the content into a command

# DELIMITOR
" " - delimitor to make multi word command

' ' - delimitor to make multi word command but without local and environement variables

` ` - delimitor to execute a command in another one

( ) - delimitor to execute a command in another shell