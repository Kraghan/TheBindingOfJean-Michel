//
// Created by Kraghan on 21/12/2016.
//

#include <iostream>
#include <sstream>
#include "../../Header/Tools/SettingsParser.hpp"

/* Explicit */ SettingsParser::SettingsParser()
{
    std::ifstream infile(settingsFile);

    if(infile.good())
    {
        bool graphicBlock = false;
        std::string line;
        while (std::getline(infile, line))
        {
            if(line.find('[') != std::string::npos && line.find(']') != std::string::npos)
            {
                if (line == "[GRAPHICS]")
                {
                    graphicBlock = true;
                    continue;
                }
            }

            if(graphicBlock)
            {
                std::istringstream iss(line);
                std::string name;
                char symbole;
                unsigned value;
                iss >> name >> symbole >> value;
                if(name == "RESOLUTIONS")
                {
                    if(value > 2)
                        value = 2;
                    m_resolution = value;
                }
            }
        }
    }
}

/* Virtual */ SettingsParser::~SettingsParser()
{

}

unsigned SettingsParser::getResolution()
{
    return m_resolution;
}
