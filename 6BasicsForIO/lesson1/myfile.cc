#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

int main()
{
	std::ofstream ofs("./log.txt", std::ios_base::out | std::ios_base::binary);
	if (!ofs.is_open()) {
		std::cerr << "open error" << std::endl;
		return 1;
	}

	std::string msg = "hello log.txt\n";

	ofs.write(msg.c_str(), msg.size() + 1);


	return 0;
}
