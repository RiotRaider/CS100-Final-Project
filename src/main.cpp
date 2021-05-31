#include "../header/Map/Tile.hpp"
#include "../header/Map/Map.hpp"
#include "../header/Quest/Questlog.hpp"
#include "../header/Quest/Quest.hpp"
#include "../header/Intitialization/initialization.hpp"
#include "../header/Intitialization/InitialPlayer.hpp"
#include "../header/Menu.hpp"
#include "../header/Combat.hpp"

#include <iostream>
#include <stdlib.h>

int main(){
//Prepare RNG for use by seeding with system time
	srand(time(0));
//Global Generation Interfaces
	CharacterFactory *CharCreator = new CharacterFactory();
	InitialPlayer* pGen = new InitialPlayer();

//World Initialization Interface
	Initialization* worldGen = nullptr;

//Key Object Pointers
	Map* map =new Map();
	QuestLog* quests = new QuestLog();
	Player* player = nullptr;

//Interface Object Pointers
	CoreMenu* menu = nullptr;

//Control Variables
	char choice = '0'; //controls main menu
	bool game_done = false;//indicates game over

//Welcome Message
        std::cout << "=========================================\n";
	std::cout << "Welcome to Phantomheart!\n\n";
//Start Menu Loop
	while(choice != '2'){
		std::cout << "***MAIN MENU***\n\nPlease make a selection:\n1 - Start New Game\n2 - Quit\n";
		std::cin >> choice;
		switch(choice){
			case '1':
			        std::cout << "\n\n=========================================\n";
				std::cout<<"***NEW GAME***\n\n";
				//Reset Game Objects if not first play during run
				if(player){
					delete player; 
					delete quests; 
					delete map; 
					delete worldGen;
					delete menu;
					map = new Map(); 
					quests = new QuestLog();}
				//Create new Player
				std::cout<<"**CHARACTER CREATION**\n\n";
				player = pGen->createPlayer(CharCreator);
				//Create Map and Populate Quests
				worldGen = new Initialization(map, quests);
				menu = new CoreMenu(map, quests, player);
				while(!game_done){
					while(menu->getFlag()){
						menu->menu();
					}
					if(player->getCurHP()<=0){
                                                std::cout << player->getName() << " has been beaten. Their adventure is over. What a shame...\n" ;
                                                game_done = 1;
					}else if(quests->compareQuest(map->getCurrent())){
						std::cout << player->getName() << " managed to follow orders and have a wonderful time. Good job!\n";
						game_done = 1;
					}else if(menu->getMoveFlag()){
						std::cout << "COMBAT IMPLEMENTED HERE\n";
					}else{
						std::cout << "Progress was not saved\n";
						game_done = 1;
					}
						
				}
				break;
			case '2':
				std::cout <<"\n\nTHANK YOU FOR PLAYING!!!\n\n\n";
				std::cout << "=========================================\n";
				break; 
			default: 
				std::cout << "Invalid Selection\n\n\n";
				break;
		}

	}
	std::cin.clear();
	std::cin.ignore();	


	//Delete any objects created during runtime
	if(player){delete player; delete quests; delete map; delete worldGen;}
	delete pGen; 		//delete Player Initializer
	delete CharCreator; 	//delete CharacterFactory

	return 0;
}

