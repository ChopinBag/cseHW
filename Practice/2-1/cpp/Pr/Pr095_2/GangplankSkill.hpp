#ifndef GANGPLANKSKILL_HPP
#define GANGPLANKSKILL_HPP
#include "Skill.hpp"
#include "Champion.hpp"
#include <iostream>

using namespace std;

class GangplankSkill : public Skill {
    public:
        GangplankSkill() = default;
        
        void q() override{
            cout << "TRIAL BY FIRE" << endl;
        };
        void w() override{
            cout << "PARRRLEY" << endl;
        };
        void e() override{
            cout << "REMOVE SCURVY" << endl;
        };
        void r() override{
            cout << "POWDER KEG" << endl;
        };
};

#endif