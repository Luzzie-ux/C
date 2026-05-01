*This README is made for the sole reason of learning how to utilize linked lists, made by Luz*

#Programming in the C Language

As a low-level language that lets us handle memory manually and dynamically, C gives us pointers to acess memory addresses and its values to do so you only need

    >The Asterisk *

An `*` signifies that now a variable or its name points to its address.

So whenever we call `char   *name` we create a var that now points to where the var name lives but not what char name stores. So if we use `printf("%p", name)` the program will print to the standard output the address of name.

To acess what name stores we need to dereference it by adding `*` again to our var so when we do `printf("%s", *name)` we now print what is found inside char name. 
