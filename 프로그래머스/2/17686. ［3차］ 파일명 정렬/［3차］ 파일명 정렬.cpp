#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

struct FileInfo {
    string filename;
    string head;
    int num;
    
    FileInfo(string file): filename(file) {
        int numS = 0;
        while (numS < file.length() && !isdigit(file[numS])) {
            file[numS] = tolower(file[numS]);
            numS++;
        }
        head = file.substr(0, numS);
        
        int numE = numS;
        while (numE < file.length() && isdigit(file[numE])) {
            numE++;
        }
        
        num = stoi(file.substr(numS, min(5, numE - numS)));
    }
};

vector<string> solution(vector<string> files) {
    vector<FileInfo> infos;
    
    infos.reserve(files.size());
    for (const auto &file : files) {
        infos.push_back(FileInfo(file));
    }
    stable_sort(infos.begin(), infos.end(), [](const FileInfo &f1, const FileInfo &f2) {
        if (f1.head == f2.head) {
            return f1.num < f2.num;
        }
        return f1.head < f2.head;
    });
    
    vector<string> sorted;
    sorted.reserve(infos.size());
    for (const auto &info : infos) {
        sorted.push_back(info.filename);
    }
    return sorted;
}