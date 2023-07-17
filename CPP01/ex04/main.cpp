#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

int check_ifs(std::ifstream* ifs)
{
	if (ifs->fail() == true)
	{
		std::cout << "Input file error : " << std::strerror(errno) << std::endl;
		return (1);
	}
	return (0);
}

int check_ofs(std::ofstream* ofs)
{
	if (ofs->fail() == true)
	{
		std::cout << "Ouput file error : " << std::strerror(errno) << std::endl;
		return (1);
	}
	return (0);
}

std::string replace_occurences(std::string content, std::string s1, std::string s2)
{
	size_t	i = 0;
	size_t	pos = content.find(s1, i);;

	if (s1.length() == 0)
		return (content);
	while (pos != std::string::npos)
	{
		i = pos + s2.length();
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos = content.find(s1, i);
	}
	return (content);
}

std::string	get_file_content(std::ifstream* ifs)
{
	std::stringstream bufferstream;

	bufferstream << ifs->rdbuf();
	return (bufferstream.str());
}

int main(int argc, char const *argv[])
{
	if (argc != 4)
		return (std::cout << "Error ! Syntax : /ex04 <filename> <s1> <s2>" << std::endl, 1);
	std::ifstream ifs(argv[1]);
	std::ofstream ofs((std::string(argv[1]) + ".replace").c_str());
	if (check_ifs(&ifs) || check_ofs(&ofs))
		return (1);
	ofs << replace_occurences(get_file_content(&ifs), argv[2], argv[3]);
	return 0;
}
