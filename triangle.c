#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Global variable representing final mark for the task.
int final_mark = 0;


/*
 * Function:  triangle
 * --------------------
 * Given 3 side lengths as strings, returns the type of triangle:
 * NOTE: Only integer sides are considered valid!
 *
 *  length1: length of side 1
 *  length2: length of side 2
 *  length3: length of side 3
 *
 *  returns: The type of triangle, namely one of:
 *  ["Illegal", "Equilateral", "Isosceles", "Right", "Flat", "Impossible",
 *  "Scalene"]
 */
char *triangle(char *length1, char *length2, char *length3) {
        long l1   = atoi(length1);
        long l2   = atoi(length2);
        long l3   = atoi(length3);
        long temp = 0;

        // Perform Illegal Checks
        char temp_str[10];

        snprintf(temp_str, 10, "%ld", l1);
        if (strcmp(temp_str, length1) != 0) return "Illegal";

        snprintf(temp_str, 10, "%ld", l2);
        if (strcmp(temp_str, length2) != 0) return "Illegal";

        snprintf(temp_str, 10, "%ld", l3);
        if (strcmp(temp_str, length3) != 0) return "Illegal";


        // Sort (smallest to largest)
        if (l1>l2) {
                temp = l1;
                l1 = l2;
                l2 = temp;
        } if (l2>l3) {
                temp = l2;
                l2 = l3;
                l3 = temp;
        } if (l1>l2) {
                temp = l1;
                l1 = l2;
                l2 = temp;
        }

        // Classifier
        if (l1<=0 || l2 <=0 || l3<=0) {
                return "Illegal";
        }
        else if (l1==l2 && l2==l3) {
                return "Equilateral";
        }
        else if ((l1*l1)+(l2*l2)==(l3*l3)) {
                return "Right";
        }
        else if (l1+l2==l3) {
                return "Flat";
        }
        else if ((l1+l2)<l3) {
                return "Impossible";
        }
        else if (l1==l2 || l2==l3 || l3==l1) {
                return "Isosceles";
        }
        return "Scalene";
}


/*
 * Function:  print_result
 * --------------------
 * Prints final mark and percentage for task.
 */
void print_result(){
        printf("--------------------------------\n");
        printf("Tests passed: %d\n", final_mark);
        printf("Percentage complete: %d%%\n", final_mark*2);
        printf("--------------------------------\n");
}


/*
 * Function:  eq
 * --------------------
 * Compares the actual program result vs the expected print_result.
 *
 *  actual: pointer to string representing actual classification.
 *  expected: pointer to string representing expected classification.
 */
void eq(char *actual, char *expected) {
        if (strcmp(actual, expected) != 0) {
                fprintf(stderr, "Test failure, actual: %s\n", actual);
                fprintf(stderr, "Expected: %s\n", expected);
                print_result();
                exit(1);
        }
}


/*
 * Function:  test
 * --------------------
 * Runs all the tests on the triangle task.
 * NOTE: Look here to see which tests are passing/failing!
 */
void test() {
        eq(triangle("8", "8", "8"), "Equilateral"); final_mark++;
        eq(triangle("1073", "1073", "1073"), "Equilateral"); final_mark++;
        eq(triangle("15", "15", "13"), "Isosceles"); final_mark++;
        eq(triangle("15", "13", "15"), "Isosceles"); final_mark++;
        eq(triangle("13", "15", "15"), "Isosceles"); final_mark++;
        eq(triangle("25", "25", "27"), "Isosceles"); final_mark++;
        eq(triangle("25", "27", "25"), "Isosceles"); final_mark++;
        eq(triangle("27", "25", "25"), "Isosceles"); final_mark++;
        eq(triangle("3", "4", "5"), "Right"); final_mark++;
        eq(triangle("5", "12", "13"), "Right"); final_mark++;
        eq(triangle("5", "13", "12"), "Right"); final_mark++;
        eq(triangle("12", "5", "13"), "Right"); final_mark++;
        eq(triangle("12", "13", "5"), "Right"); final_mark++;
        eq(triangle("13", "5", "12"), "Right"); final_mark++;
        eq(triangle("13", "12", "5"), "Right"); final_mark++;
        eq(triangle("12", "14", "15"), "Scalene"); final_mark++;
        eq(triangle("12", "15", "14"), "Scalene"); final_mark++;
        eq(triangle("14", "12", "15"), "Scalene"); final_mark++;
        eq(triangle("14", "15", "12"), "Scalene"); final_mark++;
        eq(triangle("15", "12", "14"), "Scalene"); final_mark++;
        eq(triangle("15", "14", "12"), "Scalene"); final_mark++;
        eq(triangle("7", "9", "16"), "Flat"); final_mark++;
        eq(triangle("7", "16", "9"), "Flat"); final_mark++;
        eq(triangle("9", "16", "7"), "Flat"); final_mark++;
        eq(triangle("16", "7", "9"), "Flat"); final_mark++;
        eq(triangle("16", "9", "7"), "Flat"); final_mark++;
        eq(triangle("2", "3", "13"), "Impossible"); final_mark++;
        eq(triangle("2", "13", "3"), "Impossible"); final_mark++;
        eq(triangle("13", "2", "3"), "Impossible"); final_mark++;
        eq(triangle("0", "0", "0"), "Illegal"); final_mark++;
        eq(triangle("0", "10", "12"), "Illegal"); final_mark++;
        eq(triangle("10", "0", "12"), "Illegal"); final_mark++;
        eq(triangle("10", "12", "0"), "Illegal"); final_mark++;
        eq(triangle("-1", "-1", "-1"), "Illegal"); final_mark++;
        eq(triangle("-1", "10", "12"), "Illegal"); final_mark++;
        eq(triangle("10", "-1", "12"), "Illegal"); final_mark++;
        eq(triangle("10", "12", "-1"), "Illegal"); final_mark++;
        eq(triangle("x", "y", "z"), "Illegal"); final_mark++;
        eq(triangle("10", "12", "13.4"), "Illegal"); final_mark++;
        eq(triangle("03", "4", "5"), "Illegal"); final_mark++;
        eq(triangle("3", "04", "5"), "Illegal"); final_mark++;
        eq(triangle("3", "4", "05"), "Illegal"); final_mark++;
        eq(triangle("3x", "4y", "5z"), "Illegal"); final_mark++;
        eq(triangle("2147483648","2147483647","2147483647"),"Illegal"); final_mark++;
        eq(triangle("2147483647","2147483648","2147483647"),"Illegal"); final_mark++;
        eq(triangle("2147483647","2147483647","2147483648"),"Illegal"); final_mark++;
        eq(triangle("2147483647","2147483647","2147483647"),"Equilateral"); final_mark++;
        eq(triangle("1100000000","1705032704","1805032704"),"Scalene"); final_mark++;
        eq(triangle("2000000001","2000000002","2000000003"),"Scalene"); final_mark++;
        eq(triangle("150000002","666666671","683333338"),"Scalene"); final_mark++;
        print_result();
}


/*
 * Function:  main
 * --------------------
 * main invocation point for triangle task.
 */
//sides of triangle passed as a passed as pointers to pointers to char:
//hence **argv==*argv[]
int main (int argc, char *argv[]) {
        if (argc == 1) {
                test();
                return 0;
        }
        else if (argc == 4) {
                char *result = triangle(argv[1], argv[2], argv[3]);
                printf("%s\n", result);
                return 0;
        }
        else {
                fprintf(stderr, "Use e.g.: ./triangle 3 4 5\n");
                exit(1);
        }
}


//go into terminal
//Developer/Github/Triangles (use tab and double tab to complete directory)
//enter button
//make
//./triangle
// pwd which on e youre in
