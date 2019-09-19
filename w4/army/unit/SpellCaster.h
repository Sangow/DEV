#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include <cstring>
#include "../unit/Unit.h"
#include "../state/MagicState.h"

class SpellCaster : public Unit {
    protected:
        MagicState* mState;

        bool unitIsMage() const;
    public:
        SpellCaster(const std::string& charName, const std::string& charClass);
        virtual ~SpellCaster();

        virtual double getMana() const override;
        virtual double getManaLimit() const override;
        double getIntellect() const;
        double getFaith() const;
        const std::string& getCurrentSpell() const;
        MagicState& getMagicState() const;

        virtual void changeState(State* newState, const std::string& newCharClass) override;
        void cleanMState();

        void changeSpell(const std::string& spellName);

        virtual void cast(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellcaster);

#endif // SPELLCASTER_H