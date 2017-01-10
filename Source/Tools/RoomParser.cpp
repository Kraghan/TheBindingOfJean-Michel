//
// Created by Kraghan on 21/12/2016.
//

#include "../../Header/Tools/RoomParser.hpp"

/* Explicit */ RoomParser::RoomParser()
{
    for(unsigned i = 0; i < elements; ++i) {
        std::ifstream infile(dirPath + roomFiles[i]);

        if (infile.good()) {
            bool RoomBlock = false;
            bool dimensionsBlock = false;
            bool obstacleBlock = false;
            std::vector<sf::Vector2f> obstacle;

            std::string line;
            unsigned levelBoss = 0;
            unsigned width = 0,height = 0;

            while (std::getline(infile, line)) {
                if (line[0] == '#')
                    continue;

                if (line.find('[') != std::string::npos && line.find(']') != std::string::npos) {
                    if (line == "[Room]")
                    {
                        dimensionsBlock = false;
                        RoomBlock = true;
                        obstacleBlock = false;
                        continue;
                    } else if (line == "[DIMENSION]")
                    {
                        dimensionsBlock = true;
                        RoomBlock = false;
                        obstacleBlock = false;
                        continue;
                    } else if (line == "[OBSTACLE]")
                    {
                        dimensionsBlock = false;
                        RoomBlock = false;
                        obstacleBlock = true;
                        continue;
                    }
                }

                if (RoomBlock) {
                    std::istringstream iss(line);
                    std::string name;
                    char symbole;
                    unsigned value;
                    iss >> name >> symbole >> value;

                    if (name == "LEVEL_BOSS") {
                        levelBoss = value;
                    }
                }

                if (dimensionsBlock) {
                    std::istringstream iss(line);
                    std::string name;
                    char symbole;
                    unsigned value;
                    iss >> name >> symbole >> value;

                    if (name == "ROOM_WIDTH") {
                        if (value > 2)
                            value = 2;
                        if (value < 1)
                            value = 1;
                        width = value;
                    }
                    if (name == "ROOM_HEIGHT") {
                        if (value > 2)
                            value = 2;
                        if (value < 1)
                            value = 1;
                        height = value;
                    }
                }

                if (obstacleBlock)
                {
                    std::istringstream iss(line);
                    unsigned x, y;
                    iss >> x >> y;
                    x = 160 + x * 80;
                    y = 160 + y * 80;
                    obstacle.push_back(sf::Vector2f(x,y));
                }
            }

            if(height == 0)
                std::cerr<< "Error : Height not set for file : "<< roomFiles[i] <<std::endl;
            if(width == 0)
                std::cerr<< "Error : Width not set for file : "<< roomFiles[i] <<std::endl;
            if(height != 0 && width != 0)
            {
                Room* room = RoomStorage::Instance()->addRoom(width,height,levelBoss);

                for(auto vector : obstacle)
                {
                    room->addObstacle(vector);
                }
            }
        }
    }
}

/* Virtual */ RoomParser::~RoomParser()
{

}