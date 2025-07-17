#include <iostream>

char ft_to_upper(char letter)
{
    if (letter >= 'a' && letter <= 'z')
        letter -= 'a' - 'A';
    return (letter);
}

int main(int argc, char **argv)
{
    char    letter;

    if (argc == 1)
        std:: cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" <<std::endl;
    else
    {
    for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j] != 0; j++)
            {
                letter = ft_to_upper(argv[i][j]);
                std::cout << letter;
            }
        }
        std::cout << std::endl;
    }
    return (0);
}