#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    double e = 2.0;
    double n = 1;
    double total_time = 0;
    
    if (dataFile.is_open()){
        while (getline(dataFile, line)){
            auto start = high_resolution_clock::now();
            if (cipherFile.is_open()){
                
                vector<string> items = split(line, delimiter);
                
                for (int i = 0 ; i < items.size(); ++i)
                    cipherFile<<stoi(items[i]) * (i > 1 ? e : 1)<<' ';
                
                cipherFile<<'\n';
            } else
                break;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            total_time = duration.count();
        }
        if (cipherFile.is_open())
            cipherFile.close();
        dataFile.close();
    } else
        cout << "Unable to open file";

    
    
    cout << total_time/1000000;

    return 0;
}