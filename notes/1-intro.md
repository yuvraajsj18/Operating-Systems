# Operating System



## Chapter 1 - Introduction

### What is an Operating System?

- An operating system is a program that manages the computer hardware.
- It provides a basis for application programs.
- Acts as an intermediary between the computer user and the computer hardware

**Different OS can be very different from each other according to the purpose they serve. Some are designed to be efficient, some to be convenient and other a mix of this two**.



### What Operating Systems Do?

- A computer system can be divided into 4 components:
  - Hardware - CPU + Memory + I/O devices, provided the basic computing resources for the system.
  - OS - Controls the hardware and coordinates its use among the various application programs for various users.
  - Application Program - word processors, compilers, browsers etc : define the ways in which the resources are used to solve users computing problem.
  - Users

![Components of a computer system](1-intro.assets/1_1_SystemComponents.jpg)

**An OS provides the means for proper use of these hardware resources in the operation of the computer system**. 

It's like a government, do no useful function by itself, but provides an *environment* within which other programs can do useful work.

### OS From Different Perspective

#### User's View

- For users an OS is a program that allows them to take advantage of the computer resources according to different requirements. 
- How a user views OS depends on the interface used
- Single user System (like a PC):
  - Resources are used by single user
  - goal is to maximise work
  - ease of use > performance > resource utilisation
- Multiple user system (like a mainframe):
  - Maximum resource utilisation to assure all available CPU Time, memory IO are efficiently used
- Workstations - users have individual resources but share networking and server resources, OS designed to compromise between individual usability and resource utilisation
- Phones: OS designed for individual usability, performance per unit of battery.
- Embedded: OS designed to run without user intervention

#### System's View

- For a computer, an OS is a **resource allocator**. 
  - It allocates the different resources the CPU has to different programs for efficient and fair use.
- OS manages resources such as CPU Time, memory space, file-storage space, I/O Devices etc.
- OS handles numerous and possibly conflicting requests for resources.
- OS is a **control program** that manages the execution of user programs to prevent errors and improper use of the computer. It is especially concerned with the operation and control of I/O devices.

### Defining Operating Systems

- An OS shipped by the vendor may contains several programs.
- The main of which is the Kernel that's why we may define OS in this way:
  - The operating system is the one program running at all times on the computer—usually called the **kernel**.
- Along with Kernel, there are two other types of program - 
  - Kernel - The core program of OS
  - System Programs - programs associated with the OS but not part of the kernel.
  - Application Programs - programs not associated with OS, generally what a normal user will use.

### Computer System Organization

Before learning more about how computer systems operate, let's see how a computer system is structured.

