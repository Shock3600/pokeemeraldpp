AbandonedShip_HiddenFloorCorridors_MapScripts:: @ 823896C
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorCorridors_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorCorridors_OnLoad
	.byte 0

AbandonedShip_HiddenFloorCorridors_OnResume: @ 8238977
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 255, 5, 4
	end

AbandonedShip_HiddenFloorCorridors_OnLoad: @ 8238980
	call_if_unset FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1
	call_if_unset FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2
	call_if_unset FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4
	call_if_unset FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6
	call_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
	call_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
	call_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
	call_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
	end

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1:: @ 82389C9
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2:: @ 82389D3
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4:: @ 82389DD
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Unlocked, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6:: @ 82389E7
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Unlocked, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1:: @ 82389F1
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2:: @ 82389FB
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, 1
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4:: @ 8238A05
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Locked, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6:: @ 8238A0F
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Locked, 0
	return

AbandonedShip_HiddenFloorCorridors_EventScript_Room1Door:: @ 8238A19
	lockall
	goto_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_1_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_1_KEY
	setflag FLAG_USED_ROOM_1_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room2Door:: @ 8238A50
	lockall
	goto_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_2_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_2_KEY
	setflag FLAG_USED_ROOM_2_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room4Door:: @ 8238A87
	lockall
	goto_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_4_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_4_KEY
	setflag FLAG_USED_ROOM_4_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room6Door:: @ 8238ABE
	lockall
	goto_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_6_KEY, 1
	compare VAR_RESULT, FALSE
	goto_if_eq AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_6_KEY
	setflag FLAG_USED_ROOM_6_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked:: @ 8238AF5
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked:: @ 8238AFF
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked:: @ 8238B09
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked:: @ 8238B13
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen:: @ 8238B1D
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end
	
AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer::
	goto_if_set FLAG_BANETTE_GET, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Defeated
	goto_if_set FLAG_BADGE07_GET, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Battle
	goto_if_set FLAG_BADGE05_GET, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_So_Close
	goto_if_set FLAG_BADGE03_GET, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Not_Bad
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Weak, MSGBOX_DEFAULT
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Battle::
	goto_if_set FLAG_IS_CHAMPION, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Champ
	goto_if_set FLAG_BADGE08_GET, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Badge08
	goto AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Badge07

AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_So_Close::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_So_Close, MSGBOX_DEFAULT
	end
	
AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Not_Bad::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Not_Bad, MSGBOX_DEFAULT
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Champ::
	trainerbattle_single TRAINER_BANETTE_CHAMP, AbandonedShip_HiddenFloorCorridors_Text_Battle_Champ, AbandonedShip_HiddenFloorCorridors_Text_Defeat, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Give_Stone
	
AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Badge08::
	trainerbattle_single TRAINER_BANETTE_BADGE08, AbandonedShip_HiddenFloorCorridors_Text_Battle_Intro, AbandonedShip_HiddenFloorCorridors_Text_Defeat, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Give_Stone
	
AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Badge07::
	trainerbattle_single TRAINER_BANETTE_BADGE07, AbandonedShip_HiddenFloorCorridors_Text_Battle_Intro, AbandonedShip_HiddenFloorCorridors_Text_Defeat, AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Give_Stone
	
AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Give_Stone::
	giveitem ITEM_BANETTITE, 1
	setflag FLAG_BANETTE_GET
	end
	
AbandonedShip_HiddenFloorCorridors_EventScript_Mega_Trainer_Defeated::
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Defeated, MSGBOX_DEFAULT
	end

AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked: @ 8238B27
	.string "The door is locked.\p"
	.string "“RM. 1” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked: @ 8238B5B
	.string "The door is locked.\p"
	.string "“RM. 2” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked: @ 8238B8F
	.string "The door is locked.\p"
	.string "“RM. 4” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked: @ 8238BC3
	.string "The door is locked.\p"
	.string "“RM. 6” is painted on the door.$"

AbandonedShip_HiddenFloorCorridors_Text_InsertedKey: @ 8238BF7
	.string "{PLAYER} inserted and turned the\n"
	.string "KEY.\p"
	.string "The inserted KEY stuck fast,\n"
	.string "but the door opened.$"

AbandonedShip_HiddenFloorCorridors_Text_Weak:
	.string "You're not even close\n"
	.string "to my power. Once you're\n"
	.string "less weak come back to see me.$"
	
AbandonedShip_HiddenFloorCorridors_Text_So_Close:
	.string "You're so close! Once\n"
	.string "You get a little stronger\n"
	.string "come back for a fight!$"
	
AbandonedShip_HiddenFloorCorridors_Text_Not_Bad:
	.string "You're not so bad...\n"
	.string "Maybe in the future we can fight.$"
	
AbandonedShip_HiddenFloorCorridors_Text_Battle_Champ:
	.string "The Champion! I've been\n"
	.string "looking forward to this.\n"
	.string "If I win, maybe I'll\n"
	.string "go challenge the Elite 4 and you!$"

AbandonedShip_HiddenFloorCorridors_Text_Battle_Intro:
	.string "Now this is a battle\n"
	.string "I'm looking forward to!\n"
	.string "Bring it on!$"
	
AbandonedShip_HiddenFloorCorridors_Text_Defeat:
	.string "Wow...\n"
	.string "You beat me. You truly\n"
	.string "are great. Use this\n"
	.string "stone to harness the\n"
	.string "power of MEGA BANETTE!$"
	
AbandonedShip_HiddenFloorCorridors_Text_Defeated:
	.string "You've already proved\n"
	.string "your worth! I hope\n"
	.string "making good use of that MEGA STONE.$"