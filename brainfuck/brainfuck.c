#include <stdint.h>
#include <stdio.h>
#include <conio.h>



int main(int argc, char** argv)
{
    static char cells[30000] = {0};
    char program[256] = {0};
    printf("Enter program:\n");
    scanf("%s",&program);
    getchar();
    char* instruction_pointer = &program[0];
    char* data_pointer = &cells[0];
    while(*instruction_pointer != '\0')
    {
        
        switch (*instruction_pointer)
        {
        case '>':
            ++data_pointer;
            break;
        case '<':
            --data_pointer;
            break;
        case '+':
            ++*data_pointer;
            break;
        case '-':
            --*data_pointer;
            break;
        case '.':
            printf("%c",*data_pointer);
            break;
        case ',':
            
            *data_pointer = getch();
            break;
        case '[':
            if(*data_pointer == 0)
            {
                int num_open = 0;
                int num_closed = 0;
                do
                {
                    
                    if(*instruction_pointer == '[')
                    {
                        num_open++;
                    }
                    else if(*instruction_pointer == ']')
                    {
                        num_closed++;
                    }
                    ++instruction_pointer;

                } while (num_open != num_closed);
                
            }
            break;
        case  ']':
            if(*data_pointer != 0)
            {
                int num_open = 0;
                int num_closed = 0;
                do
                {
                    
                    if(*instruction_pointer == '[')
                    {
                        num_open++;
                    }
                    else if(*instruction_pointer == ']')
                    {
                        num_closed++;
                    }
                    --instruction_pointer;

                } while (num_open != num_closed);
            }
            break;
            
        default:
            printf("Invalid input\n");
            return 0;
            break;
        }
        instruction_pointer++;


    }
    return 1;
}