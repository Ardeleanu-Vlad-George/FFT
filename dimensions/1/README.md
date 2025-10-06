# Purpose
Learn the very basics of the FFT, by implementing in an unfussy language, with no third party libraries and code that is very modular and easy 
 to read and understand. The language of choice is ISO C99, the implementation is done for a vector read from a file hardcoded into 'main.c' 
 the output is written to another hardcoded file. No input checks need to be done, the input is coherent and FFT compatible.
The post FFT operations common in image processing are also implemented.
# Bonus
None
# MadeWith
- GCC; version 9.4.0
- GNU Make; version 4.2.1
- ISO C99
# ExampleOfUsage
For the input:
```
|data.in|
++++++++++
4
11 22 3 4
++++++++++

```
We get the following output:
```
|data.out|
+++++++++++++++++++++++
4
(176.127479,0.000000)
(208.062732,0.000000)
(255.000000,0.000000)
(208.062732,0.000000)
+++++++++++++++++++++++
```
