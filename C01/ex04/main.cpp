
#include <iostream>
#include <fstream>
#include <string>


static std::string replaceAll(const std::string& content, const std::string& s1, const std::string& s2)
{

	std::string result;
	
	size_t start = 0;
	size_t pos;

	while((pos = content.find(s1, start)) != std::string::npos)
	{
		result += content.substr(start, pos - start);
		result += s2;
		start = pos + s1.length();
	}	
	result += content.substr(start);
	return result;

}

int main(int argc, char **argv)
{
	if(argc != 4){std::cout << "Usage: .sed_is_for_losers <filename> <s1> <s2>" << std::endl; return 1;}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if(s1.empty())
	{
		std::cout << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}
	std::ifstream infile(filename.c_str());
	if(!infile.is_open())
	{
		std::cout << "Error : cannot open input file." << std::endl;
		return 1;
	}

	std::string content;
	std::string line;
	while(std::getline(infile, line))
	{
		content += line;
		if(!infile.eof())
			content += "\n";
	}
	infile.close();

	std::string outname = filename + ".replace";
	std::ofstream outfile(outname.c_str());
	if(!outfile.is_open())
	{
		std::cout << "Error: cannot open output file." << std::endl;
		return 1;
	}
	outfile << replaceAll(content, s1, s2);
	outfile.close();
	
	return 0;


}
