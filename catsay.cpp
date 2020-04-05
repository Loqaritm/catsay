#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <fstream>

std::string eightBall(){
    std::string answers[] = {"maybe", "yes", "no", "could be", "go for it", "you bet", "dont even", "possible", "420"};
    int lenOfAnswers = sizeof(answers)/sizeof(answers[0]);
    int result = std::rand() % lenOfAnswers;
    return answers[result];
}

std::string magicEightBall(){
    std::string answers[] = {"yes", "definitely", "true", "ofcourse", "if you're saying this about ramon then ofcourse", "420"};
    int lenOfAnswers = sizeof(answers) / sizeof(answers[0]);
    int result = std::rand() % lenOfAnswers;
    return answers[result];
}

std::string joke(){
    std::ifstream myfile("catsay_jokes.csv");
    if(!myfile){
        return "COULDN'T LOAD FILE, SO NO JOKES FOR YOU";
    }
    int number_of_lines = 0;
    std::string line = "";
    while (std::getline(myfile, line))
        ++number_of_lines;

    int result = std::rand() % number_of_lines;

    myfile.clear();
    myfile.seekg(0, myfile.beg);
    number_of_lines = 0;

    while(std::getline(myfile, line)){
        if(number_of_lines == result){
            break;
        }
        ++number_of_lines;
    }

    std::stringstream ss;
    ss.str("");
    bool flag = false;
    for (char i : line){
        if(flag) ss << i;
        if(i=='\r') return "STOP USING WINDOWS FORMATED TEXT FILES";
        if(i == ',') flag = true;
    }

    return ss.str().c_str();
}

int main(int argc, char *argv[]){
    std::srand(std::time(0));

    std::stringstream mess_ss;
    for (int i =1; i < argc; i++){
        mess_ss << argv[i];
        if (i < argc - 1) mess_ss <<" ";
    }

    std::string mess;
    mess = mess_ss.str();
    if(mess == "8ball"){
        mess = eightBall();
    }
    else if(mess == "magic8ball"){
        mess = magicEightBall();
    }
    else if(mess == "joke"){
        mess = joke();
    }

    int lenOfMess = mess.length();
    // printf("%d\n", lenOfMess);
    std::stringstream ss;
    ss << " _";
    for (int i = 0; i < lenOfMess; i++){
        ss<<"_";   
    }
    ss << "_ \n";
    
    ss << "< ";
    ss << mess;
    ss << " >\n";

    ss << " -";
    for (int i = 0; i< lenOfMess; i++){
        ss<<"-";
    }
    ss << "- \n";

    ss << "          \\ \n";
    ss << "           \\ \n";
    // ss << "          (^・ω・^ ) \n";



    // ss.str("");
    ss << "     ▐▀▄       ▄▀▌   ▄▄▄▄▄▄▄ \n";
    ss << "     ▌▒▒▀▄▄▄▄▄▀▒▒▐▄▀▀▒██▒██▒▀▀▄ \n";
    ss << "    ▐▒▒▒▒▀▒▀▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▀▄ \n";
    ss << "    ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▒▒▒▒▒▒▒▒▒▒▒▒▀▄ \n";
    ss << "  ▀█▒▒▒█▌▒▒█▒▒▐█▒▒▒▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌ \n";
    ss << "  ▀▌▒▒▒▒▒▒▀▒▀▒▒▒▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐   ▄▄ \n";
    ss << "  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌▄█▒█ \n";
    ss << "  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒█▀ \n";
    ss << "  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▀ \n";
    ss << "  ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌ \n";
    ss << "   ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐ \n";
    ss << "   ▐▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▌ \n";
    ss << "    ▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▐ \n";
    ss << "    ▐▄▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▄▌ \n";
    ss << "      ▀▄▄▀▀▀▀▀▄▄▀▀▀▀▀▀▀▄▄▀▀▀▀▀▄▄▀ \n";




    printf(ss.str().c_str());
    
    // printf(argv[1]);
    printf("\n");

	return 0;
}

