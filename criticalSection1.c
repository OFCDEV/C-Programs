#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int shrd = 0;
void process(int inc) {
 int x = shrd;
 x += inc;
 sleep(1);
 shrd = x;
 printf("Process: shrd = %d\n", shrd);
}
int main() {
 pid_t pid1, pid2;
 pid1 = fork();
 if (pid1 == 0) process(1);
 else {
 pid2 = fork();
 if (pid2 == 0) process(-1);
 else {
 waitpid(pid1, NULL, 0);
 waitpid(pid2, NULL, 0);
 printf("Final value: %d\n", shrd);
 }
 }
 return 0;
}