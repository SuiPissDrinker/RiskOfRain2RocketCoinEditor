#include <iostream>
#include <cctype>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std; // eat my balls I use this even though it 'can' cause issues. lick them really good oh yeah I like that
string myGitHub = "https://github.com/SuiPissDrinker";// My github
string configFileLoc = "RocketGameEditconfigFile.txt";//Location of the config file
string dataFileLoc;//The located of the file retard, like it's literally in the name (PS you smell horrible)
string openedData;//The data we're handling
string configArg1;//To check if the file was actually editted by the user
string configArg2;//This SHOULD be the file location
string configArg3;//This SHOULD be the amount of coins
inline void Debug()
{
    cout << "debug" << endl;
}

void modifyDataFile()
{
    
fstream dataFS;
ofstream oDataFS; //yes this is useless, no it's needed. Why? I have no clue, but if you remove it will cause the program to segfault when in the edit file block if it's not here
dataFS.open(dataFileLoc, ios::in);
if (dataFS.is_open())
{
    //locates the value in the file
    getline(dataFS, openedData);
    int coinsAt[1];
    coinsAt[0] = (openedData.find("<coins>")+6);
    coinsAt[1] = (openedData.find("</coins>"));\

    //edits value
    openedData.erase(coinsAt[0]+1, coinsAt[1]-coinsAt[0]-1);
    openedData.insert(coinsAt[0]+1, configArg3);

    dataFS.close();

    //edits the file
    dataFS.open(dataFileLoc, ios::out);
    if (dataFS.is_open())
    {
    dataFS << openedData << endl;;
    }
    else
    {
        cerr << "Something went wrong when writing the file\n";
        exit(EXIT_FAILURE);
    }
    
}
else 
{
    cerr << "Shit's fucked.\nMost likely you fucked up the file location dawg\n";
    exit(EXIT_FAILURE);
}

}



int getConfigs()
{
    ifstream congfigFS;
    congfigFS.open(configFileLoc, ios::in);
    if (congfigFS.is_open())
    {
        
    
    
    getline(congfigFS, configArg1);
    configArg1.erase(1, 420);
    configArg1 = tolower(configArg1[0]);
    if (configArg1 == "t") //Check if the user actually modded the config file
    {
        getline(congfigFS, configArg2);
        getline(congfigFS, configArg3);
        dataFileLoc = configArg2;  
    }
    else if (configArg1 == "f")
    {
        cout << "oh ballokcks, you forgot to configure the config file. Please check the read me in my .zip to figure out how to :3 {kys nerd}]m";
        exit(EXIT_FAILURE);
    }
    else
    {
        cout << "You messed up the config file somehow, mostlikely your cheeto dust fingers mistyped something\n";
        exit(EXIT_FAILURE);
    }
    
    congfigFS.close();
    return 0;

    }
    else 
    {
        cerr << "Problem opening the config file\nMost likely it doesn't exist or the name is messed up\n";
        exit(EXIT_FAILURE);
    }

}
int main()
{
cout << "Check out my github!\nhttps://github.com/SuiPissDrinker\n";
getConfigs();
modifyDataFile();
cout << "Enjoy your coins, when you run out (I know you're gonna roll that lunar table, you gambler), just run the program and again\n";
cout << "Make retart the game before running this" << endl;
return 0;

}