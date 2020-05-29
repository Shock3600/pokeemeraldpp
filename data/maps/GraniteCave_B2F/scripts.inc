GraniteCave_B2F_MapScripts:: @ 822DC79
	.byte 0

GraniteCave_B2F_EventScript_Mega_Trainer::
	goto_if_set FLAG_AGGRON_GET, GraniteCave_B2F_EventScript_Mega_Trainer_Defeated
	goto_if_set FLAG_BADGE07_GET, GraniteCave_B2F_EventScript_Mega_Trainer_Battle
	goto_if_set FLAG_BADGE05_GET, GraniteCave_B2F_EventScript_Mega_Trainer_So_Close
	goto_if_set FLAG_BADGE03_GET, GraniteCave_B2F_EventScript_Mega_Trainer_Not_Bad
	msgbox GraniteCave_B2F_Text_Weak, MSGBOX_DEFAULT
	end

GraniteCave_B2F_EventScript_Mega_Trainer_Battle::
	goto_if_set FLAG_IS_CHAMPION, GraniteCave_B2F_EventScript_Mega_Trainer_Champ
	goto_if_set FLAG_BADGE08_GET, GraniteCave_B2F_EventScript_Mega_Trainer_Badge08
	goto GraniteCave_B2F_EventScript_Mega_Trainer_Badge07

GraniteCave_B2F_EventScript_Mega_Trainer_So_Close::
	msgbox GraniteCave_B2F_Text_So_Close, MSGBOX_DEFAULT
	end
	
GraniteCave_B2F_EventScript_Mega_Trainer_Not_Bad::
	msgbox GraniteCave_B2F_Text_Not_Bad, MSGBOX_DEFAULT
	end

GraniteCave_B2F_EventScript_Mega_Trainer_Champ::
	trainerbattle_single TRAINER_AGGRON_CHAMP, GraniteCave_B2F_Text_Battle_Champ, GraniteCave_B2F_Text_Defeat, GraniteCave_B2F_EventScript_Mega_Trainer_Give_Stone
	
GraniteCave_B2F_EventScript_Mega_Trainer_Badge08::
	trainerbattle_single TRAINER_AGGRON_BADGE08, GraniteCave_B2F_Text_Battle_Intro, GraniteCave_B2F_Text_Defeat, GraniteCave_B2F_EventScript_Mega_Trainer_Give_Stone
	
GraniteCave_B2F_EventScript_Mega_Trainer_Badge07::
	trainerbattle_single TRAINER_AGGRON_BADGE07, GraniteCave_B2F_Text_Battle_Intro, GraniteCave_B2F_Text_Defeat, GraniteCave_B2F_EventScript_Mega_Trainer_Give_Stone
	
GraniteCave_B2F_EventScript_Mega_Trainer_Give_Stone::
	giveitem ITEM_AGGRONITE, 1
	setflag FLAG_AGGRON_GET
	end
	
GraniteCave_B2F_EventScript_Mega_Trainer_Defeated::
	msgbox GraniteCave_B2F_Text_Defeated, MSGBOX_DEFAULT
	end
	
GraniteCave_B2F_Text_Weak:
	.string "You're not even close\n"
	.string "to my power. Once you're\n"
	.string "less weak come back to see me.$"
	
GraniteCave_B2F_Text_So_Close:
	.string "You're so close! Once\n"
	.string "You get a little stronger\n"
	.string "come back for a fight!$"
	
GraniteCave_B2F_Text_Not_Bad:
	.string "You're not so bad...\n"
	.string "Maybe in the future we can fight.$"
	
GraniteCave_B2F_Text_Battle_Champ:
	.string "The Champion! I've been\n"
	.string "looking forward to this.\n"
	.string "If I win, maybe I'll\n"
	.string "go challenge the Elite 4 and you!$"

GraniteCave_B2F_Text_Battle_Intro:
	.string "Now this is a battle\n"
	.string "I'm looking forward to!\n"
	.string "Bring it on!$"
	
GraniteCave_B2F_Text_Defeat:
	.string "Wow...\n"
	.string "You beat me. You truly\n"
	.string "are great. Use this\n"
	.string "stone to harness the\n"
	.string "power of MEGA AGGRON!$"
	
GraniteCave_B2F_Text_Defeated:
	.string "You've already proved\n"
	.string "your worth! I hope\n"
	.string "making good use of that MEGA STONE.$"
