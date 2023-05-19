# Philosophers

This is the philosophers' project from 42Network.
Link to the subject: https://cdn.intra.42.fr/pdf/pdf/66003/fr.subject.pdf


Prior to diving into my notes and thought process for this project, I highly recommend watching the captivating YouTube video playlist titled "Unix Threads in C" created by CodeVault. It covers key notions regarding threads, race conditions, mutex, and even semaphores if you plan to tackle the bonus part.

LGRIND
Lgrind is a tool quite like Valgrind but for threads.

WHAT IS A THREAD?

In this project, we delve into a new concept: threads. 
Threads enable concurrent execution and allow different parts of a program to run independently. Each philosopher is represented by a thread. It works quite like processes with forks, but the main difference is that when forking, we duplicate all the variables, while threads share the same memory space.

That is really cool because it makes it easier to communicate between threads than it is to communicate between processes.

But when using threads, we might encounter a race condition problem. I'll let you research the subject by yourself. Once again, the CodeVault video is very comprehensive: https://youtu.be/FY9livorrJI

THE IMPORTANCE OF USING A MUTEX

When multiple threads are executing concurrently, they may access shared data simultaneously, leading to data corruption or inconsistent results. Here, the mutex comes into play.

A mutex serves as a synchronization mechanism to protect shared resources and prevent race conditions in multi-threaded programs. They act as guards for critical sections, ensuring that only one thread can access the protected resource at a time, while others patiently wait their turn. In C, a mutex can be seen as a lock that threads can acquire or release.

A mutex is like a lock that ensures only one thread can access a shared resource at a time. Before accessing the resource, a thread needs to acquire the mutex. If the mutex is currently held by another thread, the requesting thread waits until the mutex is available.

Once a thread acquires the mutex, it has exclusive access to a critical section of code. This guarantees that only one thread can execute the protected code, preventing simultaneous access to the shared resource.

After completing its work in the critical section, the thread releases the mutex, allowing other waiting threads to acquire it and continue their execution. Releasing the mutex enables other threads to access the shared resource one by one in an orderly manner.

PHILOSOPHERS' STATUS
To improve the code's readability, I created an enum list of all the possible statuses of the philosophers. They are all quite self-explanatory, except, perhaps, the FED status, which means that the philosopher has eaten the required number of times.

enum e_type_status_philo
{
START,
EATING,
SLEEPING,
THINKING,
FED,
DEAD
};

SLEEPING, EATING, AND THINKING

Philosophers spend their time thinking, eating, and sleeping.

The time spent eating or sleeping is represented by the usleep function, passing the given input as a parameter. The usleep function is quite similar to the sleep function, except the time interval is specified in microseconds for the former and in seconds for the latter. In our case, the subject explicitly requires the use of microseconds. Therefore, we will use the usleep function.

The subject doesn't set boundaries regarding the amount of time spent thinking. Thus, we don't need the usleep function for this action, and we will simply express it by a change in the status.

TIME
The subject allows us to use the gettimeofday function available in the <sys/time.h> library.

More info here: https://linuxhint.com/gettimeofday_c_language/