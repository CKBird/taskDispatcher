README.txt

Task Dispatcher Timeline:
Assigned: 28th May, 2016
Started: Early June, 2016
All old code adandoned for a variety of reasons.
Restarted: 16th August, 2016 7:00PM
Completed: 17th August, 2016 3:00AM

Hours spent to code: 8
Days from Assigned to Completed: 81

Notes: 
1) I should have been much more serious about finishing this earlier. Although wrapping my head around how I might complete the task was a little difficult at first, it should not have taken this long. Note to self: When you take your socks off, put them directly in the hamper, not on the floor.
2) I created the queue by hand, no <queue> was included in the making of this code

How to Execute:
1) Extract folder
2) Invoke Makefile using 'make' from a terminal
3) Execute using ./taskMain as the executable title

Functionality:
1) Read in list of tasks and details of tasks from input file (taskMain.cpp:21-48)
2) Dequeue tasks one at a time from ready queue and process them correctly (taskMain.cpp:56-91)
3) Read through each queue and print out contents as a log (taskMain.cpp:92-100)

Description of Classes:
TCB: the basic unit class to hold a single task
queueBase: the handmade queue to manage enqueue end (FIFO), enqueue priority (FI(H)ighest (P)riority O), and pop
functionLUT: LUT for functions to be executed, how the main class was able to view each TCB as 'task agnostic'

Breakdown:
Step 1) 
a) Relativly straight forward, while the task type read in is not DONE, read in 3 values, dynamically create TCB object type (TCB.h/.cpp) fill with correct information
b) Insert into ready queue using priority enqueue, which traverses queue comparing priorities, then inserts at correct place
c) Continue until DONE is found

Step 2)
a) Pop highest priority task from ready queue and analyze
b) First check for dead-tasks (0 iterations (with no previous executions) or 0 priority)
c) If Iterations is 0, but it has been previously executed, mark as completed (should never hit this, but is failsafe)
d) If above are not met, then the task needs to be executed. If number of iterations minus number of times executed is less than 1 (total times to execute - times executed) then it should be marked as complete and not run again
e) If (total times to execute - times executed) is greater than 0, generate new random priority, and put back in ready queue based on new priority

Step 3) 
a) Starting at head of queue (linked list structure) read data, print to screen, go to next

Memory Notes:
All TCBs were created dynamically, nothing created until it's needed.
All memory DEallocation was left to standard running procedure as objects were needed for the rest of runtime regardless of when they were 'completed' or not. IOW: Even when 'done' with a task, it needed to remain alive on one of the three queues until termination of program. You can see attempts at a delete function within a destructor in queueBase.cpp:26-37. These were before I determined that running procedure was correct for deallocation.

Possible Expansion:
1) I made it easy to add new functions into the functionLUT class, simple lookup table functionality is easily expandable, but for hundreds of functions a new method for storing and looking up should be used.
2) Could also add a 'time to execute' variable in each task, to give it a set amount of time it would take to execute that task, would allow for various scheduling techniques and also give estimated run time of all tasks as a simulation tool.
3) Pointers to previous elements were never used. Could either remove them completely to save space, or abuse them in some of my lookup functions for slightly faster execution.
4) Time of dequeue was noted, but not printed out in log. Can add in if interested/needed.
5) Makefile makes it easy for future expansion as well.

Final Thoughts:
Very good, thought provoking program. Was forced to think outside the box on some of the constraints of the project. Very much enjoyed writing the program when I finally started it, and feel it helped me prepare well for Xilinx interview tomorrow. I am willing to work on another program if you have one :)