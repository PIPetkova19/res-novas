#include <iostream>
#include <cmath>
using namespace std;

//Covert dec to bin
long long decToBin(int dec) {
    int bin = 0;
    int counter = 1;

    while (dec) {
        bin += (dec % 2) * counter;
        dec /= 2;
        counter *= 10;
    }
    return bin;
}

//Covert bin to Gray code
void binToGraysCode(int dec) {
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
    cout << "Gray code: " << gray;
}

int main() {
    int dec;
    cin >> dec;
    binToGraysCode(dec);
}