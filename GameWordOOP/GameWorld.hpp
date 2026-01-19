#pragma once

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Player;


class Strategy
{
    protected:
    float power;
    public:
    Strategy();
    Strategy(float power);
    virtual string GetType();
    virtual void Xuat();
    float getPower();
};

class MagicAttack:public Strategy
{
    public:
    MagicAttack();
    void Xuat();
    string GetType();
};
class CriticalAttack:public Strategy
{
    public:
    CriticalAttack();
    void Xuat();
    string GetType();
};

class PhysicalAttack:public Strategy
{
    public:
    PhysicalAttack();
    void Xuat();
    string GetType();
};

class Player
{
    protected:
    string name;
    public:
    Player();
    Player(string name);
    virtual bool isLoss();
    virtual void Add(Player*newp);
    virtual float GetHP();
    virtual float GetATK();
    virtual float GetDEF();
    virtual void SetHP(float orther);
    virtual void SetATK(float orther);
    virtual void SetDEF(float orther);
    virtual void ReciveDamage(float damage);
    virtual void Attack(Player*orther);
    virtual void Xuat(int depht);
    virtual void Print();
    virtual void TimePass();
};

class Character:public Player
{
    private:
    float HP;
    float ATK;
    float DEF;
    Strategy* type;
    public:
    Character();
    Character(string name,float hp,float atk,float def);
    bool isLoss();
    void SetHP(float orther);
    void SetATK(float orther);
    void SetDEF(float orther);
    float GetHP();
    float GetATK();
    float GetDEF();
    void SetAttackStrategy(Strategy* moi);
    void ReciveDamage(float damage);
    void Attack(Player*orther);
    virtual void Xuat(int depth);
    virtual void Print();
    virtual void TimePass();
};
class Decorator:public Character
{
    protected:
    Character* player;
    int countdown;
    public:
    Decorator();
    Decorator(Character*newPlayer);
    void SetHP(float orther);
    void SetATK(float orther);
    void SetDEF(float orther);
    float GetHP();
    float GetATK();
    float GetDEF();
    virtual void Buff();
    virtual void DeBuff();
    virtual void Xuat(int depth);
    virtual void Print();
    virtual void TimePass();
};

class Ring:public Decorator
{
    public:
    Ring();
    Ring(Character*player);
   
    void Buff();
    void DeBuff();
    void Xuat(int depth);
    void Print();
    void TimePass();
}; 

class Sword:public Decorator
{
    public:
    Sword();
    Sword(Character*player);
   
    void Buff();
    void DeBuff();
    void Xuat(int depth);
    void Print();
     void TimePass();
};

class Poisoned:public Decorator
{
    public:
    Poisoned();
    Poisoned(Character*player);
    void Buff();
    void DeBuff();
    void Xuat(int depth);
    void Print();
    void TimePass();
};
class Party:public Player
{
    private:
    vector<Player*>dsCon;
    public:
    Party();
    Party(string name);
    bool isLoss();
    void Add(Player*moi);
    float GetHP();
    float GetATK();
    float GetDEF();
    void ReciveDamage(float damage);
    void Attack(Player*orther);
    void Xuat(int depth);
    void Print();
    void TimePass();
};
class GameWorld
{
    private:
    vector<Player*>dsPlayer;
    GameWorld();
    public:
    static GameWorld& getInstance();
    void AddEntity(Player*newPlayer);
    void Print();
    void Clear();
    void NextTime();
};