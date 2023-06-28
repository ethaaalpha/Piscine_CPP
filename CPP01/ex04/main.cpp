#include <iostream>
#include <fstream>
#include <sstream>

std::ifstream getInStream(std::string file)
{
	std::ifstream ifs(file);

	if (ifs.fail() == true)
	{
		std::cout << "Error : " << std::strerror(errno) << std::endl;
		std::exit(1);
	}
	return (ifs);
}

std::ofstream getOutStream(std::string file)
{
	std::ofstream ofs(file);

	if (ofs.fail() == true)
	{
		std::cout << "Error : " << std::strerror(errno) << std::endl;
		std::exit(1);
	}
	return (ofs);
}

std::string replace_occurences(std::string content, std::string s1, std::string s2)
{
	size_t	i = 0;
	size_t	pos = content.find(s1, i);;

	while (pos != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos = content.find(s1, i);
		i += s2.length();
	}
	return (content);
}

std::string	get_file_content(std::ifstream& ifs)
{
	std::stringstream bufferstream;

	bufferstream << ifs.rdbuf();
	return (bufferstream.str());
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
		return (std::cout << "Error ! Syntax : /ex04 <filename> <s1> <s2>" << std::endl, 1);
	std::ifstream ifs = getInStream(argv[1]);
	std::ofstream ofs = getOutStream(std::string(argv[1]) + ".replace");

	ofs << replace_occurences(get_file_content(ifs), argv[2], argv[3]);
	return 0;
}
