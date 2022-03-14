#include <stdio.h>
#include <string.h>
int view(long long obj[], int len[], int max_len[]) {
    for (int j = 0; j<len[0]; j++) {
        printf("%4d: ", j+1);
        int bit = 0;
        long long num = obj[j];
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
        printf("%*s | ", max_len[0], str_bits);
        printf("%*lld\n", max_len[0], obj[j]);
    }
}
int put(char zn[], long long to[], int j, int max_len[]){
        if (strlen(zn) > max_len[0]) {
            max_len[0] = strlen(zn);
        }

        int k = 0;
        if (zn[0] == '-') {
            k = 1;
        }
        while (zn[k] != '\0') {
            to[j] = to[j] << 1;
            to[j] |= zn[k] & 1;
            k++;
        }
        if (zn[0] == '-') {
            to[j] = ~to[j]+1;
        }
        return 0;
}
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
int fill(long long obj[], int len[], int max_len[]) {
    printf("send '/' after last value\n");
    int ch;
    char req[64];
    printf("%4d: ", len[0]+1);
    while((getline(req)) != '/') {
        put(req, obj, len[0], max_len);
        len[0]++;
        printf("%4d: ", len[0]+1);
    }
    return 0;
}
int main() {
    long long data[1024] = {0,};
    int len[] = {0};
    int max_len[] = {0};
    fill(data, len, max_len);
    printf("------------------------\n");
    view(data, len, max_len);
    return 0;
}
