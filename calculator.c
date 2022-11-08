#include <cs50.h>
#include <stdio.h>

int main(void) {
    char answer = get_char("If you would like to sum type s, minus type m, multiply type t or do a percentage operator type p: ");
    // inputs for numbers
    int x = get_int("x: ");
    int y = get_int("y: ");
    //operators
    int sum = x + y;
    int min = x - y;
    int tim = x * y;
    int rem = x % y;
    // if statement for greater than or equal to
    if (answer == 'm') {
        printf("%i\n", min);
    } else if (answer == 's') {
        printf("%i\n", sum);
    } else if (answer == 't') {
        printf("%i\n", tim);
    } else {
        printf("%i\n", rem);
    }
}
