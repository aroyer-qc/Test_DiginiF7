
# nOS API Documentation

## How nOS Works

nOS is a lightweight real-time operating system (RTOS) designed for embedded systems. It provides multitasking, synchronization, and timing services with minimal overhead. nOS uses a cooperative or preemptive scheduler (depending on configuration) to manage threads, and offers primitives such as semaphores, mutexes, queues, and timers for safe communication and resource sharing between threads.

**Typical nOS application flow:**
1. Initialize the nOS kernel and services.
2. Create synchronization primitives (semaphores, mutexes, queues) as needed.
3. Create application threads, passing them stacks and entry functions.
4. Start the scheduler to enable multitasking.
5. Use nOS API calls within threads for synchronization, communication, and timing.

---

## Getting Started: Minimal Example

Below is a simple example showing how to initialize nOS, create a thread, and use a semaphore for synchronization. Variable names are generic for clarity.

```c
#include "nOS.h"

// Thread stack and control block
nOS_Thread myThread;
nOS_Stack myThreadStack[128];

// Semaphore
nOS_Sem mySemaphore;

// Thread entry function
void MyThreadEntry(void *arg) {
	while (1) {
		// Wait for the semaphore to be given
		nOS_SemTake(&mySemaphore, NOS_WAIT_FOREVER);
		// Do some work here
	}
}

int main(void) {
	// Initialize nOS
	nOS_Init();

	// Create a binary semaphore (initial count 0, max count 1)
	nOS_SemCreate(&mySemaphore, 0, 1);

	// Create a thread
	nOS_ThreadCreate(&myThread, MyThreadEntry, NULL, myThreadStack, sizeof(myThreadStack)/sizeof(nOS_Stack));

	// Start the scheduler (enables multitasking)
	nOS_Start();

	// Main thread can give the semaphore to start the other thread
	nOS_SemGive(&mySemaphore);

	while (1) {
		// Main loop
	}
}
```

---

## Example: Mutex Usage

```c
nOS_Mutex myMutex;

// Create a normal mutex
nOS_MutexCreate(&myMutex, NOS_MUTEX_NORMAL);

// Lock and unlock in a thread
nOS_MutexLock(&myMutex, NOS_WAIT_FOREVER);
// Critical section
nOS_MutexUnlock(&myMutex);
```

---

## Example: Queue Usage

```c
#define QUEUE_SIZE 8
uint8_t queueBuffer[QUEUE_SIZE];
nOS_Queue myQueue;

// Create a queue for bytes
nOS_QueueCreate(&myQueue, queueBuffer, sizeof(uint8_t), QUEUE_SIZE);

// Write to the queue
uint8_t dataToSend = 42;
nOS_QueueWrite(&myQueue, &dataToSend, NOS_WAIT_FOREVER);

// Read from the queue
uint8_t receivedData;
nOS_QueueRead(&myQueue, &receivedData, NOS_WAIT_FOREVER);
```

---

## Example: Timer Usage

```c
// Timer callback function
void MyTimerCallback(void *arg) {
	// Timer event code
}

nOS_Timer myTimer;

// Create a one-shot timer (fires once after 100 ticks)
nOS_TimerCreate(&myTimer, MyTimerCallback, NULL, 100, NOS_TIMER_ONE_SHOT);

// Start the timer
nOS_TimerStart(&myTimer);
```

---

This document provides an overview of all public functions available in `nOS.h`, including their usage, parameters, return values, and important notes. This is intended as a quick reference for developers integrating or using nOS in their projects.

---

## Table of Contents
- [Initialization and Scheduler Control](#initialization-and-scheduler-control)
- [Thread Management](#thread-management)
- [Synchronization Primitives](#synchronization-primitives)
- [Memory Management](#memory-management)
- [Timers, Signals, Time, Alarms, Barriers](#timers-signals-time-alarms-barriers)

---

## Initialization and Scheduler Control

### nOS_Init
**Description:** Initialize nOS scheduler and enabled services.

**Prototype:**
```c
nOS_Error nOS_Init(void);
```
**Returns:**
- `NOS_OK`: Initialization successfully completed.
- `NOS_E_INIT`: Scheduler already initialized.

**Notes:**
- This is the first nOS function that the application should call, else the behavior is undefined.

---

### nOS_Start
**Description:** Enable context switching.

**Prototype:**
```c
nOS_Error nOS_Start(void);
```
**Returns:**
- `NOS_OK`: Initialization successfully completed.
- `NOS_E_RUNNING`: Context switching is already enabled.

**Notes:**
- Call this function when you are ready to allow context switching.

---

### nOS_Yield
**Description:** Request an immediate context switch from the currently running thread to the highest priority ready thread.

**Prototype:**
```c
nOS_Error nOS_Yield(void);
```
**Returns:**
- `NOS_OK`: Yielding successfully completed.
- `NOS_E_ISR`: Can't yield from interrupt service routine.
- `NOS_E_LOCKED`: Can't yield from a scheduler locked section.

---

### nOS_Tick
**Description:** Send ticks to scheduler and enabled services. Can send single or multiple ticks.

**Prototype:**
```c
void nOS_Tick(nOS_TickCounter ticks);
```
**Parameters:**
- `ticks`: Number of ticks to do.

**Notes:**
- Must be called x times per second by the application if needed (`x = NOS_CONFIG_TICKS_PER_SECOND`).

---

### nOS_GetTickCount
**Description:** Get scheduler free running tick counter.

**Prototype:**
```c
nOS_TickCounter nOS_GetTickCount(void);
```
**Returns:**
- Tick counter (width determined by `NOS_CONFIG_TICK_COUNT_WIDTH`).

**Notes:**
- This is a free running counter that will overflow.

---

### nOS_MsToTicks
**Description:** Convert a number of milliseconds to number of ticks.

**Macro:**
```c
#define nOS_MsToTicks(MS) ...
```
**Parameters:**
- `MS`: Number of milliseconds.

**Returns:**
- Number of ticks.

---

## Thread Management

### nOS_ThreadCreate
**Description:** Create a new thread and add it to the scheduler.

**Prototype:**
```c
nOS_Error nOS_ThreadCreate(nOS_Thread *thread, nOS_ThreadEntry entry, void *arg, nOS_Stack *stack, size_t ssize[, ...]);
```
**Parameters:**
- `thread`: Pointer to nOS_Thread object allocated by the application.
- `entry`: Pointer to the thread entry function (should be a never-ending loop).
- `arg`: Pointer used as parameter when thread runs.
- `stack`: Pointer to array of nOS_Stack entries allocated by the application.
- `ssize`: Total size of the stack in nOS_Stack entries.
- Additional parameters for call stack size, priority, state, MPU, and name may be present depending on configuration.

**Returns:**
- `NOS_OK`: Thread successfully created.
- `NOS_E_INV_OBJ`: Pointer to nOS_Thread object is invalid.
- `NOS_E_INV_VAL`: Invalid parameter(s).
- `NOS_E_INV_PRIO`: Priority is higher than allowed.
- `NOS_E_INV_STATE`: State of the thread is invalid.

**Notes:**
- Only available on some platforms for certain parameters.
- Not all parameters are available in all configurations.

---

### nOS_ThreadDelete
**Description:** Delete thread and remove it from ready to run list or any waiting list managed by the scheduler.

**Prototype:**
```c
nOS_Error nOS_ThreadDelete(nOS_Thread *thread);
```
**Parameters:**
- `thread`: Pointer to nOS_Thread object (can be NULL for running thread).

**Returns:**
- `NOS_OK`: Thread successfully deleted.
- `NOS_E_INV_OBJ`: Pointer to nOS_Thread object is invalid.
- `NOS_E_LOCKED`: Can't delete running thread from scheduler locked section.

**Notes:**
- Pointer can be NULL to access the running thread.

---

### nOS_ThreadAbort
**Description:** Abort waiting operation of thread and remove it from the event waiting list.

**Prototype:**
```c
nOS_Error nOS_ThreadAbort(nOS_Thread *thread);
```
**Parameters:**
- `thread`: Pointer to nOS_Thread object.

**Returns:**
- `NOS_OK`: Thread successfully aborted.
- `NOS_E_INV_OBJ`: Pointer to nOS_Thread object is invalid.
- `NOS_E_INV_STATE`: Thread not currently in waiting state.

---

### nOS_ThreadSuspend / nOS_ThreadResume / nOS_ThreadSuspendAll / nOS_ThreadResumeAll
**Description:** Suspend/resume individual or all threads. Use with care to avoid deadlocks.

**Prototype:**
```c
nOS_Error nOS_ThreadSuspend(nOS_Thread *thread);
nOS_Error nOS_ThreadResume(nOS_Thread *thread);
nOS_Error nOS_ThreadSuspendAll(void);
nOS_Error nOS_ThreadResumeAll(void);
```
**Parameters:**
- `thread`: Pointer to nOS_Thread object (can be NULL for running thread).

**Returns:**
- `NOS_OK`: Operation successful.
- `NOS_E_INV_OBJ`: Pointer to nOS_Thread object is invalid.
- `NOS_E_INV_STATE`: Thread is already/not in suspended state.
- `NOS_E_LOCKED`: Can't suspend/resume from scheduler locked section.

---

### nOS_ThreadGetPriority / nOS_ThreadSetPriority
**Description:** Get or set the priority of a thread.

**Prototype:**
```c
int16_t nOS_ThreadGetPriority(nOS_Thread *thread);
nOS_Error nOS_ThreadSetPriority(nOS_Thread *thread, uint8_t prio);
```

---

### nOS_ThreadGetName / nOS_ThreadSetName
**Description:** Get or set the name of a thread (if enabled).

**Prototype:**
```c
const char* nOS_ThreadGetName(nOS_Thread *thread);
nOS_Error nOS_ThreadSetName(nOS_Thread *thread, const char *name);
```

---

### nOS_ThreadJoin
**Description:** Wait for a thread to terminate (if enabled).

**Prototype:**
```c
nOS_Error nOS_ThreadJoin(nOS_Thread *thread, int *ret, nOS_TickCounter timeout);
```

---

## Synchronization Primitives

### nOS_SemCreate / nOS_SemDelete / nOS_SemTake / nOS_SemGive / nOS_SemIsAvailable
**Description:** Create, delete, take, give, and check availability of semaphores.

**Prototype:**
```c
nOS_Error nOS_SemCreate(nOS_Sem *sem, nOS_SemCounter count, nOS_SemCounter max);
nOS_Error nOS_SemDelete(nOS_Sem *sem);
nOS_Error nOS_SemTake(nOS_Sem *sem, nOS_TickCounter timeout);
nOS_Error nOS_SemGive(nOS_Sem *sem);
bool nOS_SemIsAvailable(nOS_Sem *sem);
```

---

### nOS_MutexCreate / nOS_MutexDelete / nOS_MutexLock / nOS_MutexUnlock / nOS_MutexIsLocked / nOS_MutexGetOwner
**Description:** Create, delete, lock, unlock, and query mutexes.

**Prototype:**
```c
nOS_Error nOS_MutexCreate(nOS_Mutex *mutex, nOS_MutexType type[, uint8_t prio]);
nOS_Error nOS_MutexDelete(nOS_Mutex *mutex);
nOS_Error nOS_MutexLock(nOS_Mutex *mutex, nOS_TickCounter timeout);
nOS_Error nOS_MutexUnlock(nOS_Mutex *mutex);
bool nOS_MutexIsLocked(nOS_Mutex *mutex);
nOS_Thread* nOS_MutexGetOwner(nOS_Mutex *mutex);
```

---

### nOS_QueueCreate / nOS_QueueDelete / nOS_QueueRead / nOS_QueuePeek / nOS_QueueWrite / nOS_QueueWriteInFront / nOS_QueueFlush / nOS_QueueIsEmpty / nOS_QueueIsFull / nOS_QueueGetCount
**Description:** Create, delete, read, write, and manage queues for thread-safe communication.

**Prototype:**
```c
nOS_Error nOS_QueueCreate(nOS_Queue *queue, void *buffer, uint8_t bsize, nOS_QueueCounter bmax);
nOS_Error nOS_QueueDelete(nOS_Queue *queue);
nOS_Error nOS_QueueRead(nOS_Queue *queue, void *block, nOS_TickCounter timeout);
nOS_Error nOS_QueuePeek(nOS_Queue *queue, void *block);
nOS_Error nOS_QueueWrite(nOS_Queue *queue, void *block, nOS_TickCounter timeout);
nOS_Error nOS_QueueWriteInFront(nOS_Queue *queue, void *block, nOS_TickCounter timeout);
nOS_Error nOS_QueueFlush(nOS_Queue *queue, nOS_QueueCallback callback);
bool nOS_QueueIsEmpty(nOS_Queue *queue);
bool nOS_QueueIsFull(nOS_Queue *queue);
nOS_QueueCounter nOS_QueueGetCount(nOS_Queue *queue);
```

---

### nOS_FlagCreate / nOS_FlagDelete / nOS_FlagWait / nOS_FlagSend / nOS_FlagSet / nOS_FlagClear
**Description:** Create, delete, wait, send, set, and clear flag event objects.

**Prototype:**
```c
nOS_Error nOS_FlagCreate(nOS_Flag *flag, nOS_FlagBits flags, nOS_FlagBits excl);
nOS_Error nOS_FlagDelete(nOS_Flag *flag);
nOS_Error nOS_FlagWait(nOS_Flag *flag, nOS_FlagBits flags, nOS_FlagBits *res, nOS_FlagOption opt, nOS_TickCounter timeout);
nOS_Error nOS_FlagSend(nOS_Flag *flag, nOS_FlagBits flags, nOS_FlagBits mask);
#define nOS_FlagSet(f,m) nOS_FlagSend((f), NOS_FLAG_BITS_ALL, (m))
#define nOS_FlagClear(f,m) nOS_FlagSend((f), 0, (m))
```

---

## Memory Management

### nOS_MemCreate / nOS_MemDelete / nOS_MemAlloc / nOS_MemFree / nOS_MemIsAvailable / nOS_MemAvailable
**Description:** Create, delete, allocate, free, and query memory blocks.

**Prototype:**
```c
nOS_Error nOS_MemCreate(nOS_Mem *mem, void *buffer, nOS_MemSize bsize, nOS_MemCounter bmax);
nOS_Error nOS_MemDelete(nOS_Mem *mem);
void* nOS_MemAlloc(nOS_Mem *mem, nOS_TickCounter timeout);
nOS_Error nOS_MemFree(nOS_Mem *mem, void *block);
bool nOS_MemIsAvailable(nOS_Mem *mem);
nOS_MemCounter nOS_MemAvailable(nOS_Mem *mem);
```

**How nOS Handles Memory Management:**
nOS provides a simple memory pool system for dynamic allocation in embedded environments. You define a buffer (array) for memory blocks, then use nOS to manage allocation and freeing of fixed-size blocks from this pool. This avoids fragmentation and is deterministic, making it suitable for real-time systems.

**Typical usage:**
1. Create a memory pool with a buffer and block size.
2. Allocate blocks as needed (returns pointer or NULL if unavailable).
3. Free blocks when done.
4. Query available blocks.

**Example:**
```c
#define BLOCK_SIZE 32
#define BLOCK_COUNT 10
uint8_t memBuffer[BLOCK_SIZE * BLOCK_COUNT];
nOS_Mem myMemPool;

// Create a memory pool for 10 blocks of 32 bytes each
nOS_MemCreate(&myMemPool, memBuffer, BLOCK_SIZE, BLOCK_COUNT);

// Allocate a block
void *pBlock = nOS_MemAlloc(&myMemPool, NOS_WAIT_FOREVER);
if (pBlock != NULL) {
	// Use the memory block
}

// Free the block when done
nOS_MemFree(&myMemPool, pBlock);

// Check if blocks are available
if (nOS_MemIsAvailable(&myMemPool)) {
	// There is at least one free block
}

// Get the number of available blocks
nOS_MemCounter available = nOS_MemAvailable(&myMemPool);
```

---

## Timers, Signals, Time, Alarms, Barriers

### nOS_Timer* (Tick, Process, Create, Delete, Start, Stop, etc.)
**Description:** Manage software timers with callback and priority.

**Prototype:**
```c
void nOS_TimerTick(nOS_TickCounter ticks);
void nOS_TimerProcess([uint8_t prio]);
nOS_Error nOS_TimerCreate(nOS_Timer *timer, nOS_TimerCallback callback, void *arg, nOS_TimerCounter reload, nOS_TimerMode mode[, uint8_t prio]);
nOS_Error nOS_TimerDelete(nOS_Timer *timer);
nOS_Error nOS_TimerStart(nOS_Timer *timer);
nOS_Error nOS_TimerStop(nOS_Timer *timer, bool instant);
nOS_Error nOS_TimerRestart(nOS_Timer *timer, nOS_TimerCounter reload);
nOS_Error nOS_TimerPause(nOS_Timer *timer);
nOS_Error nOS_TimerContinue(nOS_Timer *timer);
nOS_Error nOS_TimerSetReload(nOS_Timer *timer, nOS_TimerCounter reload);
nOS_Error nOS_TimerSetCallback(nOS_Timer *timer, nOS_TimerCallback callback, void *arg);
nOS_Error nOS_TimerSetMode(nOS_Timer *timer, nOS_TimerMode mode);
nOS_Error nOS_TimerSetPrio(nOS_Timer *timer, uint8_t prio);
bool nOS_TimerIsRunning(nOS_Timer *timer);
bool nOS_TimerAnyTriggered([uint8_t prio]);
```

---

### nOS_Signal* (Process, Create, Delete, Send, SetCallback, GetCount, AnyRaised)
**Description:** Manage software signals (software interrupts) with callback and priority.

**Prototype:**
```c
void nOS_SignalProcess([uint8_t prio]);
nOS_Error nOS_SignalCreate(nOS_Signal *signal, nOS_SignalCallback callback, void **buffer, nOS_SignalCounter max[, uint8_t prio]);
nOS_Error nOS_SignalDelete(nOS_Signal *signal);
nOS_Error nOS_SignalSend(nOS_Signal *signal, void *arg);
nOS_Error nOS_SignalSetCallback(nOS_Signal *signal, nOS_SignalCallback callback);
#define nOS_SignalIsRaised(s) (nOS_SignalGetCount(s) > 0)
nOS_SignalCounter nOS_SignalGetCount(nOS_Signal *signal);
bool nOS_SignalAnyRaised([uint8_t prio]);
```

---

### nOS_Time* (Tick, Get, Set, Convert, DateGet, DateSet, DateConvert, DateWait, etc.)
**Description:** Real-time module compatible with UNIX timestamp, date/time conversion, and waiting.

**Prototype:**
```c
void nOS_TimeTick(nOS_TickCounter ticks);
nOS_Time nOS_TimeGet(void);
nOS_Error nOS_TimeSet(nOS_Time time);
nOS_TimeDate nOS_TimeConvert(nOS_Time time);
bool nOS_TimeIsLeapYear(uint16_t year);
uint16_t nOS_TimeGetDaysPerYear(uint16_t year);
uint8_t nOS_TimeGetDaysPerMonth(uint8_t month, uint16_t year);
nOS_TimeDate nOS_TimeDateGet(void);
nOS_Error nOS_TimeDateSet(nOS_TimeDate timedate);
nOS_Time nOS_TimeDateConvert(nOS_TimeDate timedate);
nOS_Error nOS_TimeWait(nOS_Time time);
nOS_Error nOS_TimeDateWait(nOS_TimeDate timedate);
```

---

### nOS_Alarm* (Tick, Process, Create, Delete, SetTime, SetCallback, AnyTriggered)
**Description:** Manage software alarms with callback.

**Prototype:**
```c
void nOS_AlarmTick(void);
void nOS_AlarmProcess(void);
nOS_Error nOS_AlarmCreate(nOS_Alarm *alarm, nOS_AlarmCallback callback, void *arg, nOS_Time time);
nOS_Error nOS_AlarmDelete(nOS_Alarm *alarm);
nOS_Error nOS_AlarmSetTime(nOS_Alarm *alarm, nOS_Time time);
nOS_Error nOS_AlarmSetCallback(nOS_Alarm *alarm, nOS_AlarmCallback callback, void *arg);
bool nOS_AlarmAnyTriggered(void);
```

---

### nOS_Barrier* (Create, Delete, Wait)
**Description:** Manage thread barriers for synchronization.

**Prototype:**
```c
nOS_Error nOS_BarrierCreate(nOS_Barrier *barrier, uint8_t max);
nOS_Error nOS_BarrierDelete(nOS_Barrier *barrier);
nOS_Error nOS_BarrierWait(nOS_Barrier *barrier);
```

---

*This documentation was auto-generated from the inline comments in nOS.h. For detailed usage and platform-specific notes, refer to the source code and configuration headers.*
