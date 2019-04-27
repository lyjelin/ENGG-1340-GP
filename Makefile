
Functions.o : Functions.c
  gcc -c $^

main.o : main.c HeatherFile.h 
  gcc -c $^

whole_function : Functions.o main.o
  gcc -pedantic-errors -std=c11 $^ -o $@
