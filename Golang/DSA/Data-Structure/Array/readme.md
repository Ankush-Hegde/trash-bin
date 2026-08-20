In Go, an array is a fixed-size sequence of elements of the exact same data type. The size of an array is determined at compile time and forms part of its type system (meaning [5]int and [10]int are completely distinct, incompatible types). Because arrays cannot be resized, Go developers typically prefer using Slices, which act as dynamic, flexible wrappers around arrays

Key Differences Illustrated Above

- Syntax Distinction: Arrays explicitly define size [5]int or [...]string. Slices leave the brackets empty []int.
- Shared Storage: sliceFromPrimes := primes[1:4] does not allocate a copy of the numbers. It creates a window pointing directly inside primes. Changing sliceFromPrimes[0] immediately overwrites the array value.
- The append() function: Arrays cannot be resized. Slices use append() to dynamically scale size automatically.

length & capacity
- Length (len) is the exact number of elements currently inside the slice. This is the data you can actively read, write, or loop through.
- Capacity (cap) is the total number of elements the underlying array can hold before Go is forced to allocate new memory. It counts from the start of the slice to the very end of that backing array.