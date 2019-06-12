/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/03 18:24:45 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/03 18:41:46 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int		main(int argc, char const *argv[])
{
	std::string         s1;
	std::string         s2;
	std::string         buffer;
	std::string         output;
	std::string         filename;

	if (argc == 4)
	{
		s1 = argv[2];
		s2 = argv[3];
		filename = argv[1];
		output = filename + ".replace";
		std::ifstream   readFile(filename);
		if (readFile.fail())
		{
			std::cout << "Open file fail! :(" << std::endl;
			exit(1);
		}
		std::ofstream    outFile(output);
		if (outFile.fail())
		{
			std::cout << "Create file fail! :(" << std::endl;
			exit(1);
		}
		while (std::getline(readFile, buffer))
		{
			while (buffer.find(s1) != std::string::npos)
			{
				buffer.replace(buffer.find(s1), s1.length(), s2);
			}
			outFile << buffer;
			outFile << std::endl;
		}
		if (buffer == "")
		{
			outFile << std::endl;
		}
		readFile.close();
		outFile.close();
	}
	else
	{
		std::cout << "usage: " << argv[0];
		std::cout << " file <s1> <s2>" << std::endl;
	}
	return (0);
}
