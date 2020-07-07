#include <iostream>
#include <random>
#include <ctime>
#include <stdio.h>
using namespace std;
 
int main()
{ 
    srand(time(NULL));
    char arr[5];
    arr[4] = '\0';
    bool condition = 0, exitCond = true;;
    char input[5];
    input[4] = '\0';
    for (int i = 0; i < 4; i++) {
        do {
            condition = false;
            arr[i] = rand() % 10+'0';
            for (int k = 0; k < i; k++) {
                if (arr[k] == arr[i])condition = true;
            }
        } while (condition);
    } 
    cout << "I made a number!" << endl;
    while(exitCond){
    cout << "Input 4 digit:" << endl;
    condition = false;
    for (int i = 0; i < 4; i++) {
        input[i] = getchar();
        if (input[i] == '\n') {
            input[i] = getchar();
        }
        if (input[i] >= '0' && input[i] <= '9') { 
            for (int k = 0; k < i; k++) {
                if (input[k] == input[i])condition = true;
            }
            if (condition) {
                cout << "The digits must be different!" << endl;
                while (getchar() != '\n');
                i = 0;
            }
        }
        else {
            cout << "U need input digits, little dummy!" << endl;
            while (getchar() != '\n');
            i = 0;
        }
    }
    condition = false;
    int bulls=0, cows=0;
    for (int i = 0; i < 4; i++) {
        for (int k = 0; k < 4; k++) {
            if (arr[i] == input[k]) {
                if (i == k) {
                    bulls++;
                }
                else {
                    cows++;
                }
            }
        }
    }
    cout << "here " << bulls << " bulls and " << cows << " cows" << endl;
    if (bulls == 4) {
        cout << "Congratulations! My number is: "<<arr<<"! Would you like to continue?(y/n)" << endl;
        char tmpInp = getchar();
        if (tmpInp == '\n') {
            tmpInp = getchar();
        }
        if (tmpInp != 'y') {
            exitCond = false;
        }
    }
    }
    return 0;
}
