#include <stdio.h> 
#include <stdbool.h>

int main() { int n, r;
printf("Enter number of processes : "); scanf("%d", &n);

printf("Enter number of resources : "); scanf("%d", &r);

int max[n][r], alloc[n][r], need[n][r]; int avail[r];
bool done[n];

printf("Enter maximum requirement : \n"); for(int i = 0; i < n; i++) {
for(int j = 0; j < r; j++) scanf("%d", &max[i][j]);
done[i] = false;
}

printf("Enter allocated matrix : \n"); for(int i = 0; i < n; i++) {
for(int j = 0; j < r; j++) scanf("%d", &alloc[i][j]);
}
printf("Resource Vector : "); for(int j = 0; j < r; j++)
scanf("%d", &avail[j]);

for(int i = 0; i < n; i++) for(int j = 0; j < r; j++)
need[i][j] = max[i][j] - alloc[i][j]; int completed = 0;
while(completed < n) { bool found = false; for(int i = 0; i < n; i++) {
if(!done[i]) {
bool canRun = true; for(int j = 0; j < r; j++) {
if(need[i][j] > avail[j]) { canRun = false; break;
 
}
}

if(canRun) {
for(int j = 0; j < r; j++) avail[j] += alloc[i][j];

done[i] = true; completed++; found = true;
}
}
}
if(!found) {
printf("Deadlock detected"); return 0;
}
}

printf("Deadlock not detected. Safe sequence is available"); return 0;
}
