#include <string.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    char    buffer[1024], *line;
    int t1, t2, warned1;

    if (timeout_init()) {
        fprintf(stderr, "timeout_init(): %s.\n", strerror(errno));
        return 1;
    }

    printf("You have five seconds to type something.\n");
    t1 = timeout_set(2.5); warned1 = 0;
    t2 = timeout_set(5.0);
    line = NULL;

    while (1) {

        if (timeout_passed(t1)) {
            /* Print only the first time we notice. */
            if (!warned1++)
                printf("\nTwo and a half seconds left, buddy.\n");
        }

        if (timeout_passed(t2)) {
            printf("\nAw, just forget it, then.\n");
            break;
        }

        line = fgets(buffer, sizeof buffer, stdin);
        if (line) {
            printf("\nOk, you typed: %s\n", line);
            break;
        }
    }

    /* The two timeouts are no longer needed. */
    timeout_unset(t1);
    timeout_unset(t2);

    /* Note: 'line' is non-NULL if the user did type a line. */

    if (timeout_done()) {
        fprintf(stderr, "timeout_done(): %s.\n", strerror(errno));
        return 1;
    }

    return 0;
}
