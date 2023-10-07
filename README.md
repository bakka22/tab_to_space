Description : 
this program creats a new temporary file and copies all the content of the
specified file to the new file, and when a tab charactr "\t" is encounterd
the program replaces it with four space characters "    " (the rule of four
in python indentation). after copying is done, the new file is renamed after
the old file and the old file is removed.

**NOTE : the permissons of the old file are not copied to the new file so
you would need to set access permissions manually for the newly created file.

Set up:  compile the code to a file named as you wish using the -o flag with
gcc, move the compiled file to a directory included in your $PATH enviroment
variable for example : "/bin". you can use the command "sudo" with the command
"mv" to access such directory, or you can add the directory where your file is
to the $PATH enviroment variable. so you can use the program using only it's
name and not the entire path.

Usage : type the name you chose for your program followed by the name of the
file you want it to work on like this :
<program_name> <file_name>
  you can also specify multiple file names using any method:
<program_name> <file1_name> <file2_name>
or 
<program_name> *
or 
<program_name> *.py