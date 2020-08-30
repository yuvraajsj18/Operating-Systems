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

- Each process is represented in the OS by a Process Control Block(PCB) - also task control block.
- It contains Information associated with a specific process.
- Information Stored:
  - **Process State**: new, ready, running, waiting, terminated.
  - **Program counter**: address of next instruction to be executed.
  - **CPU registers**: Content of all CPU centric registers like accumulators, index register, stack pointers, etc must be saved when interupt occurs, to allow the process to be continued correctly afterward.
  - **CPU Scheduling Information**: This information includes process priority, scheduling queue pointers and other scheduling parameters.
  - **Memory management information**: Information about the memory allocated to the process.
  - **Accounting information**: CPU used, clock time elapsed since start, time limits.
  - **I/O status information**: I/O devices allocated to process, list of open files.

![image-20200830153603631](processes.assets/image-20200830153603631.png)

## Process Scheduling

- Maximise CPU use, quickly switch processes onto CPU for time sharing.

- **Process scheduler** selects among available processes for next execution on CPU.

- Maintains **scheduling queues** of processes

  - **Job queue** - set of all processes in the system.

  - **Ready queue** - set of all processes residing in main memory, ready and waiting to execute.

  - **Device queue** - set of all processes waiting for an I/O device. Each device has its own device queue.

  - Process Migrate among the various queues.

  - These queues are generally stored as a *linked list*.

    - A ready queue header contains pointers to the first and final PCB in the list.
    - Each PCB includes a pointer field that points to the next PCB in the ready queue.

    ![image-20200830160739887](processes.assets/image-20200830160739887.png)

    - **Queueing Diagram**

      ![image-20200830161453407](processes.assets/image-20200830161453407.png)

      A new process is initially put in the ready queue. It waits there until it is selected for execution, or is **dispatched**. Once the process is allocated the CPU and is executing, one of the several events could occur:

      - The process could issue an I/O request and the be placed in an I/O queue.
      - The process could create a new subprocess and wait for the subprocess's termination.
      - The process could be removed forcibly from the CPU as a result of an interrupt, and be put back in the ready queue.
      - On termination, the process is remvoed from all queues and PBC and resources are deallocated.

### Schedulers

- **Short-term scheduler(or CPU scheduler)** - selects which process should be executed next and allocates CPU.

  - Sometimes the only scheduler in a system.
  - Short term scheduler is invoked **frequently** (milliseconds) => (must be fast)

- **Long-term scheduler(or job scheduler)** - selects which processes should be brought into the ready queue.

  - Long term scheduler is invoked infrequently (seconds, minutes) => (may be slow)
  - The long term scheduler controls the **degree of multiprogramming**(the number of processes in main memory).

- Processes can be described as either:

  - **I/O bound process**: spends more time doing I/O than computation, many short CPU burst.
  - **CPU bound process**: spends more time doing computations, few very long CPU bursts.

- *Long term scheduler strives for good process mix(there should be both I/O bound and CPU bound processes)*

- **Medium Term Scheduler** - It is required when long term scheduler did not bring good mix of CPU and IO bound processes.

  - It decreases the degree of multiprogramming.
  - Removes process from memory, store on disk, bring back in from disk to continue execution: **swapping**.

  ![image-20200830203549955](processes.assets/image-20200830203549955.png)

### Context Switch

Switching the CPU to another process requires performing a state save of the current process and a state restore of a different process. This task is known as a **context switch**. 

When a context switch occurs, the kernel saves the context of the old process in its PCB and loads the saved context of the new process scheduled to run.

*Context switch time is pure overhead*: because the system does no useful work while switching.

Speed of context switch varies from machine to machine depending on memory speed, number of registers etc.

The more complex the OS, the more work must be done during context switch.

![image-20200830204405120](processes.assets/image-20200830204405120.png)





















