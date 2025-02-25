#include "MageEnchants.h"

#include "Mage.h"
#include "Utils/Check.h"

MageEnchants::MageEnchants(Mage* mage) :
    CharacterEnchants(mage)
{}

QVector<EnchantName::Name> MageEnchants::get_available_enchants(const int equipment_slot) const {
    switch (equipment_slot) {
    case EquipmentSlot::MAINHAND: {
        QVector<EnchantName::Name> enchants {EnchantName::Name::EnchantWeaponSpellPower};

        if (has_2hand()) {
            enchants.append({});
        }
        else
            enchants.append({});

        return enchants;
    }
    case EquipmentSlot::OFFHAND:
    case EquipmentSlot::RANGED:
        return {};
    case EquipmentSlot::HEAD:
    case EquipmentSlot::LEGS:
        return {
            EnchantName::Name::ArcanumOfFocus,
            EnchantName::Name::PresenceOfSight,
        };
    case EquipmentSlot::SHOULDERS:
        return {
            EnchantName::Name::ZandalarSignetOfMojo,
        };
    case EquipmentSlot::BACK:
        return {};
    case EquipmentSlot::WRIST:
        return {
            EnchantName::Name::EnchantBracerManaRegeneration,
        };
    case EquipmentSlot::GLOVES:
        return {
            EnchantName::Name::EnchantGlovesFirePower,
            EnchantName::Name::EnchantGlovesFrostPower,
        };
    case EquipmentSlot::CHEST:
        return {
            EnchantName::Name::EnchantChestGreaterStats
        };
    case EquipmentSlot::BOOTS:
        return {
            EnchantName::Name::EnchantBootsMinorSpeed,
            EnchantName::Name::EnchantBootsSpirit,
        };
    }

    check(false, "MageEnchants::get_available_enchants reached end of switch");
    return {};
}

QVector<EnchantName::Name> MageEnchants::get_available_temp_enchants(const int equipment_slot) const {
    switch (equipment_slot) {
    case EquipmentSlot::MAINHAND: {
        QVector<EnchantName::Name> enchants {
            EnchantName::BrilliantWizardOil,
            EnchantName::ShadowOil,
        };
        return enchants;
    }
    case EquipmentSlot::OFFHAND:
        return {};
    }

    check(false, "MageEnchants::get_available_temp_enchants reached end of switch");
    return {};
}
