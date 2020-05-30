PacifidlogTown_MapScripts:: @ 81EBAB1
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition: @ 81EBABC
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume: @ 81EBAC0
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy:: @ 81EBAC3
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl:: @ 81EBACC
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman:: @ 81EBAD5
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign:: @ 81EBADE
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end
	
PacifidlogTown_EventScript_Mega_Trainer::
	goto_if_set FLAG_GYARADOS_GET, PacifidlogTown_EventScript_Mega_Trainer_Defeated
	goto_if_set FLAG_BADGE07_GET, PacifidlogTown_EventScript_Mega_Trainer_Battle
	goto_if_set FLAG_BADGE05_GET, PacifidlogTown_EventScript_Mega_Trainer_So_Close
	goto_if_set FLAG_BADGE03_GET, PacifidlogTown_EventScript_Mega_Trainer_Not_Bad
	msgbox PacifidlogTown_Text_Weak, MSGBOX_DEFAULT
	end

PacifidlogTown_EventScript_Mega_Trainer_Battle::
	goto_if_set FLAG_IS_CHAMPION, PacifidlogTown_EventScript_Mega_Trainer_Champ
	goto_if_set FLAG_BADGE08_GET, PacifidlogTown_EventScript_Mega_Trainer_Badge08
	goto PacifidlogTown_EventScript_Mega_Trainer_Badge07

PacifidlogTown_EventScript_Mega_Trainer_So_Close::
	msgbox PacifidlogTown_Text_So_Close, MSGBOX_DEFAULT
	end
	
PacifidlogTown_EventScript_Mega_Trainer_Not_Bad::
	msgbox PacifidlogTown_Text_Not_Bad, MSGBOX_DEFAULT
	end

PacifidlogTown_EventScript_Mega_Trainer_Champ::
	trainerbattle_single TRAINER_GYARADOS_CHAMP, PacifidlogTown_Text_Battle_Champ, PacifidlogTown_Text_Defeat, PacifidlogTown_EventScript_Mega_Trainer_Give_Stone
	
PacifidlogTown_EventScript_Mega_Trainer_Badge08::
	trainerbattle_single TRAINER_GYARADOS_BADGE08, PacifidlogTown_Text_Battle_Intro, PacifidlogTown_Text_Defeat, PacifidlogTown_EventScript_Mega_Trainer_Give_Stone
	
PacifidlogTown_EventScript_Mega_Trainer_Badge07::
	trainerbattle_single TRAINER_GYARADOS_BADGE07, PacifidlogTown_Text_Battle_Intro, PacifidlogTown_Text_Defeat, PacifidlogTown_EventScript_Mega_Trainer_Give_Stone
	
PacifidlogTown_EventScript_Mega_Trainer_Give_Stone::
	giveitem ITEM_GYARADOSITE, 1
	setflag FLAG_GYARADOS_GET
	end

PacifidlogTown_Text_FastRunningCurrent: @ 81EBAE7
	.string "The sea between PACIFIDLOG and\n"
	.string "SLATEPORT has a fast-running tide.\p"
	.string "If you decide to SURF, you could end\n"
	.string "up swept away somewhere else.$"

PacifidlogTown_Text_NeatHousesOnWater: @ 81EBB6C
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"

PacifidlogTown_Text_SkyPillarTooScary: @ 81EBBAC
	.string "The SKY PILLAR?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in PACIFIDLOG,\n"
	.string "that suits me fine.$"

PacifidlogTown_Text_TownSign: @ 81EBC7A
	.string "PACIFIDLOG TOWN\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"

PacifidlogTown_EventScript_Mega_Trainer_Defeated::
	msgbox PacifidlogTown_Text_Defeated, MSGBOX_DEFAULT
	end
	
PacifidlogTown_Text_Weak:
	.string "You're not even close\n"
	.string "to my power. Once you're\n"
	.string "less weak come back to see me.$"
	
PacifidlogTown_Text_So_Close:
	.string "You're so close! Once\n"
	.string "You get a little stronger\n"
	.string "come back for a fight!$"
	
PacifidlogTown_Text_Not_Bad:
	.string "You're not so bad...\n"
	.string "Maybe in the future we can fight.$"
	
PacifidlogTown_Text_Battle_Champ:
	.string "The Champion! I've been\n"
	.string "looking forward to this.\n"
	.string "If I win, maybe I'll\n"
	.string "go challenge the Elite 4 and you!$"

PacifidlogTown_Text_Battle_Intro:
	.string "Now this is a battle\n"
	.string "I'm looking forward to!\n"
	.string "Bring it on!$"
	
PacifidlogTown_Text_Defeat:
	.string "Wow...\n"
	.string "You beat me. You truly\n"
	.string "are great. Use this\n"
	.string "stone to harness the\n"
	.string "power of MEGA GYARADOS!$"
	
PacifidlogTown_Text_Defeated:
	.string "You've already proved\n"
	.string "your worth! I hope\n"
	.string "making good use of that MEGA STONE.$"
