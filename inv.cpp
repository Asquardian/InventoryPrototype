#include <iostream>
#include <vector>

class Player{
    public:
        int hp;
        Player(){
            hp = 100;
        };
        void stat(){
            std::cout << hp << std::endl;
        }
        void UseHP(int plusHP){
            hp += plusHP;
        }
};

class Item{
    public:
        virtual void ItemEffect(Player &p){
            std::cout << "fuckme";
        }
};

class Heal : public Item {
    private:
        int heal;
    public:
        Heal(): heal(10){

        }
        void ItemEffect(Player &p){
            std::cout<<"use\n";
            p.UseHP(heal);
        }
};

class UnHeal : public Item{    private:
        int heal;
    public:
        UnHeal(): heal(10){

        }
        void ItemEffect(Player &p){
            std::cout<<"use Unheal\n";
            p.UseHP(-heal);
        }
};

class Inventory{
    private:
        int numberOfItem;
    public:
        std::vector<Item*> Invent;
        void AddItem(Item &item){
            Invent.push_back(&item);
            numberOfItem++;
        }
        Inventory(){
            numberOfItem = 0;
        }
        ~Inventory(){
            Invent.clear();
        }
        void UseItemByID(int id, Player &p){
            Invent[id]->ItemEffect(p);
        }

};

int main(){
    Player p;
    Inventory i;
    Heal hp;
    UnHeal uhp;
    i.AddItem(hp);
    i.UseItemByID(0, p);
    p.stat();
    i.AddItem(uhp);
    i.UseItemByID(1, p);
    p.stat();
    return 0;
}