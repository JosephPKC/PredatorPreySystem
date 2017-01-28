#ifndef CONSTANTS_H
#define CONSTANTS_H

//constants used by the world class, and creature class along with its derived classes
const int MAXLENGTH = 250; //150 //250
const int MAXHEIGHT = 250; //150 //250

const int CREATUREINITIAL = 0; // 1:6
const int PREDATORINITIAL = 1000; //400 //1000
const int PREYINITIAL = 5000; //1200 //5000
const int HUNTERINITIAL = 500; //200 //500
const int INFECTEDINITIAL = 0;

const int INFECTSPREADCHANCE = 30;//30
const int INFECTSPAWNCHANCE = 30;//40

const char NULLTYPE = '\0';
const char CREATURETYPE = 'C';
const char PREDATORTYPE = 'o';
const char PREYTYPE = '.';
const char WALLTYPE = 'W';
const char HUNTERTYPE = 'h';
const char INFECTEDTYPE = '#';

const int CREATUREBREED = 1; //2
const int PREDATORBREED = 6; //9
const int PREYBREED = 3; //3
const int HUNTERBREED = 6;
const int INFECTEDSPREAD = 0;

const int CREATURELIFE = 2;
const int PREDATORSTARVE = 2; //3
const int PREYLIFE = 8; //6
const int HUNTERSTARVE = 2;
const int INFECTEDLIFE = 4;

const float PIXELCONSTANT = .71;//.71
const int DEFAULTHEIGHT = 500;
const int DEFAULTWIDTH = 800;
const int REFRESHRATE = 50;
const int LCDDIGITS = 10;

#endif // CONSTANTS_H



