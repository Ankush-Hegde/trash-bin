`malloc` (Memory Allocation): Allocates a specified number of bytes in memory and returns a pointer to the first byte. It does not initialize the memory, meaning the allocated space contains whatever "garbage" data was previously left there.

`calloc` (Contiguous Allocation): Allocates memory for an array of elements, clears all the bytes by setting them to zero, and returns a pointer to the start.

`realloc` (Re-allocation): Changes the size of a previously allocated memory block. It can expand or shrink the block, preserving existing data up to the minimum of the old and new sizes, and will allocate a new block and copy data over if the current block cannot be expanded in place.

`free` Deallocates a block of memory that was previously allocated by malloc, calloc, or realloc, returning it back to the system heap so the memory can be reused and prevent memory leaks.