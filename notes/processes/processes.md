# Processes

## Process Concept

- Process - a program in execution.

- Process is not just *program code*(AKA text section), it also includes:

  - the current activity represented by - 
    - Program Counter Value
    - Content of processor registers
  - Process stack (function parameters, local variables, and return address)
  - Data section(global variables)
  - Heap - Memory that is dynamically allocated during process run time. 

- *Program* is a **passive** entity, whereas a *process* is an **active** entity.

- If user(multiple or single) invoke same copy of the browser, these will be separate processes, despite belonging to the same passive entity.

  - Although the text segment of processes of same program are equivalent, the data, heap, and stack sections are different.

- **Summary**:

  **A program is not a process**; a *program* is a *passive* entity, such as a file containing a list of instructions stored on a disk(executable file), whereas a *process* is an *active* entity, with a *program counter* specifying the next instruction to *execute* and a set of *associated resources*.

  A *program becomes a process* when an executable file is *loaded into memory* either by double clicking or writing a command.

  ![Process in memory](processes.assets/3_01_Process_Memory.jpg)

  ​															A Process in Memory

## Process State

- As a process executes, it changes **state** -
- *The state of a process is defined in part by the current activity of the process*.
- Each process may be in one of the following states:
  - **New** - The process is being created.
  - **Running** - Instructions are being executed.
    - At one moment of time, only one process can be in running state.
  - **Waiting** - The process is waiting for some event to occur. (such as an I/O completion or reception of a signal).
  - **Ready** - The process is waiting to be assigned to a processor.
  - **Terminated**: The process has finished execution.
- The states name are arbitrary and vary across OS, but the state they represent are found on all systems.
- **Many processes can be in the ready and waiting state.**

![Diagram of process state](processes.assets/3_02_ProcessState.jpg)



## Process Control Block

















