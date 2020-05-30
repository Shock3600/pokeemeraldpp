VictoryRoad_B1F_MapScripts:: @ 82364E4
	.byte 0

VictoryRoad_B1F_EventScript_Samuel:: @ 82364E5
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon:: @ 82364FC
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle:: @ 8236513
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell:: @ 823652A
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle:: @ 8236541
	trainerbattle_single TRAINER_HALLE, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end
	
VictoryRoad_B1F_EventScript_Mega_Trainer::
	goto_if_set FLAG_HERACROSS_GET, VictoryRoad_B1F_EventScript_Mega_Trainer_Defeated
	goto_if_set FLAG_BADGE07_GET, VictoryRoad_B1F_EventScript_Mega_Trainer_Battle
	goto_if_set FLAG_BADGE05_GET, VictoryRoad_B1F_EventScript_Mega_Trainer_So_Close
	goto_if_set FLAG_BADGE03_GET, VictoryRoad_B1F_EventScript_Mega_Trainer_Not_Bad
	msgbox VictoryRoad_B1F_Text_Weak, MSGBOX_DEFAULT
	end

VictoryRoad_B1F_EventScript_Mega_Trainer_Battle::
	goto_if_set FLAG_IS_CHAMPION, VictoryRoad_B1F_EventScript_Mega_Trainer_Champ
	goto_if_set FLAG_BADGE08_GET, VictoryRoad_B1F_EventScript_Mega_Trainer_Badge08
	goto VictoryRoad_B1F_EventScript_Mega_Trainer_Badge07

VictoryRoad_B1F_EventScript_Mega_Trainer_So_Close::
	msgbox VictoryRoad_B1F_Text_So_Close, MSGBOX_DEFAULT
	end
	
VictoryRoad_B1F_EventScript_Mega_Trainer_Not_Bad::
	msgbox VictoryRoad_B1F_Text_Not_Bad, MSGBOX_DEFAULT
	end

VictoryRoad_B1F_EventScript_Mega_Trainer_Champ::
	trainerbattle_single TRAINER_HERACROSS_CHAMP, VictoryRoad_B1F_Text_Battle_Champ, VictoryRoad_B1F_Text_Defeat, VictoryRoad_B1F_EventScript_Mega_Trainer_Give_Stone
	
VictoryRoad_B1F_EventScript_Mega_Trainer_Badge08::
	trainerbattle_single TRAINER_HERACROSS_BADGE08, VictoryRoad_B1F_Text_Battle_Intro, VictoryRoad_B1F_Text_Defeat, VictoryRoad_B1F_EventScript_Mega_Trainer_Give_Stone
	
VictoryRoad_B1F_EventScript_Mega_Trainer_Badge07::
	trainerbattle_single TRAINER_HERACROSS_BADGE07, VictoryRoad_B1F_Text_Battle_Intro, VictoryRoad_B1F_Text_Defeat, VictoryRoad_B1F_EventScript_Mega_Trainer_Give_Stone
	
VictoryRoad_B1F_EventScript_Mega_Trainer_Give_Stone::
	giveitem ITEM_HERACRONITE, 1
	setflag FLAG_HERACROSS_GET
	end
	
VictoryRoad_B1F_EventScript_Mega_Trainer_Defeated::
	msgbox VictoryRoad_B1F_Text_Defeated, MSGBOX_DEFAULT
	end

VictoryRoad_B1F_Text_SamuelIntro: @ 8236558
	.string "The thought that I'm getting closer to\n"
	.string "the POKéMON LEAGUE…\p"
	.string "I'm getting stage fright…$"

VictoryRoad_B1F_Text_SamuelDefeat: @ 82365AD
	.string "I couldn't do a thing…$"

VictoryRoad_B1F_Text_SamuelPostBattle: @ 82365C4
	.string "The POKéMON LEAGUE became distant\n"
	.string "again… What a letdown…$"

VictoryRoad_B1F_Text_ShannonIntro: @ 82365FD
	.string "To win your way through the POKéMON\n"
	.string "LEAGUE, you need the trust of your\l"
	.string "POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat: @ 823664D
	.string "Your relationship is based on\n"
	.string "solid trust.$"

VictoryRoad_B1F_Text_ShannonPostBattle: @ 8236678
	.string "By being together all the time, trust\n"
	.string "grows between POKéMON and TRAINERS.$"

VictoryRoad_B1F_Text_MichelleIntro: @ 82366C2
	.string "This isn't the goal. It's only a place\n"
	.string "on the way to the POKéMON LEAGUE.$"

VictoryRoad_B1F_Text_MichelleDefeat: @ 823670B
	.string "That's the way!$"

VictoryRoad_B1F_Text_MichellePostBattle: @ 823671B
	.string "You'll do fine, for sure!\n"
	.string "Your POKéMON are all eager to go!$"

VictoryRoad_B1F_Text_MitchellIntro: @ 8236757
	.string "My POKéMON are cosmically\n"
	.string "awe inspiring!$"

VictoryRoad_B1F_Text_MitchellDefeat: @ 8236780
	.string "I've never met anyone like you before.$"

VictoryRoad_B1F_Text_MitchellPostBattle: @ 82367A7
	.string "Even outside of battle, I sense\n"
	.string "incredible power emanating from you\l"
	.string "and your POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro: @ 82367FD
	.string "Okay, no need to get your back up!\n"
	.string "Relax, let's take it easy!$"

VictoryRoad_B1F_Text_HalleDefeat: @ 823683B
	.string "Whoa!\n"
	.string "Wonderful!$"

VictoryRoad_B1F_Text_HallePostBattle: @ 823684C
	.string "Sure, this is VICTORY ROAD.\p"
	.string "But it's not all that different from\n"
	.string "the path you've taken so far.\p"
	.string "Try to enjoy things the rest of\n"
	.string "the way!$"

VictoryRoad_B1F_Text_Weak:
	.string "You're not even close\n"
	.string "to my power. Once you're\n"
	.string "less weak come back to see me.$"
	
VictoryRoad_B1F_Text_So_Close:
	.string "You're so close! Once\n"
	.string "You get a little stronger\n"
	.string "come back for a fight!$"
	
VictoryRoad_B1F_Text_Not_Bad:
	.string "You're not so bad...\n"
	.string "Maybe in the future we can fight.$"
	
VictoryRoad_B1F_Text_Battle_Champ:
	.string "The Champion! I've been\n"
	.string "looking forward to this.\n"
	.string "If I win, maybe I'll\n"
	.string "go challenge the Elite 4 and you!$"

VictoryRoad_B1F_Text_Battle_Intro:
	.string "Now this is a battle\n"
	.string "I'm looking forward to!\n"
	.string "Bring it on!$"
	
VictoryRoad_B1F_Text_Defeat:
	.string "Wow...\n"
	.string "You beat me. You truly\n"
	.string "are great. Use this\n"
	.string "stone to harness the\n"
	.string "power of MEGA HERACROSS!$"
	
VictoryRoad_B1F_Text_Defeated:
	.string "You've already proved\n"
	.string "your worth! I hope\n"
	.string "making good use of that MEGA STONE.$"
	