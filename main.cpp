#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <sstream>

//basic pokemon structure
class pokemon{
public:
    std::string name;
    int HP;
    int attack;
    int defense;
    pokemon(std::string s, int h, int a, int d){
        name = s;
        HP = h;
        attack = a;
        defense = d;
    }
};

//vectors containing each user's pokemon
std::vector<pokemon> markPokemon;
std::vector<pokemon> userPokemon;
bool userIsMark;

//preload base data
void loadData(){
    markPokemon.push_back(pokemon("MarkEevee",55,55,50));
    markPokemon.push_back(pokemon("MarkRowlet",68,55,55));
    markPokemon.push_back(pokemon("MarkCyndaquil",39,52,43));
    markPokemon.push_back(pokemon("MarkZorua",40,65,40));
    markPokemon.push_back(pokemon("MarkBulbasaur",45,49,49));
    markPokemon.push_back(pokemon("MarkOshawott",55,55,45));
    markPokemon.push_back(pokemon("MarkFennekin",40,45,40));
    markPokemon.push_back(pokemon("MarkSneasel",55,95,55));

    userPokemon.push_back(pokemon("Eevee",55,55,50));
    userPokemon.push_back(pokemon("Rowlet",68,55,55));
    userPokemon.push_back(pokemon("Cyndaquil",39,52,43));
    userPokemon.push_back(pokemon("Zorua",40,65,40));
    userPokemon.push_back(pokemon("Bulbasaur",45,49,49));
    userPokemon.push_back(pokemon("Oshawott",55,55,45));
    userPokemon.push_back(pokemon("Fennekin",40,45,40));
    userPokemon.push_back(pokemon("Sneasel",55,95,55));
}

//view a select pokemon's stats
void viewPokemon(int index){
    if(userIsMark){
        std::cout << markPokemon.at(index).name << " " << std::endl;
        std::cout << "HP: " << markPokemon.at(index).HP << " " << std::endl;
        std::cout << "Attack: " << markPokemon.at(index).attack << " " << std::endl;
        std::cout << "Defense: " << markPokemon.at(index).defense << " " << std::endl;
    } else {
        std::cout << userPokemon.at(index).name << " " << std::endl;
        std::cout << "HP: " << userPokemon.at(index).HP << " " << std::endl;
        std::cout << "Attack: " << userPokemon.at(index).attack << " " << std::endl;
        std::cout << "Defense: " << userPokemon.at(index).defense << " " << std::endl;
    }
    std::cout << "\n";
}

//dispay list of all Pokemon
void viewList(){
    if(userIsMark){
        for(int i=0;i<markPokemon.size();i++){
            std::cout << (i+1) << ") " + markPokemon.at(i).name << std::endl;
        }
    } else {
        for(int i=0;i<userPokemon.size();i++){
            std::cout << (i+1) << ") " + userPokemon.at(i).name << std::endl;
        }
    }

    std::cout << "\n";
};

//edit a select pokemon's stats
void editPokemon(int index){
    if(userIsMark){
        std::cout << markPokemon.at(index).name << std::endl;
        std::cout << "HP: " << markPokemon.at(index).HP << std::endl;
        std::cout << "Attack: " << markPokemon.at(index).attack << std::endl;
        std::cout << "Defense: " << markPokemon.at(index).defense << std::endl;
    } else {
        std::cout << userPokemon.at(index).name << std::endl;
        std::cout << "HP: " << userPokemon.at(index).HP << std::endl;
        std::cout << "Attack: " << userPokemon.at(index).attack << std::endl;
        std::cout << "Defense: " << userPokemon.at(index).defense << std::endl;
    }
    //Choose which stat to edit
    std::cout << "Enter which stat you would like to edit ( [1]-HP, [2]-Attack, [3]-Defense) followed by a space and a new value\n"
              << "The new stat value must be greater than 2."<< std::endl;
    int statIndex = -1;
    char readIn[64];
    unsigned int statChange = -1;
    std::cin >> statIndex >> readIn;
    //ensure value is big enough
    if(strcmp(readIn, "0") != 0 && strcmp(readIn, "1") != 0 && strcmp(readIn, "2") != 0 && readIn[0] != '-'){
        //convert from input to tangable integer
        std::stringstream str_strm(readIn);
        str_strm >> statChange;
        //remove fainted pokemon
        if(statChange == -1 && statIndex == 1){
            if(userIsMark)
                markPokemon.erase(markPokemon.begin()+index);
            else
                userPokemon.erase(userPokemon.begin()+index);
        }
            //make the change in stat
        else switch(statIndex){
                case 1:
                    if(userIsMark){
                        markPokemon.at(index).HP = statChange;
                    } else {
                        userPokemon.at(index).HP = statChange;
                    }
                    break;
                case 2:
                    if(userIsMark){
                        markPokemon.at(index).attack = statChange;
                    } else {
                        userPokemon.at(index).attack = statChange;
                    }
                    break;
                case 3:
                    if(userIsMark){
                        markPokemon.at(index).defense = statChange;
                    } else {
                        userPokemon.at(index).defense = statChange;
                    }
                    break;
                default:
                    std::cout << "Please Enter a valid number 0-3" << std::endl;
            }
    } else{
        std::cout << "Value is too low....\n" << std::endl;
    }
}

//simulate battle between you and your opponent
void battle(){
    std::vector<pokemon> markteam;
    std::vector<pokemon> userteam;

    //select team to attack with
    if(userIsMark){
        viewList();
        std::cout << "please enter the 3 indexes of your chosen battle pokemon with a space in between" << std::endl;
        int choice = -1;
        for(int i=0;i<3;){
            std::cin >> choice;
            if(choice < 1 || choice > markPokemon.size())
                std::cout << "Please enter a valid index" << std::endl;
            else{
                bool chosenAlready = false;
                for(int j=0;j<markteam.size();j++){
                    if(markteam.at(i).name == markPokemon.at(choice-1).name) {
                        chosenAlready = true;
                        std::cout << "Please select a new pokemon. This one is already on your team" << std::endl;
                        break;
                    }
                }
                if(!chosenAlready){
                    markteam.push_back(pokemon(markPokemon.at(choice-1).name, markPokemon.at(choice-1).HP, markPokemon.at(choice-1).attack, markPokemon.at(choice-1).defense));
                    i++;
                }
            }
        }
        //select opponent's team
        for(int i=0;i<3;){
            choice = rand()%userPokemon.size();
            bool chosenAlready = false;
            for(int j=0;j<userteam.size();j++){
                if(userteam.at(j).name == userPokemon.at(choice-1).name) {
                    chosenAlready = true;
                    std::cout << "Please select a new pokemon. This one is already on your team" << std::endl;
                    break;
                }
            }
            if(!chosenAlready) {
                userteam.push_back(pokemon(userPokemon.at(choice - 1).name, userPokemon.at(choice - 1).HP,
                                           userPokemon.at(choice - 1).attack, userPokemon.at(choice - 1).defense));
                i++;
            }
        }
    } else {
        viewList();
        std::cout << "please enter the 3 indexes of your chosen battle pokemon with a space in between" << std::endl;
        int choice = -1;
        for(int i=0;i<3;){
            std::cout << "Please enter your next index: " << std::endl;
            std::cin >> choice;
            if(choice < 1 || choice > userPokemon.size())
                std::cout << "Please enter a valid index" << std::endl;
            else{
                bool chosenAlready = false;
                for(int j=0;j<userteam.size();j++){
                    if(userteam.at(j).name == userPokemon.at(choice-1).name) {
                        chosenAlready = true;
                        std::cout << "Please select a new pokemon. This one is already on your team" << std::endl;
                        break;
                    }
                }
                if(!chosenAlready){
                    userteam.push_back(pokemon(userPokemon.at(choice-1).name, userPokemon.at(choice-1).HP, userPokemon.at(choice-1).attack, userPokemon.at(choice-1).defense));
                    i++;
                }
            }
        }
        //select opponent's team
        for(int i=0;i<3;){
            choice = rand()%markPokemon.size();
            bool chosenAlready = false;
            for(int j=0;j<markteam.size();j++){
                if(markteam.at(j).name == markPokemon.at(choice-1).name) {
                    chosenAlready = true;
                    std::cout << "Please select a new pokemon. This one is already on your team" << std::endl;
                    break;
                }
            }
            if(!chosenAlready) {
                markteam.push_back(pokemon(markPokemon.at(choice - 1).name, markPokemon.at(choice - 1).HP,
                                           markPokemon.at(choice - 1).attack, markPokemon.at(choice - 1).defense));
                i++;
            }
        }
    }

    //Battle until one person's pokemon are destroyed
    while(markteam.size() > 0 && userteam.size() > 0){
        //select user's attack
        std::cout << "Please select which pokemon to attack with : " << std::endl;
        int pokeChoice = -1;
        int opponentChoice = -1;
        if(userIsMark){
            for(int i=0;i<markteam.size();i++){
                std::cout << "[" << i << "]" << markteam.at(i).name << " - HP: " << markteam.at(i).HP << std::endl;
            }
            std::cin >> pokeChoice;
            opponentChoice = rand() % userteam.size();
        } else {
            for(int i=0;i<userteam.size();i++){
                std::cout << "[" << i << "]"<< userteam.at(i).name << " - HP: " << (userteam.at(i).HP) << std::endl;
            }
            std::cin >> pokeChoice;
            opponentChoice = rand() % markteam.size();
        }
        //damage dealt is going to be att * att / (att + def)
        int damageDealt = -1;
        bool victory = false;
        //user pokemon attack first
        if(userIsMark){
            //display battle stats
            std::cout << userteam.at(opponentChoice).name << "-" << userteam.at(opponentChoice).HP << " vs. " <<
                      markteam.at(pokeChoice).name << "-" << markteam.at(pokeChoice).HP << std::endl;

            //calculate damage dealt
            damageDealt = (markteam.at(pokeChoice).attack*markteam.at(pokeChoice).attack)/(markteam.at(pokeChoice).attack+userteam.at(opponentChoice).defense);
            userteam.at(opponentChoice).HP -= damageDealt;
            if(userteam.at(opponentChoice).HP <= 0){
                std::cout << "You defeated your opponent's pokemon!" << std::endl;
                victory = true;
                userteam.erase(userteam.begin()+opponentChoice);
            } else {
                std::cout << "You dealt " << damageDealt << " damage to your opponent's pokemon";
            }

            if(!victory){
                //calculate damage recieved
                damageDealt = (userteam.at(opponentChoice).attack*userteam.at(opponentChoice).attack)/(userteam.at(opponentChoice).attack+markteam.at(pokeChoice).defense);
                markteam.at(pokeChoice).HP -= damageDealt;
                if(markteam.at(pokeChoice).HP <= 0){
                    std::cout << "Your pokemon was defeated!" << std::endl;
                    markteam.erase(markteam.begin()+pokeChoice);
                } else {
                    std::cout << "You suffered " << damageDealt << " damage from your opponent's pokemon";
                }
            }
        } else {
            //display battle stats
            std::cout << userteam.at(pokeChoice).name << "-" << userteam.at(pokeChoice).HP << " vs. " <<
                      markteam.at(opponentChoice).name << "-" << markteam.at(opponentChoice).HP << std::endl;

            //calculate damage dealt
            damageDealt = (userteam.at(pokeChoice).attack*userteam.at(pokeChoice).attack)/(userteam.at(pokeChoice).attack+markteam.at(opponentChoice).defense);
            markteam.at(opponentChoice).HP -= damageDealt;
            if(markteam.at(opponentChoice).HP <= 0){
                std::cout << "You defeated your opponent's pokemon!" << std::endl;
                markteam.erase(markteam.begin()+opponentChoice);
                victory = true;
            } else {
                std::cout << "You dealt " << damageDealt << " damage to your opponent's pokemon" << std::endl;
            }

            //calculate damage recieved
            if(!victory){
                damageDealt = (markteam.at(opponentChoice).attack*markteam.at(opponentChoice).attack)/(markteam.at(opponentChoice).attack+userteam.at(pokeChoice).defense);
                userteam.at(pokeChoice).HP -= damageDealt;
                if(userteam.at(pokeChoice).HP <= 0){
                    std::cout << "Your pokemon was defeated!" << std::endl;
                    userteam.erase(userteam.begin()+pokeChoice);
                } else {
                    std::cout << "You suffered " << damageDealt << " damage from your opponent's pokemon" << std::endl;
                }
            }
        }
    }
    //determine results
    if(markteam.size() > 0){
        std::cout << "Mark won this battle." << std::endl;
    } else {
        std::cout << "User won this battle." << std::endl;
    }
}

int main () {
    loadData();
    char test[] = "hello";
    bool mark = false;
    char help[4];
    int decision;
    int failures = 0;

    while(decision != 4){
        userIsMark = mark;

        if(failures <= 5){
            std::cout << "Please select an option of what you would like to do:" << std::endl;
            std::cout << "[0] View Pokemon List" << std::endl;
            std::cout << "[1] View a Pokemon Stats" << std::endl;
            std::cout << "[2] Edit a Pokemon" << std::endl;
            std::cout << "[3] Battle Mark" << std::endl;
            std::cout << "[4] Exit" << std::endl;

            std::cin >> decision;

            //catch any non-integer entries
            while(std::cin.fail()) {
                std::cout << "Please enter a valid integer between 0-4" << std::endl;
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cin >> decision;
                failures++;
                if(failures > 5)
                    break;
            }
        }
            //Activate Assist to help
        else{
            bool selected = false;
            while(!selected){
                std::cin.clear();
                std::cin.ignore(256,'\n');
                std::cout << "\n\n\n\n\n\n\nVERBAL HELP: Simply enter the name of the option you would like" << std::endl;
                std::cout << "To view pokemon enter view\nTo view stats enter stat\nTo edit a pokemon enter edit\nTo battle enter mark\nTo exit enter exit" << std::endl;
                std::cin >> help;
                if(strcmp(help, "view") == 0){
                    decision = 0;
                    selected = true;
                }
                else if(strcmp(help, "stat") == 0){
                    decision = 1;
                    selected = true;
                }
                else if(strcmp(help, "edit") == 0){
                    decision = 2;
                    selected = true;
                }
                else if(strcmp(help, "mark") == 0){
                    decision= 3;
                    selected = true;
                }
                else if(strcmp(help, "exit") == 0){
                    decision = 4;
                    selected = true;
                }
                else
                    std::cout << "Invalid Input. Try again." << std::endl;
            }
        }

        switch(decision){
            case 0: {
                viewList();
                break;
            }
            case 1: {
                viewList();
                //enter the index of the pokemon you want to view
                std::cout << "Which pokemon did you want to view? Please enter the index number" << std::endl;
                int pokeIndex = -1;
                std::cin >> pokeIndex;
                viewPokemon(pokeIndex - 1);
                break;
            }
            case 2: {
                viewList();
                //enter the index of the pokemon you want to edit
                std::cout << "Which pokemon did you want to edit? Please enter the index number" << std::endl;
                int pokeIndex = -1;
                std::cin >> pokeIndex;
                editPokemon(pokeIndex - 1);
                break;
            }
            case 3: {
                battle();
                break;
            }
            case 4: {
                break;
            }
            default: {
                std::cout << "Please Enter a valid number 0-4" << std::endl;
                failures++;
            }
        }
    }
    return 0;
}