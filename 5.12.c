#include <stdio.h>
#include <ctype.h>


union byte_to_bit
{
    unsigned char value;
    struct bit_t
    {
    unsigned char b7 : 1;
    unsigned char b6 : 1;
    unsigned char b5 : 1;
    unsigned char b4 : 1;
    unsigned char b3 : 1;
    unsigned char b2 : 1;
    unsigned char b1 : 1;
    unsigned char b0 : 1;
    }bit;
} byte;

int encode(const char *input, char *txt, const char *output)
{
    if(input == NULL || output == NULL || txt == NULL)
    {
        return 1;
    }
    union byte_to_bit byte_from_jpg, byte_from_text;
    FILE *finput = fopen(input, "rt");
    if(finput == NULL)
    {
        return 2;
    }
    FILE *foutput = fopen(output, "wt");
    if(foutput == NULL)
    {
        fclose(finput);
        return 4;
    }
    byte_from_jpg.value=0;
    byte_from_text.value=0;
    int dig_cnt=0;

    for(int i = 0 ; *(txt+i) != '\0' ;)
    {
        byte_from_text.value = *(txt+i);
        unsigned char c = fgetc(finput);

        if(c == ' ' || c == '\n') fprintf(foutput, "%c", c);
        else if(isdigit(c))
        {
            ungetc(c,finput);

            fscanf(finput, "%hhu", &byte_from_jpg.value);

            switch (dig_cnt)
            {
                case 0:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b0;
                    dig_cnt++;
                    break;
                case 1:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b1;
                    dig_cnt++;
                    break;
                case 2:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b2;
                    dig_cnt++;
                    break;
                case 3:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b3;
                    dig_cnt++;
                    break;
                case 4:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b4;
                    dig_cnt++;
                    break;
                case 5:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b5;
                    dig_cnt++;
                    break;
                case 6:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b6;
                    dig_cnt++;
                    break;
                case 7:
                    byte_from_jpg.bit.b7 = byte_from_text.bit.b7;
                    i++;
                    dig_cnt=0;
                    break;
                default:
                    break;
            }
            fprintf(foutput, "%hhu", (byte_from_jpg.value));
        }
        else
        {
            fclose(finput);
            fclose(foutput);
            return 3;
        }
    }

    while(1)
    {
        int c = fgetc(finput);
        if(c == EOF) break;
        else if(isdigit(c))
        {
            ungetc(c, finput);
            fscanf(finput,"%hhu", &byte_from_jpg.value);
            byte_from_jpg.bit.b7=0;
            fprintf(foutput,"%hhu", byte_from_jpg.value);
        }
        else fprintf(foutput, "%c", c);
    }

    fclose(finput);
    fclose(foutput);
    return 0;
}


int decode(const char * filename, char *txt, int size)
{
    if(filename == NULL || txt == NULL || size <=0)
    {
        return 1;
    }
    FILE *finput = fopen(filename, "rt");
    if(finput == NULL)
    {
        return 2;
    }
    union byte_to_bit byte_from_file, text;
    char *ptr = txt;
    for(int i =0 ; i<size-1 ; i++)
    {
        if(feof(finput)) break;
        for(int j = 0; j < 8 ; j++)
        {
            int res = fscanf(finput, "%hhu", &(byte_from_file.value));
            if(res != 1)
            {
                fclose(finput);
                return 3;
            }
            if(feof(finput)) break;
            switch (j){
                case 0:
                    text.bit.b0 = byte_from_file.bit.b7;
                    break;
                case 1:
                    text.bit.b1 = byte_from_file.bit.b7;
                    break;
                case 2:
                    text.bit.b2 = byte_from_file.bit.b7;
                    break;
                case 3:
                    text.bit.b3 = byte_from_file.bit.b7;
                    break;
                case 4:
                    text.bit.b4 = byte_from_file.bit.b7;
                    break;
                case 5:
                    text.bit.b5 = byte_from_file.bit.b7;
                    break;
                case 6:
                    text.bit.b6 = byte_from_file.bit.b7;
                    break;
                case 7:
                    text.bit.b7 = byte_from_file.bit.b7;
                    break;
                default:
                    break;

            }
        }
        *ptr = text.value;
        ptr++;
    }
    *ptr='\0';
    fclose(finput);
    return 0;
}


int main() {
    char input[31], output[31], text[1001];
    char a;
    printf("Do you want to encode (E/e) or decode (D/d) a message?: ");
    scanf("%c", &a);
    while(getchar()!='\n');
    if(a == 'd' || a == 'D')
    {
        printf("Enter input: ");
        scanf("%30[^\n]s", input);
        while(getchar()!='\n');
        char *ptr;
        ptr=text;
        int res = decode(input, ptr, 1001);
        if(res == 2)
        {
            printf("Couldn't open file");
            return 4;
        }
        if(res == 3)
        {
            printf("File corrupted");
            return 6;
        }
        for(int i = 0 ; *(text+i) != '\0' ; i++)
        {
            printf("%c", *(text+i));
        }
    }
    else if(a == 'e' || a == 'E')
    {
        printf("Enter text to be encoded: ");
        scanf("%1000[^\n]", text);
        while(getchar()!='\n');
        printf("Enter input: ");
        scanf("%30[^\n]s", input);
        while(getchar()!='\n');
        printf("Enter output: ");
        scanf("%30[^\n]s", output);
        while(getchar()!='\n');
        int res = encode(input, text, output);
        if(res == 2)
        {
            printf("Couldn't open file");
            return 4;
        }
        if(res == 3)
        {
            printf("File corrupted");
            return 6;
        }
        if(res == 4)
        {
            printf("Couldn't create file");
            return 5;
        }
        printf("File saved");
    }
    else
    {
        printf("Incorrect input data");
        return 1;
    }
    //encode("00119.jpeg.txt","The biotechnology wave is similar to the information technology wave of the 1980s and 1990s. - Dietmar Hopp", "output.txt");

    return 0;
}