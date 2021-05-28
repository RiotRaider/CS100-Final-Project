
#include "../Map/Map.hpp"
#include "../Map/Tile.hpp"
#include "../Quest/Quest.hpp"
#include "../Quest/Questlog.hpp"

class initialization
{
private: 
Map* test = new Map();
QuestLog* quests= new QuestLog();
public:
initialization(Map* map_in, QuestLog* quests_in)
{
Tile* beginning = new Tile ("You stand at a bustling space station. The flashing neon signs and the whirr of the air control unit inundates the station. Several teleportation portals lie at the cardinal directions of the room. To the North, lies the way to the blue planet. To the South, the Red. To the West, Rainbow. To the East Green. ", 1);
Tile* green = new Tile ("Welcome to the Green planet, a verdant planet filled with vegetation. To the West, the portal you just exited from glows with unworldy energies. To the North, a jungle temple towers above the trees. To the South, a massive tree towers over all the rest. To the East, a beam of life shoots up from the planet." ,1);
Tile* Temple = new Tile("You enter a cobblestone Temple, Moss propogating through out the stone, and Vines growing out of every wall. As you walk in, you see a brazier. Etched in stone above are the words, \"Bring the lifeblood of red\" you wonder what this could mean. You can go South to return to the portal." , 1);
Tile* Tower = new Tile("You visit the tower, a closed door blocks your way, who knows what is inside. A princess? A Dragon? Or maybe it's just an empty tower. You can go North to return to the portal." , 1);
Tile* Pillar = new Tile("A massive pillar of light shoots into the sky, projecting its holiness upwards, or maybe something is shooting downards. Only the creator knows the truth. You can go West to return to the portal" , 1);
Tile* blue = new Tile ("Welcome to the Blue planet, an ocean planet flooded with water. You look South, at the portal you just exited from, throbbing with energy. To the North, there is Ocean, to the West, Ocean, and finally, to the East, also Ocean.", 1);
Tile* Ocean = new Tile("You're currently in the Ocean, as you look around, there really isn't much. Just more Ocean.",1);
Tile* red = new Tile ("Welcome to the Red planet, a planet with heavy volcanic activity. You look North, at the portal you just exited from, pulsing with energies. To the South, you see a massive volcano. To the West, a man. To the East, a river of lava. " ,1);
Tile* Man = new Tile ("A man in a glowy blue suit stands here, he has a big hover clipboard and appears to be just standing there. You can go East to return to the portal.", 1);
Tile* River = new Tile ( "A winding river of lava flows through here, blocking your way across. Not that you particularly want to go across You can go West to return to the Portal" , 1);
Tile* Volcano = new Tile ("You enter a small hole in the wall of the volcano, like one of those old terran films, there is a pathway leading to a massive lava pool. A pile of rocks lay at the end of the walk way. You can go North to return to the portal",1);
Tile* rainbow = new Tile ("RAINBOW WORLDDDDDDDDDDDDDDDDDDDDDDDDDDD" ,1);
test->setLoc(beginning);
test->insertTile(beginning);
test->insertTile(green);
test->insertTile(Temple);
test->insertTile(Tower);
test->insertTile(Pillar);
test->insertTile(blue);
test->insertTile(Ocean);
test->insertTile(red);
test->insertTile(Man);
test->insertTile(River);
test->insertTile(Volcano);
test->insertTile(rainbow);
test->setLoc(beginning);

//set adjacencies
beginning->setAdj(rainbow, green, blue, red);
rainbow->setAdj(nullptr, nullptr, nullptr ,nullptr);
green->setAdj(beginning, Pillar, Temple ,Tower);
Pillar->setAdj(green, nullptr, nullptr,nullptr);
Temple->setAdj(nullptr,nullptr,nullptr,green);
Tower->setAdj(nullptr,nullptr,green,nullptr);
blue->setAdj(Ocean,  Ocean ,Ocean, beginning);
Ocean->setAdj(blue,blue,blue,blue);
red->setAdj(Man, River,beginning ,Volcano);
Man->setAdj(nullptr,red,nullptr,nullptr);
Volcano->setAdj(nullptr,nullptr,red,nullptr);
River->setAdj(red,nullptr,nullptr,nullptr);

//associate quests with Tiles
quests->addQuest(new Quest("Welcome to the game, you are a dashing explorer, meant to be the first line of scouting in this new planet rush. HQ has ordered that you go to the red planet", "go to red planet" , "You land on the red planet, a hazardous planet bursting with lava.",beginning , red));
quests->addQuest(new Quest("Your communicator crackles to life \"HEY CADET GET TO WORK EXPLORING THIS JUNK HEAP I AINT PAYING YOU TO STAND THERE\"" , "Better listen to the officer. Explore the red planet." , "The Man hails you, \"Hey man, I got something for you.\"", red, Man));
quests->addQuest(new Quest("\"Hey there, friend,\" the man says, \"I heard you wanna know about this land, well, I can tell you. I've been here for quite a while. The thing is, I need a favor. Ya see, I gotta get me one of them big rocks from the volcano, but this play is filled with monsters. Can you get it for me?\"","get a stone from the volcano for this man.", "You grab a big rock off the volcano", Man , Volcano));
quests->addQuest(new Quest("You grabbed a rock out of the volcano, time to go back to the man" , "Go back to the man" , "\"Heyyy, good job, now I can finally get my data log done. Here is a copy, I'm sure youre boss man will appreciate it.\"", Volcano ,Man));
quests->addQuest(new Quest("With the information, the red planet is explored, time to go back to HQ","Go through the portal back to HQ", "You arrive at the office of your Officer and drop off the data. \"Took you long enough you space fool\"" ,Man, beginning));
quests->addQuest(new Quest("As soon as you sit down, the officer barks at you again, \"CADET, WHAT ARE YOU DOING?! YOU STILL GOT 3 MORE PLANETS TO LOG.\" You sigh, but a job is a job, so you get up and decide to go to the blue portal. ","Go to the blue planet","Whelp, you arrived at the blue planet, Doesn't really look like much currently",beginning,blue));
quests->addQuest(new Quest("Your communicator once again blazes out a very familiar voice \"WHAT ARE YOU DOING YOU BUFFON, START LOOKING.\" You decide that it's probably a good idea to do what you officer says and start looking.","Explore the blue planet","You've arrived at the end of this shore, and all you see is Ocean",blue,Ocean));
quests->addQuest(new Quest("You've looked around quite a bit, and can only see Ocean as far as the eye can see, maybe it's time to give up?","Keep looking around the planet","You've decided that you've had enough of that big blue blob, and went back to the office with your data pad.",Ocean ,beginning));
quests->addQuest(new Quest("You walk into the office, and drop off your data pad, of course, you are instantly welcomed with shouting \"WHAT IS THIS CADET?! JUST OCEAN? HOW USELESS IS THIS INFORMATION? YOU AINT GETTING PAID FOR THIS.\" You quickly explain that this was all that was on the planet, and there wasn't anything else. But the Officer wanted no part of it. Instead, he just sent you on to the Green Planet","God, you hate your job. Off to the Green Planet.","You arrived at the Green Planet, at least this one looks more interesting. Time to look around.",beginning,green));
quests->addQuest(new Quest("The communicator once again belts off some random words, this time you don't listen to it though. It's all the same anyways.","Explore the green planet.","You arrive at a glowing pillar, on a whim, you decide to walk over and touch it. As soon as you do, a disemboied voice echos through your mind. \"Solve the puzzle at the temple, and the secrets of the rainbow shall be yours\". You think that you don't really care about the secrets of the rainbow. But just as soon as you think that, the voice continues \"There will also be cool loooooot\". Now that's something you can get behind.",green,Pillar));
quests->addQuest(new Quest("Reinvigorated by the idea of cool loot, you decied to go over to the temple.","Go to the temple.","You arrive at the temple, it reminds you of something very blocky, watching out for tripwires and dispensers, you read the shrine message again.",Pillar,Temple));
quests->addQuest(new Quest("Knowing the message, you think on how to solve it.","Solve the puzzle.","You've arrived at the lava river, sucking some lava into your suit resivour.",Temple,River));
quests->addQuest(new Quest("Time to deliver the \"blood\".","Deliever the lava to the Temple","You return to the temple and pour out the lava.",River, Temple));
quests->addQuest(new Quest("The temple echos and shakes, as you pour the lava into the brazier. As the lava flows through the brazier, the words above change temporarily, \"Go to the temple and slap yourself\". A little bit strange, but little trouble for sweet loot you suppose.","Go to the temple and commit THE SLAP","You arrive at the temple, guess it's time to slap yourself. This feels weird.",Temple, Tower));
quests->addQuest(new Quest("The voice echos in your mind again. \"Go to rainbow worlddddddddddddddddd the sweet loot is there\". Whelp, time to trust the magical disembodied voice in your mind. No way this could go wrong.","Go to Rainbow World","You've arrived at RAINBOW WORLDDDDDDDDDDDDDD",Tower, rainbow));
Quest* ending = nullptr;
quests->addQuest(ending);
beginning=nullptr;
rainbow=nullptr;
green=nullptr;
Pillar=nullptr;
Temple=nullptr;
Tower=nullptr;
blue=nullptr;
Ocean=nullptr;
red=nullptr;
Man=nullptr;
Volcano=nullptr;
River=nullptr;
map_in = test;
quests_in = quests;
}

};
