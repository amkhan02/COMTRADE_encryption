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

int main(){
    string line;
    string delimiter = ",";
    ifstream dataFile ("Homework_02_Fall24.DAT");
    ofstream cipherFile ("ENCRYPTED.dat");
    double e = 2.0; // TODO: read in an RSA key pair from a generated file
                    // * Will need to convert from base64
                    // * Decide on a key format (start with openSSH, expand to different formats as necessary)
    double n = 1;
    double total_time = 0;
    
    if (dataFile.is_open()){
        while (getline(dataFile, line)){
            auto start = high_resolution_clock::now(); // Start timer
            if (cipherFile.is_open()){
                
                vector<string> items = split(line, delimiter);
                
                // Placeholder for encryption
                // This code simply doubles the voltage, current, and frequency data
                // TODO: replace this with an RSA calculation 
                for (int i = 0 ; i < items.size(); ++i)
                    cipherFile<<stoi(items[i]) * (i > 1 ? e : 1)<<' ';
                
                cipherFile<<'\n';
            } else
                break;
            auto stop = high_resolution_clock::now(); // Stop timer
            auto duration = duration_cast<microseconds>(stop - start); // Calculate elapsed time
            total_time = duration.count(); // save to print at the end
        }
        if (cipherFile.is_open())
            cipherFile.close();
        dataFile.close();
    } else
        cout << "Unable to open file";

    
    
    cout << total_time/1000000; // print the measured time in seconds

    return 0;
}