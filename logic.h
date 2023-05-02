#include <fstream>
#include <vector>


#ifndef LOGIC_H
#define LOGIC_H

namespace dat{
std::string get_current_dir();

std::vector<std::string> get_tracks();

void add_track(std::string&name);

void renew_tracks(std::vector<std::string> vec);
}

namespace logic {

int index(std::vector<std::string>&, std::string);

}

#endif // LOGIC_H
