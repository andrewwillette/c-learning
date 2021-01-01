# Learning C
Following examples and advice from [this book](http://ptgmedia.pearsoncmg.com/images/9780789751997/samplepages/0789751992.pdf)


## Lesson 1 Notes

### Brief history of C
Created by Dennis Ritchie at Bell Telephone Laboratories in 1972. It was created for the specific purpose of designing the UNIX operating system. Different versions of C were being used in many different areas, there were some headaches because of this. The American National Standards Institute (ANSI) formed a committee in 1983 to establish a standard definition of C, which became known as ANSI Standard C.

Why the name C? Its predecessor was called B. B was developed by Ken Thompson of Bell Labs. It was named B because of Bell Labs.

Interesting, don't have to label files .c, but it's recommended. Eh, I'm not sure about this. Just tested it and got error
<pre>
clang: error: linker command failed with exit code 1 (use -v to see invocation)
</pre>

### The Compiler
Translates your C code into machine language. The machine language generated by the compiler is called object code, and the disk file containing them is an object file.

My compiler on mac is gcc, installed with X-code

### The Linker
Takes one or more object files generated by a compiler and combines them into one executable program.
I believe that the linker is used even with I only write one .c file because it has to link my program with the built-in C libraries. 

My linker on mac is ld. Not really sure how to use this yet.

## Lesson 2 Notes

Looking at ``bigyear.c``, let's discuss the programs components.

The ``main()`` function - The only component required in every executable C program. Passing ``void`` is not necessary in all compilers, but the ANSI compiler recommends including it to show there is nothing sent to the ``main`` function. Per the ANSI Standard, the only statement one needs to include is the ``return`` statement.

In C, a variable must be defined before it can be used.

### How to debug a C program from the terminal? GDB? LLDB?

I'm reading about something called gdb. The GNU Debugger (GDB), a portable debugger. GDB offers extensive facilities for tracing and altering the execution of computer programs. The user can monitor and modify the values of programs' internal variables, and even call functions independently of the program's normal behavior.

GDB target processors (as of 2003 ( we out here )) include: Alpha, ARM, AVR, H8/300, Altera Nios/Nios II, System/370, System 390, X86 and its 64-bit extension X86-64, IA-64 "Itanium", Motoral 68000, MIPS, PA-RISC, PowerPC, SuperH, SPARC, and VAX. Less-known target processors supported in the standard release have included A29K, ARC, ETRAX CRIS, D10V, D30V, FR-30, FR-V, Intel i960, 68HC11, Motorola 88000, MCORE, MN10200, MN10300, NS32K, Stormy16, and Z8000. (Newer releases will likely not support some of these.) GDB has compiled-in simulators for even lesser-known target processors such like M32R or V850.

GDB is still actively developed. As of version 7.0 new features include support for Python scripting and as of version 7.8 GNU Guile scripting as well. Since version 7.0, support for "reversible debugging" -- allowing a debugging session to step backward, much like rewinding a crashed program to see what happened -- is available.

This debugger seems kind of awful honestly. I read online about good debugger and people say just learn to code you shouldn't have to debug. The hell is the C community on about? What are these people? Just don't write bugs and then you don't need a debugger? This is insanity.

Giving up on this for now, seems difficult. Having issues with gdb not being codesigned.
Unable to find Mach task port for process-id 2002: (os/kern) failure (0x5).
    (please check gdb is codesigned - see taskgated(8))

Alright, got lldb working. We out here.

This list_it.c uses fgets function... Reading the doc [here](https://devdocs.io/c/io/fgets).

<pre>
char *fgets( chat *str, int count, FILE *stream);

Reads at most ``counts - 1`` characters from the given file stream and stores them in the character array pointed to by ``str``. Parsing stops if end-of-file occurs or a newline character is found, in which case ``str`` will contain that newline character. If no errors occur, writes a null character at the position immediately after the last character written to ``str``.

The behavior is undefined if ``count`` is less than 1.
</pre>

## Lesson 3 Notes

### Regarding Variable Names

- The name can contain letters (a to z, A to Z), digits (0 to 9), and the underscore character (_)
- The first character of the name must be a letter. The underscore is also a legal first character, but its use is not recommended at the beginning of a name. A digit (0 to 9) cannot be used as the first character.
- Case matters (that is, upper- and lowercase letters). C is case-sensitive, thus, the names ``count`` and ``Count`` refer to two different variables.
- C keywords cannot be used as variable names. A keyword is a word that is part of the C langauge.

C programmers commonly use only lowercase letters in variable names, although this isn't required. Using all uppercase letters is usually reserved for the names of constants.

### Numeric Variable Types

C provides several different types of numeric variables. You need different types of variables because different numeric values have varying memory storage requirements and differ in the ease with which certain mathematical operations can be performed on them. Small integers (for example, 1, 199, and -9) require less memory to store, and your computer can perform mathematical operations (addition, multiplication, and so on) with such numbers quickly. In contrast, large integers and floating-point values (123,000,000, 3.14, or 0.000000871265, for example) require more storage space and more time for mathematical operations. By using the appropriate variable types, you ensure that your program runs as efficiently as possible.

C's numeric variables fall into the following two main categories:
- Integer variables hold values that have no fractional part (that is, whole numbers only). Integer variables come in two flavors, signed integer variables can hold positive or negative values, whereas unsigned integer variables can hold only positive values (and 0).
- Floating-point variables hold values that have a fractional part (that is, real numbers)

|Variable Type|Keyword|Bytes Required|Range|
|-------------|-------|--------------|-----|
|Character|``char``|1|``-128`` to ``127``|
|Short Integer|``short``|2|``-32767`` to ``32767``|
|Integer|``int``|4|``-2,147,483,647`` to ``2,147,483,647``|
|Long integer|``long``|4|``-2,147,483,647`` to ``2,147,483,647``|
|Long long integer|``long long``|8|``-9,223,372,036,854,775,807`` to ``9,223,372,036,854,775,807``|
|Unsigned character|``unsigned char``|1|``0`` to ``255``|
|Unsigned short integer|``unsigned short``|2|``0`` to ``655535``|
|Unsigned integer|``unsigned int``|4|``0`` to ``4,294,967,295``|
|Unsigned long integer|``unsigned long``|4|``0`` to ``4,294,967,295``|
|Unsigned long long integer|``unsigned long long``|8|``0`` to ``18,446,744,073,709,551,615``|
|Single-precision floating-point|``float``|4|``1.2E-38`` to ``3.4E38``|
|Double-precision floating-point|``double``|8|``2.2E-308`` to ``1.8E308^2``|

``int`` and ``long`` look identical. Why is this? The ``int`` and ``long`` indeed are identical on 64-bit Intel systems (PCs), but they might be different on other types of hardware. Remember that C is a flexible, portable language, so it provides different keywords for the two types. If you work on a PC, you can use ``int`` and ``long`` interchangeably.

No special keyword is needed to make an integer variable signed; integer variables are signed by default. You can, however, include the ``signed`` keyword if you want. The keywords show in the above table are used in variable declarations, which we will discuss in the next section.

``sizeof.c`` helps you determine the size of variables on your particular computer. Don't be surprised if your output doesn't match the output presented after the listing.

| Commonly Used Keyword|Full Name|
|----------------------|---------|
|`char`|`signed char`|
|`short`|`signed short int`|
|`int`|`signed int`|
|`long`|`signed long int`|
|`long long`|`signed long long int`|
|`unsigned char`|`unsigned char`|
|`unsigned short`|`unsigned short int`|
|`unsigned int`|`unsigned int`|
|`unsigned long`|`unsigned long int`|
|`unsigned long long`|`unsigned long long int`|

As you can see from this table, _short_ and _long_ types are actually just variations of the _int_ type. Most programmings don't use the full name of the variable types, rather, they use thke shorter version.

### Variable Declarations
Before you can use a variable in the C program, it must be declared. A variable declaration tells the compiler the name and type of a variable. The declaration may also initialize the variable to a specific value. If your program attempts to use a variable that hasn't been declared, the compiler generates an error message. A variable declaration has the following form:
<pre>
typename varname;
</pre>

_typename_ specifies the variable type and must be one of the keywords listed in above table. _varname_ is the variable name, which must follow the rules mentioned earlier. You can declare multiple variables of the same type on one line by separating the varaible names with commas:
<pre>
int count, number, start;
float percent, total;
</pre>

In Lesson 12 , "Understanding Variable Scope", you learn that the location of variable declarations in the source code is important because it affects the ways in which your program can use the variables. For now, you can place all the variable declarations together just before the start of the ``main()`` function.

### The _typedef_ keyword
The _typedef_ keyword is used to create a new name for an existing data type. In effect, _typedef_ creates a synonym. For example, the statement:
<pre>
typedef int integer;
</pre>
creates _integer_ as a synonym for _int_. You then can use _integer_ to definte variables of type _int_, as in this example:
<pre>
integer count;
</pre>
Note that _typedef_ doesn't create a new data type; it enables you to use a different name for only a predefined data type. The most common use of _typedef_ concerns aggregate data types, as explained in Lesson 11, "Implementing Structures, Unions, and TypeDefs." An aggregate data type consists of a combination of data types presented in this lesson. (I am sure you are a bit confused by this last sentence--dont' worry about it; it just means that the _typedef_ keyword will be much more valuable to you after you learn about structures.)

### Initializing Variables
When you declare a variable, you instruct the compiler to set aside storage space for the variable. However, the value stored in that space--the value of the variable--isn't defined. It might be zero, or it might be some random "garbage" value. Before using a variable, you should always initialize it to a known value. You can do this independently of the variable definition by using an assignment statement, as in this example:
<pre>
int count;
count = 0;
</pre>

Note that this statement uses the (=), which is C's assignment operator and is discussed further in Lesson 4, "The Pieces of a C Program: Statements, Expressions, and Operators". For now, you need to be aware that the equal sign in programming is not the same as the equal sign in algebra. If you write
<pre>
x = 12
</pre>
in an algebraic statement, you are stating a fact: "x equals c". In C, however, it means something quite different. In C it means "assign the value 12 to the variable named X".

You can also initialize a variable when it's declared. To do so, follow the variable name in the declaration statement with an equal sign and the wanted initial value:
<pre>
int count = 0;
double percent = 0.01, taxrate = 28.5;
</pre>
The first statement declares a variable called _count_ as an integer and initializes it to 0. The second statement declares two variables as doubles and initalizes them. The first, _percent_, is initialzed to 0.01. The second, _taxrate_, is initialized to _28.5_.

Be careful not to initialize a variable with a value outside the allowed range. Here are two examples of out-of-range initializations:
<pre>
short weight = 100000;
unsigned int value = -2500;
</pre>
The C compiler might not catch such errors. Your program might compile and link, but you might get unexpected results when the program runs.

### Constants
Like a variable, a _constant_ is a data storage location used by your program. Unlike a variable, the value stored in a constant can't be changed during program execution. C has two types of constants, each with its own specific uses:
- Literal constants
- Symbolic constants

#### Literal Constants
A _literal constant_ is a value that is typed directly into the source code where it is needed. Here are two examples:
<pre>
int count = 20;
float tax_rate = 0.28;
</pre>
The _20_ and _0.28_ are literal constants. The preceding statements store these values in the variables _count_ and _tax_rate_. Note that one of these constants contains a decimal point, whereas the other does not. The presence of absence of the decimal point destinguishes floating-point constants from integer constants.

A literal constant written with a decimal point is a floating-point constant and is represented by the C compiler as a double-precision number. Floating-point constants can be written in standard decimal notation, as shown in these examples:
<pre>
123.456
0.019
100.
</pre>
Note that the third constant, _100._, is written with a decimal point even though it's an integer. The decimal point causes the C compiler to treat the constant as a double-precision value. Without the decimal point, it is treated as an integer constant.

Floating-point constants can also be written in scientific notation. You might recall from high school math that scientific notation represents a number as a decimal part multiplied by _10_ to a positive or negative power. Scientific notation is particularly useful for representing extremely large and extremely small values. In C, scientific notation is written as a decimal number followed immediately by an _E_ or _e_ and the exponent.

|`1.23E2`|`1.23 times 10 to the 2nd power, or 123`|
|`4.08e6`|`4.08 times 10 to the 6th power, or 408000`|
|`.85e-4`|`.85 times 10 to the -4th power, or .000085`|
A constant written without a decimal point is represented by the compiler as an integer number. Integer constants can be written in three different notations:

- A constant starting with any digit other than 0 is interpreted as a decimal integer (that is, the standard base-10 number system). Decimal constants can contain the digits 0 to 9 and a leading minus or plus sign. (Without a leading minus or plus sign, a constant is assumed to be positive).
- A constant starting with the digit 0 is interpreted as an octal integer (the base-8 number system). Octal constants can contain the digits 0 through 7 and a leading minus or plus sign.
- A constant starting with _0x_ or _0X_ is interpreted as a hexadecimal constant (the base-16 number system). Hexadecimal constants can contain the digits 0 through 9, the letters A through F, and a leading minus or plus sign.

#### Symbolic Constants
A _symbolic constant_ is a constant represented by a name (symbol) in your program. Like a literal constant, a symbolic constant can't change. Whenever you need the constant's value in your program, you use its name as you would use a variable name. The actual value of the symbolic constant needs to be entered only once, when it is first defined.

Symbolic constants have two significant advantanges over literal constants, as the following example shows. Suppose that you write a program that performs a variety of geometrical calculations. The program frequently needs the value _π_ (3.14) for its calculations. (You might recall from geometry class that _π_ is the ratio of a circle's circumference to its diameter.) For example, to calculate the circumference and area of a circle with a known radiu, you could write
<pre>
circumference = 3.14 * (2 * radius);
area = 3.14 * (radius) * (radius)
</pre>
The asterisk (*) is C's multiplication operator and is covered in Lesson 4. Thus, the first of these statements means "Multiply 2 times the value stored in the variable _radius_, and then multiple the result by 3.14. Finally, assign the result to the variable named _circumference_."

If, however, you define a symbolic constant with the name _PI_ and the value 3.14, you could write 
<pre>
circumference = PI * (2 * radius);
area = PI * (radius)*(radius);
</pre>
The resulting code is clearer. Rather than puzzling over what the value _3.14_ is for, you can see immediately that the constant _PI_ is used.

The second advantage of symbolic constants becomes apparent when you need to change the constant. Continuing with the preceding example, you might decide that for greater accuracy your program needs to use a value of _PI_ with more decimal places: _3.14159_ rather than _3.14_. If you had used literal constants _PI_, you would have to go through your source code and change each occurrence of the value from _3.14_ to _3.14159_. With a symbolic constant, you need to make a change only in the place in which the constant is defined. The rest of your code would not need to be changed.

##### Defining Symbolic Constants
C has two methods for defining a symbolic constant: the ``#define`` directive and the ``const`` keyword. the ``#define`` directive is used as follows:
<pre>
#define CONSTNAME literal
</pre>
This creates a constant named ``CONSTNAME`` with the value of _literal_. __literal__ .
