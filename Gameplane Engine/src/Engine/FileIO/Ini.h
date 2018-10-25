#pragma once
#pragma warning(disable:4996)

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

class Ini
{
public:
	static const char* readString(const char* filepath, const char* section, const char* inkey, const char* fallback)
	{
		std::string key = inkey;

		std::ifstream f(filepath);
		std::string line;
		while (getline(f, line))
		{
			if (line == "[" + (std::string)section + "]")
			{
				while (getline(f, line))
				{
					if (line.at(0) == '[' && !(line == "[" + (std::string)section + "]"))
					{
						f.close();
						return fallback;
					}
					bool success = true;
					int lastchar = 0;
					for (unsigned int i = 0; i < key.length(); i++)
					{
						if (key.at(i) != line.at(i))
						{
							success = false;
						}
						lastchar = i;
					}
					if (success)
					{
						bool foundequal = false;
						bool foundbeginning = false;
						std::string returnvalue = "";

						for (unsigned int i = lastchar + 1; i < line.length(); i++)
						{
							if (line.at(i) == ' ' && !foundbeginning)
							{
								continue;
							}

							if (line.at(i) == '=')
							{
								if (!foundequal)
								{
									foundequal = true;
									continue;
								}
								else
								{
									return fallback;
								}
							}

							if (foundequal)
							{
								foundbeginning = true;
								char c = line.at(i);
								returnvalue += c;
							}
						}
						if (!foundequal)
						{
							return fallback;
						}
						char* finalreturn = new char[returnvalue.length() + 1];
						strcpy(finalreturn, returnvalue.c_str());
						return finalreturn;
					}
				}
			}
			return fallback;
		}
		
	}
	static int readReal(const char* filepath, const char* section, const char* inkey, int fallback)
	{
		std::string stringnumber = readString(filepath, section, inkey, "ERROR");
		if (stringnumber != "ERROR")
		{
			return stoi(stringnumber);
		}
		return 0;
	}
};