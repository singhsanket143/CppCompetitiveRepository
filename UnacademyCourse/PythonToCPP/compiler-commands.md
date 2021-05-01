## Following are the useful commands for cpp codes

- g++ file.cpp (Creates an exec file with name a.out)
- g++ file.cpp -o run (Creates an exec file with name run)
- g++ -E file.cpp > f.cpp (Dumps the output of preprocessing step to f.cpp, -E flag is for preprocessor expansion and comment removal step)
- g++ -S file.cpp (Creates and assembly level code file.s)
- g++ -c file.s (Creates object code file.o viz non exec)

- g++ -Ox file.cpp -o run (x : {1,2,3} it will introduce x level of optimisation to your code)


