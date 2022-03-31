#include "header.h"

struct Client
{
    string name, str;
    int start_time, end_time, duration_time;
    Client(string line) {
        str = line + '\n';
        vector <string> words = split(line);
        name = words[0];
        start_time = stoi(split(words[1], ':')[0]) * 60 + stoi(split(words[1], ':')[1]);
        end_time = stoi(split(words[2], ':')[0]) * 60 + stoi(split(words[2], ':')[1]);
        if (end_time < start_time) {
            end_time += 1440;
        }
        duration_time = end_time - start_time;
    }
};

bool is_client_in(Client a, vector <Client> base) {
    for (int i = 0; i < base.size(); i++) {
        if (base[i].name == a.name) return true;
        else if (base[i].end_time > a.end_time && a.end_time > base[i].start_time) return true;
        else if (a.start_time < base[i].start_time && a.end_time > base[i].end_time) return true;
        else if (base[i].start_time < a.start_time && a.start_time < base[i].end_time) return true;
    }
    return false;
}

void CreateFile(const char* FName) {
    cout << "Choose the input mode. 1 - append, 2 - create new.\n>>>";
    int input_mode; cin >> input_mode;
    string str = "";
    vector <Client> base;
    while (true) {
        if (input_mode == 1) {
            ifstream inf(FName, ios::binary);
            char symbol;
            while (inf.read((char*)&symbol, sizeof(char)))
            {
                if (symbol == '\n') {
                    base.push_back(Client(str));
                    str = "";
                }
                else str += symbol;
            }
            inf.close();
            break;
        }
        else if (input_mode == 2) {
            break;
        }
        else {
            cout << "Wrong input format!\n>>>";
            cin >> input_mode;
        }
    }
    ofstream ouf(FName, ios::binary);
    cout << "Enter the information about clients in format [surname hh:mm hh:mm]\n";
    cin.ignore();
    getline(cin, str);
    while (str[0] != 19) {
        Client temp(str);
        if (base.size() == 0) {
            base.push_back(temp);
            getline(cin, str);
            continue;
        }
        if (!is_client_in(temp, base)) base.push_back(temp);
        else cout << "Error!" << endl;
        getline(cin, str);
    }
    for (int i = 0; i < base.size(); i++) {
        ouf.write(base[i].str.c_str(), base[i].str.length());
    }
    ouf.close();
}

void PrintFile(const char* FName) {
	ifstream inf(FName, ios::binary);
	char symbol;
	while (inf.read((char*)&symbol, sizeof(char))) {
		cout << symbol;
	}
}

void CreateNewFile(const char* FName1, const char* FName2) {
    ifstream inf(FName1, ios::binary);
    ofstream ouf(FName2, ios::binary);
    vector <Client> base;
    char symbol;
    string line = "";
    while (inf.read((char*)&symbol, sizeof(char)))
    {
        if (symbol == '\n') {
            Client a(line);
            if ((a.end_time - a.start_time) > 30) {
                base.push_back(a);
            }
            line = "";
        }
        else line += symbol;
    }
    for (int i = 0; i < base.size(); i++) {
        ouf.write(base[i].str.c_str(), base[i].str.length());
    }
}

vector<string> split(string line, char sep) {
    vector<string> words;
    string temp_word = "";
    line += sep;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == sep) {
            if (temp_word.length() > 0) {
                words.push_back(temp_word);
            }
            temp_word = "";
        }
        else {
            temp_word += line[i];
        }
    }
    return words;
}