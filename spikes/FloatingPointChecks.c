//
//  FloatingPointChecks.c
//  
//
//  Created by Matthew Mazzarella on 10/18/16.
//
//
#include <math.h>
#include <stdbool.h>
#include <stdio.h>


bool abosluteCheck(float expectednum, float result, float threshold);
bool relativeCheck(float expectednum, float result, float threshold);

int main(int argc, char*argv[])
{
    //Initializing some test floats
    float expectednum = 12900;
    float result = 12900.00173;
    
    //absoluteCheck will return true or false
    bool answer = abosluteCheck(expectednum, result, 001);
    
    //Prints 1 for true (within the threshold) or
    //0 for false (not within threshold)
    printf("Absolute: %d\n", answer);//DEBUG
    
    //Creating some test floats for my relative check
    float num1 = 1401.000040;
    float num2 = 1400.0000399;
    
    //relativeCheck will return true of false
    answer = relativeCheck(num1, num2, .00001);
    
    //Prints 1 for true (within the threshold) or
    //0 for false (not within threshold)
    printf("Relative: %d\n", answer);//DEBUG
}

bool abosluteCheck(float expectednum, float result, float threshold)
{
    //Calculates the absolute value of the result minus
    //the expected result. Compares this to the given threshold.
    printf("%f\n", fabs(result - expectednum));//DEBUG
    if(fabs(result - expectednum) < threshold)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

bool relativeCheck(float num1, float num2, float threshold)
{
    //Relative error is measured by comparing the error to the expected result/threshold. (More accurate)
    
    //Let's see if the error is within the threshold
    printf("%f\n",fabs((num1-num2)/num2));//DEBUG
    if((fabs((num1-num2)/num2)) <= threshold)
    {
        return true;
    }
    return false;
}
//single/double percision
//square root function
//
