#include <iostream>
#include <fstream>
using namespace std;

string getFileLocation(){
    string loc;
    cout << "File location: " << endl;
    cin >> loc;
    return loc;
}  

bool convertFile(string location) {
    ifstream input;
    ofstream output;

    input.open(location, ios::binary); // Without binary, it automatically converts line endings

    if(!input.is_open()){
        cout << "Invalid location!" << endl;
        return false;
    }

    int dot = location.find_last_of('.');
    if(dot != string::npos) location.replace(dot, 1, "_new.");
    output.open(location, ios::binary);


    char c;
    for(;;){
        input.get(c);
        if(!input.good()){
            if(input.eof()) return true;
            else return false;
        } 
        if(c == '\r'){
            input.get(c); 
            if(c == '\n') output << '\n'; // drop the \r
            else output << '\r' << c; // leave as it was, I dont know if this is needed
        } else if (c == '\n'){
            output << "\r\n";
        } else {
            output << c;
        }
        // cout << c;

    }
}

int main(int argc, char *argv[]){
    cout << "Hello World!" << endl;

    string loc = getFileLocation();
    // string loc = "C:\\Users\\Domin\\Documents\\UZH_Docs\\_HS22\\C++\\Exercises\\Exercise 1\\test_new.txt";
    bool success = convertFile(loc);
    if(success) cout << "Success";
    else cout << "Couldn't convert file";

    return 0;
}
