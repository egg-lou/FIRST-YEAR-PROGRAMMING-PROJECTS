#include <stdio.h>


// pointer = a 'variable-like' reference that holds a memory address to another variable, array, etc.
//           some tasks are performed more easily with pointers 

//           * = indirection  operator (value at address)
//           & = address operator (to get the address of the variable)

            // format specifiers to print the address of a variable "%x" or "%p"

// if you are using vscode highlight the code the ctrl + /

//  We can use pointers to be passed on a function
// void printAge(int *pAge){  // use the indirection operator to declare a variable
//     printf("\nYou are %d years old\n", *pAge);
// }


// int SumOfElements(int *A, int size){ 
//     int i, sum = 0;

//     for(i = 0; i < 5; i++){
//         sum+= A[i];

        // sum+= *(A+i);  // you can do it this way too 
//     }
//     return sum;
// }



int main(){

    int *pAge = NULL;  // pointer variable ready to accept the address of a normal variable it's best practice to use a NULL value when declaring a pointer variable

    int age = 21;  // normal variable that holds a value of 21

    pAge = &age;  // pass the address of the age variable to give access to the pointer variable Age
    
    // *pAge is pointing to the memory address of the age variable which is at 0061FF18 or 61ff18


    printf("\nThe address where *pAge is pointing at using the p format specifier: %p\n", pAge);  // you may use %p or %x to print the address and don't use the indirection operator for this one just the pointer variable Age

    printf("\nThe address where *pAge is pointing at using the x format specifier: %x\n", pAge);  // you may use %p or %x to print the address and don't use the indirection operator for this one just the pointer variable Age

    printf("\nThe address where *pAge is pointing at using the p format specifier + 2: %p\n", pAge + 2);  // you may use %p or %x to print the address and use the & ampersand to print the address of the age variable + 2

    printf("\nThe address where *pAge is pointing at using the p format specifier - 2: %p\n", pAge - 2);  // you may use %p or %x to print the address and use the & ampersand to print the address of the age variable - 2

    // printf("\n\n=================================================================================\n\n");


    // printf("\nThe address of age using the p format specifier: %p\n", &age);  // you may use %p or %x to print the address and use the & ampersand to print the address of the age variable

    // printf("\nThe address of age using the x format specifier: %x\n", &age);  // you may use %p or %x to print the address and use the & ampersand to print the address of the age variable

    // printf("\nThe address of age using the p format specifier + 2: %p\n", &age + 2);  // you may use %p or %x to print the address and use the & ampersand to print the address of the age variable + 2

    // printf("\nThe address of age using the p format specifier - 2: %p\n", &age - 2);  // you may use %p or %x to print the address and use the & ampersand to print the address of the age variable - 2


    // printf("\n\n=================================================================================\n\n");


    // printf("\nThe value of age: %d\n", age);  // print the value held by age

    // printf("\nThe value stored at the address pointed at by *pAge: %d\n", *pAge);  // to print the value that the memory address holds use the indirection operator also called as dereferencing 


    // to know the size of a variable we can use the sizeof(variable) function

    // printf("\nsize of age: %d bytes\n", sizeof(age));  // size of age variable  
    
    // printf("\nsize of *pAge: %d bytes\n", sizeof(pAge));  // size of pAge pointer variable  

    // printAge(pAge); // giving the value held by the pointer pointing at an address to a function for it to use

    // printf("\n\n=================================================================================\n\n");

    // how to point a pointer to a pointer that is pointing to a variable

    // basically **ptr2  ->  *ptr1  ->  num 

    // funnily enough we can also point to a pointer that is pointing to a pointer that is also pointing on a pointer and a pointer that is pointing to a num

    // basically ***ptr3  -> **ptr2  ->  *ptr1  ->  num 

    // int num = 12;
    // int *ptr1 = NULL;
    // int **ptr2 = NULL;
    // int ***ptr3 = NULL;


    // ptr1 = &num;
    // ptr2 = &ptr1;
    // ptr3 = &ptr2;

    // printf("\nadress of num: %p\n", &num);
    // printf("\nadress where *ptr1 is pointing to: %p\n", ptr1);
    // printf("\nadress where **ptr2 is pointing to: %p\n", ptr2);
    // printf("\nadress where ***ptr3 is pointing to: %p\n", ptr3);

    // printf("\n\n");

    // printf("\nvalue of num: %d\n", num);
    // printf("\nvalue of where *ptr1 is pointing to: %d\n", *ptr1);
    // printf("\nvalue of where **ptr2 is pointing to: %d\n", **ptr2);
    // printf("\nvalue of where ***ptr3 is pointing to: %d\n\n", ***ptr3);


    // printf("\n\n=================================================================================\n\n");

    // Pointers and Arrays

    // int = 4 bytes
    // A ->  5 x 4  = 20 bytes 

    /*
    Contigous block of memory meaning they are close to one another or in a sequence
    Example:
    
    address:  |  200  |  204  |  208  |  212  |  216  |
    data:     |   1   |   3   |   5   |   2   |   9   |
    index:    |  A[0] |  A[1] |  A[2] |  A[3] |  A[4] |

    How to access the memory and value with pointers?

    Address: &A[i] or A(i + 1)
    Address: A[i] or *A(i + 1)

    &A[i] = 200
    &A[i + 1] = 204
    &A[i + 2] = 208
    &A[i + 3] = 212
    &A[i + 4] = 216
    
    A = 1
    *(A + 1) = 3 
    *(A + 2) = 5 
    *(A + 3) = 2 
    *(A + 4) = 9 

    */

   // so how do we access it using a for loop for printing or might be accessing something

    // int A[] = {1, 3, 5, 2, 9};

    // int i;
    // int *p = NULL;
    // p = A;

    // the 1st way
    // for (i = 0; i < 5; i++){
    //     printf("Address = %p\n", &A[i]);
    //     printf("Address = %p\n", A + i);
    //     printf("Value = %d\n", A[i]);
    //     printf("Value = %d\n", *(A + i));
    // }

    // printf("\n \n");


    // the 2nd way using the p pointer variable as a means to traverse the whole array

    // for(i =0; i < 5; i++){
    //     printf("Address = %p\n", p);
    //     printf("Value = %d\n", *p);
    //     p++; // we increment p not A because it is invalid
    // }

    // printf("\n");


    // printf("\n\n=================================================================================\n\n");

    // So how to pass an array into a function??
    // Go to the top and check how the function looks 
    // Name of function SumOfElements


    // int A[] = {1, 3, 5, 2, 9};


    // calculate the size of the array
    // int size = sizeof(A)/sizeof(A[0]);

    // function call
    // int total = SumOfElements(A, size);

    // printf("\nSum of Elements = %d\n", total);

    // printf("\n");

    return 0;
}