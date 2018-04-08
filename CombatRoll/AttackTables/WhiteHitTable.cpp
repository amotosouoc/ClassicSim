
#include "WhiteHitTable.h"
#include <QDebug>

WhiteHitTable::WhiteHitTable(const float miss, const float dodge, const float parry,
                             const float glancing, const float block,  const float critical)
{
    assert(miss >= 0);
    assert(dodge >= 0);
    assert(parry >= 0);
    assert(glancing >= 0);
    assert(block >= 0);
    assert(critical >= 0);

    this->miss_range = int(round(miss * 10000));
    this->dodge_range = int(round(dodge * 10000)) + miss_range;
    this->parry_range = int(round(parry * 10000)) + dodge_range;
    this->glancing_range = int(round(glancing * 10000)) + parry_range;
    this->block_range = int(round(block * 10000)) + glancing_range;
    this->critical_range = int(round(critical * 10000)) + block_range;
}

int WhiteHitTable::get_outcome(const int roll, const float crit_mod) {
    assert(roll >= 0 && roll < 10000);

    if (roll < this->miss_range)
        return Outcome::MISS;
    if (roll < this->dodge_range)
        return Outcome::DODGE;
    if (roll < this->parry_range)
        return Outcome::PARRY;
    if (roll < this->glancing_range)
        return Outcome::GLANCING;
    if (roll < this->block_range)
        return Outcome::BLOCK;
    if (roll < this->critical_range + int(round(crit_mod * 10000)))
        return Outcome::CRITICAL;
    return Outcome::HIT;
}

void WhiteHitTable::dump_table(void) {
    qDebug() << "------------";
    qDebug() << "MISS RANGE " << miss_range;
    qDebug() << "DODGE RANGE " << dodge_range;
    qDebug() << "PARRY RANGE " << parry_range;
    qDebug() << "GLANCING RANGE " << glancing_range;
    qDebug() << "BLOCK RANGE " << block_range;
    qDebug() << "CRITICAL RANGE " << critical_range;
}

void WhiteHitTable::update_crit_chance(const float critical) {
    this->critical_range = int(round(critical * 10000)) + block_range;;
}
