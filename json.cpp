#include <fstream>
#include <string>
#include "rapidjson/document.h"
#include "worker.h"

std::vector<Worker> jsonParser(const std::string &jsonFile)
{
        std::vector<Worker> workers;

        rapidjson::Document docs;

        std::ifstream file(jsonFile);
        if (!file.is_open())
                throw std::runtime_error("Error opening file: " + jsonFile);

        std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
        docs.Parse(content.c_str());

        if (!docs.IsArray())
                throw std::runtime_error("Invalid JSON format.");

        for (const auto &worker_Json : docs.GetArray())
        {
                Worker worker;
                worker.id = worker_Json["id"].GetInt();
                worker.name = worker_Json["name"].GetString();

                for (const auto &availability : worker_Json["availability"].GetArray())
                {
                        std::vector<int> avail;
                        avail.push_back(availability[0].GetInt());
                        avail.push_back(availability[1].GetInt());
                        worker.availability.push_back(avail);
                }
                for (const auto &knowledge : worker_Json["knowledge"].GetArray())
                {
                        worker.knowledge.push_back(knowledge.GetString());
                }
                workers.push_back(worker);
        }
        return workers;
}
