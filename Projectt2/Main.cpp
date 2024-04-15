#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"

using namespace std;

void convertIntegerToBinary(int number);
void convertFractionToBinary(double fraction);

int main() {
    while (true) {
        cout << "\nEnter a decimal number or type 'exit' to stop: ";
        string userInput;
        getline(cin, userInput);

        if (userInput == "exit" || userInput == "EXIT") {
            cout << "Thank you for using the binary converter. Goodbye!" << endl;
            break;
        }

        try {
            double decimalNumber = stod(userInput);
            int integerPart = static_cast<int>(decimalNumber);
            double fractionalPart = decimalNumber - integerPart;

            convertIntegerToBinary(integerPart);
            convertFractionToBinary(fractionalPart);
        }
        catch (const invalid_argument&) {
            cout << "Please provide a valid decimal number." << endl;
        }
        catch (const out_of_range&) {
            cout << "The number you entered is too large." << endl;
        }
    }
    return 0;
}

void convertIntegerToBinary(int number) {
    BinaryStack stack;
    if (number == 0) {
        stack.pushData(0);
        cout << "Binary (integer part): 0" << endl;
        return;
    }
    while (number > 0) {
        stack.pushData(number % 2);
        number /= 2;
    }
    cout << "Binary (integer part): ";
    while (!stack.isStackEmpty()) {
        cout << stack.popData();
    }
    cout << endl;
}

void convertFractionToBinary(double fraction) {
    BinaryQueue queue;
    int iterations = 20; // limit precision to 20 bits
    while (fraction > 0 && iterations-- > 0) {
        fraction *= 2;
        int bit = static_cast<int>(fraction);
        queue.enqueueData(bit);
        fraction -= bit;
    }
    cout << "Binary (fractional part): 0.";
    while (!queue.isQueueEmpty()) {
        cout << queue.dequeueData();
    }
    cout << endl;
}
