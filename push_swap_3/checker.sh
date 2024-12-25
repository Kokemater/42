gcc nums_generator/num_generator.c -D SIZE=$1 -o generate_nums
gcc *.c -o push_swap -g -fsanitize=address
./push_swap $(./generate_nums) | ./checker_linux $(./generate_nums)