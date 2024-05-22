#include <iostream>
#include <vector>
#include <stdexcept>
#include "worker.h"

std::vector<Worker> jsonParser(const std::string& jsonFile);

void shiftAssigner(const std::vector<Worker>& workers) {
            std::vector<std::string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
                std::vector<std::string> shifts = {"Morning", "Afternoon", "Evening"};

                    const int morningShiftStart = 8;
                        const int morningShiftEnd = 12;
                            const int afternoonShiftStart = 13;
                                const int afternoonShiftEnd = 17;
                                    const int eveningShiftStart = 18;
                                        const int eveningShiftEnd = 22;

                                            for(const auto& day : days) {
                                                            std::cout << "----- " << day << " -----" << std::endl;
                                                                    for(const auto& shift : shifts) {
                                                                                        std::cout << shift << " shift:" << std::endl;
                                                                                                    for(const auto& worker : workers) {
                                                                                                                            for(const auto& available : worker.availability) {
                                                                                                                                                        if((available[0] <= morningShiftStart && available[1] >= morningShiftEnd && shift == "Morning") ||
                                                                                                                                                             (available[0] <= afternoonShiftStart && available[1] >= afternoonShiftEnd && shift == "Afternoon") ||
                                                                                                                                                                    (available[0] <= eveningShiftStart && available[1] >= eveningShiftEnd && shift == "Evening")) {
                                                                                                                                                              std::cout << "Assign " << worker.name << " to " << shift << " shift." << std::endl;
                                                                                                                                                              break;
                                                                                                                                                          }
                                                                                                                                                      }
                                                                                                                                        }
                                                                                                            }
                                                                        }
}

int main(int argc, char *argv[]) {
            if (argc != 2) {
                            std::cerr << "Enter a valid JSON file." << std::endl;
                                    return 1;
                                        }

                try {
                                const std::string jsonFilePath = argv[1];
                                        auto workers = jsonParser(jsonFilePath);
                                                shiftAssigner(workers);
                                                    } catch (const std::exception& e) {
                                                                    std::cerr << "Error: " << e.what() << std::endl;
                                                                            return 1;
                                                                                }

                    return 0;
}
