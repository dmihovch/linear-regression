make clean
make all
valgrind --leak-check=full ./lr
