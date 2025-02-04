#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
//#include <gmpxx.h>

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
    int encrypting = 1; // 1= encrypting, 0 = decrypting

    ifstream dataFile (encrypting ? "Homework_02_Fall24.DAT" : "ENCRYPTED.dat");
    ofstream outFile (encrypting ? "ENCRYPTED.dat" : "decrypted.dat");

    long long e = encrypting ? 77239747 : 1606632367; // Use aidan public key if encrypting, otherwise mine
    long long n = encrypting ? 100980637 : 2997331637;

    // e = 1606632367; //My public key to overwrite previous value for testing
    // n = 2997331637;

    long long d = 314254663; // My private key

    double total_time = 0;
    int iter_count = 0;
    if (dataFile.is_open()){
        while (getline(dataFile, line)){
            auto start = high_resolution_clock::now(); // Start timer
            if (outFile.is_open()){
                
                vector<string> items = split(line, delimiter);
                
                for (int i = 0 ; i < items.size(); ++i){
                    long long val = 0;
                    uint64_t val_u = 0;
                    try{
                       val = stoll(items[i]);
                    } catch(exception e){
                        std::cout << "invalid value of stoll " << items[i] << '\n';
                    }
                    if (encrypting){
                        outFile<< ((i > 1) ? to_string(pow(val, e, n)) : items[i] ); // Do not encrypt the first two fields
                    }else{ 
                        outFile<< ((i > 1) ? to_string(pow(val, d, n)) : items[i] ); // Do not decrypt the first two fields
                    }
                    if (i != 4)
                        outFile<<','; //don't put a comma at the last
                }
                outFile<<'\n';
            } else
                break;
            auto stop = high_resolution_clock::now(); // Stop timer
            auto duration = duration_cast<microseconds>(stop - start); // Calculate elapsed time
            total_time += duration.count(); // save to print at the end
            iter_count++;
        }
        if (outFile.is_open())
            outFile.close();
        dataFile.close();
    } else
        std::cout << "Unable to open file";
    
    
    std::cout << total_time/iter_count/1000000; // print the average time to process each line in seconds

    return 0;
}