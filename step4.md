# Step 4

## Updating VS Code for C/C++

This is our first step using C. Make sure your editor is setup correctly.

    Objective: If you haven't already, install the official C/C++ extension for VS Code from Microsoft

&nbsp;
## Calling C code from Python

We will start by porting your "update state" type functions. IO is messy so porting the functions without IO is a good place to start.

    Objective: Write C versions of all your state update type functions.

Python code can call C code. This allows us to port your project from Python to C in stages while keeping it fully functional for testing. This is conceptually simple but tricky in practice and this step will help you understand under the hood in both languages a bit more.

https://realpython.com/python-bindings-overview/

https://stackoverflow.com/questions/145270/calling-c-c-from-python

    Objective: Call your C functions from the corresponding Python functions. All your Python unit tests should still pass.

As always, create a new branch off `main` for your changes and once you have them working, submit a PR (pull request) into `main` and set me as a reviewer.
