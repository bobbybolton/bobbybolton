#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void deal_with_alarm(int x) {
    printf("Alarm went off\n");
}

void control_c(int x) {
    printf("control-c\n");
}

int main() {
    signal(SIGALRM, deal_with_alarm);
    signal(SIGINT, control_c);
    alarm(5);
    int i;
    for (i = 0; i < 10; i += 1) {
        printf("%d ", i);
        fflush(stdout);
        sleep(1);
    }
    printf("Done\n");
    return 0;
}
