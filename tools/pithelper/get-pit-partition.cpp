#include "pit.h"

#include <cstring>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <PIT> <file to flash>" << std::endl;
        return 1;
    }

    struct PIT pit = loadPIT(argv[1]);
    std::string partition = std::string(argv[2]);

    for (PITPartition part : pit.partitions) {
        if (part.flash_filename == partition) {
            std::cout << part.partition_name << std::endl;
            break;
        }
    }
}
