#include <stdio.h>
#include <stdbool.h>

// https://man7.org/linux/man-pages/man5/terminal-colors.d.5.html
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

static bool balanced(char* string)
{
    int depth = 0;

    // Walk through the string character by character until the end of the string is reached (C strings end with the null terminator, "\0")
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '{') {
            depth++;
        } else if (string[i] == '}') {
            depth--;
        }

        if (depth < 0) {
            return false;
        }
    }

    return (depth == 0);
}

static void test_balanced(char* string, bool expected)
{
    bool result = balanced(string);
    if (result == expected) {
        printf(ANSI_COLOR_GREEN "PASS" ANSI_COLOR_RESET);
    } else {
        printf(ANSI_COLOR_RED "FAIL" ANSI_COLOR_RESET);
    }

    printf(": '%6s' %s balanced\n", string, result ? "is" : "is not");
}

int main()
{
    bool result;

    // Test balanced braces
    test_balanced("{}{}{}", true);
    test_balanced("{{{}}}", true);
    test_balanced("{{}{}}", true);
    test_balanced("{h}{i}", true);
    test_balanced("{{hi}}", true);
    test_balanced("", true);

    // Test unbalanced braces
    test_balanced("}{}{}{", false);
    test_balanced("{}}{{}", false);
    test_balanced("{}{}}", false);
    test_balanced("{{}{}", false);
    test_balanced("{}{}{", false);
    test_balanced("}{}{}", false);
}
