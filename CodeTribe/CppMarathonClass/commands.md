- To Compile C++ File : g++ hello.cpp
    - The above command with create a file name a.out which is executable
    - To execute this file use : ./a.out

- To Compile C++ File with specific output name : g++ hello.cpp -o run
    - The above command with create a file name run which is executable
    - To execute this file use : ./run

- To get the preprocessor output use : g++ -E hello.cpp
- To dump the output of preprocessing in a file use : g++ -E hello.cpp > temp.cpp
- To get the assemly code use : g++ -S hello.cpp
- To get the executable file use : g++ -c hello.

- Few more handy commands
    - ls : to print the list of files
    - cat hello.cpp : to print the content of a file
    - touch hello.cpp : Creates a new file

- Compiler optimisations
    - g++ -O3 compiler_optimisation.cpp -o run2