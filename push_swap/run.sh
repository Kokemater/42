gcc *.c -o push_swap -fsanitize=address
./push_swap "$@"