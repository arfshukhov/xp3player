#include <fstream>
#include <vector>
#include <iomanip>
#include <direct.h>
#include <iostream>
#include <algorithm>
#include <logic.h>

namespace dat {
std::string get_current_dir(){
    std::string path;
    path = _getcwd( NULL, 0 );
    return path;
}

std::vector<std::string> get_tracks(){
    std::vector<std::string> tracks;
    auto path = dat::get_current_dir();
    std::fstream fin(path+"\\data.txt");
    while(!fin.eof()){
        std::string line;
        getline(fin, line);
        tracks.push_back(line);
    }
    fin.close();
    tracks.pop_back();
    tracks.erase(
        std::unique(tracks.begin(), tracks.end()), tracks.end()
        );
    for(unsigned i = 0; i< tracks.size(); i++){
        if(tracks[i]=="" || tracks[i]==" ") tracks.erase(tracks.begin()+i);
    }
    return tracks;
}

void add_track(std::string& name){
    auto path = dat::get_current_dir();
    std::ofstream fout(path+"\\data.txt", std::ios::app);
    std::cout<<path+"\\data.txt"<<std::endl;
    fout << name<<std::endl;
    fout.close();
}

void renew_tracks(std::vector<std::string> vec){
    auto path = dat::get_current_dir();
    std::ofstream fout(path+"\\data.txt");
    for(auto elem: vec){
        fout<<elem+"\n";
    }
    fout.close();
}
}


namespace logic {

int index(std::vector<std::string>& vec, std::string t){
    unsigned idx = 0;
    for (auto track:vec){
        if (track == t){
            return idx;
        }
        idx++;
    }
    return -1;
}
}
