#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("sizeof(char):               %lu\n", sizeof(char));
    printf("sizeof(unsinged char):      %lu\n", sizeof(unsigned char));
    printf("sizeof(signed char):        %lu\n", sizeof(signed char));
    printf("sizeof(int8_t):             %lu\n", sizeof(int8_t));
    printf("sizeof(uint8_t):            %lu\n", sizeof(uint8_t));
    printf("sizeof(short):              %lu\n", sizeof(short));
    printf("sizeof(unsigned short):     %lu\n", sizeof(unsigned short));
    printf("sizeof(signed short):       %lu\n", sizeof(signed short));
    printf("sizeof(int16_t):            %lu\n", sizeof(int16_t));
    printf("sizeof(uint16_t):           %lu\n", sizeof(uint16_t));
    printf("sizeof(int):                %lu\n", sizeof(int));
    printf("sizeof(unsigned int):       %lu\n", sizeof(unsigned int));
    printf("sizeof(signed int):         %lu\n", sizeof(signed int));
    printf("sizeof(int32_t):            %lu\n", sizeof(int32_t));
    printf("sizeof(uint32_t):           %lu\n", sizeof(uint32_t));
    printf("sizeof(long):               %lu\n", sizeof(long));
    printf("sizeof(unsigned long):      %lu\n", sizeof(unsigned long));
    printf("sizeof(signed long):        %lu\n", sizeof(signed long));
    printf("sizeof(int64_t):            %lu\n", sizeof(int64_t));
    printf("sizeof(uint64_t):           %lu\n", sizeof(uint64_t));
    printf("sizeof(long long):          %lu\n", sizeof(long long));
    printf("sizeof(unsigned long long): %lu\n", sizeof(unsigned long long));
    printf("sizeof(signed long long):   %lu\n", sizeof(signed long long));
    return 0;
}
