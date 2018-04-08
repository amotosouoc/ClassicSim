#ifndef OFFHANDATTACK_H
#define OFFHANDATTACK_H

#include "Spell.h"

class Warrior;

class OffhandAttack: public Spell {
public:
    OffhandAttack(Engine* engine, Character* pchar, CombatRoll* roll);

    float get_next_expected_use() const;
    void update_next_expected_use(const float);
    bool attack_is_valid(const int) const;
    int get_next_iteration();
    void reset_effect() override;

protected:
private:
    int spell_effect(const int) override;
    Warrior* pchar;
    float next_expected_use;
    int iteration;
    QVector<float> talent_ranks;
};

#endif // OFFHANDATTACK_H
