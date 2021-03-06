#include "Cards.h"

#include <random>

static const MinionAura Aura_PlusTwoAttack = { MinionAuraEffect::BonusAttack, 2, AuraDuration::EndOfTurn };

static const Battlecry Battlecry_AbusiveSergeant = { Aura_PlusTwoAttack, TargetType::AnyMinion };
static const Battlecry Battlecry_ElvenArcher = { SpellEffect::DamageCharacter, 1, TargetType::AnyCharacter };
static const Battlecry Battlecry_VoodooDoctor = { SpellEffect::HealCharacter, 2, TargetType::AnyCharacter };
static const Battlecry Battlecry_NoviceEngineer = { SpellEffect::DrawCard, 1, TargetType::SelfPlayer };
static const Battlecry Battlecry_ArcaneGolem = { SpellEffect::AddManaCrystal, 1, TargetType::Opponent };
static const Battlecry Battlecry_EarthenRingFarseer = { SpellEffect::HealCharacter, 3, TargetType::AnyCharacter };
static const Battlecry Battlecry_IronforgeRifleman = Battlecry_ElvenArcher;
static const Battlecry Battlecry_DarkIronDwarf = Battlecry_AbusiveSergeant;
static const Battlecry Battlecry_AzureDrake = Battlecry_NoviceEngineer;
static const Battlecry Battlecry_DarkscaleHealer = { SpellEffect::HealCharacter, 2, TargetType::AllFriendlyCharacters };
static const Battlecry Battlecry_StormpikeCommando = { SpellEffect::DamageCharacter, 2, TargetType::AnyCharacter };
static const Battlecry Battlecry_Nightblade = { SpellEffect::DamageCharacter, 3, TargetType::Opponent };
static const Battlecry Battlecry_PriestessOfElune = { SpellEffect::HealCharacter, 4, TargetType::SelfPlayer };
static const Battlecry Battlecry_Alextrasza = { SpellEffect::SetHealth, 15, TargetType::AnyPlayer };

static const Deathrattle Deathrattle_LeperGnome = { SpellEffect::DamageCharacter, 2, TargetType::Opponent };
static const Deathrattle Deathrattle_ZombieChow = { SpellEffect::HealCharacter, 5, TargetType::Opponent };
static const Deathrattle Deathrattle_BloodmageThalnos = { SpellEffect::DrawCard, 1, TargetType::SelfPlayer };
static const Deathrattle Deathrattle_LootHoarder = { SpellEffect::DrawCard, 1, TargetType::SelfPlayer };
static const Deathrattle Deathrattle_UnstableGhoul = { SpellEffect::DamageCharacter, 1, TargetType::AllMinions };
static const Deathrattle Deathrattle_DancingSwords = { SpellEffect::DrawCard, 1, TargetType::Opponent };
static const Deathrattle Deathrattle_Abomination = { SpellEffect::DamageCharacter, 2, TargetType::AllCharacters };

const CardData AllCards[] = {
	{ CardType::Spell, 0, "The Coin", SpellEffect::AddMana, 1, TargetType::SelfPlayer },

	// 0-mana neutral cards
	{ 0, "Wisp",					1, 1, CardFlags::CanBeInDecks }, // Wisp

	// 1-mana neutral cards
	{ 1, "Abusive Sergeant",		2, 1, Battlecry_AbusiveSergeant, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 1, "Angry Chicken",			1, 1, CardFlags::None, MinionRace::Beast },
	{ 1, "Argent Squire",			1, 1, MinionAbilityFlags::DivineShield, CardFlags::CanBeInDecks },
	{ 1, "Bloodsail Corsair",		1, 2, CardFlags::None, MinionRace::Pirate},
	{ 1, "Elven Archer",			1, 1, Battlecry_ElvenArcher, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 1, "Goldshire Footman",		1, 2, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 1, "Grimscale Oracle",		1, 1, CardFlags::None, MinionRace::Murloc },
	{ 1, "Hungry Crab",				1, 2, CardFlags::None, MinionRace::Beast },
	{ 1, "Leper Gnome",				2, 1, Deathrattle_LeperGnome, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 1, "Lightwarden",				1, 2 },
	{ 1, "Murloc Raider",			2, 1, CardFlags::CanBeInDecks, MinionRace::Murloc },
	{ 1, "Murloc Tidecaller",		1, 2, CardFlags::None, MinionRace::Murloc },
	{ 1, "Secretkeeper",			1, 2 },
	{ 1, "Shieldbearer",			0, 4, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 1, "Southsea Deckhand",		2, 1, CardFlags::None, MinionRace::Murloc },
	{ 1, "Stonetusk Boar",			1, 1, MinionAbilityFlags::Charge, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 1, "Undertaker",				1, 2 },
	{ 1, "Voodoo Doctor",			2, 1, Battlecry_VoodooDoctor, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 1, "Worgen Infiltrator",		2, 1, MinionAbilityFlags::Stealth, CardFlags::CanBeInDecks },
	{ 1, "Young Dragonhawk",		1, 1, MinionAbilityFlags::Windfury, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 1, "Young Priestess",			2, 1 },
	{ 1, "Zombie Chow",				2, 3, Deathrattle_ZombieChow, MinionAbilityFlags::None, CardFlags::CanBeInDecks },

	// 2-mana neutral cards
	{ 2, "Acidic Swamp Ooze",		3, 2 },
	{ 2, "Amani Berserker",			2, 3 },
	{ 2, "Ancient Watcher",			4, 5, MinionAbilityFlags::CannotAttack, CardFlags::CanBeInDecks },
	{ 2, "Bloodfen Raptor",			3, 2, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 2, "Bloodmage Thalnos",		1, 1, Deathrattle_BloodmageThalnos, MinionAbilityFlags::None, CardFlags::CanBeInDecks, MinionRace::None, 1 },
	{ 2, "Bloodsail Raider",		2, 3, CardFlags::None, MinionRace::Pirate },
	{ 2, "Bluegill Warrior",		2, 1, MinionAbilityFlags::Charge, CardFlags::CanBeInDecks, MinionRace::Murloc },
	{ 2, "Captains Parrot",			1, 2, CardFlags::None, MinionRace::Beast },
	{ 2, "Crazed Alchemist",		2, 2 },
	{ 2, "Dire Wolf Alpha",			2, 2, CardFlags::None, MinionRace::Beast },
	{ 2, "Doomsayer",				0, 7 },
	{ 2, "Echoing Ooze",			1, 2 },
	{ 2, "Faerie Dragon",			3, 2, MinionAbilityFlags::CannotBeTargeted, CardFlags::None, MinionRace::Dragon },
	{ 2, "Frostwolf Grunt",			2, 2, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 2, "Haunted Creeper",			1, 2, CardFlags::None, MinionRace::Beast },
	{ 2, "Ironbeak Owl",			2, 1, CardFlags::None, MinionRace::Beast },
	{ 2, "Knife Juggler",			3, 2 },
	{ 2, "Kobold Geomancer",		2, 2, CardFlags::CanBeInDecks, MinionRace::None, 1 },
	{ 2, "Loot Hoarder",			2, 1, Deathrattle_LootHoarder, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 2, "Lorewalker Cho",			0, 4 },
	{ 2, "Mad Bomber",				3, 2 },
	{ 2, "Mad Scientist",			2, 2 },
	{ 2, "Mana Addict",				1, 3 },
	{ 2, "Mana Wraith",				2, 2 },
	{ 2, "Master Swordsmith",		1, 3 },
	{ 2, "Millhouse Manastorm",		4, 4 },
	{ 2, "Murloc Tidehunter",		2, 1, CardFlags::None, MinionRace::Beast },
	{ 2, "Nat Pagle",				0, 4 },
	{ 2, "Nerubar Weblord",			1, 4 },
	{ 2, "Nerubian Egg",			0, 2 },
	{ 2, "Novice Engineer",			1, 1, Battlecry_NoviceEngineer, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 2, "Pint-Sized Summoner",		2, 2 },
	{ 2, "River Crocolisk",			2, 3, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 2, "Sunfury Protector",		2, 3 },
	{ 2, "Unstable Ghoul",			1, 3, Deathrattle_UnstableGhoul, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 2, "Wild Pyromancer",			3, 2 },
	{ 2, "Youthful Brewmaster",		3, 2 },

	// 3-mana neutral cards
	{ 3, "Acolyte Of Pain",			1, 3 },
	{ 3, "Alarm-o-Bot",				0, 3 },
	{ 3, "Arcane Golem",			4, 2, Battlecry_ArcaneGolem, MinionAbilityFlags::Charge, CardFlags::CanBeInDecks },
	{ 3, "Big Game Hunter",			4, 2 },
	{ 3, "Blood Knight",			3, 3 },
	{ 3, "Coldlight Oracle",		2, 2, CardFlags::None, MinionRace::Murloc },
	{ 3, "Coldlight Seer",			2, 3, CardFlags::None, MinionRace::Murloc  },
	{ 3, "Dalaran Mage",			1, 4 },
	{ 3, "Dancing Swords",			4, 4, Deathrattle_DancingSwords, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 3, "Deathlord",				2, 8 },
	{ 3, "Demolisher",				1, 4 },
	{ 3, "Earthen Ring Farseer",	3, 3, Battlecry_EarthenRingFarseer, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 3, "Emperor Cobra",			2, 3, CardFlags::None, MinionRace::Beast },
	{ 3, "Flesheating Ghoul",		2, 3 },
	{ 3, "Harvest Golem",			2, 3 },
	{ 3, "Imp Master",				1, 5 },
	{ 3, "Injured Blademaster",		4, 7 },
	{ 3, "Ironforge Rifleman",		2, 2, Battlecry_IronforgeRifleman, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 3, "Ironfur Grizzly",			3, 3, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks, MinionRace::Beast},
	{ 3, "Jungle Panther",			4, 2, MinionAbilityFlags::Stealth, CardFlags::CanBeInDecks, MinionRace::Beast},
	{ 3, "King Mukla",				5, 5, CardFlags::None, MinionRace::Beast },
	{ 3, "Magma Rager",				5, 1, CardFlags::CanBeInDecks },
	{ 3, "Mind Control Tech",		3, 3 },
	{ 3, "Murloc Warleader",		3, 3, CardFlags::None, MinionRace::Murloc },
	{ 3, "Questing Adventurer",		2, 2 },
	{ 3, "Raging Worgen",			3, 3 },
	{ 3, "Raid Leader",				2, 2 },
	{ 3, "Razorfen Hunter",			2, 3 },
	{ 3, "Scarlet Crusader",		3, 1, MinionAbilityFlags::DivineShield, CardFlags::CanBeInDecks },
	{ 3, "Shade Of Naxxramas",		2, 2 },
	{ 3, "Shattered Sun Cleric",	3, 2 },
	{ 3, "Silverback Patriarch",	1, 4, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 3, "Southsea Captain",		3, 3, CardFlags::None, MinionRace::Pirate },
	{ 3, "Stoneskin Gargoyle",		1, 4 },
	{ 3, "Tauren Warrior",			2, 3, MinionAbilityFlags::Taunt },
	{ 3, "Thrallmar Farseer",		2, 3, MinionAbilityFlags::Windfury, CardFlags::CanBeInDecks },
	{ 3, "Tinkmaster Overspark",	3, 3 },
	{ 3, "Wolfrider",				3, 1, MinionAbilityFlags::Charge, CardFlags::CanBeInDecks },

	// 4-mana neutral cards
	{ 4, "Ancient Brewmaster",		5, 4 },
	{ 4, "Ancient Mage",			2, 5 },
	{ 4, "Baron Riverdare",			1, 7 },
	{ 4, "Chillwind Yeti",			4, 5, CardFlags::CanBeInDecks },
	{ 4, "Cult Master",				4, 2 },
	{ 4, "Dark Iron Dwarf",			4, 4, Battlecry_DarkIronDwarf, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 4, "Defender Of Argus",		4, 4 },
	{ 4, "Dragonling Mechanic",		2, 4 },
	{ 4, "Dread Corsair",			3, 3, MinionAbilityFlags::Taunt, CardFlags::None, MinionRace::Pirate },
	{ 4, "Gnomish Inventor",		2, 4 },
	{ 4, "Leeroy Jenkins",			6, 2, MinionAbilityFlags::Charge },
	{ 4, "Mogu'shan Warden",		1, 7, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 4, "Oasis Snapjaw",			2, 7, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 4, "Ogre Magi",				4, 4, CardFlags::CanBeInDecks, MinionRace::None, 1},
	{ 4, "Old Murk Eye",			2, 4, CardFlags::None, MinionRace::Murloc  },
	{ 4, "Sen'jin Shieldmasta",		3, 5, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 4, "Silvermoon Guardian",		3, 3, MinionAbilityFlags::DivineShield, CardFlags::CanBeInDecks },
	{ 4, "Spellbreaker",			4, 3 },
	{ 4, "Stormwind Knight",		2, 5, MinionAbilityFlags::Charge, CardFlags::CanBeInDecks },
	{ 4, "Twilight Drake",			4, 1, CardFlags::None, MinionRace::Dragon },
	{ 4, "Violet Teacher",			3, 5 },
	{ 4, "Wailing Soul",			3, 5 },

	// 5-mana neutral cards
	{ 5, "Abomination",				4, 4, Deathrattle_Abomination, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 5, "Azure Drake",				4, 4, Battlecry_AzureDrake, MinionAbilityFlags::None, CardFlags::CanBeInDecks, MinionRace::Dragon, 1 },
	{ 5, "Booty Bay Bodyguard",		5, 4, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 5, "Captain Greenskin",		5, 4, CardFlags::None, MinionRace::Pirate },
	{ 5, "Darkscale Healer",		4, 5, Battlecry_DarkscaleHealer, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 5, "Elite Tauren Chieftan",	5, 5 },
	{ 5, "Faceless Manipulator",	3, 3 },
	{ 5, "Fen Creeper",				3, 6, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 5, "Feugen",					4, 7 },
	{ 5, "Frostwolf Warlord",		4, 4 },
	{ 5, "Gadgetzan Auctioneer",	4, 4 },
	{ 5, "Gurubashi Berserker",		2, 7 },
	{ 5, "Harrison Jones",			5, 4 },
	{ 5, "Loatheb",					5, 5 },
	{ 5, "Nightblade",				4, 4, Battlecry_Nightblade, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 5, "Silver Hand Knight",		4, 4 },
	{ 5, "Sludge Belcher",			3, 5, MinionAbilityFlags::Taunt },
	{ 5, "Spectral Knight",			4, 6, MinionAbilityFlags::CannotBeTargeted },
	{ 5, "Spiteful Smith",			4, 6 },
	{ 5, "Stalaag",					7, 4 },
	{ 5, "Stampeding Kodo",			3, 5, CardFlags::None, MinionRace::Beast },
	{ 5, "Stormpike Commando",		5, 2, Battlecry_StormpikeCommando, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 5, "Stranglethorn Tiger",		5, 5, MinionAbilityFlags::Stealth, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 5, "Venture Co. Mercenary",	7, 6 },

	// 6-mana neutral cards
	{ 6, "Archmage",				4, 7 },
	{ 6, "Argent Commander",		4, 2, MinionAbilityFlags::Charge | MinionAbilityFlags::DivineShield, CardFlags::CanBeInDecks },
	{ 6, "Boulderfist Ogre",		6, 7, CardFlags::CanBeInDecks },
	{ 6, "Cairne Bloodhoof",		4, 5 },
	{ 6, "Frost Elemental",			5, 5 },
	{ 6, "Gelbin Mekkatorque",		6, 6 },
	{ 6, "Hogger",					4, 4 },
	{ 6, "Illidan Stormrage",		7, 5, CardFlags::None, MinionRace::Demon },
	{ 6, "Lord of the Arena",		6, 5, MinionAbilityFlags::Taunt, CardFlags::CanBeInDecks },
	{ 6, "Maexxna",					2, 8, CardFlags::None, MinionRace::Beast },
	{ 6, "Priestess of Elune",		5, 4, Battlecry_PriestessOfElune, MinionAbilityFlags::None, CardFlags::CanBeInDecks },
	{ 6, "Reckless Rocketeer",		5, 2, MinionAbilityFlags::Charge, CardFlags::CanBeInDecks },
	{ 6, "Sunwalker",				4, 5, MinionAbilityFlags::Taunt | MinionAbilityFlags::DivineShield, CardFlags::CanBeInDecks },
	{ 6, "Sylvanas Windrunner",		5, 5 },
	{ 6, "The Beast",				9, 7, CardFlags::None, MinionRace::Beast },
	{ 6, "The Black Knight",		4, 5 },
	{ 6, "Windfury Harpy",			4, 5, MinionAbilityFlags::Windfury, CardFlags::CanBeInDecks },

	// 7-mana neutral cards
	{ 7, "Baron Geddon",			7, 5 },
	{ 7, "Core Hound",				9, 5, CardFlags::CanBeInDecks, MinionRace::Beast },
	{ 7, "Ravenholdt Assassin",		7, 5, MinionAbilityFlags::Stealth, CardFlags::CanBeInDecks },
	{ 7, "Stormwind Champion",		6, 6 },
	{ 7, "War Golem",				7, 7, CardFlags::CanBeInDecks },

	// 8-mana neutral cards
	{ 8, "Gruul",					7, 7 },
	{ 8, "Kel'Thuzad",				6, 8 },
	{ 8, "Ragnaros the Firelord",	8, 8, MinionAbilityFlags::CannotAttack },

	// 9-mana neutral cards
	{ 9, "Alexstrasza",				8, 8, Battlecry_Alextrasza, MinionAbilityFlags::None, CardFlags::CanBeInDecks, MinionRace::Dragon },
	{ 9, "Malygos",					4, 12, CardFlags::None, MinionRace::Dragon },
	{ 9, "Nozdormu",				8, 8, CardFlags::None, MinionRace::Dragon },
	{ 9, "Onyxia",					8, 8, CardFlags::None, MinionRace::Dragon },
	{ 9, "Ysera",					4, 12, CardFlags::None, MinionRace::Dragon },

	// 10-mana neutral cards
	{ 10, "Deathwing",				12, 12 },
	{ 10, "Sea Giant",				8, 8, CardFlags::None, MinionRace::Dragon },

	// 12-mana neutral cards
	{ 12, "Mountain Giant",			8, 8 },

	// 20-mana neutral cards
	{ 20, "Molten Giant",			8, 8 },

	// Priest cards
	{ CardType::Spell, 1, "Holy Smite", SpellEffect::DamageCharacter, 2, TargetType::AnyCharacter },
};

const CardData* GetCardData(Card c)
{
	return &AllCards[(unsigned)c];
}

CardData::CardData(uint8_t mana_cost, const char* name, uint8_t attack, uint8_t health, CardFlags card_flags, MinionRace race, uint8_t minion_spelldamage)
	: m_type(CardType::Minion)
	, m_mana_cost(mana_cost)
	, m_name(name)
	, m_attack(attack)
	, m_health(health)
	, m_minion_abilities(MinionAbilityFlags::None)
	, m_minion_race(race)
	, m_minion_spelldamage(minion_spelldamage)
	, m_minion_deathrattle(Deathrattle{ })
	, m_flags(card_flags)
{

}

CardData::CardData(uint8_t mana_cost, const char* name, uint8_t attack, uint8_t health, MinionAbilityFlags flags, CardFlags card_flags, MinionRace race)
	: m_type(CardType::Minion)
	, m_mana_cost(mana_cost)
	, m_name(name)
	, m_attack(attack)
	, m_health(health)
	, m_minion_abilities(flags)
	, m_minion_race(race)
	, m_minion_spelldamage(0)
	, m_minion_deathrattle(Deathrattle{ })
	, m_flags(card_flags)
{

}

CardData::CardData(uint8_t mana_cost, const char* name, uint8_t attack, uint8_t health, Deathrattle deathrattle, MinionAbilityFlags minion_flags, CardFlags card_flags, MinionRace race, uint8_t minion_spelldamage)
	: m_type(CardType::Minion)
	, m_mana_cost(mana_cost)
	, m_name(name)
	, m_attack(attack)
	, m_health(health)
	, m_minion_abilities(minion_flags)
	, m_minion_race(race)
	, m_minion_spelldamage(minion_spelldamage)
	, m_minion_deathrattle(deathrattle)
	, m_flags(card_flags)
{

}

CardData::CardData(uint8_t mana_cost, const char* name, uint8_t attack, uint8_t health, Battlecry battlecry, MinionAbilityFlags minion_flags, CardFlags card_flags, MinionRace race, uint8_t minion_spelldamage)
	: m_type(CardType::Minion)
	, m_mana_cost(mana_cost)
	, m_name(name)
	, m_attack(attack)
	, m_health(health)
	, m_minion_abilities(minion_flags)
	, m_minion_race(race)
	, m_minion_spelldamage(minion_spelldamage)
	, m_minion_deathrattle(Deathrattle{ })
	, m_minion_battlecry(battlecry)
	, m_flags(card_flags)
{

}



// Spell constructor
CardData::CardData(CardType type, uint8_t mana_cost, const char* name, SpellEffect effect, uint8_t effect_param, TargetType target_type, CardFlags card_flags )
	: m_type(type)
	, m_mana_cost(mana_cost)
	, m_name(name)
	, m_attack(0)
	, m_health(0)
	, m_minion_abilities(MinionAbilityFlags::None)
	, m_minion_race(MinionRace::None)
	, m_minion_spelldamage(0)
	, m_spell_data(SpellData{ effect, effect_param, target_type })
	, m_minion_deathrattle(Deathrattle{  })
	, m_minion_battlecry(Battlecry{ })
	, m_flags(card_flags)
{
}

bool CardData::HasBattlecry( ) const
{
	if (m_type == CardType::Spell)
		return false;

	if (m_minion_battlecry.m_effect == SpellEffect::None)
		return false;
	
	return true;
}

std::vector<Card> DeckPossibleCards;

void FilterDeckPossibleCards( )
{
	DeckPossibleCards.clear( );

	for (Card c = Card::Wisp; // Skip Coin
		 c != Card::MAX;
		 c = (Card)((unsigned)c + 1)
		 )
	{
		const CardData* data = GetCardData(c);
		if ( HasFlag( data->m_flags, CardFlags::CanBeInDecks) )
		{
			DeckPossibleCards.push_back(c);
		}
	}
}