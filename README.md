*This README is made for the sole reason of learning how to utilize linked lists, made by Luz*

#Programming in the C Language

##Pointers

As a low-level language that lets us handle memory manually and dynamically, C gives us pointers to acess memory addresses and its values to do so you only need

    >The Asterisk *.

An `*` signifies that now a variable or its name points to its address.

So whenever we call `char   *name` we create a var that now points to where the var name lives but not what char name stores. So if we use `printf("%p", name)` the program will print to the standard output the address of name.

To acess what `name` stores we need to dereference it by adding `*` next to our var, now when we call `printf("%s", *name)` whatever is inside the address will be printed.

    >Think of pointers as coordenates, when we initizalize char *name it will be considered as the address of where "name" lives.

    >And when we dereference it, we enter its home, being able to see what is inside :D.

In another subject, arrays can also be considered pointers for the way they work internally, not being so different in nature but syntax.

Because of that, arrays will eventually decay into pointers and the prove of that is the different way they can be written `str[i] == *(str + i)`.
