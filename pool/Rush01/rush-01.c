#include <unistd.h>



void print_board(int board[11][11], int size)
{
    for (int i = 1; i < size + 1; i++) {

        for (int j = 1; j < size + 1; j++) 
        {
            char letter = board[i][j] + '0';
            write(1, &letter, 1);
            if (j != size)
                write(1," ",1);
        }
        write(1,"\n",1);

    }
}


void obvious_move(int board[11][11], int size) 
{
    for(int i = 0; i < size +2; i++ )
    {
        for(int j = 0; j < size + 2; j++)
        {
            if ((board[i][j] == 1) && (i == 0 || i == size +1 || j == 0 || j == size +1))
            {
                if (i + 1 >= 1 && i + 1 <=4 && j >=1 && j <= 4)
                    board[i + 1][j] = 4;
                else if (i - 1 >= 1 && i - 1 <=4 && j >=1 && j <= 4)
                    board[i - 1][j] = 4;
                if (j + 1 >= 1 && j + 1 <=4 && i >=1 && i <= 4)
                    board[i][j+1] = 4;
                else if (j - 1 >= 1 && j - 1 <=4 && i >=1 && i <= 4)
                    board[i][j-1] = 4;
            }
            else if ((board[i][j] == 4) && (i == 0 || i == size +1 || j == 0 || j == size +1))
            {
                if (i + 1 >= 1 && i + 1 <=4 && j >=1 && j <= 4)
                {
                    board[i + 1][j] = 1;
                    board[i + 2][j] = 2;
                    board[i + 3][j] = 3;
                    board[i + 4][j] = 4;
                }
                else if (i - 1 >= 1 && i - 1 <=4 && j >=1 && j <= 4)
                {
                    board[i - 1][j] = 1;
                    board[i - 2][j] = 2;
                    board[i - 3][j] = 3;
                    board[i - 4][j] = 4;
                }
                if (j + 1 >= 1 && j + 1 <=4 && i >=1 && i <= 4)
                {
                    board[i][j+1] =1;
                    board[i][j+2] =2;
                    board[i][j+3] =3;
                    board[i][j+4] =4;
                }
                    
                else if (j - 1 >= 1 && j - 1 <=4 && i >=1 && i <= 4)
                {
                    board[i][j-1] =1;
                    board[i][j-2] =2;
                    board[i][j-3] =3;
                    board[i][j-4] =4;
                }
            }
        }


    }
}


void create_board(int board[11][11], int size, char *init_board) {
    int posup = 0;
    int posdown = 8;
    int posleft = 16;
    int posright = 24; 

    // Inicializamos el tablero con algún valor, por ejemplo, ceros.
    for (int i = 0; i < size + 2; i++) {
        for (int j = 0; j < size + 2; j++) {
            if (i == 0 && j >= 1 && j <= size)
            {
                board[i][j] = init_board[posup] - '0';
                posup += 2; 
            }
            else if (i == size + 1 && j >= 1 && j <= size)
            {  
                board[i][j] = init_board[posdown] - '0';
                posdown += 2; 
            }
            else if (j == 0 && i >= 1 && i <= size)
            {
                board[i][j] = init_board[posleft] - '0';
                posleft += 2;
            }
            else if (j == size + 1 && i >= 1 && i <= size)
            {
                board[i][j] = init_board[posright] - '0';
                posright += 2;
            }  
            else
            {
                board[i][j] = 0;
            }
        }
    }
}
int size_of_board(char *init_board)
{   
    int i;
    int words;

    words = 0;
    i = 0;
    while(init_board[i] != 0)
    {
        if ((init_board[i] >= '0' && init_board[i]<= '9')
            && (init_board[i + 1] == ' ' || init_board[i + 1] == '\0'))
                words++;
        else if((init_board[i] != ' '))
        {
            write(1, "Error\n",6);
            return -1;
        }
        i ++;
    }
    if ((words % 4) != 0)
    {
        write(1, "Error\n",6);
        return -1;
    }
    return (words / 4);
}


int is_full(int row, int col, int board[11][11], int size)
{
    int i = 1;
    int row_full = 1;
    int col_full = 1;
    while(i <= size)
    {
        if (board[row][i] == 0 && i != col)
            row_full = 0;
        i++;
    }
    i = 1;
    while(i <= size)
    {
        if (board[i][col] == 0 && i != row)
            col_full = 0;
        i++;
    }
    if (col_full)
        return 2;
    if (row_full)
        return 1;
    return 0;
}
// Función para verificar si es seguro colocar num en board[row][col]
int isSafe(int board[11][11], int row, int col, int num, int size)
{
    int i;
    int j;
    int jumps;
    int max_height;
    int max_jumps;
    board[row][col] = num;

// Comprobar saltos desde abajo hasta arriba
    max_height = 0;
    i = size; 
    max_jumps = board[size + 1][col];
    jumps = 0;
    while(i >= 1)
    {
        if (board[i][col] > max_height)
        {
            max_height = board[i][col];
            jumps++;
        }
        if (jumps > max_jumps && is_full(row, col, board, size) == 2)
        {
            board[row][col] = 0;
            return 0;
        }
        i--;
    }
    if (jumps != max_jumps && is_full(row, col, board, size) == 2)
        {
            board[row][col] = 0;
            return 0;
        }

// Comprobar desde arriba hasta abajo
    max_jumps = board[0][col];
    jumps = 0;
    max_height = 0;
    i = 1;
    while(i <= 4)
    {
        if (board[i][col] > max_height)
        {
            max_height = board[i][col];
            jumps++;
        }
        if (jumps > max_jumps && is_full(row, col, board, size) == 2)
        {
            board[row][col] = 0;
            return 0;
        }
        i++;
    }
    if (jumps != max_jumps &&  is_full(row, col, board, size) == 2)
        {
            board[row][col] = 0;
            return 0;
        }
// Comprobar de derecha a izquierda
    jumps = 0;
    max_height = 0;
    j = size; 
    max_jumps = board[row][size + 1];
    jumps = 0;
    while(j >= 1)
    {
        if (board[row][j] > max_height)
        {
            max_height = board[row][j];
            jumps++;
        }
        if (jumps > max_jumps && is_full(row, col, board, size) == 1)
        {
            board[row][col] = 0;
            return 0;
        }
        j--;
    }
    if (is_full(row, col, board, size) == 1)
    {
        {
        if (jumps != max_jumps)
        {
            board[row][col] = 0;
            return 0;
        }
        }    

    }

// Comprobar de izquierda a derecha  
    max_jumps = board[row][0];
    jumps = 0;
    max_height = 0;
    j = 1;
    while(j <= size)
    {
        if (board[row][j] > max_height)
        {
            max_height = board[row][j];
            jumps++;
        }
        if (jumps > max_jumps && is_full(row, col, board, size) == 1)
        {
            board[row][col] = 0;
            return 0;
        }
        j++;
    }
    if (jumps != max_jumps && is_full(row, col, board, size) == 1)
        {
            board[row][col] = 0;
            return 0;
        }

board[row][col] = 0;

// Comprobar repeticiones en las filas hacia abajo
    i = 1;
    while (row - i >= 1)
    {
        if (board[row - i][col] == num)
        {
            board[row][col] = 0;
            return 0;
        }
        i++;
    }
// Comprobar repeticiones en las filas hacia abajo
    i = 1;
    while (row + i <= size)
    {
        if (board[row + i][col] == num)
        {
            board[row][col] = 0;
            return 0;
        }
        i++;
    }
// Comprobar repeticiones en columnas hacia la izquierda
    j = 1;

    while (col + j <= size)
    {
        if (board[row][col + j] == num)
            return (0);
        j++;
    }

// comprobar repeticicones en columnas hacia la derecha
    j = 1;
    while (col - j >= 1)
    {
        if (board[row][col - j] == num)
            return (0);
        j++;
    }

    return 1;
}

//  backtracking
int skycreeper_solver(int board[11][11], int size) 
{   

    int row = -1;
    int col = -1;
    int free_squares = 0;
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                free_squares = 1;
                break;
            }
        }
        if (free_squares) {
            break;
        }
    }
    if (!free_squares) {
        return 1;
    }
    for (int num = 1; num <= size; num++) {
        if (isSafe(board, row, col, num, size)) {
            board[row][col] = num;
            if (skycreeper_solver(board, size)) {
                return 1;
            }
            board[row][col] = 0;
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        write(1, "Error\n",6);
        return 1;
    }

    int size;
    int board[11][11];
    size = size_of_board(argv[1]);
    create_board(board, size, argv[1]);
    obvious_move(board, size);
    if (skycreeper_solver(board,size) == 1) 
    {
        print_board(board,size);
    } else 
    {
        write(1, "Error\n",6);
    }
    return 0;
}
