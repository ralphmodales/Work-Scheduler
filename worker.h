#ifndef WORKER_H
#define WORKER_H

#include <string>
#include <vector>

struct Worker
{
        int id;
        std::string name;
        std::vector<std::vector<int>> availability;
        std::vector<std::string> knowledge;
};

#endif
