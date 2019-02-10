/**
 * Author: Vargas Romero Erick Efraín
 * Last modification: 09 Febraury 2019
 * **/
#include <bits/stdc++.h>

using namespace std;

//Functions definitions
string cipher(string c, vector<int> &K);
string decoder(string m, vector<int> &K);
void choose(string str, vector<int> &K);
void out_file(string str, string file_name);
string read_file();

int main(){
    string str;
    int k, v;
    vector<int> K;
    str = read_file();
    cout << "How many keys we gonna use? -> ";
    cin >> k;
    while(k--){
        cout << "Write the key " << (k + 1) << " -> ";
        cin >> v;
        K.push_back(v);
    }
    choose(str, K);
    return 0;
}

/**
 * This function creates a ciphertext
 * @param: char* m, the plain text
 * @param: int shift, our k value
 * @return: char*, ciphertext
 * **/
string cipher(string c, vector<int> &K){
    string cipher_text = "";
    int size = c.size();
    int size_keys = K.size();
    for(int i = 0, j = 0; i  < size; i++, j++){
        if(c[i] != ' '){
            if(islower(c[i])){
                c[i] = ((c[i] + K[j % size_keys]) % ('z' + 1));
                if( !islower(c[i]) ) 
                    c[i] = 'a' + c[i];
            }
            else if(isupper(c[i])){
                c[i] = ((c[i] + K[j % size_keys]) % ('Z' + 1));
                if( !isupper(c[i])) 
                    c[i] = 'A' + c[i];
            }
        }
    }
    return c;
}   

/**
 * This function decode ciphertext
 * @param: char* m, the ciphertext
 * @param: int shift, our k value
 * @return: char*, plain text
 * **/
string decoder(string m, vector<int> &K){
    string plain_text = "";
    int size = m.size();
    int size_keys = K.size();
    for(int i = 0, j = 0; i < size; i++, j++){
        if(m[i] != ' '){
           if(islower(m[i])){
                m[i] = abs((m[i] - K[j % size_keys]) % ('z' + 1));
                if( !islower(m[i]) ) 
                    m[i] = ('z' + 1) - abs('a' - m[i]);
            } else if(isupper(m[i])){
                m[i] = abs((m[i] - K[j % size_keys]) % ('Z' + 1));
                if( !isupper(m[i]) ) 
                    m[i] = ('Z' + 1) - abs('A' - m[i]);
            }
        }
    }
    return m;
}   
/**
 * This function gets the content of a text file
 * @param: none
 * @return: (string) the content of our file in a string
 * **/
string read_file(){
    string file_name, str = "", line = "";
    ifstream input_file;
    cout << "Write the file path -> ";
    getline(cin, file_name);
    input_file.open(file_name.c_str(), ios::in);
    if(input_file.is_open()){
        while(!input_file.eof()){
            getline(input_file, line);
            str += line;
        }
        input_file.close();
    } else
        cout << "\nFile doesn't exist or you're not allowed to open it" << endl;
    
    return str;
}

/**
 * This function creates a file
 * @param: (string) content file
 * @param: (string) file name
 * @return: nothing
 * **/
void out_file(string str, string file_name){
    ofstream output_file(file_name);
    output_file << str << endl;
    output_file.close();
}

/**
 * Main of our program
 * @param: (string) str, the string to manipulate (code or decode)
 * @param: (vector<int>) K, all the keys
 * @return: nothing
 * **/
void choose(string str, vector<int> &K){
    int option;
    string content = "";
    cout << "\n1. Ciphe" << endl;
    cout << "2. Decode" << endl;
    cout << "3. Exit" << endl;
    cin >> option;
    switch (option)
    {
        //Cipher
        case 1:
            content = cipher(str, K);
            cout << content << endl;
            out_file(str, "plain_text.txt");
            out_file(content, "cipher_text.txt");
            break;
        //Decode
        case 2:
            content = decoder(str, K);
            cout << content << endl;
            out_file(content, "plain_text.txt");
            out_file(str, "cipher_text.txt");
            break;
        default:
            cout << "Option " << option << " doesn't exists" << endl;
            break;
    }
}