#include<iostream>
#include <ctime>
#include <time.h>
#include <string>
using namespace std;

//-------------------------------------------Variables------------------------------------------------
struct {
    string name;
    int health;
    int coins;
    int potions;
    string weapon;
    int weoponlvl;
    int speed;
    bool defend;
    int damage;
    string bag[5];
    bool elyria;
    int stamnia;

} player;

struct {
    string name;
    int health;
    int ammo;
    int speed;
    int damage;
    string weapon;
    bool trick;
    bool sorcerer;
} enemy;

int stageCounter;
int answer;
bool archer = 0;
int powerRange = 0;
bool exitLoop = 0;
float dialogSpeed = 0.2;

//------------------------------------------------------------------------------------------------------

void sleep(float seconds){
    clock_t startClock = clock();
    float secondsAhead = seconds * CLOCKS_PER_SEC;
    // do nothing until the elapsed time has passed.
    while(clock() < startClock+secondsAhead);
    return;
}


void banner(){
    cout << "  ____ _                     _      _                    __" << endl << 
" / ___| |__  _ __ ___  _ __ (_) ___| | ___  ___    ___  / _|" << endl << 
"| |   | '_ \\| '__/ _ \\| '_ \\| |/ __| |/ _ \\/ __|  / _ \\| |_ " << endl << 
"| |___| | | | | | (_) | | | | | (__| |  __/\\__ \\ | (_) |  _|" << endl <<
" \\____|_| |_|_| _\\___/|_| |_|_|\\___|_|\\___||___/  \\___/|_|  " << endl <<
"               | ____| | __| | ___  _ __(_) __ _ " << endl <<
"               |  _| | |/ _` |/ _ \\| '__| |/ _` |" << endl <<
"               | |___| | (_| | (_) | |  | | (_| | " << endl <<
"               |_____|_|\\__,_|\\___/|_|  |_|\\__,_|" << endl << endl;
    cout << "                __...--~~~~~-._   _.-~~~~~--...__" << endl << 
"              //               `V'               \\\\" << endl <<
"             //                 |                 \\\\"  << endl <<
"            //__...--~~~~~~-._  |  _.-~~~~~~--...__\\\\"  << endl <<
"           //__.....----~~~~._\\ | /_.~~~~----.....__\\\\" << endl <<
"           ===================\\\\|//==================" << endl <<
"                              `---`" << endl;
    }

void dialog(string str){
    for(int i(0); i < str.size(); ++i){
        if( str[i] == ' '){
            cout << " ";
            sleep(dialogSpeed);
        }else{
            cout << str[i] << flush;
        }
    }
    cout << endl;
    return;
}

void finalBanner(){
    cout <<"          __.,,------.._" << endl <<
"      ,'\"   _      _   \"`. " << endl <<
"     /.__, ._  -=- _\"`    Y" << endl <<
"    (.____.-.`      \"\"`   j" << endl <<
"     VvvvvvV`.Y,.    _.,-'       ,     ,     ," << endl <<
"        Y    ||,   '\"\\         ,/    ,/    ./" << endl <<
"        |   ,'  ,     `-..,'_,'/___,'/   ,'/   ," << endl <<
"   ..  ,;,,',-'\"\\,'  ,  .     '     ' \"\"' '--,/    .. .." << endl <<
" ,'. `.`---'     `, /  , Y -=-    ,'   ,   ,. .`-..||_|| .." << endl <<
"ff\\`. `._        /f ,'j j , ,' ,   , f ,  \\=\\ Y   || ||`||_..\"" << endl <<
"l` \\` `.`.\"`-..,-' j  /./ /, , / , / /l \\   \\=\\l   || `' || ||..." << endl <<
" `  `   `-._ `-.,-/ ,' /`\"/-/-/-/-\"'''\"`.`.  `'.\\--`'--..`'_`' || ," << endl <<
"            \"`-_,',  ,'  f    ,   /      `._    ``._     ,  `-.`'//         ," << endl <<
"        ,',.,-'\"          \\=) ,`-.         ,    `-'._`.V |       \\ // .. . /j" << endl <<
"        |f\\               `._ )-.\"`.     /|         `.| |        `.`-||-\\/" << endl <<
"        l` \\`                 \"`._   \"`--' j          j' j          `-`---'" << endl <<
"         `  `                     \"`,-  ,'/       ,-'\"  /" << endl <<
"                                 ,'\",__,-'       /,, ,-'" << endl <<
"                                 Vvv'            VVv'" << endl;
dialog("In the silent syntax, Parsa Ghasemi's creation bids adieu.");
}


void dialogSpacer(){
    sleep(1.0);
    cout << endl << "Enter to continue ...";
    cin.ignore();
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
    banner();
    return;
}

void playerStats(){
    dialogSpacer();
    cout << "\t \t -------------------------------" << endl;
    cout << "\t \t| " << player.name << "\t \t \t \t| " << endl;
    cout << "\t \t -------------------------------|" << endl;
    cout << "\t \t| Player HP: " << player.health << "   \t \t" << "|" << endl;
    cout << "\t \t| Player Weapon: " << player.weapon << "\t \t" << "|" << endl;
    cout << "\t \t| Weopon level: " << player.weoponlvl << "  \t \t" << "|" <<  endl;
    cout << "\t \t| Inventory" << "\t \t \t" << "|" <<  endl;
    cout << "\t \t|   Coins: " << player.coins << "\t \t \t" << "|" <<  endl;
    cout << "\t \t|   Potions: " << player.potions << "\t \t \t" << "|" <<  endl;
    cout << "\t \t|   Other: " << player.bag[0] << player.bag[1] << player.bag[2] << "\t \t \t" << "|" <<  endl;
    cout << "\t \t -------------------------------" << endl;
    dialogSpacer();

}

void battleStats(){
    cout << " -----------------------------------------------------------" << endl;
    cout << "| " << player.name << "\t \t \t \t| " << enemy.name << "\t \t    |" << endl;
    cout << " -------------------------------|--------------------------- " << endl;
    cout << "| Player HP: " << player.health << "   \t \t" << "| Enemy HP: " << enemy.health << "\t \t    |" << endl;
    cout << "| Player Weapon: " << player.weapon << " \t" << "| Enemy Weapon: " << enemy.weapon << "\t    |" << endl;
    cout << "| Inventory" << "\t \t \t" << "|" << "\t \t \t    |" <<  endl;
    cout << "|   Coins: " << player.coins << "\t \t \t" << "|" << "\t \t \t    |" <<  endl;
    cout << "|   Potions: " << player.potions << "\t \t \t" << "|" << "\t \t \t    |" <<  endl;
    cout << "|   Other: " << player.bag[0] << player.bag[1] << player.bag[2] << "\t \t \t" << "|" << "\t \t \t    |" <<  endl;
    cout << " -----------------------------------------------------------" << endl;

}


void playerAttack(){
    if (player.weapon == "Broadsword") player.damage = (rand()% 15 + 10)+ player.weoponlvl*2;
    else if(player.weapon == "Longbow") player.damage = (rand()% 20 + 16) + player.weoponlvl*2;
    else if(player.weapon == "Enchanted Staff") player.damage = (rand()% 25 + 21) + player.weoponlvl*2;
    else if(player.weapon == "Boomerang Blade") player.damage = (rand()% 30 + 26) + player.weoponlvl*2;
    if (enemy.trick == 1){
        player.damage = player.damage/2;
        enemy.trick = 0;
    }
    enemy.health -= player.damage;
    dialog("(Damage: " + to_string(player.damage) + " ) \"Take that! Feel the steel!\"");
}

void playerDefend(){
    dialog("(Defended the enemy attack) \"In the name of Eldoria, I wield the power of magic!\"");
    player.defend = true;
}
void playerHeal(){
    dialog("\"A sip of health - exactly what I needed.\"");
    player.potions--;
    player.health = 100;
}
void playerCompanion(){
    player.damage = rand()% 40 + 1;
    if (enemy.trick == 1){
        player.damage = player.damage/2;
        enemy.trick = 0;
    }
    enemy.health -= player.damage;
    if (player.damage >= 20) dialog("(Damage: " + to_string(player.damage) + ") " + "Elyria: \"Right on target! They won't know what hit them.\"");
    else dialog("(Damage: " + to_string(player.damage) + ") " + "Elyria: \"I'll know where to hit him next time!\"");

}

void playerSelect(){
    cout << "(3) (Attack) \"Draw your weapons! It's time to settle this.\"" << endl;
    cout << "(2) (Defend) \"I'll be ready for whatever you throw at me. Come at me!\"" << endl;
    cout << "(1) (Use Item) \"I'll use a healing potion to stay in the fight.\"" << endl;
    if(player.elyria == 1) cout << "(0) (Companion Skill) \"Elyria, lend me your aid! Use your archery skills!\"" << endl;
    int select;
    cin >> select;
    switch (select)
    {
    case 3:
        playerAttack();
        break;
    case 2:
        playerDefend();
        break;
    case 1:
        playerHeal();
        break;
    case 0:
        playerCompanion();
        break;
    default:
        dialog("Wrong input, try again ...");
        dialogSpacer();
        playerSelect();
        break;
    }
}

void enemyAttack(){
    if (enemy.weapon == "Broadsword") enemy.damage = rand()% 15 + 10;
    else if(enemy.weapon == "Longbow") enemy.damage = rand()% 20 + 16;
    else if(enemy.weapon == "Enchanted Staff") enemy.damage = rand()% 25 + 21;
    else if(enemy.weapon == "Boomerang Blade") enemy.damage = rand()% 30 + 26;
    dialog("(Damage: " + to_string(enemy.damage) + ") " + enemy.name + ": \"You're not the first to challenge us. Get ready for some pain!\"");
    player.health -= enemy.damage; 
}
void enemyTrick(){
    enemy.trick = 1;
    dialog("(Next turn attack damage lowered by 50%) " + enemy.name + ": \"Ha! Enjoy that little surprise. It won't get any easier.\"");
}
void enemyAllies(){
    dialog(enemy.name + ": Here comes my army, prepare to get cooked!");
    enemy.damage = rand() % 30;
    player.health -= enemy.damage; 
    dialog("(Damage: " + to_string(enemy.damage) + ") " + enemy.name + "'s army hit you once each.");

}

void enemySelect(){
    if (player.defend == 1){
        player.defend = 0;
        return;
    }
    int select;
    select = rand()% 3 + 0;
    switch (select)
    {
    case 0:
        enemyAttack();
        break;
    case 1:
        enemyTrick();
        break;
    case 2:
        enemyAllies();
        break;
    default:
        dialog(enemy.name + ": \"Aghh hurts, be ready for the next punch!\"");
        break;
    }
}



void welcome(){
    for (int z = 0; z < 50; z++) cout << endl;
    dialog("Welcome!");
    cin.ignore();
    for (int z = 0; z < 50; z++) cout << endl;
    dialog("Before we begin here are some rules and useful keys usable for your adventure.");
    cout << endl;
    dialog("Rules: ");
    dialog("1. **Read All Dialogs:** The narrative holds clues and vital information. Pay attention to the details.");
    dialog("2. **Follow Instructions:** Only input when prompted to avoid unintended consequences.");
    dialog("3. **Immerse Yourself:** Engage with the world and its characters. Your choices shape the journey.");
    dialog("4. **Embrace the Challenge:** Navigate wisely. Your decisions influence the outcome.");
    cout << endl;
    dialog("Important keys:");
    dialog("1. (9 + Enter) At any prompt you can use this key to get players stats like health, coins, potions and etc.");
    cout << endl;
    cout << endl;
    dialog("And once again do not enter anything unless you are asked to...!");
    dialog("May I know your name, brave adventurer?");
    cin >> player.name;

    dialog("One more thing before you start " + player.name + ", Select your text speed:");
    dialog("(2) 1x");
    dialog("(1) 2x");
    dialog("(0) instant");
    cin >> answer;
    switch (answer)
    {
    case 2:
        dialogSpeed = 0.2;
        break;
    case 1:
        dialogSpeed = 0.07;
        break;
    case 0:
        dialogSpeed = 0;
        break;
    default:
        break;
    }
    dialogSpacer();
}


int main(){
    welcome();
    srand (time(NULL));
    player.coins = 100;

//--------------------------------------------introduction--------------------------------------------------
    stageCounter = 0;
    for (int i = 0; i < 50; i++)
    {
        cout << endl;
    }
    dialogSpacer();
    dialog("Welcome to the Chronicles of Eldoria.");
    dialogSpacer();
    
    dialog("In the mystical land of Eldoria, a prophecy foretells of an ancient artifact known as the Heartstone, hidden deep within the treacherous Darkwood Forest. Legends claim that the one who possesses the Heartstone will gain unimaginable power and the ability to reshape the fate of Eldoria. You, a young adventurer seeking glory, have set out on a perilous journey to find the Heartstone and uncover the secrets it holds.");
    dialogSpacer();    



//------------------------------------Chapter 1: The Call to Adventure--------------------------------------------------
    stageCounter = 1;
    dialog("Chapter 1: The Call to Adventure");
    dialog("Sage: \"Greetings, young adventurer. I sense a restless spirit within you. Have you heard of the prophecy of the Heartstone?\"");
    dialog("(1) (Ask about the Heartstone) \"Tell me more about this Heartstone.\"");
    dialog("(0) (Decline) \"I'm not interested.\"");
    cin >> answer;

    dialogSpacer();  

    if (answer == 1){
        dialog("Sage: \"Ah, the Heartstone, a relic of ancient power. It is said to be hidden deep within the Darkwood Forest, guarded by mystical forces. The prophecy foretells that whoever possesses the Heartstone gains unimaginable power and the ability to shape the fate of Eldoria itself.\"");
        dialog("(1) (Express interest) \"That sounds incredible. How can I find it?\"");
        dialog("(0) (Express doubt) \"Prophecies and ancient relics? Sounds like a fairy tale.\"");
        cin >> answer;
        dialogSpacer();
        if (answer == 1){
            dialog("Sage: \"To find the Heartstone, you must journey into the Darkwood Forest. Be wary, for the path is treacherous, and the forest is filled with both danger and opportunity. Seek the guidance of the guardian, solve the riddles that guard the way, and you may unveil the Heartstone's location.\"");
            dialogSpacer();
        }else{
            dialog("Sage: \"Doubt can be a heavy burden, but the Heartstone's power is real, and its existence shapes the destiny of Eldoria. Whether you choose to believe or not, the journey into the Darkwood awaits those who seek it.\"");
            dialog("(1) (Change mind) \"Alright, I'll consider the quest.\"");
            dialog("(0) (Remain skeptical) \"I'll pass on this mythical adventure.\"");
            cin >> answer;
            if (answer == 0) return 0;
            dialogSpacer();
        }
    }else {
        dialog("Sage: \"I understand, not everyone is drawn to the call of ancient prophecies and mystical artifacts. But remember, destiny has a curious way of finding those who least expect it. Should you change your mind, the path to the Heartstone will still be here, waiting for a willing soul.\"");
        dialogSpacer();
    }
    dialog("Sage: \"I'll give you 100 coins for your pathway, You may continue your adventure ...\"");
    player.coins = 100;
    player.health = 100;
    player.weoponlvl = 1;
    dialogSpacer();
//------------------------------------Chapter 1: The Call to Adventure--------------------------------------------------

    dialog("As you wander through the narrow cobblestone streets of Eldoria, the lively sounds of laughter and clinking glasses draw your attention.");
    dialogSpacer();
    dialog("Bartender: \"Ah, a brave soul seeking the Heartstone. Watch out for the Darkwood, lad. It's a treacherous place.\"");
    dialog("(1) (Ask about the Darkwood) \"Tell me more about the Darkwood.\"");
    dialog("(0) (Thank the bartender) \"Thanks for the warning.\"");
    cin >> answer;
    dialogSpacer();

    if (answer == 1){
        dialog("Bartender: \"The Darkwood is no ordinary forest. It's shrouded in mystery and danger. Beware of the enchanted creatures that dwell within, and watch your step. The path is tricky, and many who enter never return.\"");
        dialogSpacer();
    } else{
        dialog("...");
        dialogSpacer();
    }

    dialog("Merchant: \"Looking for supplies, are ya? I've got potions, lanterns, and maps to help you on your journey.\"");
    dialog("(1) (Ask about supplies) \"What do you recommend for the journey?\"");
    dialog("(0) (Decline) \"I'm not interested right now.\"");
    cin >> answer;
    if (answer == 1){
        dialogSpacer();
        dialog("Merchant: \"A wise adventurer always stocks up before heading into the Darkwood. I recommend potions for healing, a lantern to light your way, and a map to navigate the forest's twists and turns.\"");
        dialog("(1) (Purchase supplies, 25 coins) \"I'll take the essentials.\"");
        dialog("(0) (Decline) \"I'll manage without.\"");
        cin >> answer;
        if (answer == 1){
            dialogSpacer();
            dialog("-25 coins...");
            player.coins -= 25;
            player.potions ++;
        }
    }
    dialogSpacer();
    dialog("(1) (Continue exploring) \"I'll explore more of the town.\"");
    dialog("(0) (Head to the Darkwood) \"Time to face the challenge of the Darkwood.\"");
    cin >> answer;
    if (answer == 1){
        dialogSpacer();
        dialog("Mysterious Figure: \"I've heard you're after the Heartstone. Mind some company? I'm skilled with a bow.\"");
        dialog("(1) (Accept) \"Sure, a companion would be helpful.\"");
        dialog("(0) (Decline) \"I prefer to travel alone.\"");
        cin >> answer;
        if (answer == 1){
            player.elyria = 1;
            dialogSpacer();
            dialog("Mysterious Figure: \"Excellent choice! I'm Elyria, and together, we'll navigate the challenges of the Darkwood. Lead the way, and let's make history.\"");
            archer = 1;
        }else if(answer == 0){
            dialogSpacer();
            dialog("Mysterious Figure: \"Fair enough. If you change your mind, you know where to find me. Best of luck on your journey.\"");
            dialog("(1) (Reconsider) \"Actually, having a companion might be a good idea.\"");
            dialog("(0) (Thank and decline again) \"I'll manage on my own.\"");
            cin >> answer;
            if(answer == 1){
                player.elyria = 1;
                dialogSpacer();
                dialog("Mysterious Figure: \"Excellent choice! I'm Elyria, and together, we'll navigate the challenges of the Darkwood. Lead the way, and let's make history.\"");
                archer = 1;
            } else if(answer == 0){
                player.elyria = 0;
                dialogSpacer();
                dialog("Ask the Sage for me whenever you need help");
            }
        }
    }

//-------------------------------------Chapter 2: Into the Darkwood Forest---------------------------------------------

//-------------------------------------------------Scene 1: Thieves' Encounter---------------------------------------------------------- 
    dialogSpacer();
    dialog("Chapter 2: Into the Darkwood Forest");
    dialogSpacer();
    dialog("The outskirts of the Darkwood Forest, a narrow path with looming trees.");
    dialogSpacer();
    dialog("Thug Leader: \"Hold up, stranger! This is our territory. Pay the toll, and we'll let you pass.\"");
    dialog("(2) (Negotiate) \"Let's talk this out.\"");
    dialog("(1) (Pay the Toll) \"Fine, take what you want.\"");
    dialog("(0) (Combat) \"I won't be bullied! Draw your weapons!\"");
    cin >> answer;
    switch (answer)
    {
    case 2: 
        dialogSpacer();
        dialog("Thug Leader: \"Alright, let's hear what you've got to say.\"");
        dialog("(2) (Diplomacy) \"We're all just travelers in this vast world. There's no need for hostility. How about we find a peaceful solution?\"");
        dialog("(1) (Deception) \"Look, I'm just a poor traveler. I have nothing of value. Can't you let me pass without trouble?\"");
        dialog("(0) (Neutral) \"We can both benefit from a peaceful resolution. How about you let me through, and we both avoid unnecessary trouble?\"");
        cin >> answer;
        switch (answer)
        {
        case 2:
            dialogSpacer();
            dialog("Thug Leader's Response: \"Peaceful, eh? What do you propose?\"");
            dialog("(2) (Persuasion Check) \"I have some extra coin. What if I pay you for safe passage?\"");
            dialog("(1) (Intimidation Check) \"You don't want trouble. I can assure you that. Let me pass, and there won't be any.\"");
            dialog("(0) (Charm Check) \"We're all just trying to survive in this world. Help a fellow traveler, and karma might repay you.\"");
            cin >> answer;
            switch (answer)
            {
            case 2:
                dialogSpacer();
                dialog("Thug Leader: \"How much are we talking about?\"");
                dialogSpacer();
                dialog("Enter an amount you are willing to pay the Thug Leader: ");
                cin >> answer;
                dialogSpacer();
                cout << "Thug Leader: \"How much are we talking about?\"";
                dialog("\"Here's " + to_string(answer) + " . Let's call it even, and we'll be on our separate ways.\"");
                dialog("Thug Leader: \"Fine. Take your path and make it quick.\"");
                break;
            case 1:
                dialogSpacer();
                dialog("Thug Leader: \"Fine, we ain't looking for a fight. Move along.\"");
                break;
            case 0:
                dialogSpacer();
                dialog("hug Leader: \"Survival, huh? Well, make it quick. This territory ain't charity.\"");

            default:
                break;
            }

            break;

        case 1:
            dialogSpacer();
            dialog("Thug Leader: \"Poor, huh? Empty your pockets, and we'll see if you're telling the truth.\"");
            dialog("(1) (Deception Check) \"I swear, I'm broke. Just a wanderer trying to find a better place.\"");
            dialog("(0) (Offer a fake item) \"All I got is this trinket. It's not worth much, but maybe you'll find some use for it.\"");
            cin >> answer;
            switch (answer)
            {
            case 1:
                dialogSpacer();
                dialog("Thug Leader: \"Fine, take a look. But if you're lying, you'll regret it.\"");
                break;
            case 0:
                dialogSpacer();
                dialog("Thug Leader: \"Trinket, eh? Let me see that... Fine, you can pass.\"");
                break;
            default:
                break;
            }
            break;

        case 0:
            dialogSpacer();
            dialog("Thug Leader: \"Benefit, you say? What's in it for us?\"");
            dialog("(1) (Offer assistance) \"I might have some skills that could be useful to you later. Let me through, and consider it a favor.\"");
            dialog("(0) (Promise future payment) \"I don't have much now, but I'll owe you a favor. Let me through, and I'll repay you in the future.\"");
            cin >> answer;
            switch (answer)
            {
            case 1:
                dialogSpacer();
                dialog("Thug Leader: \"Skills, huh? Fine, you better keep your word.\"");
                break;
            case 0:
                dialogSpacer();
                dialog("Thug Leader: \"A favor, eh? You better remember that when the time comes.\"");
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }

        break;
    case 1:
        dialogSpacer();
        dialog("Thug Leader: \"Smart choice. Hand it over.\"");
        player.coins -= 50;
        break;
    case 0:
        player.health = 100;
        player.weapon = "Broadsword";
        enemy.name = "Thug Leader";
        enemy.health = 200;
        enemy.weapon = "Longbow";
        dialogSpacer();
        dialog("Thug Leader: \"You thought you could cross our territory without consequences, eh? Prepare to face the consequences!\"");
        dialogSpacer();
        while(player.health > 0 and enemy.health > 0){
            battleStats();
            playerSelect();
            enemySelect();
            dialogSpacer();
        }
        if(player.health <= 0 and enemy.health <= 0) {
            dialog("(Draw fight) Thug Leader: \"Not bad, adventurer. You put up a fight. But remember, this is our turf. Cross us again, and it won't end well for you.\"");
        }
        else if(player.health > 0 and enemy.health <= 0) {
            dialog("(Player Won) Thug Leader: \"You may have won this round, but don't get too comfortable. We're not done here. Eldoria's not as safe as you think. You may take my weapon!\"");
            player.weapon = "Longbow";
            player.coins += 75;
            dialogSpacer();
            dialog("You take Thug Leaders weopon and 75 coins from his pocket as a trophy ...");
        }
        else if(player.health <= 0 and enemy.health > 0) {
            dialog("(Enemy Won) Thug Leader: \"You thought you could challenge us and emerge unscathed? Eldoria's weaklings. This is our territory, and you're not welcome. Begone!\"");
            dialogSpacer();
            dialog("You continue your adventure with 25hp ...");
        }
        break;
    default:
        break;
    }

    //-----------------------------------Scene 2: Navigating the Forest-------------------------------------
    dialog("Deeper into the Darkwood Forest, the atmosphere becomes more ominous.");
    dialogSpacer();
    dialog("With the thieves dealt with, you face the winding paths of the Darkwood. Your tattered map reveals two options: a winding trail or a rocky shortcut.");
    dialog("(1) (Winding Trail) \"I'll take the winding trail.\"");
    dialog("(0) (Rocky Shortcut) \"The rocky shortcut seems faster.\"");
    cin >> answer;
    switch (answer)
    {
    case 1:
        dialogSpacer();
        dialog("You venture onto the winding trail, the air thick with an otherworldly presence. As you proceed, you come across a clearing where a friendly forest spirit materializes.");
        dialogSpacer();
        dialog("Forest Spirit: \"Greetings, seeker of the Heartstone. I am Nysara, guardian of these woods. What brings you to the heart of the Darkwood?\"");
        dialog("(2) (Befriend) \"I seek the Heartstone. Can you offer guidance, Nysara?\"");
        dialog("(1) (Question) \"What dangers lie ahead in the Darkwood?\"");
        dialog("(0) (Decline Interaction) \"I don't have time for this. I'll continue on my own.\"");
        cin >> answer;
        dialogSpacer();
        switch (answer)
        {
        case 2:
            dialog("Nysara: \"Your quest is noble. Take this enchanted talisman and a potion; it will protect you in times of need.\"");
            player.bag[0] = "Enchanted Talisman";
            player.potions ++;
            break;
        case 1:
            dialog("Nysara: \"The path is fraught with enchanted creatures. Treat them with respect, and they may aid you.\"");
            break;
        case 0:
            dialog("Nysara looks disappointed, but the player proceeds without the forest spirit's aid.");
            break;
        case 9:
            playerStats();
            break;
        default:
            break;
        }
        break;
    case 0:
        dialogSpacer();
        dialog("The rocky path is treacherous, but your determination pushes you forward. As you near a hidden cave entrance, you encounter mystical beings guarding the way");
        dialogSpacer();
        dialog("Enchanted Guardian: \"Halt, intruder! The Heartstone's path is protected. State your purpose.\"");
        dialog("(2) (Diplomacy) \"I seek the Heartstone, and I mean no harm. Can we pass peacefully?\"");
        dialog("(1) (Intimidate) \"Stand aside! I won't be stopped by enchanted creatures.\"");
        dialog("(0) (Stealth) \"I'll try to slip by unnoticed.\"");
        cin >> answer;
        dialogSpacer();
        switch (answer)
        {
        case 2:
            dialog("Enchanted Guardian: \"Your intentions seem pure. Proceed, but beware of what lies within.\"");
            break;
        case 1:
            dialog("Enchanted Guardian: \"Your arrogance will be your downfall!\"");
            enemy.name = "Aerion";
            enemy.health = 200;
            enemy.weapon = "Enchanted Staff";
            dialogSpacer();
            while(player.health > 0 and enemy.health > 0){
                battleStats();
                playerSelect();
                enemySelect();
                dialogSpacer();
            }
            if(player.health <= 0 and enemy.health <= 0) {
                dialog("(Draw fight) Enchanted Guardian: \"Not bad, adventurer. You put up a fight. But remember, this is our turf. Cross us again, and it won't end well for you.\"");
            }
            else if(player.health > 0 and enemy.health <= 0) {
                dialog("(Player Won) Enchanted Guardian: \"You may have won this round, but don't get too comfortable. We're not done here. Eldoria's not as safe as you think. You may take my weapon!\"");
                player.weapon = "Enchanted Staff";
                player.coins += 100;
                dialogSpacer();
                dialog("You take Enchanted Guardians weopon and 100 coins from his pocket as a trophy ...");
            }
            else if(player.health <= 0 and enemy.health > 0) {
                dialog("(Enemy Won) Enchanted Guardian: \"You thought you could challenge us and emerge unscathed? Eldoria's weaklings. This is our territory, and you're not welcome. Begone!\"");
                dialogSpacer();
                dialog("After hearing what " + enemy.name+ " said you runaway and continue your adventure with 25hp ...");
            }
//--------------------------------------------------------------------------------------------
            break;
        case 0:
            dialog("(Succeeded slipping in) ...");
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
//------------------------------------Chapter 2.5: The Town of Eldervale--------------------------------------
    dialogSpacer();
    dialog("hapter 2.5: The Town of Eldervale");
    dialogSpacer();
    dialog("As you exit the Darkwood Forest, the town of Eldervale sprawls before you. Its lively streets are filled with merchants, adventurers, and the aroma of freshly baked bread.");

//-------------------------------------Scene 1: Exploring Eldervale--------------------------------------------
    while (1)
    {
        dialogSpacer();
        dialog("(2) (Visit the Potion Shop) \"I should stock up on potions. A visit to the local apothecary is in order.\"");
        dialog("(1) (Check the Weapon Smith) \"Time to upgrade my gear. Let's see what the weapon smith has to offer.\"");
        dialog("(0) (Explore the Marketplace) \"I'll take a stroll through the marketplace. There might be unique items or quests available.\"");
        cin >> answer;
        switch (answer)
        {
        case 2:
            dialogSpacer();
            dialog("Apothecary: \"Greetings, traveler! What potions do you seek? Healing, stamina, or something more exotic?\"");
            while(1){
                dialog("(2) (Buy Healing Potions) \"I'll take a few healing potions.\"");
                dialog("(1) (Buy Stamina Potions) \"Stamina potions, please. I anticipate a challenging journey.\"");
                dialog("(Enter 0 to return)");
                cin >> answer;
                switch (answer)
                {
                case 2:
                    dialogSpacer();
                    if (player.coins < 25)
                    {
                        dialog("(25 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        
                        break;
                    }
                    dialog("Apothecary: \"Wise choice. Here are potions crafted from the rarest herbs. They'll mend your wounds in no time.\"");
                    dialogSpacer();
                    dialog("(-25 coins) Healing Potion added to the bag.");
                    player.potions++;
                    player.coins -= 25;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 1:
                    dialogSpacer();
                    if (player.coins < 25)
                    {
                        dialog("(25 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        break;
                    }
                    dialog("Apothecary: \"Ah, preparing for the long haul. These potions will keep your energy levels up during your adventures.\"");
                    dialogSpacer();
                    dialog("(-25 coins) Stamnia Potion added to the bag.");
                    player.stamnia++;
                    player.coins -= 25;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 9:
                    playerStats();
                    break;
                default:
                    exitLoop = 1;
                    break;
                }
                dialogSpacer();
                if (exitLoop == 1){
                    exitLoop = 0;
                    break;
                }
            }
            break;
        case 1:
            dialog("Weapon Smith: \"Ah, a discerning customer! We have blades, staves, and bows of the finest craftsmanship.\"");
            while(1){
                dialogSpacer();
                dialog("(2) (Upgrade Sword) \"I'm looking to enhance my sword. What do you have?\"");
                dialog("(1) (Upgrade Staves) \"I've been considering a staff for more magical prowess.\"");
                dialog("(Enter 0 to return)");

                cin >> answer;
                switch (answer)
                {
                case 2:
                    dialogSpacer();
                    if (player.coins < 20)
                    {
                        dialog("(20 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        break;
                    }
                    dialog("Weapon Smith: \"A splendid choice! This enchanted blade will cut through your foes with precision. A true work of art.\"");
                    dialogSpacer();
                    dialog("(-20 coins) Current weopon upgraded.");
                    player.weoponlvl++;
                    player.coins -= 20;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 1:
                    dialogSpacer();
                    if (player.coins < 20)
                    {
                        dialog("(20 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        break;
                    }
                    dialog("Weapon Smith: \"A splendid choice! This enchanted Staves will cut through your foes with precision. A true work of art.\"");
                    dialogSpacer();
                    dialog("(-20 coins) Current weopon upgraded.");
                    player.weoponlvl++;
                    player.coins -= 20;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 9:
                    playerStats();
                    break;
                default:
                    exitLoop = 1;
                    break;
                }
                if (exitLoop == 1){
                    exitLoop = 0;
                    break;
                }
            }
            break;
        case 0:
            dialogSpacer();
            dialog("Market Trader: \"Welcome, adventurer! I have rare trinkets and information on local quests. Care to browse?\"");
            dialog("(2) (Buy Trinkets) \"What rare trinkets do you have for sale?\"");
            dialog("(1) (Inquire About Local Quests) \"Any interesting quests available in the region?\"");
            dialog("(0) (Bypass the Trader) \"I'll pass for now. I have my sights set on my primary quest.\"");
            
            cin >> answer;
            switch (answer)
            {
            case 2:
                dialogSpacer();
                if (player.coins < 10)
                {
                    dialog("(10 coins needed) Low coin balance...");
                    dialog("Coin balance: " + to_string(player.coins));
                    break;
                }
                dialog("Market Trader: \"Behold, a collection of mystical trinkets! Each has a tale of its own. Take your pick, adventurer.\"");
                dialogSpacer();
                dialog("(-10 coins) Trinkets added to the bag.");
                player.coins -= 10;
                dialog("Remaining coins: " + to_string(player.coins));
                break;
            case 1:
                dialog("Market Trader: \"Indeed, there's a bounty on creatures in the Darkwood. Bring proof of their demise, and you'll be rewarded handsomely.\"");
                break;
            case 0:
                dialog("Market Trader: \"As you wish, but don't hesitate to return if you seek something extraordinary.\"");
                break;
            case 9:
                playerStats();
                break;
            default:
                break;
            }           
            break;
        case 9:
            playerStats();
            break;
        default:
            exitLoop = 1;
            break;
        }
        if (exitLoop == 1){
            exitLoop = 0;
            break;
        }
    }




//--------------------------------------Chapter 3: The Guardian's Riddle-------------------------
    dialogSpacer();
    dialog("Chapter 3: The Guardian's Riddle");
    dialogSpacer();
    dialog("As you progress deeper into the Darkwood Forest, the atmosphere becomes more mystical. Eventually, you reach the entrance to a hidden chamber where the Guardian awaits.");
    dialogSpacer();
    dialog("Before you stands a magnificent entrance to a chamber, guarded by an ancient figure, the Guardian of the Heartstone. The Guardian's eyes glow with wisdom, and their presence exudes an air of ancient magic.");
    dialogSpacer();
//---------------------------------------Scene 1: Guardian's Challenge-------------------------------
    dialog("Guardian: \"Only those worthy may enter. Answer my riddle, and the path shall open.\"");
    dialogSpacer();
    dialog("Riddle: \"I speak without a mouth and hear without ears. I have no body, but I come alive with the wind. What am I?\"");
    string riddleAnswer;
    int counter = 3;
    while(1){
        cout << "(" << counter << ") "<< "Enter your answer(Type hint for help): ";
        cin >> riddleAnswer;
        if (riddleAnswer == "Echo" or riddleAnswer == "echo"){
            dialog("(Correct answer) Guardian: \"Correct, seeker. The path is open to you.\"");
            break;
        } else if((riddleAnswer == "Hint" or riddleAnswer == "hint") and counter != 0){
            dialog("Guardian: \"In the silent whispers of the forest, my essence is revealed.\"");
        } else if(counter == 0){
            dialog("(1) (Answer: Echo) \"The answer is an echo.\"");
            dialog("(0) (Answer: Wind) \"I believe the answer is the wind.\"");
            cin >> answer;
            if(answer == 1){
                dialog("(Correct answer) Guardian: \"Finally correct, seeker. The path is open to you.\"");
                break;
            }else{
                dialog("Guardian: \"Your attempts have been in vain. A seeker who cannot grasp the essence of the riddle is not yet ready to proceed.\"");
                return 0;
            }
        }
        else{
            dialog("(Wrong answer) Guardian: \"Incorrect. Try again.\"");
        }
        counter--;
        dialogSpacer();
    }


//----------------------------------------------------Scene 2: Prove Your Worth--------------------------------------------
    dialogSpacer();
    dialog("The Guardian's words echo through the chamber. The entrance remains sealed, and the path forward eludes you. Perhaps there is a way to uncover the truth behind the riddle or seek guidance elsewhere.");
    dialogSpacer();
    dialog("As the entrance creaks open, you step into the chamber. The path ahead is filled with illusions challenging your perceptions and testing your courage.");
    dialogSpacer();
    dialogSpacer();
    dialog("Guardian: \"Prove your courage in the face of illusions.\"");
    dialog("(2) (Navigate Illusions) \"I will trust my instincts and navigate through the illusions.\"");
    dialog("(1) (Doubt and Hesitate) \"These illusions are disorienting. I hesitate, unsure of my path.\"");
    dialog("(0) (Invoke Companion's Guidance) \"Elyria, guide me through these illusions with your keen perception.\"");
    cin >> answer;

    switch (answer)
    {
    case 2:
        dialogSpacer();
        dialog("With focused determination, you traverse the illusions, maintaining your course. The illusions attempt to deceive, but your unwavering will guides you through unscathed.");
        break;

    case 1:
        dialogSpacer();
        dialog("Guardian: \"Strength lies in overcoming doubt. Face the illusions with resolve.\"");
        dialogSpacer();
        dialog("As doubt creeps in, the illusions intensify. Shadows dance, and the path becomes obscured. The Guardian's words echo, urging you to find courage within.");
        dialog("(1) (Overcome Doubt) \"I shake off the doubt and push forward.\"");
        dialog("(2) (Remain Hesitant) \"I struggle to overcome the doubt and remain hesitant.\"");
        cin >> answer;

        switch (answer)
        {
        case 1:
            dialogSpacer();
            dialog("Your determination breaks through the illusions. Step by step, you conquer uncertainty and move forward.");
            break;

        case 2:
            dialogSpacer();
            dialog("Guardian: \"The path reveals itself to those who push beyond uncertainty. Seek courage, seeker.\"");
            break;
        case 9:
            playerStats();
            break;
        default:
            break;
        }

        break;

    case 0:
        dialogSpacer();
        dialog("Elyria: \"I'll do my best. Trust my lead, and we'll prevail together.\"");
        dialogSpacer();
        dialog("Elyria steps forward, her keen eyes assessing the illusions. With her guidance, you navigate the illusions with more clarity.");
        dialog("(1) (Follow Elyria's Lead) \"I trust Elyria's lead and follow her through the illusions.\"");
        dialog("(0) (Strike Your Own Path) \"I appreciate Elyria's help, but I choose to strike my own path.\"");
        cin >> answer;

        switch (answer)
        {
        case 1:
            dialogSpacer();
            dialog("With Elyria's guidance, you navigate the illusions seamlessly, forging ahead with confidence.");
            break;

        case 0:
            dialogSpacer();
            dialog("Elyria: \"As you wish. I'll be ready to assist if needed.\"");
            dialogSpacer();
            dialog("You carve your path through the illusions independently, relying on your instincts.");
            break;
        case 9:
            playerStats();
            break;
        default:
            break;
        }

        break;
    case 9:
        playerStats();
        break;
    default:
        break;
    }

//------------------------------------Chapter 3.5: The Town of Eldervale--------------------------------------
    dialogSpacer();
    dialog("Chapter 3.5: Back to The Town of Eldervale");
    dialogSpacer();
//-------------------------------------Scene 1: Exploring Eldervale--------------------------------------------
    while (1)
    {
        dialogSpacer();
        dialog("(2) (Visit the Potion Shop) \"I should stock up on potions. A visit to the local apothecary is in order.\"");
        dialog("(1) (Check the Weapon Smith) \"Time to upgrade my gear. Let's see what the weapon smith has to offer.\"");
        dialog("(0) (Explore the Marketplace) \"I'll take a stroll through the marketplace. There might be unique items or quests available.\"");
        cin >> answer;
        switch (answer)
        {
        case 2:
            dialogSpacer();
            dialog("Apothecary: \"Greetings, traveler! What potions do you seek? Healing, stamina, or something more exotic?\"");
            while(1){
                dialog("(2) (Buy Healing Potions) \"I'll take a few healing potions.\"");
                dialog("(1) (Buy Stamina Potions) \"Stamina potions, please. I anticipate a challenging journey.\"");
                dialog("(Enter 0 to return)");
                cin >> answer;
                switch (answer)
                {
                case 2:
                    dialogSpacer();
                    if (player.coins < 25)
                    {
                        dialog("(25 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        
                        break;
                    }
                    dialog("Apothecary: \"Wise choice. Here are potions crafted from the rarest herbs. They'll mend your wounds in no time.\"");
                    dialogSpacer();
                    dialog("(-25 coins) Healing Potion added to the bag.");
                    player.potions++;
                    player.coins -= 25;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 1:
                    dialogSpacer();
                    if (player.coins < 25)
                    {
                        dialog("(25 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        break;
                    }
                    dialog("Apothecary: \"Ah, preparing for the long haul. These potions will keep your energy levels up during your adventures.\"");
                    dialogSpacer();
                    dialog("(-25 coins) Stamnia Potion added to the bag.");
                    player.stamnia++;
                    player.coins -= 25;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 9:
                    playerStats();
                    break;
                default:
                    exitLoop = 1;
                    break;
                }
                dialogSpacer();
                if (exitLoop == 1){
                    exitLoop = 0;
                    break;
                }
            }
            break;
        case 1:
            dialog("Weapon Smith: \"Ah, a discerning customer! We have blades, staves, and bows of the finest craftsmanship.\"");
            while(1){
                dialogSpacer();
                dialog("(2) (Upgrade Sword) \"I'm looking to enhance my sword. What do you have?\"");
                dialog("(1) (Upgrade Staves) \"I've been considering a staff for more magical prowess.\"");
                dialog("(Enter 0 to return)");

                cin >> answer;
                switch (answer)
                {
                case 2:
                    dialogSpacer();
                    if (player.coins < 20)
                    {
                        dialog("(20 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        break;
                    }
                    dialog("Weapon Smith: \"A splendid choice! This enchanted blade will cut through your foes with precision. A true work of art.\"");
                    dialogSpacer();
                    dialog("(-20 coins) Current weopon upgraded.");
                    player.weoponlvl++;
                    player.coins -= 20;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 1:
                    dialogSpacer();
                    if (player.coins < 20)
                    {
                        dialog("(20 coins needed) Low coin balance...");
                        dialog("Coin balance: " + to_string(player.coins));
                        break;
                    }
                    dialog("Weapon Smith: \"A splendid choice! This enchanted Staves will cut through your foes with precision. A true work of art.\"");
                    dialogSpacer();
                    dialog("(-20 coins) Current weopon upgraded.");
                    player.weoponlvl++;
                    player.coins -= 20;
                    dialog("Remaining coins: " + to_string(player.coins));
                    break;
                case 9:
                    playerStats();
                    break;
                default:
                    exitLoop = 1;
                    break;
                }
                if (exitLoop == 1){
                    exitLoop = 0;
                    break;
                }
            }
            break;
        case 0:
            dialogSpacer();
            dialog("Market Trader: \"Welcome, adventurer! I have rare trinkets and information on local quests. Care to browse?\"");
            dialog("(2) (Buy Trinkets) \"What rare trinkets do you have for sale?\"");
            dialog("(1) (Inquire About Local Quests) \"Any interesting quests available in the region?\"");
            dialog("(0) (Bypass the Trader) \"I'll pass for now. I have my sights set on my primary quest.\"");
            
            cin >> answer;
            switch (answer)
            {
            case 2:
                dialogSpacer();
                if (player.coins < 10)
                {
                    dialog("(10 coins needed) Low coin balance...");
                    dialog("Coin balance: " + to_string(player.coins));
                    break;
                }
                dialog("Market Trader: \"Behold, a collection of mystical trinkets! Each has a tale of its own. Take your pick, adventurer.\"");
                dialogSpacer();
                dialog("(-10 coins) Trinkets added to the bag.");
                player.coins -= 10;
                dialog("Remaining coins: " + to_string(player.coins));
                break;
            case 1:
                dialog("Market Trader: \"Indeed, there's a bounty on creatures in the Darkwood. Bring proof of their demise, and you'll be rewarded handsomely.\"");
                break;
            case 0:
                dialog("Market Trader: \"As you wish, but don't hesitate to return if you seek something extraordinary.\"");
                break;
            case 9:
                playerStats();
                break;
            default:
                break;
            }           
            break;
        
        default:
            exitLoop = 1;
            break;
        }
        if (exitLoop == 1){
            exitLoop = 0;
            break;
        }
    }

//-------------------------------------------------Chapter 4: Unveiling the Heartstone---------------------------------
    dialogSpacer();
    dialog("Chapter 4: Unveiling the Heartstone");
    dialogSpacer();
    dialog("As you navigate the mysterious corridor, it opens up into a cavern aglow with the soft light of the Heartstone. A hooded figure appears, revealing the sorcerer who guards the Heartstone.");
    dialogSpacer();
    dialog("The cavern bathes in the gentle glow of the Heartstone. At its center stands a hooded figure, the guardian appointed to protect the Heartstone.");
//----------------------------------------------Scene 1 -------------------------------------------
    dialogSpacer();
    dialog("Hooded Sorcerer: \"So, a seeker has come. Do you truly believe you are worthy of the Heartstone's power?\"");
    dialog("(2) (Confident) \"I am here to claim the Heartstone and fulfill the prophecy.\"");
    dialog("(1) (Question the Sorcerer) \"Why guard the Heartstone? What is its purpose?\"");
    dialog("(0) (Challenge the Sorcerer) \"Step aside, sorcerer. The Heartstone is mine by right.\"");
    cin >> answer;
    dialogSpacer();
    switch (answer) {
        case 2:
            dialog("Hooded Sorcerer: \"Bold words. To claim the Heartstone, you must prove your strength.\"");
            break;
        case 1: 
            dialog("Hooded Sorcerer: \"The Heartstone is a source of immense power. Its purpose is to shape the destiny of Eldoria. But not all can wield such power.\"");
            break;
        case 0: 
            dialog("Hooded Sorcerer: \"You are not the first to make such a claim. Prepare to face the consequences.\"");
            break;
        default: 
            dialog("Hooded Sorcerer: \"Your indecision speaks volumes. Face the consequences of your hesitation.\"");
            break;
    }

//------------------------------------------------Scene 2: Turn-Based Battle-----------------------------------------
    dialogSpacer();
    dialog("The confrontation escalates into a turn-based battle. The cavern becomes the arena where you must face the sorcerer to claim the Heartstone.");
    dialogSpacer();
    dialog("Sorcerer's Taunt: \"You think you can challenge me for the Heartstone? Foolish mortal!\"");
    dialogSpacer();

    enemy.name = "Sorcerer";
    enemy.health = 200;
    enemy.weapon = "Boomerang Blade";
    while(player.health > 0 and enemy.health > 0){
        battleStats();
        playerSelect();
        enemySelect();
        dialogSpacer();
    }
    if(player.health <= 0 and enemy.health <= 0) {
        dialog("(Draw fight) Sorcerer: \"Not bad, adventurer. You put up a fight. But remember, this is our turf. Cross us again, and it won't end well for you.\"");
    }
    else if(player.health > 0 and enemy.health <= 0) {
        dialog("(Player Won) Sorcerer: \"You may have won this round, but don't get too comfortable. We're not done here. Eldoria's not as safe as you think. You may take my weapon!\"");
        player.weapon = "Enchanted Staff";
        player.coins += 100;
        dialogSpacer();
        dialog("You take Sorcerers weopon and 100 coins from his pocket as a trophy ...");
    }
    else if(player.health <= 0 and enemy.health > 0) {
        dialog("(Enemy Won) Sorcerer: \"You thought you could challenge us and emerge unscathed? Eldoria's weaklings. This is our territory, and you're not welcome. Begone!\"");
        dialogSpacer();
        dialog("You continue your adventure with 25hp ...");
        player.health = 25;
    }
    dialogSpacer();
    dialog("Sorcerer: \"You wield potential, seeker, a potential that could be harnessed for the greater good. Why squander it in a futile attempt to claim the Heartstone on your own?\"");
    dialog("(1) (Accept Sorcerer's Offer) \"What do you offer, sorcerer? Why not join forces?\"");
    dialog("(0) (Reject Sorcerer's Offer) \"I seek the Heartstone for a noble cause. I won't be swayed by your offer.\"");
    cin >> answer;
    switch (answer)
    {
    case 1:
        dialog("Sorcerer: \"Join me, and together, we can harness the Heartstone's power. Eldoria can be remade in our image.\"");
        enemy.sorcerer = 1;
        break;
    case 0:
        dialog("Sorcerer: \"Noble causes are often the downfall of fools. Prepare for your demise.\"");
        enemy.sorcerer = 0;
        break;
    default:
        break;
    }
//-----------------------------------------Chapter 5: The Consequences of Choice--------------------------------------------------------
    dialogSpacer();
    dialog("Chapter 5: The Consequences of Choice");
    dialogSpacer();
    dialog("As the confrontation with the sorcerer concludes, the cavern remains silent. The Heartstone radiates power, whispering promises of glory and temptation.");
    dialogSpacer();
    dialog("With the defeat of the sorcerer, the cavern falls silent. The Heartstone pulsates with an ethereal glow, its power beckoning you.");
    dialogSpacer();

//-------------------------------------------------Scene 1: Holding the Heartstone-----------------------------------------
    dialog("Approaching the Heartstone, you feel its energy resonating with the core of your being. The whispers of the Heartstone echo in your mind.");
    dialogSpacer();
    dialog("Heartstone's Voice: \"Seeker, the power to shape Eldoria rests in your hands. Embrace the potential within, and mold the world to your desires.\"");
    dialog("(1) (Embrace the Power) \"I accept the Heartstone's offer. Eldoria will be shaped by my will.\"");
    dialog("(0) (Resist Temptation) \"I resist the allure of the Heartstone. My goal is to protect Eldoria, not dominate it.\"");
    cin >> answer;
    dialogSpacer();
    switch (answer)
    {
    case 1:
        dialog("As you embrace the power, a surge of energy courses through you. The Heartstone becomes an extension of your will.");
        break;
    case 0:
        dialog("You resist the enchanting whispers, acknowledging the responsibility that comes with such power.");
        break;
    default:
        break;
    }

//-------------------------------------------Scene 2: Moral Decision-----------------------------------------------------
    dialogSpacer();

    dialog("As the player holds the Heartstone, a moment of reflection ensues. The cavern's glow intensifies, responding to the player's decision.");
    dialogSpacer();
    dialog("Heartstone's Voice: \"Your choices echo through the ages. Will you be a savior or succumb to the darkness within?\"");
    dialogSpacer();
    dialog("(2) (Shape Eldoria Positively) \"I will use the Heartstone to bring prosperity to Eldoria, ensuring a bright future for its inhabitants.\"");
    dialog("(1) (Shape Eldoria with Ambition) \"I seek power to elevate Eldoria to unprecedented heights. It's time for the world to witness true greatness.\"");
    dialog("(0) (Succumb to Darkness) \"I embrace the darkness within. Eldoria will bow to my will, and I shall be its ruler.\"");
    cin >> answer;
    dialogSpacer();
    switch (answer)
    {
    case 2:
        dialog("The Heartstone resonates with your intentions, its glow radiating a sense of hope.");
        break;
    case 1:
        dialog("The Heartstone responds to your ambition, its glow taking on a more intense and commanding aura.");
        break;
    case 0:
        dialog("The Heartstone darkens, absorbing the shadows of your intent. The air thickens with an ominous energy.");
        break;
    default:
        break;
    }

//----------------------------------------------Scene 3: Scene 3: Outcome---------------------------------------------------
    dialogSpacer();
    dialog("As you hold the Heartstone, your choices reverberate through Eldoria. The world awaits the consequences of your decisions.");
    dialogSpacer();
    dialog("The tale of your journey concludes, yet Eldoria's fate is forever altered. Your choices leave a legacy that defines the destiny of this realm.");
    dialogSpacer();
    answer = rand()% 3;
    switch (answer)
    {
    case 2:
        dialog("Eldoria thrives under your benevolent rule, and your name is remembered as a savior.");
        break;
    case 1:
        dialog("Eldoria falls into chaos, consumed by your thirst for power, and your name becomes a whisper of dread.");
        break;
    case 0:
        dialog("Eldoria rises to new heights, but at the cost of individual freedoms, and your legacy is one of mixed opinions.");
        break;
    default:
        break;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
    for (int i = 0; i < 50; i++) cout << endl << endl << endl;
    finalBanner();
    dialog("The End ...");
    return 0;
    

}