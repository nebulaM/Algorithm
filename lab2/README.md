#Lab 2

Q1. Enter the lab file directory, compile and run the program using:

```sh
make
./insertion 12 5 9 3 2 25 8 19 200 10
```

The program outputs all zeroes. What’s wrong?

Debug the program. Identify and correct errors until “insertion” works correctly.

Here is the full [user manual for gdb] (https://sourceware.org/gdb/current/onlinedocs/gdb/)

Q2. Fill in the blanks in the following program.

```c++
#include <iostream>
int main () {

 int* p1;
 int* p2;
 int x = 5;
 int y = 15;

 p1 = &x; // x contains ____; y ____; p1 ____; p2 ____
 p2 = &y; // x contains ____; y ____; p1 ____; p2 ____
 *p1 = 6; // x contains ____; y ____; p1 ____; p2 ____
 *p1 = *p2; // x ____; y ____; p1 ____; p2 ____
 p2 = p1; // x ____; y ____; p1 ____; p2 ____
 *p1 = *p2+10; // x ____; y ____; p1 ____; p2 ____
 return 0;
}
```

Q3. Experiment with the following code:

```c++
#include <iostream>
int a = 7;
int b = 6;
int* c = &b;
void test( int& x, int y, int*& z ) {
 x++;
 y++;
 z= &a;
}
int main() {
 test(a,b,c);
 std::cout << a << " " << b << " " << *c << std::endl;
 return 0;
}
```

What happens when you modify the test arguments?

Try changing the various arguments from pass-by-reference to pass-by-value and vice-versa.

What happens?

What happens if you make b a pointer?

```c++
int* b = (int*) malloc( sizeof(int) ); // instead of “int b = 6;”
*b = 6; // new firstline of main()
// change the other “b” in main() to “*b” as well
What about y?
void test( int& x, int* y, int*& z ) {
 x++;
 (*y)++;
...
test(a,&b,c); 
```
