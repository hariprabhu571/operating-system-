Rajesh SSE:
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int files[50], indexBlock[50], indBlock, n;
void recurse1();
void recurse2();
void recurse1(){
    printf("Enter the index block: ");
    scanf("%d", &indBlock);
    if (files[indBlock] != 1){
        printf("Enter the number of blocks and the number of files needed for the index %d on the disk: ", indBlock);
        scanf("%d", &n);
    }
    else{
        printf("%d is already allocated\n", indBlock);
        recurse1();
    }
    recurse2();
}
void recurse2(){
    int ch;
    int flag = 0;
    for (int i=0; i<n; i++){
        scanf("%d", &indexBlock[i]);
        if (files[indexBlock[i]] == 0)
            flag++;
    }
    if (flag == n){
        for (int j=0; j<n; j++){
            files[indexBlock[j]] = 1;
        }
        printf("Allocated\n");
        printf("File Indexed\n");
        for (int k=0; k<n; k++)
{
            printf("%d ------> %d : %d\n", indBlock, indexBlock[k], files[indexBlock[k]]);
        }
    }
    else{
        printf("File in the index is already allocated\n");
        printf("Enter another indexed file\n");
        recurse2();
    }
    printf("Do you want to enter more files?\n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse1();
    else
        exit(0);
    return;
}
int main()
{
    for(int i=0;i<50;i++)
        files[i]=0;
    recurse1();
    return 0;
}

#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    n = 5; 
    m = 3;
    int alloc[5][3] = { { 0, 1, 0 }, 
                        { 2, 0, 0 },
                        { 3, 0, 2 },
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } };
 
    int max[5][3] = { { 7, 5, 3 }, 
                      { 3, 2, 2 },
                      { 9, 0, 2 },
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } }; 
    int avail[3] = { 3, 3, 2 };
 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
     
      if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }
    return (0);
}
