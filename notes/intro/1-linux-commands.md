# Basic Linux Commands

To execute the following linux commands, open your terminal/shell.

You may use a one of the following to get a linux shell on your computer:

- Linux distribution(distro) like [ubuntu](https://ubuntu.com/download/desktop)
- [Virtual machine](https://www.virtualbox.org/) 
- [Windows subsytem for linux(WSL)](https://docs.microsoft.com/en-us/windows/wsl/install-win10) to get a linux shell on windows 10.

If you don't have any, the easiest to start with will be WSL in my opinion as you can easily download it from Microsoft store on windows 10.

### Commands

- `date` : prints the system date and time

- `pwd` : Short for present working directory, it outputs the current working directory.

- `touch` : Creates a new file

  ```bash
  touch filename
  ```

  Now you have a file named filename in your current folder(directory)

  - To create multiple files

    ```bash
    touch file1 file2 
    ```

- `ls`  : displays all the files and folders in our current directory.

  - If you followed previous `touch` command it will show filename, file1, file2.

  - Options for `ls` command:

    - `ls -u` : show newest files first

    - `ls -r` : show files in reverse order, oldest first.

    - `ls -l` : show files and folder in long listing format

      Example output:

      ```bash
      total 2
      -rwxrwxrwx 1 root root 11 Aug 16 15:47 file1*
      -rwxrwxrwx 1 root root  9 Aug 16 15:47 file2*
      -rwxrwxrwx 1 root root 27 Aug 16 15:47 filename*
      ```

      Explanation of output:

      **Column 1**:

      Column 1 shows permission for files and folders for three different users - owner | group | others 

      - r = read, w = write, x = execute 

      **Column 2**:

      Column 2 shows number of hard links to that file or folder which is 1 by default. 

      A link in UNIX is a pointer to a file.

      **Column 3**: Shows file owner

      **Column 4**: Shows file group

      **Column 5**: Shows file size in bytes

      **Column 6**: Shows file date and time of creation

      **Column 7**: Shows filename

  - You may use different options in combination like: `ls -lr`

- **Terminal Based Editors**

  - Various different editors exists for editing files in a terminal like **vi**, **vim**, **nano**.

  - `vi` : Used to create a new file or edit previously created once.

    ```bash
    vi newFileName
    ```

    this will create new file named newFileName in your current directory and prompt an editor in the terminal.

    - To start editing the file, press `i`. Now you are in *insert* mode. Type whatever you want.
    - To exit the insert mode press `esc`.
    - To save the file: press `:` and then type `w`.
    - To save and exit the vi, press `:` and then type `wq`.
    - To quit the vi editor without saving, press `:` and type `!q`.

  - `vim` : vim is similar editor to `vi` but with more features. You can perform similar command in vim like vi.

  - `nano` : nano is the easiest between all three. Type `nano filename` and you will understand the rest yourself.

- `cat` : displays file content on the standard output(console).

  ```bash
  cat filename
  ```

- `wc` : displays word count of a file in the following format

  - Options
    - -w : prints only number of words.
    - -l : prints only number of lines.
    - -c : prints only number of characters.

  ```bash
  wc filename
  ```

  Output:

  ```115 538 3320 filename```

  ```number-of-lines number-of-words - byte-count filename```

- `clear`  :  clear the terminal screen.

  ​	alternatively use control + l.

- `rm` : removes a file

  ```bash
  rm filename
  ```

  the file with name 'filename' will be deleted.

  **To delete a directory(folder) use the option `-r` which means recursively delete all the files in the folder

  ```bash
  rm -r foldername
  ```

- `mkdir` : creates a new directory(folder).

  ```bash
  mkdir folderName
  ```

  Now if you execute `ls` it will show folderName.

- `cd` : change current working directory to given directory.

  ```bash
  cd folderName
  ```

  To Move a folder back from current folder type `cd ..`

  `..` = previous folder.

  `.`  = current folder

- `cp` : copy a file/files to another folder.

  Suppose you have two files named file1, file2 and you wants to copy them in a folder named new in the current directory.

  ```bash
  cp file1 file2 new
  ```

- `mv` : Similar to `cp` but moves the file instead of copying.

- `alias`: creates a different name for a command.

  ```bash
  alias create=touch
  create file1
  ```

  Now `create` works same as `touch`.

  **Note** : The alias will exist for the current session only and will be forgotten once you restart the terminal.

  To make it persistent, add the alias line in ./bashrc as per the following: 

  ```bash
  vi ~/.bashrc
  ```

  Then add a new line in bashrc as you edit in `vi`

  `alias create="touch"`

  save the file.

  Now you can use `create` instead of `touch` anytime.



### More Commands

- **ed**: ed is a line oriented text editor, you can use it to edit/create a file like you did with *vi*.

  ```bash
  ed
  a	# type a to append content to file
  This is a line	# Start appending content to your file
  This is another line my file
  .	# This marks the end of file
  w filename # appends lines to file or create a new file
  ```

- **who**: shows who is logged in

  ```bash
  who
  yuvrajsj18 :0           2020-08-19 23:13 (:0)	# sample output
  ```

- **who am i**: show your own system details if you are in a multi-user system.

- **pr**: shows content of files in print format.

  - Total lines per page is 66, 10 for headers and 56 for content.
  - The content is paginated so we can know how much content will be shown per page.
  - *You can columnate the content using **-n** option*.

  ```bash
  pr filename
  
  2020-08-19 11:41                      file1                       Page 1
  
  
  This is a text
  this is more text
  This is more more text
  ```

- **cmp**: Compare two files byte by byte. It will print the first byte number on the first line number where the content of two files differ.

  ```bash
  cmp file1 file2
  file1 file2 differ: byte 1, line 1	# Sample output
  ```

- **diff**: compare files line by line. It also shows what needs to be changed to make file to make file1 same as file2.

  ```bash
  diff file1 file2
  1,3c1,4				# Sample output
  < This is a text
  < this is more text
  < This is more more text
  ---
  > ABC
  > XYZ
  > MNNP
  > ABCC
  ```

  - a means append.

    ```bash
    3a4
    > This is some text
    # This means after line 3 you need to append given text to match line 4 of second file
    ```

  - c means change.

    ```bash
    2,3c3
    < Uttar Pradesh
    < Kolkata
    ---
    > Andhra Pradesh
    # This means change line 2 to 3 of file 1 to line 3 of file 2
    ```

  -  d means delete.

    ```bash
    3d2
    < Telangana
    # Means delete line 3 of file1 to match line 2 of file2
    ```

- **sort** : sort lines of text files.

  - -n means sort by numeric values.

  ```bash
  sort filename	# to sort by ascii values
  sort -n filename # to sort by numeric values
  ```

  - +c means to sort according to a particular column in file. c starts with 0.

  ```bash
  cat filename	# we have a file with following content
  word1	word4	word1
  word2	word3	word2
  word3	word2	word3
  word4	word5	word4
  word5	word6	word5
  word6	word1	word6
  word7	word8	word7
  word8	word7	word8
  word9	word9	word9
  
  sort +1 filename	# sort file according to second column
  word6   word1   word6
  word3   word2   word3
  word2   word3   word2
  word1   word4   word1
  word4   word5   word4
  word5   word6   word5
  word8   word7   word8
  word7   word8   word7
  word9   word9   word9
  # Look lines are sorted according to second column
  ```

- **;** : semicolon is used as a command separator to execute multiple command one after other.

  ```bash
  date; ls; who
  Wednesday 19 August 2020 11:43:37 PM IST		# Sample output
  file1*  file3*  file-ed*    mvfile1*  sort*
  file2*  file4*  file-nums*  newDir/   yuvraj/
  yuvrajsj18 :0           2020-08-19 23:13 (:0)
  ```

- **tail**: Output the last part of a file,by default it will output last 10 lines.

  ```bash
  tail filename 	# Output last 10 lines
  tail -n filename 	# Output last n lines
  tail +n filename 	# Output lines from nth line to end
  ```

- **Redirection Symbols**: There are three redirection symbols as follows:

  - **>** : It prints the output of a command to file.

    ```bash
    ls > filename		# this will add all files and folder to filename
    date > filename 	# this will change the content of file to the date
    ```

  - **>>** : It will append the output of a command to a file.

    ```bash
    ls >> filename		# This will append the output of ls to file
    ```

  - **|** : This is used to send output of one command to other command.

    - ls | sort means first ls is executed and it output is send to sort then it will execute.

    ```bash
    ls | sort 	# this will print the files in sorted order
    ```

  - #### Exercise

    - How to print sorted list of users?

      who | sort

    - Count the number of files and directories in current directory:

      ls | wc -l

    - Count the number of files and directories in directory user1/networks:

      ls user1/networks | wc -l
  
- **grep** :  print lines that matches a given pattern.

  - Format: grep -options regex filename

  - Regex Basic Options:

    | `?`         | The question mark indicates *zero or one* occurrences of the preceding element. For example, `colou?r` matches both "color" and "colour". |
    | ----------- | ------------------------------------------------------------ |
    | `*`         | The asterisk indicates *zero or more* occurrences of the preceding element. For example, `ab*c` matches "ac", "abc", "abbc", "abbbc", and so on. |
    | `+`         | The plus sign indicates *one or more* occurrences of the preceding element. For example, `ab+c` matches "abc", "abbc", "abbbc", and so on, but not "ac". |
    | `{n}`       | The preceding item is matched exactly *n* times.             |
    | `{min,}`    | The preceding item is matched *min* or more times.           |
    | `{min,max}` | The preceding item is matched at least *min* times, but not more than *max* times. |
    | .           | matches any character                                        |
    | ^           | Specify beginning                                            |
    | $           | Specify end                                                  |

    [Read more about regex](https://en.wikipedia.org/wiki/Regular_expression)

    - Build Regex expression easily and visually with this tool - [Regex101](https://regex101.com/)

  - Options for grep

    - -v : print all lines that exludes the given regex.
    - -n : print line numbers.

  - #### Exercise

    - Search for 'is' in a file

      ```bash
      grep 'is' filename
      ```

    - Search for lines that doesn't include 'is'

      ```bash
      grep -v 'is' filename
      ```

    - Check if user1 is logged in or not

      ```bash
      who | grep 'user1'
      ```

    - Find how many times user1 has logged in

      ```bash
      who | grep 'user1' | wc -l
      ```

    - Search all lines that end with 's'.

      ```bash
      grep 's$' filename
      ```

    - See all filenames that begins with 'a'

      ```bash
      # Solution 1 with grep
      ls | grep '^a'
      
      # Solution 2 with ls
      ls a*
      ```

    - See all empty lines in a file

      ```bash
      grep '^$' filename -n
      ```

    - Find all email address in a file

      ```bash
      grep '.\+@.\+\..\+' email_files.txt
      ```

      - Explanation
        .\\+ means any character 1 or more times
        @ means match @ character literally

        .\\+ means any character 1 or more times

        \\. means match the . character literally

        .\\+ means any character 1 or more times

- **Shell Variables** : Shell variables are special variables used by the shell.

  - **$HOME** : Contains path of home directory

  - **$PATH** : Contains executable's directories separated by a colon : 

  - To Define your own variables:

    ```bash
    variable_name="value"
    ```

#### Thanks

