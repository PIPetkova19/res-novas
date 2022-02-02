/*#include <iostream>
#include <cmath>
using namespace std;

//Convert dec to bin
long long int decToBin(int dec) {
    int bin = 0;
    int counter = 1;

    while (dec) {
        bin += (dec % 2) * counter;
        dec /= 2;
        counter *= 10;
    }
    return bin;
}

//Convert bin to Gray code
long long int  binToGraysCode(int dec) {
    long long binary, gray = 0;
    int lastNum = 0, penultimateNum = 0, counter = 0;
    binary = decToBin(dec);
    while (binary != 0)
    {
        lastNum = binary % 10;
        binary /= 10;
        penultimateNum = binary % 10;

        //Make XOR of both numbers
        if ((lastNum ^ penultimateNum) != 0) {
            //Pow(10, counter) makes them bigger
            gray += pow(10, counter);
        }
        counter++;
    }
    return gray;
}

//Use gray code as bin and convert it to dec
void grayCodeConversion(long long temp) {
    long long num = binToGraysCode(temp);
    int sum = 0, i = 0;
    while (num)
    {
        sum += (num % 10) * pow(2, i);
        i++;
        num = num / 10;
    }
    cout << sum;
}
int main() {
    int dec;
    cin >> dec;
    grayCodeConversion(dec);
}
*/