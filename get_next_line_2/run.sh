gcc -Wall -Wextra -Werror *.c -fsanitize=address  -D BUFFER_SIZE=1024 -o get_next_line 
./get_next_line