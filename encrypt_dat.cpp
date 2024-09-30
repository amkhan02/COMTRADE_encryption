#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to split a string into a vector of strings based on a specified delimiter
vector<string> split(string& s, string& delimiter){
    vector<string> substrings;
    size_t pos = 0;
    string substring;

    while ((pos = s.find(delimiter)) != string::npos){
        substring = s.substr(0, pos);
        substrings.push_back(substring);
        s.erase(0, pos+delimiter.length());
    }

    substrings.push_back(s);
    return substrings;
}

long long pow(long long base, long long exp, long long mod){
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}

int main(){
    string line;
    string delimiter = ",";
    int encrypting = 1;

    ifstream dataFile (encrypting ? "Homework_02_Fall24.DAT" : "encrypted.dat");
    ofstream outFile (encrypting ? "ENCRYPTED.dat" : "decrypted.dat");

    long long e = encrypting ? 77239747 : 1606632367; // TODO: read in an RSA key pair from a generated file
                    // * Will need to convert from base64
                    // * Decide on a key format (start with openSSH, expand to different formats as necessary)
    long long n = encrypting ? 100980637 : 2997331637;
    long long d = 314254663;

    

    double total_time = 0;
    
    if (dataFile.is_open()){
        while (getline(dataFile, line)){
            auto start = high_resolution_clock::now(); // Start timer
            if (outFile.is_open()){
                
                vector<string> items = split(line, delimiter);
                
                // Placeholder for encryption
                // This code simply doubles the voltage, current, and frequency data
                // TODO: replace this with an RSA calculation 
                for (int i = 0 ; i < items.size(); ++i){
                    if (encrypting)
                        outFile<< ((i > 1) ? to_string(pow(stoi(items[i]), e, n)) : items[i] ) <<',';
                    else 
                        outFile<< ((i > 1) ? to_string(pow(stoi(items[i]), d, n)) : items[i] ) <<',';
                }
                outFile<<'\n';
            } else
                break;
            auto stop = high_resolution_clock::now(); // Stop timer
            auto duration = duration_cast<microseconds>(stop - start); // Calculate elapsed time
            total_time = duration.count(); // save to print at the end
        }
        if (outFile.is_open())
            outFile.close();
        dataFile.close();
    } else
        cout << "Unable to open file";

    
    
    cout << total_time/1000000; // print the measured time in seconds

    return 0;
}