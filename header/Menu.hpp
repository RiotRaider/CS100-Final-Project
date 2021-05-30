#ifndef __MENU_HPP__
#define __MENU_HPP__

//#include "../Map.hpp"
//#include "../QuestLog.hpp"

#include <string>
#include "../header/Map/Map.hpp"
#include <iostream>
class Menu {

	public:
		virtual void print() = 0;
//		virtual char getChoice() = 0;
		virtual bool getFlag() = 0;
		//virtual bool 
		virtual void setChoice() = 0;
	protected:
		char choice;
		bool flag;
		
};



class MapMenu : public Menu {

        private:
        Map * newMap;
        public:
                MapMenu(Map* map) {this->newMap= map;}
       
		MapMenu() {}
                void print() override {
                                std::cout << "1 - Move West\n2 - Move East\n3 - Move North\n4 - Move South" << std::endl;
                                }


//                char getChoice() {
  //                      return choice;
    //            }
                bool getFlag() {return true;} //have to implement?

                void setChoice() {std::cin >> choice;
			          newMap->move(choice);
			}

};






class CharMenu : public Menu {
	
	private:
	
	MapMenu *compass;
	Map *newMap;
	QuestLog* newQuests;

	public:
		CharMenu (Map* map, QuestLog * quests) {compass = new MapMenu(map);
				this->newMap = map;
				this->newQuests = quests;
				flag = true;
				}
		void print() {std::cout << newMap->getCurrent()->getdescription() +
						"\n1 - Move \n2 - Check Objective\n3 - Check Inventory\n4 - Quit Game" << std::endl;}
		
		void setChoice() {
				  std::cin >> choice;
				  switch(choice) {
					case '1':
						compass->print();
						compass->setChoice();
								
						break;
					case '2':
						std::cout << newQuests->getCurrent()->getObj() << std::endl;	
						
						break;
					case '3':
						break;
					case '4':
						flag = false;
						break;
					}

				}
/*
		char getChoice () {return choice;}
*/
		bool getFlag() { if(newQuests->compareQuest(newMap->getCurrent())) {
						flag = false;
					}
				return flag; 
				}

};


class CombatMenu : public Menu {
//		 void setChoice(char c) {choice = c;}

		void print () {std::cout << "" << std::endl;}
//		char getChoice () {return  choice;}
//		bool getFlag() {return false;}

};








#endif
