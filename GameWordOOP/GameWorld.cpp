#include<iostream>
#include<string>
#include<vector>
#include"GameWorld.hpp"
using namespace std;

GameWorld::GameWorld()
{

}
GameWorld& GameWorld::getInstance()
{
    static GameWorld newWorld;
    return newWorld;
}

void GameWorld::AddEntity(Player*newPlayer)
{
    this->dsPlayer.push_back(newPlayer);
}

void GameWorld::Clear()
{
    for(int i=0;i<this->dsPlayer.size();i++)
    {
        delete this->dsPlayer[i];
    }
    this->dsPlayer.clear();
}

void GameWorld::NextTime()
{
    for(int i=0;i<this->dsPlayer.size();i++)
    {
        this->dsPlayer[i]->TimePass();
    }
}

void GameWorld::Print()
{
     for(int i=0;i<this->dsPlayer.size();i++)
    {
        this->dsPlayer[i]->Xuat(0);
    }
}

Strategy::Strategy()
{
    this->power=0;
}
Strategy::Strategy(float power)
{
    this->power=power;
}
string Strategy::GetType()
{
    return "Normal";
}
void Strategy::Xuat()
{
    cout<<"";
}
float Strategy::getPower()
{
    return this->power;
}
MagicAttack::MagicAttack()
{
    this->power=0;
}
void MagicAttack::Xuat()
{
    cout<<"Xuc manh phep thuat\n";
}
string MagicAttack::GetType()
{
    return"Magic";
}
PhysicalAttack::PhysicalAttack()
{
    this->power=0;
}
void PhysicalAttack::Xuat()
{
    cout<<"Xuc manh vat ly\n";
}
string PhysicalAttack::GetType()
{
    return"Physic";
}
CriticalAttack::CriticalAttack()
{
    this->power=0;
}
void CriticalAttack::Xuat()
{
    cout<<"Xuc manh soc sat thuong\n";
}
string CriticalAttack::GetType()
{
    return"Critical";
}

void Player::Add(Player*newp)
{
    return;
}
Player::Player()
{
    this->name=name;
}
Player::Player(string name)
{
    this->name=name;
}
float Player::GetHP()
{
    return 0;
}
float Player::GetATK()
{
return 0;
}
float Player::GetDEF()
{
return 0;
}
void Player::ReciveDamage(float damage)
{
    return;
}
void Player::Attack(Player*orther)
{

    return;
}

void Player::Xuat(int depht)
{
    for(int i=0;i<depht;i++)
    {
        cout<<"  ";
    }
}
void Player::Print()
{
    this->Xuat(0);
}
void Player::TimePass()
{
    return;
}
void Player::SetATK(float orther)
{
    return;
}
void Player::SetDEF(float orther)
{
    return;
}
void Player::SetHP(float orther)
{
    return;
}
bool Player::isLoss()
{
    return 1;
}
Character::Character()
{
    this->name="";
    this->ATK=0;
    this->HP=0;
    this->DEF=0;
    this->type=nullptr;
}
Character::Character(string name,float hp,float atk,float def)
{
    this->name=name;
    this->HP=hp;
    this->ATK=atk;
    this->DEF=def;
    this->type=nullptr;
}
void Character::SetHP(float orther)
{
    this->HP+=orther;
}
void Character::SetATK(float orther)
{
    this->ATK+=orther;
}
void Character::SetDEF(float orther)
{
        this->DEF+=orther;
}
void Character::SetAttackStrategy(Strategy* moi)
{
    this->type=moi;
}
void Character::ReciveDamage(float damage)
{
    float dam=damage-this->DEF;
    if(dam>0)
    {
        this->HP-=dam;
    }
}
void Character::Attack(Player*orther)
{
    if(this->isLoss()==0)
    {
        orther->ReciveDamage(this->GetATK());
    }
    else
    {
        cout<<"Player has name "<<this->name<<" lossed and cound not attack\n";
    }
}
bool Character::isLoss()
{
    if(this->GetHP()<=0)
    {
        return 1;
    }
    return 0;
}
void Character::Xuat(int depth)
{
    string t="Normal";
    if(type)
    {
        t=this->type->GetType();
    }
    Player::Xuat(depth);
    cout<<"Name: "<<this->name<<" Thuoc tinh: "<<t<<endl;
    Player::Xuat(depth);
    cout<<"ATK: "<<this->ATK<<", DEF: "<<this->DEF<<" , HP: "<<this->HP<<endl;
}
void Character::Print()
{
    this->Xuat(0);
}
void Character::TimePass()
{
    return;
}
float Character::GetATK()
{
    return this->ATK;
}
float Character::GetHP()
{
    return this->HP;
}
float Character::GetDEF()
{
    return this->DEF;
}

Decorator::Decorator()
{
    this->countdown=0;
}
Decorator::Decorator(Character*newPlayer)
{
    this->player=newPlayer;
    this->countdown=0;
}
void Decorator::Buff()
{
    return;
}
void Decorator::DeBuff()
{
    return;
}
void Decorator::Xuat(int depth)
{
    Character::Xuat(depth);
    Player::Xuat(depth);

}
void Decorator::Print()
{
    this->Xuat(0);
}
void Decorator::TimePass()
{
    return;
}

Ring::Ring()
{
    
}

Ring::Ring(Character*player)
{
 this->player=player;
}
void Ring::Buff()
{
    if(countdown%2!=0)
    this->player->SetATK(20);
}
void Ring::DeBuff()
{
    if(countdown%2==0)
    {
        this->SetATK(-20);
    }
}
void Ring::Xuat(int depth)
{
    this->player->Xuat(depth);
    Player::Xuat(depth);
    cout<<"Have a Ring\n";
}
void Ring::Print()
{
    this->Xuat(0);
}
void Ring:: TimePass()
{this->Buff();
    this->DeBuff();
    this->countdown+=1;
    
}
float Decorator::GetATK()
{
    return this->player->GetATK();
}
float Decorator::GetDEF()
{
    return this->player->GetDEF();
}
float Decorator::GetHP()
{
    return this->player->GetHP();
}
void Decorator::SetATK(float orther)
{
    this->player->SetATK(orther);
}

void Decorator::SetDEF(float orther)
{
    this->player->SetDEF(orther);
}

void Decorator::SetHP(float orther)
{
    this->player->SetHP(orther);
}
Sword::Sword()
{

}
Sword::Sword(Character*player)
{
    this->player=player;
}
void Sword:: Buff()
{
    if(countdown%2==0)
    {
    this->player->SetATK(+50);
    this->player->SetDEF(-20);
    }
}
void Sword::DeBuff()
{
    if(countdown%2!=0)
    {
    this->player->SetATK(-50);
    this->player->SetDEF(+20);
    }

}
void Sword::Xuat(int depth)
{
    this->player->Xuat(depth);
    Player::Xuat(depth);
    cout<<"Have a Sword\n";
}
void Sword::Print()
{
 this->Xuat(0);
}
void Sword::TimePass()
{DeBuff();
    Buff();
    this->countdown++;
    
}

Poisoned::Poisoned()
{

}
Poisoned::Poisoned(Character*player)
{
    this->player=player;
}
void Poisoned::Buff()
{
    this->player->SetHP(-5);
}
void Poisoned::DeBuff()
{
    if(this->countdown>=5)
    {
        this->player->SetHP(+5);
    }
}
void Poisoned::Xuat(int depth)
{
     this->player->Xuat(depth);
   Player::Xuat(depth);
    cout<<"Be poisioned\n";
}
void Poisoned::Print()
{
 this->Xuat(0);
}
void Poisoned::TimePass()
{
    this->Buff();
    this->DeBuff();
    this->countdown++;
}


Party::Party()
{

}
Party::Party(string name)
{
    this->name=name;
}
void Party::Add(Player*moi)
{
    this->dsCon.push_back(moi);
}
float Party::GetHP()
{
 float total=0;
 for(int i=0;i<this->dsCon.size();i++)
 {
    total+=this->dsCon[i]->GetHP();
 }
 return total;
}
float Party::GetATK()
{
float total=0;
 for(int i=0;i<this->dsCon.size();i++)
 {
    total+=this->dsCon[i]->GetATK();
 }
 return total;
}
float Party::GetDEF()
{
float total=0;
 for(int i=0;i<this->dsCon.size();i++)
 {
    total+=this->dsCon[i]->GetDEF();
 }
 return total;
}
void Party::ReciveDamage(float damage)
{
    float d=(damage-this->GetDEF())/this->dsCon.size();
    for(int i=0;i<this->dsCon.size();i++)
    {
        this->dsCon[i]->ReciveDamage(d);
    }
}
void Party::Attack(Player*orther)
{
    if(this->isLoss()==false){
    orther->ReciveDamage(this->GetATK());

    }
    else{
       cout<<"Party has name "<<this->name<<" lossed and cound not attack\n";
    }
}

void Party::Xuat(int depth)
{
    Player::Xuat(depth);
    cout<<"Party "<<this->name<<endl;
    for(int i=0;i<this->dsCon.size();i++)
    {
        this->dsCon[i]->Xuat(depth+1);
    }
}

void Party::Print()
{
    this->Xuat(0);
}
void Party::TimePass()
{
       for(int i=0;i<this->dsCon.size();i++)
    {
        this->dsCon[i]->TimePass();
    }
}
bool Party::isLoss()
{
    if(this->GetHP()<=0)
    {
        return 1;
    }
    return 0;
}