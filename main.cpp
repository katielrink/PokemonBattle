#include <iostream>
#include <vector>

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
//    markPokemon.push_back(pokemon("Eevee",55,55,50));
//    markPokemon.push_back(pokemon("Rowlet",68,55,55));
//    markPokemon.push_back(pokemon("Cyndaquil",39,52,43));
//    markPokemon.push_back(pokemon("Zorua",40,65,40));
//    markPokemon.push_back(pokemon("Bulbasaur",45,49,49));
//    markPokemon.push_back(pokemon("Oshawott",55,55,45));
//    markPokemon.push_back(pokemon("Fennekin",40,45,40));
    markPokemon.push_back(pokemon("Sneasel",55,95,55));
    userPokemon.push_back(pokemon("Eevee",55,55,50));
    userPokemon.push_back(pokemon("Rowlet",68,55,55));
    userPokemon.push_back(pokemon("Cyndaquil",39,52,43));
    userPokemon.push_back(pokemon("Zorua",40,65,40));
    userPokemon.push_back(pokemon("Bulbasaur",45,49,49));
    userPokemon.push_back(pokemon("Oshawott",55,55,45));
    userPokemon.push_back(pokemon("Fennekin",40,45,40));
    userPokemon.push_back(pokemon("Sneasel",55,95,55));
}


//dispay list of all Pokemon
void viewList(){
    if(!userIsMark){
        for(int i=0;i<userPokemon.size();i++){
            std::cout << (i+1) << ") " + userPokemon.at(i).name << std::endl;
        }
    } else {
        for(int i=0;i<markPokemon.size();i++){
            std::cout << (i+1) << ") " + markPokemon.at(i).name << std::endl;
        }
    }
};

//view a select pokemon's stats
void viewPokemon(int index){
    if(!userIsMark){
        std::cout << userPokemon.at(index).name << " " << std::endl;
        std::cout << "HP: " << userPokemon.at(index).HP << " " << std::endl;
        std::cout << "Attack: " << userPokemon.at(index).attack << " " << std::endl;
        std::cout << "Defense: " << userPokemon.at(index).defense << " " << std::endl;
    } else {
        std::cout << markPokemon.at(index).name << " " << std::endl;
        std::cout << "HP: " << markPokemon.at(index).HP << " " << std::endl;
        std::cout << "Attack: " << markPokemon.at(index).attack << " " << std::endl;
        std::cout << "Defense: " << markPokemon.at(index).defense << " " << std::endl;
    }
}

//edit a select pokemon's stats
void editPokemon(int index){
    if(!userIsMark){
        std::cout << userPokemon.at(index).name << ":: " << std::endl;
        std::cout << "HP: " << userPokemon.at(index).HP << ":: " << std::endl;
        std::cout << "Attack: " << userPokemon.at(index).attack << ":: " << std::endl;
        std::cout << "Defense: " << userPokemon.at(index).defense << ":: " << std::endl;
    } else {
        std::cout << markPokemon.at(index).name << ":: " << std::endl;
        std::cout << "HP: " << markPokemon.at(index).HP << ":: " << std::endl;
        std::cout << "Attack: " << markPokemon.at(index).attack << ":: " << std::endl;
        std::cout << "Defense: " << markPokemon.at(index).defense << ":: " << std::endl;
    }
    //Choose which stat to edit
    std::cout << "Which stat would you like to edit? [1]-HP, [2]-Attack, [3]-Defense" << std::endl;
    int statIndex = -1;
    std::cin >> statIndex;
    //Choose how to change stat
    std::cout << "What would you like the new stat to be?" << std::endl;
    int statChange = -1;
        std::cin >> statChange;
    //make the change in stat
    switch(statIndex){
        case 1:
            if(!userIsMark){
                userPokemon.at(index).HP = statChange;
            } else {
                markPokemon.at(index).HP = statChange;
            }
            break;
        case 2:
            if(!userIsMark){
                userPokemon.at(index).attack = statChange;
            } else {
                markPokemon.at(index).attack = statChange;
            }
            break;
        case 3:
            if(!userIsMark){
                userPokemon.at(index).defense = statChange;
            } else {
                markPokemon.at(index).defense = statChange;
            }
            break;
        default:
            std::cout << "Please Enter a valid number 0-3" << std::endl;
    }
}

//reset all pokemon, so you have a blank slate
void reset(){
    if(!userIsMark){
        while(!userPokemon.empty()){
            userPokemon.pop_back();
        }
    } else {
        while(!markPokemon.empty()){
            markPokemon.pop_back();
        }
    }
    std::cout << "reset done!" << std::endl;
}

//simulate battle between you and your opponent
void battle(){
    std::vector<pokemon> markteam;
    std::vector<pokemon> userteam;

    //select team to attack with
    if(!userIsMark){
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
    } else {
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
    }

    //Battle until one person's pokemon are destroyed
    while(markteam.size() > 0 && userteam.size() > 0){
        //select user's attack
        std::cout << "Please select which pokemon to attack with : " << std::endl;
        int pokeChoice = -1;
        int opponentChoice = -1;
        if(!userIsMark){
            for(int i=0;i<userteam.size();i++){
                std::cout << "[" << i << "]"<< userteam.at(i).name << " - HP: " << (userteam.at(i).HP) << std::endl;
            }
            std::cin >> pokeChoice;
            opponentChoice = rand() % markteam.size();
        } else {
            for(int i=0;i<markteam.size();i++){
                std::cout << "[" << i << "]" << markteam.at(i).name << " - HP: " << markteam.at(i).HP << std::endl;
            }
            std::cin >> pokeChoice;
            opponentChoice = rand() % userteam.size();
        }
        //damage dealt is going to be att * att / (att + def)
        int damageDealt = -1;
        bool victory = false;
        //user pokemon attack first
        if(!userIsMark){
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
        } else {
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
    int decision = -1;
    while(decision != 4){
        std::cout << "Please select an option of what you would like to do:" << std::endl;
        std::cout << "[0] View Pokemon List:" << std::endl;
        std::cout << "[1] View a Pokemon Stats:" << std::endl;
        std::cout << "[2] Edit a Pokemon" << std::endl;
        std::cout << "[3] Battle Mark" << std::endl;
        std::cout << "[4] Exit" << std::endl;
        std::cin >> decision;

        userIsMark = false;

        //catch any non-integer entries
        while(std::cin.fail()) {
            std::cout << "Please enter a valid integer between 0-4" << std::endl;
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> decision;
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
            }
        }
    }
    return 0;
}