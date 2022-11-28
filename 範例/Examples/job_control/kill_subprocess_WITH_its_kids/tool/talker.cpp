#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
using namespace std;

int main()
{
    for (int i=0;i<50;i++)
    {
        printf("+%d\n",i);
        sleep(1);
    }
}