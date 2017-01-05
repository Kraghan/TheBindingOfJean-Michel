//
// Created by Kraghan on 21/12/2016.
//

#ifndef BINDINGOFJEANMICHEL_SETTINGSPARSER_HPP
#define BINDINGOFJEANMICHEL_SETTINGSPARSER_HPP


#include <fstream>
#include <sstream>
#include <string>

class SettingsParser
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:
    explicit            SettingsParser              ();
    virtual             ~SettingsParser             ();
    unsigned            getResolution               ();

    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    const std::string   settingsFile                = "../Settings/Settings.ini";
    unsigned            m_resolution;
};


#endif //BINDINGOFJEANMICHEL_SETTINGSPARSER_HPP
