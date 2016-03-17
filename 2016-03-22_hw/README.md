# Assignment

Write an example program showing the use of `setjmp()` and `longjmp()`
across two function calls. You should have two functions,
one of which calls the other function. Add and set a string
array variable for each function, changing its value.
Write a function that prints the string array from within each function.
Show what happens to the array upon return from the `longjmp()`.