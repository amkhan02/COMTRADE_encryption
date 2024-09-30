#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>



// Function to compute gcd
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function to compute modular inverse
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; ++d) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1; // Should not reach here if e and phi are coprime
}
int main() {
    // RSA parameters
    int p = 61; // Example prime number
    int q = 53; // Example prime number
    int n = p * q; // n = p * q
    int phi = (p - 1) * (q - 1); // phi(n) = (p-1)*(q-1)
    int e = 17; // Public exponent
    int d = modInverse(e, phi); // Private exponent

struct DataRow {
    int index;
    int time;
    int voltage;
    int current;
    int frequency;
};

    std::ifstream inputFile("Homework_02_Fall24.dat");
    if (!inputFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<DataRow> data;

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        DataRow row;
        char comma; // To read the commas

        if (ss >> row.index >> comma >> row.time >> comma >> row.voltage >> comma >> row.current >> comma >> row.frequency) {
            data.push_back(row);
            std::cout << row.time << "\n";
        } else {
            std::cerr << "Error reading line: " << line << std::endl; // Error output
        }
    }


    // Algorithm
    // for (size_t i = 0; i < 0 data.size(); ++i)
    //     data[i].voltage 
    // }

    return 0;
}
