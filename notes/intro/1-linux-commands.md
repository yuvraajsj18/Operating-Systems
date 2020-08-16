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



#### Thanks