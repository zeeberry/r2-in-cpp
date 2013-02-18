r2-in-cpp
=========

CPU SCHEDULING - ROUND ROBIN ALGORITHM
By Zainab Ebrahimi

cpuschedule class()
This class provides the ability to create an object of class cpuschedule.
A cpuschedule object has the capability to call two functions : Getdata()
and RoundRobin(). It also defines variables only accesable within the class.

Getdata()
This function is defined within the cpuschedule class. It's main purpose is
to gather and displa basic cpu information. It displays number of processes
that is predefined and total service time. This last element is determined
by the data that is inputed by the user. User is prompt to enter service
time for each process.

 
RoundRobin()
This funtion is defined within the cpuschedule class. It's main purpose is
to perform a cpu scheduling simulation through the Round Robin algorithm.
The function is determined by the time quantum, which is defined by the user.
It determines the amount of times the CPU will process and it populates the 
RRobinarray based on the service time of each process and the time quantum.
It then outputs the two dimensional array to demonstrate the utilization of
the CPU. The RoundRobin function also calculates waiting time, turnaround time
and throughput. 

Main()
This class declares a cpuschedule object and calls the functions Getdata() and
RoundRobin(). 
