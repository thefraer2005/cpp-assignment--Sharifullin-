#include<hw01.h>
using namespace std;

bool isSimple(int number) 
{
    if(number<2){
        return false;
    }
    for(int i =2; i <= number/2; i++)
        {
            if(number%i==0){
                return false;
            }
        }
    return true;
}


int sumNumbers(int number){
    int sum= 0;
    while (number> 0) {
        sum += number% 10; 
        number/= 10;       
    }
    return sum;
}

int hw01(int start, int end)
{
    if (start < 10 || start > 99 || end < 10 || end > 99) {
        return -1; 
    }

   
int totalSum = 0; 
for (int i = start; i <= end; ++i) {
        if (isSimple(i)) { 
            totalSum += sumNumbers(i); 
        }
    }

    return totalSum; 
}
