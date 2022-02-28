#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getline(char req[64]) {
    int i = 0;
    int ch;
    while ((ch = getchar()) != '\n') {
        req[i] = ch;
        i++;
    }
    req[i] = '\0';
    return req[0];
}

int view(char ns, long long obj[][1024], int lens[], int i, int D_long[], int B_long[]) {
    int j = 0;
    while (j < lens[i]) {
        printf("%4d: ", j+1);
        if (ns != 'b' && ns != 'B') {
            char form[] = {'%', '*', 'l', 'l', ns, '\0'};
            printf(form, D_long[i], obj[i][j]);
        }
        else if (ns == 'b' || ns == 'B') {
            int bit = 0;
            long long num = obj[i][j];
            char str_bits[1024];
            int yk = 0;
            if ((num & (1ll <<  sizeof(long long)*8-1)) != 0) {
                str_bits[yk] = '-';
                yk++;
                num = ~(num) + 1;
            }
            int z_flag = 1;
            for (int k = sizeof(long long)*8-1; k >=0; k--) {
                bit = ((num & (1ll << k)) != 0);
                if (z_flag == 0){
                    str_bits[yk] =  bit + '0';
                    yk++;
                }
                else if (z_flag == 1 && bit == 1) {
                    z_flag = 0;
                    str_bits[yk] =  bit + '0';
                    yk++;
                }
            }
            if (z_flag == 1){
                str_bits[yk] =  bit + '0';
                yk++;
            }
            str_bits[yk] = '\0';
            printf("%*s", B_long[i], str_bits);
        }
        printf("\n");
        j++;
    }
}

int view2(char ns1, char ns2, long long obj[][1024], int lens[], int i1, int i2, int D_long[], int B_long[]) {
    int j = 0;
    while (j < lens[i1] || j < lens[i2]) {
        printf("%4d: ", j+1);
        if (j < lens[i1]) {
            if (ns1 != 'b' && ns1 != 'B') {
                char form[] = {'%', '*', 'l', 'l', ns1, ' ', '|', ' ', '\0'};
                printf(form, D_long[i1], obj[i1][j]);
            }
         else if (ns1 == 'b' || ns1 == 'B') {
            int bit1 = 0;
            long long num1 = obj[i1][j];
            char str_bits1[1024];
            int yk1 = 0;
            if ((num1 & (1ll <<  sizeof(long long)*8-1)) != 0) {
                str_bits1[yk1] = '-';
                yk1++;
                num1 = ~(num1) + 1;
            }
            int z_flag1 = 1;
            for (int k = sizeof(long long)*8-1; k >=0; k--) {
                bit1 = ((num1 & (1ll << k)) != 0);
                if (z_flag1 == 0){
                    str_bits1[yk1] =  bit1 + '0';
                    yk1++;
                }
                else if (z_flag1 == 1 && bit1 == 1) {
                    z_flag1 = 0;
                    str_bits1[yk1] =  bit1 + '0';
                    yk1++;
                }
            }
            if (z_flag1 == 1){
                str_bits1[yk1] =  bit1 + '0';
                yk1++;
            }
            str_bits1[yk1] = '\0';
            printf("%*s | ", B_long[i1], str_bits1);
        }
        }
        else {
            if (ns1 != 'b' && ns1 != 'B') {
                printf("%*c ", D_long[i1]+2, '|');
            }
            else if (ns1 == 'b' || ns1 == 'B') {
                printf("%*c ", B_long[i1]+2, '|');
            }
        }



        if (j < lens[i2]) {
            if (ns2 != 'b' && ns2 != 'B') {
                char form[] = {'%', '*', 'l', 'l', ns2, '\0'};
                printf(form, D_long[i2], obj[i2][j]);
            }
        else if (ns2 == 'b' || ns2 == 'B') {
            int bit2 = 0;
            long long num2 = obj[i2][j];
            char str_bits2[1024];
            int yk2 = 0;
            if ((num2 & (1ll <<  sizeof(long long)*8-1)) != 0) {
                str_bits2[yk2] = '-';
                yk2++;
                num2 = ~(num2) + 1;
            }
            int z_flag2 = 1;
            for (int k = sizeof(long long)*8-1; k >=0; k--) {
                bit2 = ((num2 & (1ll << k)) != 0);
                if (z_flag2 == 0){
                    str_bits2[yk2] =  bit2 + '0';
                    yk2++;
                }
                else if (z_flag2 == 1 && bit2 == 1) {
                    z_flag2 = 0;
                    str_bits2[yk2] =  bit2 + '0';
                    yk2++;
                }
            }
            if (z_flag2 == 1){
                str_bits2[yk2] =  bit2 + '0';
                yk2++;
            }
            str_bits2[yk2] = '\0';
            printf("%*s", B_long[i2], str_bits2);
        }
        }
        printf("\n");
        j++;
    }
}



int put(char ns, char zn[], long long to[][1024], int i, int j, int D_long[], int B_long[]) {
    if (ns != 'b' && ns != 'B') {
        if (strlen(zn) > D_long[i]) {
            D_long[i] = strlen(zn);
        }
        char form[] = {'%', 'l', 'l', ns, '\0'};
        to[i][j] = atoll(zn);

        int bit = 0;
        long long num = to[i][j];
        char str_bits[1024];
        int yk = 0;
        if ((num & (1ll <<  sizeof(long long)*8-1)) != 0) {
            str_bits[yk] = '-';
            yk++;
            num = ~(num) + 1;
        }
        int z_flag = 1;
        for (int k = sizeof(long long)*8-1; k >=0; k--) {
            bit = ((num & (1ll << k)) != 0);
            if (z_flag == 0){
                str_bits[yk] =  bit + '0';
                yk++;
            }
            else if (z_flag == 1 && bit == 1) {
                z_flag = 0;
                str_bits[yk] =  bit + '0';
                yk++;
            }
        }
        if (z_flag == 1){
            str_bits[yk] =  bit + '0';
            yk++;
        }
        str_bits[yk] = '\0';

        if (strlen(str_bits) > B_long[i]) {
            B_long[i] = strlen(str_bits);
        }


    }
    if (ns == 'b' || ns == 'B') {
        if (strlen(zn) > B_long[i]) {
            B_long[i] = strlen(zn);
        }
        int k = 0;
        if (zn[0] == '-') {
            k = 1;
        }
        while (zn[k] != '\0') {
            to[i][j] = to[i][j] << 1;
            to[i][j] |= zn[k] & 1;
            k++;
        }
        if (zn[0] == '-') {
            to[i][j] = ~to[i][j]+1;
        }

        long long num = to[i][j];
        char str_d[1024];
        _i64toa(num, str_d, 10);
        if (strlen(str_d) > D_long[i]) {
            D_long[i] = strlen(str_d);
        }

    }
    return 0;
}

int fill(char ns, long long to[][1024], int lens[], int i, int D_long[], int B_long[]) {
    printf("send '/' after last value\n");
    int ch;
    char req[64];
    printf("%4d: ", lens[i]+1);
    while (getline(req) != '/') {

        put(ns, req, to, i, lens[i], D_long, B_long);
        lens[i]++;
        printf("%4d: ", lens[i]+1);
    }
    return 0;
}

int copy(long long obj[][1024], int lens[], int from, int to, int D_long[], int B_long[]) {
    lens[to] = 0;
    for(int j = 0; j < lens[from]; j++) {
        obj[to][j] = obj[from][j];
        lens[to]++;
    }
    D_long[to] = D_long[from];
    B_long[to] = B_long[from];
    return 0;
}

int rem(int lens[], int i, int D_long[], int B_long[]) {
    lens[i] = 0;
    D_long[i] = 0;
    B_long[i] = 0;
    return 0;
}

int one_rem(long long from[][1024], int lens[], int i, char input[]){


    int len_Y = strlen(input);
    char real[16];
    int yk = 0;
    while((yk+2) < len_Y) {
        real[yk] = input[yk+2];
        yk++;
    }
    real[yk] = '\0';
    int otv = atoi(real);
    int j = 0;
    j = otv-1;


    for (int h = j; h<lens[i]-1; h++) {
        from[i][h] = from[i][h+1];
    }
    lens[i]--;
    return 0;
}

int fix(char ns, long long to[][1024], int lens[], int i, char input[], int D_long[], int B_long[]) {


    int len_Y = strlen(input);
    char real[16];
    int yk = 0;
    while((yk+3) < len_Y) {
        real[yk] = input[yk+3];
        yk++;
    }
    real[yk] = '\0';
    int otv = atoi(real);
    int j = 0;
    j = otv-1;


    printf("send '/' after last value\n");
    int ch;
    char req[64];
    printf("%4d: ", j+1);
    while (getline(req) != '/') {
        to[i][j] = 0;
        put(ns, req, to, i, j, D_long, B_long);
        j++;
        printf("%4d: ", j+1);
    }
    return 0;
}

int insert(char ns, long long to[][1024], int lens[], int i, char input[], int D_long[], int B_long[]) {

    int len_Y = strlen(input);
    char real[16];
    int yk = 0;
    while((yk+3) < len_Y) {
        real[yk] = input[yk+3];
        yk++;
    }
    real[yk] = '\0';
    int otv = atoi(real);
    int j = 0;
    j = otv-1;

    printf("send '/' after last value\n");
    int ch;
    char req[64];
    printf("%4d: ", j+1);
    while (getline(req) != '/') {
        for (int h = lens[i]-1; h>=j; h--){
            to[i][h+1]=to[i][h];
        };
        lens[i]++;
        to[i][j] = 0;
        put(ns, req, to, i, j, D_long, B_long);
        j++;
        printf("%4d: ", j+1);
    }
    return 0;
}

int screen() {
    printf("\
 _________________________________________________________________________\n\
|    ___   ___                                                            |\n\
|       / /    //   / /                        ___      ___      //   ) ) |\n\
|      / /    //   / /         //___/ /      //   ) ) //   ) )  //___/ /  |\n\
|     / /    //   / /   ____  /____  /        ___/ /   __ / /  / __  (    |\n\
|    / /    //   / /              / /       / ____/       ) ) //    ) )   |\n\
| __/ /___ ((___/ /              / /       / /____  ((___/ / //____/ /    |\n\
|_________________________________________________________________________|\n\n\
");
}
int help() {
    printf("\
dN/bN - print set N in number system d/b, N = {1, 2, 3, 4, 5, 6}\n\
note: enter the commands side by side to output two sets at the same time\n\
AdN/AbN - add elements in number system d/b at the end of set N\n\
IdNY/IbNY - insert elements in number system d/b starting from place Y into the set N\n\
FdNY/FbNY - fix (replace) elements in number system d/b starting from place Y into the set N\n\
CNM -  copy the set N to the cell M\n\
RN - remove all elements of the set N\n\
ONY - delete element Y from the set N\n\
H - print help\n\
V - view cells\n\
E - exit the program\n\
");
}
int cells(int lens[]) {
    char form1[] = {' ', ' ' ,'\0'};
    char form2[] = {' ', '\0'};
    char *list[] = {form1, form2};
    printf("\
 __1__   __2__   __3__   __4__   __5__   __6__\n\
|     | |     | |     | |     | |     | |     |\n\
|%*d%s| |%*d%s| |%*d%s| |%*d%s| |%*d%s| |%*d%s|\n\
| pcs | | pcs | | pcs | | pcs | | pcs | | pcs |\n\
|_____| |_____| |_____| |_____| |_____| |_____|\n\n\
", 3+(lens[0]/10!=0), lens[0], list[lens[0]/10!=0], 3+(lens[1]/10!=0), lens[1], list[lens[1]/10!=0], 3+(lens[2]/10!=0), lens[2], list[lens[2]/10!=0], 3+(lens[3]/10!=0), lens[3], list[lens[3]/10!=0], 3+(lens[4]/10!=0), lens[4], list[lens[4]/10!=0], 3+(lens[5]/10!=0), lens[5], list[lens[5]/10!=0]);
}



int get_com(int scr, long long data[][1024], int lens[], int D_long[], int B_long[]) {
    char input[64];
    char com = getline(input);
    switch (com) {
        case 'D':
        case 'B':
        case 'd':
        case 'b':
            if (strlen(input) == 2) {
                view(com, data, lens, input[1]-'0'-1, D_long, B_long);
            }
            else if (strlen(input) == 4) {
                view2(com, input[2], data, lens, input[1]-'0'-1, input[3]-'0'-1, D_long, B_long);
            }
            break;
        case 'A':
        case 'a':
            fill(input[1], data, lens, input[2]-'0'-1, D_long, B_long);
            break;
        case 'I':
        case 'i':
            insert(input[1], data, lens, input[2]-'0'-1, input, D_long, B_long);
            break;
        case 'F':
        case 'f':
            fix(input[1], data, lens, input[2]-'0'-1, input, D_long, B_long);
            break;
        case 'C':
        case 'c':
            copy(data, lens, input[1]-'0'-1, input[2]-'0'-1, D_long, B_long);
            break;
        case 'R':
        case 'r':
            rem(lens, input[1]-'0'-1, D_long, B_long);
            break;
        case 'O':
        case 'o':
            one_rem(data, lens, input[1]-'0'-1, input);
            break;
        case 'V':
        case 'v':
            cells(lens);
            break;
        case 'H':
        case 'h':
        default:
            help();
            break;
        case 'E':
        case 'e':
            return 0;
    }
    return 1;
}


int main() {
    int exit_flag = 1;
    long long data[5][1024];
    int lens[5] = {0};
    int D_long[5] = {0};
    int B_long[5] = {0};
    screen();
    help();
    cells(lens);
    while (exit_flag) {
        printf(">>> ");
        exit_flag = get_com(0, data, lens, D_long, B_long);
    }
    return 0;
}
