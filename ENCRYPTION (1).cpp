#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdint> // For fixed-width integer types

// Function to perform modular multiplication without overflow
uint64_t modularMultiply(uint64_t a, uint64_t b, uint64_t mod) {
    uint64_t result = 0;
    a = a % mod;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % mod;
        }
        a = (2 * a) % mod;
        b >>= 1;
    }
    return result;
}

// Function to perform modular exponentiation without overflow
uint64_t modularExponentiation(uint64_t base, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = modularMultiply(result, base, mod);
        }
        exp = exp >> 1;
        base = modularMultiply(base, base, mod);
    }
    return result;
}

// Function to encrypt a value using RSA
uint64_t rsaEncrypt(int64_t value, uint64_t e, uint64_t n) {
    // Adjust negative values to be within the range [0, n - 1]
    uint64_t adjustedValue = ((value % (int64_t)n) + n) % n;
    return modularExponentiation(adjustedValue, e, n);
}

struct DataRow {
    int index;
    int time;
    int voltage;
    int current;
    int frequency;
};

int main() {
    // Define the public exponent and modulus
    uint64_t e = 4790609; // Public exponent
    uint64_t n = 100980637; // Modulus

    // Open the input file
    std::ifstream inputFile("Homework_02_Fall24.dat");
    if (!inputFile) {
        std::cerr << "Error opening input file!" << std::endl;
        return 1;
    }

    // Open the output file
    std::ofstream outputFile("EncryptedData.dat");
    if (!outputFile) {
        std::cerr << "Error opening output file!" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<DataRow> data;

    // Read the file and store the data
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        DataRow row;
        char comma; // To read the commas

        if (ss >> row.index >> comma >> row.time >> comma >> row.voltage >> comma >> row.current >> comma >> row.frequency) {
            data.push_back(row);
        } else {
            std::cerr << "Error reading line: " << line << std::endl; // Error output
        }
    }

    // Check if data was read
    if (data.empty()) {
        std::cerr << "No valid data found in the input file!" << std::endl;
        return 1;
    }

    // Write header to output file
    outputFile << "Index,Time,Encrypted Voltage,Encrypted Current,Encrypted Frequency" << std::endl;

    for (const auto& row : data) {
        // Encrypt the values
        uint64_t encryptedVoltage = rsaEncrypt(row.voltage, e, n);
        uint64_t encryptedCurrent = rsaEncrypt(row.current, e, n);
        uint64_t encryptedFrequency = rsaEncrypt(row.frequency, e, n);

        // Cast encrypted values to int64_t for output
        outputFile << row.index << ","
                   << row.time << ","
                   << static_cast<int64_t>(encryptedVoltage) << ","
                   << static_cast<int64_t>(encryptedCurrent) << ","
                   << static_cast<int64_t>(encryptedFrequency) << std::endl;
    }

    std::cout << "Data has been written to EncryptedData.dat." << std::endl;

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
