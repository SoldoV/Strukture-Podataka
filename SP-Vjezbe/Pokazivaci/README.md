# C Programming Pointers

*Because pointers can be ugh*

Pointers are powerful features of C and (C++) programming that differentiates it from other popular programming languages like: Java and Python.

Pointers are used in C program to access the memory and manipulate the address.

## Address in C

Before you get into the concept of pointers, let's first get familiar with address in C.

If you have a variable `var` in your program, `&var` will give you its address in the memory, where `&` is commonly called the reference operator.

You must have seen this notation while using scanf() function. It was used in the function to store the user inputted value in the address of `var`.

 ```c++
  scanf("%d", &var);
  ```
  
## Input  
 ```c++  
/* Primjer korištenja adresnog operatora u C-u. */

#include <stdio.h>

int main()
{
	int var = 5;
	printf("Vrijednost: %d\n", var);
	printf("Adresa: %x\n", &var);  //Obratite pažnju na adresni operator & prije var
	return 0;
}
  ```
## Output
 ```c++  
Value: 5 
Address: 2686778
  ```
**Note:** You may obtain different value of address while using this code.

In above source code, value 5 is stored in the memory location 2686778. `var` is just the name given to that location.
