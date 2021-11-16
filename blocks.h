//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	
    // Free Swap
    {"C ", "free -h | awk '/^Swap/ { print $3\"/\"$2 }' | sed s/i//g",	10, 0},

    // Free Memory
    {"M ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	10, 0},

    // Volume
    {"V ", "amixer | awk '/  Front Left: Playback / {print $5}'",	3, 0},

    // Date
	{"", "date '+%b %d (%a) %I:%M %p'",	5, 0},
    
    // Network IP address
    {"\xf0\x9f\x96\xa7 ", "ip -f inet address | awk /inet/'{print $2}' | awk 'FNR == 2'", 30, 0},

    //Battery
    {"", "acpi | awk '{print substr($4,0,3) \" ~ \" $5}'", 5, 0}
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
