/*
 * Author: Markus Stenberg <fingon@iki.fi>
 *
 *  Copyright (c) 1997 Markus Stenberg
 *  Copyright (c) 1998-2002 Thomas Wouters
 *  Copyright (c) 2000-2002 Cord Awtry
 *  Copyright (c) 1999-2005 Kevin Stevens
 *       All rights reserved
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/file.h>

#include "mech.h"
#include "mech.events.h"
#include "autopilot.h"
#include "failures.h"
#include "p.mech.los.h"
#include "p.mine.h"
#include "p.mech.utils.h"
#include "p.mech.build.h"
#include "p.mech.startup.h"
#include "p.autopilot_command.h"
#include "p.btechstats.h"
#include "p.mech.sensor.h"
#include "p.map.obj.h"
#include "p.bsuit.h"

void sendchannelstuff(MECH * mech, int freq, char *msg);

const char *GetAmmoDesc_Model_Mode(int model, int mode)
{
	if(mode & LBX_MODE)
		return " Shotgun";
	if(mode & ARTEMIS_MODE)
		return " Artemis IV";
	if(mode & NARC_MODE)
		return (MechWeapons[model].special & NARC) ? " Explosive" :
			" Narc";
	if(mode & INARC_EXPLO_MODE)
		return " iExplosive";
	if(mode & INARC_HAYWIRE_MODE)
		return " Haywire";
	if(mode & INARC_ECM_MODE)
		return " ECM";
	if(mode & INARC_NEMESIS_MODE)
		return " Nemesis";
	if(mode & SWARM_MODE)
		return " Swarm";
	if(mode & SWARM1_MODE)
		return " Swarm1";
	if(mode & INFERNO_MODE)
		return " Inferno";
	if(mode & CLUSTER_MODE)
		return " Cluster";
	if(mode & SMOKE_MODE)
		return " Smoke";
	if(mode & MINE_MODE)
		return " Mine";
	if(mode & AC_AP_MODE)
		return " Armor Piercing";
	if(mode & AC_FLECHETTE_MODE)
		return " Flechette";
	if(mode & AC_INCENDIARY_MODE)
		return " Incendiary";
	if(mode & AC_PRECISION_MODE)
		return " Precision";
	if(mode & STINGER_MODE)
		return " Stinger";
	if(mode & AC_CASELESS_MODE)
		return " Caseless";
	if(mode & SGUIDED_MODE)
		return " Sguided";
	if(mode & ATM_ER_MODE)
		return " ExtendedRange";
	if(mode & ATM_HE_MODE)
		return " HighExplosive";
	if(mode & MML_LRM_MODE)
		return " LRM";
	return "";
}

char GetWeaponAmmoModeLetter_Model_Mode(int model, int mode)
{
	if(!(mode & AMMO_MODES))
		return ' ';
	if(mode & CLUSTER_MODE)
		return 'C';
	if(mode & SMOKE_MODE)
		return 'S';
	if(mode & MINE_MODE)
		return 'M';
	if(mode & LBX_MODE)
		return 'L';
	if(mode & ARTEMIS_MODE)
		return 'A';
	if(mode & NARC_MODE)
		return (MechWeapons[model].special & NARC) ? 'E' : 'N';
	if(mode & INARC_EXPLO_MODE)
		return 'X';
	if(mode & INARC_HAYWIRE_MODE)
		return 'Y';
	if(mode & INARC_ECM_MODE)
		return 'E';
	if(mode & INARC_NEMESIS_MODE)
		return 'Z';
	if(mode & INFERNO_MODE)
		return 'I';
	if(mode & SWARM_MODE)
		return 'W';
	if(mode & SWARM1_MODE)
		return '1';
	if(mode & AC_AP_MODE)
		return 'R';
	if(mode & AC_FLECHETTE_MODE)
		return 'F';
	if(mode & AC_INCENDIARY_MODE)
		return 'D';
	if(mode & AC_PRECISION_MODE)
		return 'P';
	if(mode & STINGER_MODE)
		return 'T';
	if(mode & AC_CASELESS_MODE)
		return 'U';
	if(mode & SGUIDED_MODE)
		return 'G';
	if(mode & ATM_ER_MODE)
		return 'R';
	if(mode & ATM_HE_MODE)
		return 'X';
	if(mode & MML_LRM_MODE)
		return '#';
	return ' ';
}

char GetWeaponFireModeLetter_Model_Mode(int model, int mode)
{
	if(!(mode & FIRE_MODES))
		return ' ';
	if(mode & HOTLOAD_MODE)
		return 'H';
	if(mode & ULTRA_MODE)
		return 'U';
	if(mode & RFAC_MODE)
		return 'F';
	if(mode & GATTLING_MODE)
		return 'G';
	if(mode & HEAT_MODE)
		return 'H';
	if(mode & RAC_TWOSHOT_MODE)
		return '2';
	if(mode & RAC_FOURSHOT_MODE)
		return '4';
	if(mode & RAC_SIXSHOT_MODE)
		return '6';
	return ' ';
}

char GetWeaponAmmoModeLetter(MECH * mech, int loop, int crit)
{
	return GetWeaponAmmoModeLetter_Model_Mode(Weapon2I(GetPartType(mech,
																   loop,
																   crit)),
											  GetPartAmmoMode(mech, loop,
															  crit));
}

char GetWeaponFireModeLetter(MECH * mech, int loop, int crit)
{
	return GetWeaponFireModeLetter_Model_Mode(Weapon2I(GetPartType(mech,
																   loop,
																   crit)),
											  GetPartFireMode(mech, loop,
															  crit));
}

const char *GetMoveTypeID(int movetype)
{
	static char buf[20];

	switch (movetype) {
	case MOVE_QUAD:
		strcpy(buf, "QUAD");
		break;
	case MOVE_BIPED:
		strcpy(buf, "BIPED");
		break;
	case MOVE_TRACK:
		strcpy(buf, "TRACKED");
		break;
	case MOVE_WHEEL:
		strcpy(buf, "WHEELED");
		break;
	case MOVE_HOVER:
		strcpy(buf, "HOVER");
		break;
	case MOVE_VTOL:
		strcpy(buf, "VTOL");
		break;
	case MOVE_FLY:
		strcpy(buf, "FLY");
		break;
	case MOVE_HULL:
		strcpy(buf, "HULL");
		break;
	case MOVE_SUB:
		strcpy(buf, "SUBMARINE");
		break;
	case MOVE_FOIL:
		strcpy(buf, "HYDROFOIL");
		break;
	default:
		strcpy(buf, "Unknown");
		break;
	}
	return buf;
}

struct {
	char *onmsg;
	char *offmsg;
	int flag;
	int infolvl;
} temp_flag_info_struct[] = {
	{
	"DESTROYED", NULL, DESTROYED, 1}, {
	NULL, "SHUTDOWN", STARTED, 1}, {
	"Torso is 60 degrees right", NULL, TORSO_RIGHT, 0}, {
	"Torso is 60 degrees left", NULL, TORSO_LEFT, 0}, {
	NULL, NULL, 0}
};

struct {
	int team;
	char *ccode;
} obs_team_color[] = {
	{
	1, "%cw"}, {
	2, "%cc"}, {
	3, "%cm"}, {
	4, "%cb"}, {
	5, "%cy"}, {
	6, "%cg"}, {
	7, "%cr"}, {
	8, "%ch%cx"}, {
	9, "%ch%cw"}, {
	10, "%ch%cc"}, {
	11, "%ch%cm"}, {
	12, "%ch%cb"}, {
	13, "%ch%cy"}, {
	14, "%ch%cg"}, {
	15, "%ch%cr"}, {
	0, "%ch%cw"}
};

void Mech_ShowFlags(dbref player, MECH * mech, int spaces, int level)
{
	char buf[MBUF_SIZE];
	int i;

	for(i = 0; i < spaces; i++)
		buf[i] = ' ';
	buf[spaces] = 0;

	if(MechStatus(mech) & COMBAT_SAFE) {
		strcpy(buf + spaces, "%cb%chCOMBAT SAFE%cn");
		notify(player, buf);
	}
	if(Fortified(mech)) {
		strcpy(buf + spaces, "%ch%cgFORTIFIED%cn");
		notify(player, buf);
	}
	if(WeaponsHold(mech)) {
		strcpy(buf + spaces, "%ch%crWEAPONS HOLD%cn");
		notify(player, buf);
	}
	if(Fallen(mech)) {
		switch (MechMove(mech)) {
		case MOVE_BIPED:
			strcpy(buf + spaces, "%cr%chFALLEN%cn");
			break;
		case MOVE_QUAD:
			strcpy(buf + spaces, "%cr%chFALLEN%cn");
			break;
		case MOVE_TRACK:
			strcpy(buf + spaces, "%cr%chTRACK DESTROYED%cn");
			break;
		case MOVE_WHEEL:
			strcpy(buf + spaces, "%cr%chAXLE DESTROYED%cn");
			break;
		case MOVE_HOVER:
			strcpy(buf + spaces, "%cr%chLIFT FAN DESTROYED%cn");
			break;
		case MOVE_VTOL:
			strcpy(buf + spaces, "%cr%chROTOR DESTROYED%cn");
			break;
		case MOVE_FLY:
			strcpy(buf + spaces, "%cr%chENGINE DESTROYED%cn");
			break;
		case MOVE_HULL:
			strcpy(buf + spaces, "%cr%chENGINE ROOM DESTROYED%cn");
			break;
		case MOVE_SUB:
			strcpy(buf + spaces, "%cr%chENGINE ROOM DESTROYED%cn");
			break;
		case MOVE_FOIL:
			strcpy(buf + spaces, "%cr%chFOIL DESTROYED%cn");
			break;
		}
		notify(player, buf);
	}
	if(IsHulldown(mech)) {
		strcpy(buf + spaces, "%cg%chHULLDOWN%cn");
		notify(player, buf);
	}
	if(MechDugIn(mech)) {
		strcpy(buf + spaces, "%cg%chDUG IN%cn");
		notify(player, buf);
	}
	if(Digging(mech)) {
		strcpy(buf + spaces, "%cgDIGGING IN%cn");
		notify(player, buf);
	}
	if(Staggering(mech)) {
		strcpy(buf + spaces, "%cr%chSTAGGERING%cn");
		notify(player, buf);
	}
	if(MechCritStatus(mech) & SLITE_DEST) {
		strcpy(buf + spaces, "%cr%chSEARCHLIGHT DESTROYED%cn");
		notify(player, buf);
	}
	if(MechLites(mech)) {
		strcpy(buf + spaces, "%cg%chSEARCHLIGHT ON%cn");
		notify(player, buf);
	} else if(MechLit(mech)) {
		strcpy(buf + spaces, "%cg%chILLUMINATED%cn");
		notify(player, buf);
	}
	if(Burning(mech) || Jellied(mech)) {
		strcpy(buf + spaces, "%cr%chON FIRE%cn");
		notify(player, buf);
	}
	if(MechCritStatus(mech) & HIDDEN) {
		strcpy(buf + spaces, tprintf("%%ch%%cgHIDDEN%%c"));
		notify(player, buf);
	}
	if(IsMechSwarmed(mech)) {
		strcpy(buf + spaces, "%cr%chSWARMED BY ENEMY SUITS%cn");
		notify(player, buf);
	}
	if(IsMechMounted(mech)) {
		strcpy(buf + spaces, "%cr%chMOUNTED BY FRIENDLY SUITS%cn");
		notify(player, buf);
	}
	if(MechSwarmTarget(mech) > 0) {
		if(getMech(MechSwarmTarget(mech))) {
			if(MechTeam(getMech(MechSwarmTarget(mech))) == MechTeam(mech))
				strcpy(buf + spaces, "%cg%chMOUNTED ON FRIENDLY UNIT%cn");
			else
				strcpy(buf + spaces, "%cg%chSWARMING ENEMY UNIT%cn");

			notify(player, buf);
		}
	}
#ifdef BT_MOVEMENT_MODES
	if(MechStatus2(mech) & DODGING) {
		strcpy(buf + spaces, tprintf("%%ch%%crDODGING%%c"));
		notify(player, buf);
	}
	if(MechStatus2(mech) & EVADING) {
		strcpy(buf + spaces, tprintf("%%ch%%crEVADING%%c"));
		notify(player, buf);
	}
	if(MechStatus2(mech) & SPRINTING) {
		strcpy(buf + spaces, tprintf("%%ch%%crSPRINTING%%c"));
		notify(player, buf);
	}
	if(MoveModeChange(mech)) {
		strcpy(buf + spaces, tprintf("%%ch%%cyCHANGING MOVEMENT MODE%%c"));
		notify(player, buf);
	}
	if(SideSlipping(mech)) {
		strcpy(buf + spaces, tprintf("%%ch%%cySIDESLIPPING%%c"));
		notify(player, buf);
	}
	if(MechTankCritStatus(mech) & CREW_STUNNED ||
	   MechCritStatus(mech) & MECH_STUNNED) {
		strcpy(buf + spaces, "%ch%crSTUNNED%c");
		notify(player, buf);
	}
#endif
	if(level == 0) {			/* our own 'status' */
		if(ECMProtected(mech)) {
			strcpy(buf + spaces, "%cg%chPROTECTED BY ECM%cn");
			notify(player, buf);
		}
		if(AngelECMProtected(mech)) {
			strcpy(buf + spaces, "%cg%chPROTECTED BY ANGEL ECM%cn");
			notify(player, buf);
		}
		if(ECMDisturbed(mech)) {
			strcpy(buf + spaces, "%cy%chAFFECTED BY ECM%cn");
			notify(player, buf);
		}
		if(AngelECMDisturbed(mech)) {
			strcpy(buf + spaces, "%cy%chAFFECTED BY ANGEL ECM%cn");
			notify(player, buf);
		}
		if(ECMCountered(mech)) {
			strcpy(buf + spaces, "%cy%chCOUNTERED BY ECCM%cn");
			notify(player, buf);
		}
		if(StealthArmorActive(mech)) {
			strcpy(buf + spaces, "%cg%chSTEALTH ARMOR ACTIVE%cn");
			notify(player, buf);
		}
		if(NullSigSysActive(mech)) {
			strcpy(buf + spaces, "%cg%chNULL SIGNATURE SYSTEM ACTIVE%cn");
			notify(player, buf);
		}
		if(checkAllSections(mech, NARC_ATTACHED)) {
			strcpy(buf + spaces, "%cy%chNARC POD ATTACHED%cn");
			notify(player, buf);
		}
		if(checkAllSections(mech, INARC_HOMING_ATTACHED)) {
			strcpy(buf + spaces, "%cy%chINARC HOMING POD ATTACHED%cn");
			notify(player, buf);
		}
		if(checkAllSections(mech, INARC_HAYWIRE_ATTACHED)) {
			strcpy(buf + spaces, "%cy%chINARC HAYWIRE POD ATTACHED%cn");
			notify(player, buf);
		}
		if(checkAllSections(mech, INARC_ECM_ATTACHED)) {
			strcpy(buf + spaces, "%cy%chINARC ECM POD ATTACHED%cn");
			notify(player, buf);
		}
		if(Extinguishing(mech)) {
			strcpy(buf + spaces, "%cy%chEXTINGUISHING FIRE%cn");
			notify(player, buf);
		}
		if(MechStatus2(mech) & AUTOTURN_TURRET) {
			strcpy(buf + spaces, "%cg%chTURRET AUTO-TURN ENGAGED%cn");
			notify(player, buf);
		}
		if(MechSections(mech)[RARM].specials & CARRYING_CLUB) {
			strcpy(buf + spaces, "%cg%chCARRYING CLUB - RIGHT ARM%cn");
			notify(player, buf);
		}
		if(MechSections(mech)[LARM].specials & CARRYING_CLUB) {
			strcpy(buf + spaces, "%cg%chCARRYING CLUB - LEFT ARM%cn");
			notify(player, buf);
		}
	}
	for(i = 0; temp_flag_info_struct[i].flag; i++)
		if(temp_flag_info_struct[i].infolvl >= level) {
			if(MechStatus(mech) & temp_flag_info_struct[i].flag) {
				if(temp_flag_info_struct[i].onmsg) {
					strcpy(buf + spaces, temp_flag_info_struct[i].onmsg);
					notify(player, buf);
				}
			} else {
				if(temp_flag_info_struct[i].offmsg) {
					strcpy(buf + spaces, temp_flag_info_struct[i].offmsg);
					notify(player, buf);
				}
			}
		}
}

const char *GetArcID(MECH * mech, int arc)
{
	static char buf[20];
	int mechlike = (MechType(mech) == CLASS_MECH ||
					MechType(mech) == CLASS_MW ||
					MechType(mech) == CLASS_BSUIT);

	if(arc & FORWARDARC)
		strcpy(buf, "Forward");
	else if(arc & RSIDEARC)
		strcpy(buf, mechlike ? "Right Arm" : "Right Side");
	else if(arc & LSIDEARC)
		strcpy(buf, mechlike ? "Left Arm" : "Left Side");
	else if(arc & REARARC)
		strcpy(buf, "Rear");
	else
		strcpy(buf, "NO");

	return buf;
}

const char *GetMechToMechID_base(MECH * see, MECH * mech, int inlos)
{
	char *mname;
	static char ids[SBUF_SIZE];

	if(!Good_obj(mech->mynum))
		return "";

	if(!inlos)
		mname = "something";
	else
		mname = silly_atr_get(mech->mynum, A_MECHNAME);

	snprintf(ids, SBUF_SIZE, "%s [%s]", mname, MechIDS(mech, inlos &&
													   MechTeam(see) ==
													   MechTeam(mech)));
	ids[SBUF_SIZE - 1] = '\0';
	return ids;
}

const char *GetMechToMechID(MECH * see, MECH * mech)
{
	char *mname;
	int team;
	static char ids[SBUF_SIZE];

	if(!mech ) {
		dprintk("bad mech");
		return "";
	}
	if(!see ) {
		dprintk("bad see");
		return "";
	}
	if(!Good_obj(mech->mynum))
		return "";

	if(!InLineOfSight_NB(see, mech, 0, 0, 0)) {
		mname = "something";
		team = 0;
	} else {
		mname = silly_atr_get(mech->mynum, A_MECHNAME);
		team = (MechTeam(see) == MechTeam(mech));
	}

	snprintf(ids, SBUF_SIZE, "%s [%s]", mname, MechIDS(mech, team));
	ids[SBUF_SIZE - 1] = '\0';
	return ids;
}

const char *GetMechID(MECH * mech)
{
	char *mname;
	static char ids[SBUF_SIZE];

	if(!Good_obj(mech->mynum))
		return "";

	mname = silly_atr_get(mech->mynum, A_MECHNAME);
	snprintf(ids, SBUF_SIZE, "%s [%s]", mname, MechIDS(mech, 0));
	ids[SBUF_SIZE - 1] = '\0';
	return ids;
}

void mech_set_channelfreq(dbref player, void *data, char *buffer)
{
	int chn = -1;
	int freq;
	MECH *mech = (MECH *) data;
	MECH *t;
	// map pointer is NULL if in a carrier. Careful.
	MAP *map = getMap(mech->mapindex);
	int i, j;

	/* UH, this is code that _pretends_ it works :-) */
	skipws(buffer);
	DOCHECK(!*buffer, "Invalid input!");
	chn = toupper(*buffer) - 'A';
	DOCHECK(chn < 0 || chn >= MFreqs(mech), "Invalid channel-letter!");
	buffer++;
	skipws(buffer);
	DOCHECK(!*buffer, "Invalid input!");
	DOCHECK(*buffer != '=', "Missing =!");
	buffer++;
	skipws(buffer);
	DOCHECK(!*buffer, "Invalid input!");
	freq = atoi(buffer);
	DOCHECK(!freq && strcmp(buffer, "0"), "Invalid frequency!");
	DOCHECK(freq < 0, "Are you trying to kid me?");
	DOCHECK(freq > 999999, "Invalid frequency - range is from 0 to 999999.");
	notify_printf(player, "Channel %c set to %d.", 'A' + chn, freq);
	mech->freq[chn] = freq;

	/* Code added from Exile to check for possible cheat freq acquring.
	 * When a player sets a freq, it loops through all the mechs on the
	 * map that do not belong to the same team and checks their freqs
	 * against the one set. If it matches it emits message
	 */
	if(freq > 0 && map) {
		for(i = 0; i < map->first_free; i++) {
			if(!(t = FindObjectsData(map->mechsOnMap[i])))
				continue;
			if(t == mech)
				continue;
			if(MechTeam(t) == MechTeam(mech))
				continue;
			for(j = 0; j < MFreqs(t); j++) {
				if(t->freq[j] == freq && !(t->freqmodes[j] & FREQ_SCAN))
					SendFreqs(tprintf("ALERT: Possible abuse by #%d (Team %d)"
									  " setting freq %d matching #%d (Team %d)!",
									  mech->mynum, MechTeam(mech), freq,
									  t->mynum, MechTeam(t)));
			}
		}
	}

}

void mech_set_channeltitle(dbref player, void *data, char *buffer)
{
	int chn = -1;
	MECH *mech = (MECH *) data;

	skipws(buffer);
	DOCHECK(!*buffer, "Invalid input!");
	chn = toupper(*buffer) - 'A';
	DOCHECK(chn < 0 || chn >= MFreqs(mech), "Invalid channel-letter!");
	buffer++;
	skipws(buffer);
	DOCHECK(!*buffer, "Invalid input!");
	DOCHECK(*buffer != '=', "Missing =!");
	buffer++;
	skipws(buffer);
	if(!*buffer) {
		mech->chantitle[chn][0] = 0;
		notify_printf(player, "Channel %c title cleared.", 'A' + chn);
		return;
	}
	strncpy(mech->chantitle[chn], buffer, CHTITLELEN);
	mech->chantitle[chn][CHTITLELEN] = 0;
	notify_printf(player, "Channel %c title set to set to %s.", 'A' + chn,
				  buffer);
}

/*                    1234567890123456 */
const char radio_colorstr[] = "xrgybmcwXRGYBMCW";

static char *ccode(MECH * m, int i, int obs, int team)
{
	int t = m->freqmodes[i] / FREQ_REST;
	static char buf[7];
	int ii;

	if(!obs) {
		if(!t) {
			strcpy(buf, "");
			return buf;
		};
		if(t < 9) {
			sprintf(buf, "%%c%c", radio_colorstr[t - 1]);
			return buf;
		}
		sprintf(buf, "%%ch%%c%c", ToLower(radio_colorstr[t - 1]));
	} else {
		// Observation lounges colorize based on team number.
		if (team > 15)
			team = team % 15;
		for(ii = 0; ii < 15; ii++) {
			if(team == obs_team_color[ii].team)
				sprintf(buf, "%s", obs_team_color[ii].ccode);
		}
		if(buf == NULL)
			sprintf(buf, "%s", obs_team_color[0].ccode);
	}
	return buf;
}

void mech_set_channelmode(dbref player, void *data, char *buffer)
{
	int chn = -1, nm = 0, i;
	MECH *mech = (MECH *) data;
	char buf[SBUF_SIZE];

	skipws(buffer);
	DOCHECK(!*buffer, "Invalid input!");
	chn = toupper(*buffer) - 'A';
	DOCHECK(chn < 0 || chn >= MFreqs(mech), "Invalid channel-letter!");
	buffer++;
	skipws(buffer);
	DOCHECK(!*buffer, "Invalid input!");
	DOCHECK(*buffer != '=', "Missing =!");
	buffer++;
	skipws(buffer);
	if(!buffer || !*buffer) {
		mech->freqmodes[chn] = 0;
		notify_printf(player, "Channel %c <send> flags cleared.", 'A' + chn);
		return;
	}
	while (buffer && *buffer) {
		switch (*buffer) {
		case 'd':
		case 'D':
			// This used to be the digital flag, but it's always digital now.
			break;
		case 'U':
		case 'u':
			nm |= FREQ_MUTE;
			break;
		default:
			for(i = 0; radio_colorstr[i]; i++)
				if(*buffer == radio_colorstr[i]) {
					nm = nm % FREQ_REST + FREQ_REST * (i + 1);
					break;
				}
			if(!radio_colorstr[i])
				buffer = NULL;
			break;
		}
		if(buffer)
			buffer++;
	}

	mech->freqmodes[chn] = nm;
	i = 0;

	if(nm & FREQ_INFO)
		buf[i++] = 'I';
	if(nm & FREQ_MUTE)
		buf[i++] = 'U';
	if(!i)
		buf[i++] = '-';
	if(nm / FREQ_REST) {
		sprintf(buf + i, "/color:%c", radio_colorstr[nm / FREQ_REST - 1]);
		i = strlen(buf);
	}
	buf[i] = 0;
	notify_printf(
		player, "Channel %c <send> flags set (%s).", 'A' + chn, buf);
}

void mech_list_freqs(dbref player, void *data, char *buffer)
{
	int i;
	MECH *mech = (MECH *) data;

	/* UH, this is code that _pretends_ it works :-) */
	notify(player, "# -- Mode -- Frequency -- Comtitle");
	for(i = 0; i < MFreqs(mech); i++)
		notify_printf(player, "%c    %c%c%c%c    %-9d    %s", 'A' + i,
					  // used to be digital bit
					  'D',
					  // used to be relay bit
					  '-',
					  mech->freqmodes[i] & FREQ_MUTE ? 'M' : '-',
					  mech->freqmodes[i] >= FREQ_REST ?
					  radio_colorstr[mech->freqmodes[i] / FREQ_REST - 1] :
					  '-',
					  mech->freq[i], mech->chantitle[i]);
}

void mech_sendchannel(dbref player, void *data, char *buffer)
{
	/* Basically, this is sorta routine 'sendchannel <letter>=message' code */
	MECH *mech = (MECH *) data;
	int fail = 0;
	int argc;
	int chn = 0;
	char *args[3];
	int i;

	cch(MECH_USUALS);
	DOCHECK(Destroyed(mech) ||
			!MechRadioRange(mech), "Your communication gear is inoperative.");
	DOCHECK(CrewStunned(mech), "You are too stunned to use the radio!");
	if((argc = proper_parseattributes(buffer, args, 3)) != 3)
		fail = 1;
	if(!fail && strlen(args[0]) > 1)
		fail = 1;
	if(!fail && args[0][0] >= 'a' && args[0][0] <= 'z')
		chn = args[0][0] - 'a';
	if(!fail && args[0][0] >= 'A' && args[0][0] <= 'Z')
		chn = args[0][0] - 'Z';
	if(!fail && (chn >= MFreqs(mech) || chn < 0))
		fail = 1;
	if(!fail)
		for(i = 0; args[2][i]; i++) {
			if((BOUNDED(32, args[2][i], 255)) != args[2][i]) {
				notify(player,
					   "Invalid: No control characters in radio messages, please.");
				for(i = 0; i < 3; i++) {
					if(args[i])
						free(args[i]);
				}
				return;
			}
		}

	if(fail) {
		notify(player,
			   "Invalid format! Usage: sendchannel <letter>=<string>");
		for(i = 0; i < 3; i++) {
			if(args[i])
				free(args[i]);
		}
		return;
	}

	if(mech->freq[chn] == 0 && In_Character(mech->mapindex)) {
		send_channel("ZeroFrequencies",
					 "Player #%d (%s) in mech #%d (channel %c) "
					 "on map #%d 0-freqs \"%s\"", player, Name(player),
					 mech->mynum, chn + 'A', mech->mapindex, args[2]);
	}

	sendchannelstuff(mech, chn, args[2]);
	for(i = 0; i < 3; i++) {
		if(args[i])
			free(args[i]);
	}
	explode_mines(mech, mech->freq[chn]);
}


/*
 * This doesn't actually scramble anymore, but it did a bit more than just
 * scrambling before. We'll leave it here since I can't be arsed to clean this.
 */
void set_radio_message_prefix(char *buffo, char *handle, char *msg)
{

	char *header = NULL;
	char buf[LBUF_SIZE];

	if(handle && *handle)
		snprintf(buffo, LBUF_SIZE, "%s<%s> %s", header ? header : "", handle,
				 msg);
	else
		snprintf(buffo, LBUF_SIZE, "%s%s", header ? header : "", msg);

}

int common_checks(dbref player, MECH * mech, int flag)
{
	MAP *mech_map;

	if(!mech)
		return 0;

	if((flag & MECH_CONSISTENT) && !CheckData(player, mech))
		return 0;

	MechLastUse(mech) = 0;

	if(flag & MECH_STARTED) {
		DOCHECK0(Destroyed(mech), "You are destroyed!");
		DOCHECK0(!(MechStatus(mech) & STARTED), "Reactor is not online!");
	}

	if(flag & MECH_PILOT) {
		DOCHECK0(Blinded(mech), "You are momentarily blinded!");
	}

	if(flag & MECH_PILOT_CON)
		DOCHECK0(Uncon(mech) && (!Started(mech) ||
								 player == MechPilot(mech)),
				 "You are unconscious....zzzzzzz");

	if(flag & MECH_PILOTONLY)
		DOCHECK0(!Wizard(player) && In_Character(mech->mynum) &&
				 MechPilot(mech) != player,
				 "Now now, only the pilot can push that button.");

	if(flag & MECH_MAP) {
		DOCHECK0(mech->mapindex < 0, "You are on no map!");
		mech_map = getMap(mech->mapindex);
		if(!mech_map) {
			notify(player, "You are on an invalid map! Map index reset!");
			mech_shutdown(player, (void *) mech, "");
			mech->mapindex = -1;
			return 0;
		}
	}
	return 1;
}


/* The code that does the actual sending of radio messages whenever
 * someone speaks on a given frequency */
void sendchannelstuff(MECH * mech, int freq, char *msg)
{
	/* The _smart_ code :-) */
	int loop, range, bearing, i, isxp;
	MECH *tempMech;
	MAP *mech_map = getMap(mech->mapindex);
	char buf[LBUF_SIZE];
	char buf2[LBUF_SIZE];
	char buf3[LBUF_SIZE];
	int sfail_type, sfail_mod;
	int rfail_type, rfail_mod;
	int obs = 0;

	char ai_buf[LBUF_SIZE];

	/* Removed the Radio Failing stuff cause it annoys me - Dany
	   CheckGenericFail(mech, -2, &sfail_type, &sfail_mod);
	 */
	if(!MechRadioRange(mech))
		return;

	/* Loop through all the units on the map */
	for(loop = 0; loop < mech_map->first_free; loop++) {
		if(mech_map->mechsOnMap[loop] != 2) {
			// XXX: The test below is indicative of very bad bookkeeping. Suggesting
			// that a dbref may be indicated as "on the map" without being on the map.
			// I believe this to be a serious problem.
			if(!
			   (tempMech =
				(MECH *) FindObjectsData(mech_map->mechsOnMap[loop])))
				continue;
			if(Destroyed(tempMech))
				continue;
			obs = (MechCritStatus(tempMech) & OBSERVATORIC);
			range = FaMechRange(mech, tempMech);
			bearing = FindBearing(
				MechFX(tempMech), MechFY(tempMech),
				MechFX(mech), MechFY(mech)
			);

			// Make sure the mech has a freq match.
			for(i = 0; i < MFreqs(tempMech); i++) {
				if(tempMech->freq[i] == mech->freq[freq] || obs) {
					if(tempMech->freqmodes[i] & FREQ_MUTE)
						// Mute mode on, this channel should be ignored.
						continue;
					break;
				}
			}

			strncpy(buf2, msg, LBUF_SIZE);

			/* Let's just do the OBSERVERIC Stuff here. No sense checking
			 * elsewhere. We'll compose the message and send it now since
			 * it should technically hear everything */

			if(obs) {
				snprintf(buf, LBUF_SIZE, "%s[%c:%d] <%s:%s:%d> <%s> %s%%c",
						 ccode(tempMech, i, obs, MechTeam(mech)),
						 (char) ('A' + i), bearing,
						 silly_atr_get(mech->mynum, A_FACTION),
						 MechIDS(mech, 0), mech->freq[freq], mech->chantitle[freq],buf2);
				mech_notify(tempMech, MECHALL, buf);
			}

			/* This is where we check to see if the mech has an AI and
			 * then we give the radio commands to the AI */
			if(MechAuto(tempMech) > 0 && tempMech->freq[i]) {
				AUTO *a = (AUTO *) FindObjectsData(MechAuto(tempMech));

				/* First check to make sure the AI is still there */
				if(!a) {
					/* No AI there so reset the AI value on the mech */
					MechAuto(tempMech) = -1;
				} else if(a && Location(a->mynum) != tempMech->mynum) {
					/* Check to see if the AI is still in the same mech */
					snprintf(ai_buf, LBUF_SIZE,
							 "Autopilot #%ld (Location: #%ld) "
							 "reported on Mech #%ld but not in the proper location",
							 a->mynum, Location(a->mynum), tempMech->mynum);
					SendAI(ai_buf);
				} else if(a) {
					/* Ok send the command to the AI, even if ECM'd */
					strncpy(buf3, msg, LBUF_SIZE);
					auto_parse_command(a, tempMech, i, buf3);
				}
			}

			if(!MechRadioRange(tempMech))
				continue;

			set_radio_message_prefix(buf3, mech->chantitle[freq], buf2);

			if(!obs) {
				snprintf(buf, LBUF_SIZE, "%s[%c:%.3d] %s%%c",
						 ccode(tempMech, i, obs, MechTeam(mech)),
						 (char) ('A' + i), bearing, buf3);
				mech_notify(tempMech, MECHALL, buf);
			}

		}
	} /* End of looping through all the units on the map */
}

/*
 * Sends a LoS radio message via laser comms.
 */
void mech_radio(dbref player, void *data, char *buffer)
{
	int argc;
	int fail = 0;
	char *args[3];
	int i;
	MECH *mech = (MECH *) data;
	dbref target;
	MECH *tempMech;

	/* radio <id>=message */
	/* Quick clone :-) */
	/* This is silly, but who cares. */
	cch(MECH_USUAL);

	DOCHECK(MechIsObservator(mech), "You can't radio anyone.");
	if((argc = proper_parseattributes(buffer, args, 3)) != 3)
		fail = 1;
	if(!fail && (!args[1] || args[1][0] != '=' || args[1][1] != 0))
		fail = 1;
	if(!fail && (!args[0] || args[0][0] == 0 || args[0][1] == 0 ||
				 args[0][2] != 0))
		fail = 1;
	if(!fail) {
		target = FindTargetDBREFFromMapNumber(mech, args[0]);
		tempMech = getMech(target);
		DOCHECK(!tempMech ||
				!InLineOfSight(mech, tempMech, MechX(tempMech),
							   MechY(tempMech), FlMechRange(map, mech,
															tempMech)),
				"Target is not in line of sight!");
		mech_printf(mech, MECHSTARTED, "You radio %s with, '%s'",
					GetMechToMechID(mech, tempMech), args[2]);
		mech_printf(tempMech, MECHSTARTED, "%s radios you with, '%s'",
					GetMechToMechID(tempMech, mech), args[2]);
		auto_reply(tempMech,
				   tprintf("%s radio'ed me '%s'",
						   GetMechToMechID(tempMech, mech), args[2]));
	}
	DOCHECK(fail, "Invalid format! Usage: radio <letter><letter>=<message>");
	for(i = 0; i < 3; i++) {
		if(args[i])
			free(args[i]);
	}
}

int MapLimitedBroadcast2d(MAP * map, float x, float y, float range,
						  char *message)
{
	int loop, count = 0;
	MECH *mech;

	for(loop = 0; loop < map->first_free; loop++) {
		if(map->mechsOnMap[loop] < 0)
			continue;
		mech = getMech(map->mechsOnMap[loop]);

		if(mech && FindXYRange(x, y, MechFX(mech), MechFY(mech)) <= range) {
			mech_notify(mech, MECHSTARTED, message);
			count++;
		}
	}
	return count;
}

int MapLimitedBroadcast3d(MAP * map, float x, float y, float z, float range,
						  char *message)
{
	int loop, count = 0;
	MECH *mech;

	for(loop = 0; loop < map->first_free; loop++) {
		if(map->mechsOnMap[loop] == -1)
			continue;
		mech = getMech(map->mechsOnMap[loop]);
		if(mech
		   && FindRange(x, y, z, MechFX(mech), MechFY(mech),
						MechFZ(mech)) <= range) {
			count++;
			mech_notify(mech, MECHSTARTED, message);
		}
	}
	return count;
}

void MechBroadcast(MECH * mech, MECH * target, MAP * mech_map, char *buffer)
{
	int loop;
	MECH *tempMech;

	if(target) {
		for(loop = 0; loop < mech_map->first_free; loop++) {
			if(mech_map->mechsOnMap[loop] != mech->mynum &&
			   mech_map->mechsOnMap[loop] != -1 &&
			   mech_map->mechsOnMap[loop] != target->mynum) {
				tempMech = (MECH *)
					FindObjectsData(mech_map->mechsOnMap[loop]);
				if(tempMech)
					mech_notify(tempMech, MECHSTARTED, buffer);
			}
		}
	} else {
		for(loop = 0; loop < mech_map->first_free; loop++) {
			if(mech_map->mechsOnMap[loop] != mech->mynum &&
			   mech_map->mechsOnMap[loop] != -1) {
				tempMech = (MECH *)
					FindObjectsData(mech_map->mechsOnMap[loop]);
				if(tempMech)
					mech_notify(tempMech, MECHSTARTED, buffer);
			}
		}
	}
}

void MechLOSBroadcast(MECH * mech, char *message)
{
	/* Sends msg to everyone except the mech */
	int i;
	MECH *tempMech;
	MAP *mech_map = getMap(mech->mapindex);
	char buf[LBUF_SIZE];

	possibly_see_mech(mech);
	if(!mech_map)
		return;
	for(i = 0; i < mech_map->first_free; i++)
		if(mech_map->mechsOnMap[i] != -1 &&
		   mech_map->mechsOnMap[i] != mech->mynum)
			if((tempMech = getMech(mech_map->mechsOnMap[i])))
				if(InLineOfSight(tempMech, mech, MechX(mech), MechY(mech),
								 FlMechRange(mech_map, tempMech, mech))) {
					sprintf(buf, "%s%s%s", GetMechToMechID(tempMech, mech),
							*message != '\'' ? " " : "", message);
					mech_notify(tempMech, MECHSTARTED, buf);
				}
}

int MechSeesHexF(MECH * mech, MAP * map, float x, float y, int ix, int iy)
{
	return (InLineOfSight(mech, NULL, ix, iy, FindRange(MechFX(mech),
														MechFY(mech),
														MechFZ(mech), x, y,
														ZSCALE *
														Elevation(map, ix,
																  iy))));
}

int MechSeesHex(MECH * mech, MAP * map, int x, int y)
{
	float fx, fy;

	MapCoordToRealCoord(x, y, &fx, &fy);
	return MechSeesHexF(mech, map, fx, fy, x, y);
}

void HexLOSBroadcast(MAP * mech_map, int x, int y, char *message)
{
	int i;
	MECH *tempMech;
	float fx, fy;

	/* substitution:
	   $h = !alarming ('your hex', '%d,%d')
	   $H = alarming ('YOUR HEX', '%d,%d (%.2f away)')
	 */
	if(!mech_map)
		return;
	MapCoordToRealCoord(x, y, &fx, &fy);
	for(i = 0; i < mech_map->first_free; i++)
		if(mech_map->mechsOnMap[i] != -1)
			if((tempMech = getMech(mech_map->mechsOnMap[i])))
				if(MechSeesHexF(tempMech, mech_map, fx, fy, x, y)) {
					char tbuf[LBUF_SIZE];
					char *c, *d = tbuf;
					int done;

					for(c = message; *c; c++) {
						done = 0;
						if(*c == '$') {
							if(*(c + 1) == 'h' || *(c + 1) == 'H') {
								c++;
								if(*c == 'h') {
									if(x == MechX(tempMech) &&
									   y == MechY(tempMech))
										strcpy(d, "your hex");
									else
										sprintf(d, "%d,%d", x, y);
									while (*d)
										d++;
								} else {
									/* Dangerous */
									if(x == MechX(tempMech) &&
									   y == MechY(tempMech))
										strcpy(d, "%ch%crYOUR HEX%cn");
									else
										sprintf(d, "%%ch%%cy%d,%d%%cn", x, y);
									while (*d)
										d++;
								}
								done = 1;
							}
						}
						if(!done)
							*(d++) = *c;
					}
					/* Apparently, it's necessary to remove trailing $'s ?? */
					if(*(d - 1) == '$')
						d--;
					*d = '\0';
					mech_notify(tempMech, MECHSTARTED, tbuf);
				}
}

void MechLOSBroadcasti(MECH * mech, MECH * target, char *message)
{
	/* Sends msg to everyone except the mech */
	int i, a, b;
	char oddbuff[LBUF_SIZE];
	char oddbuff2[LBUF_SIZE];
	MECH *tempMech;
	MAP *mech_map = getMap(mech->mapindex);

	if(!mech_map)
		return;
	possibly_see_mech(mech);
	possibly_see_mech(target);
	for(i = 0; i < mech_map->first_free; i++)
		if(mech_map->mechsOnMap[i] != -1 &&
		   mech_map->mechsOnMap[i] != mech->mynum &&
		   mech_map->mechsOnMap[i] != target->mynum)
			if((tempMech = getMech(mech_map->mechsOnMap[i]))) {
				a = InLineOfSight(tempMech, mech, MechX(mech), MechY(mech),
								  FlMechRange(mech_map, tempMech, mech));
				b = InLineOfSight(tempMech, target, MechX(target),
								  MechY(target), FlMechRange(mech_map,
															 tempMech,
															 target));
				if(a || b) {
					sprintf(oddbuff, message, b ? GetMechToMechID(tempMech,
																  target) :
							"someone");
					sprintf(oddbuff2, "%s%s%s",
							a ? GetMechToMechID(tempMech, mech) : "Someone",
							*oddbuff != '\'' ? " " : "", oddbuff);
					mech_notify(tempMech, MECHSTARTED, oddbuff2);
				}
			}
}

void MapBroadcast(MAP * map, char *message)
{
	/* Sends msg to everyone except the mech */
	int i;
	MECH *tempMech;

	for(i = 0; i < map->first_free; i++)
		if(map->mechsOnMap[i] != -1)
			if((tempMech = getMech(map->mechsOnMap[i])))
				mech_notify(tempMech, MECHSTARTED, message);
}

void MechFireBroadcast(MECH * mech, MECH * target, int x, int y,
					   MAP * mech_map, char *weapname, int IsHit)
{
	int loop, attacker, defender;
	float fx, fy, fz;
	int mapx, mapy;
	MECH *tempMech;
	char buff[SBUF_SIZE];

/* Stat recording */
	if(target) { /* only if we have a mecha */
		if(IsHit)
			MechShotsHit(mech)++;
		else
			MechShotsMissed(mech)++;
	}

	possibly_see_mech(mech);
	if(target) {
		possibly_see_mech(target);
		mapx = MechX(target);
		mapy = MechY(target);
		fx = MechFX(target);
		fy = MechFY(target);
		fz = MechFZ(target);
		for(loop = 0; loop < mech_map->first_free; loop++)
			if(mech_map->mechsOnMap[loop] != mech->mynum &&
			   mech_map->mechsOnMap[loop] != -1 &&
			   mech_map->mechsOnMap[loop] != target->mynum) {
				attacker = 0;
				defender = 0;
				tempMech = (MECH *)
					FindObjectsData(mech_map->mechsOnMap[loop]);
				if(!tempMech)
					continue;
				if(InLineOfSight(tempMech, mech, MechX(mech), MechY(mech),
								 FlMechRange(mech_map, tempMech, mech)))
					attacker = 1;
				if(target) {
					if(InLineOfSight(tempMech, target, mapx, mapy,
									 FlMechRange(mech_map, tempMech, target)))
						defender = 1;
				} else if(InLineOfSight(tempMech, target, mapx, mapy,
										FindRange(MechFX(tempMech),
												  MechFY(tempMech),
												  MechFZ(tempMech), fx, fy,
												  fz)))
					defender = 1;

				if(!attacker && !defender)
					continue;
				if(defender)
					sprintf(buff, "%s", GetMechToMechID(tempMech, target));
				if(attacker) {
					if(defender)
						mech_printf(tempMech, MECHSTARTED,
									"%s %s %s with a %s",
									GetMechToMechID(tempMech, mech),
									IsHit ? "hits" : "misses", buff,
									weapname);
					else
						mech_printf(tempMech, MECHSTARTED,
									"%s fires a %s at something!",
									GetMechToMechID(tempMech, mech),
									weapname);
				} else
					mech_printf(tempMech, MECHSTARTED,
								"Something %s %s with a %s",
								IsHit ? "hits" : "misses", buff, weapname);
			}
	} else {
		mapx = x;
		mapy = y;
		MapCoordToRealCoord(x, y, &fx, &fy);
		fz = ZSCALE * Elevation(mech_map, x, y);
		sprintf(buff, "hex %d %d!", mapx, mapy);
		for(loop = 0; loop < mech_map->first_free; loop++)
			if(mech_map->mechsOnMap[loop] != mech->mynum &&
			   mech_map->mechsOnMap[loop] != -1) {
				attacker = 0;
				defender = 0;
				tempMech = (MECH *)
					FindObjectsData(mech_map->mechsOnMap[loop]);
				if(!tempMech)
					continue;
				if(InLineOfSight(tempMech, mech, MechX(mech), MechY(mech),
								 FlMechRange(mech_map, tempMech, mech)))
					attacker = 1;
				if(target) {
					if(InLineOfSight(tempMech, target, mapx, mapy,
									 FlMechRange(mech_map, tempMech, target)))
						defender = 1;
				} else if(InLineOfSight(tempMech, target, mapx, mapy,
										FindRange(MechFX(tempMech),
												  MechFY(tempMech),
												  MechFZ(tempMech), fx, fy,
												  fz)))
					defender = 1;
				if(!attacker && !defender)
					continue;
				if(attacker) {
					if(defender)	/* att + def */
						mech_printf(tempMech, MECHSTARTED,
									"%s fires a %s at %s",
									GetMechToMechID(tempMech, mech), weapname,
									buff);
					else		/* att */
						mech_printf(tempMech, MECHSTARTED,
									"%s fires a %s at something!",
									GetMechToMechID(tempMech, mech),
									weapname);
				} else			/* def */
					mech_printf(tempMech, MECHSTARTED,
								"Something fires a %s at %s", weapname, buff);
			}
	}
}

extern int arc_override;

void mech_notify(MECH * mech, int type, char *buffer)
{
	int i;

	if(Uncon(mech))
		return;
	if(Blinded(mech))
		return;
	if(mech->mynum < 0)
		return;
	/* Let's do colorization too, just in case. */

	if(type == MECHPILOT) {
		if(GotPilot(mech))
			notify(MechPilot(mech), buffer);
		else
			mech_notify(mech, MECHALL, buffer);
	} else if((type == MECHALL && !Destroyed(mech)) ||
			  (type == MECHSTARTED && Started(mech))) {
		notify_except(mech->mynum, NOSLAVE, mech->mynum, buffer);
		if(arc_override)
			for(i = 0; i < NUM_TURRETS; i++)
				if(AeroTurret(mech, i) > 0)
					notify_except(AeroTurret(mech, i), NOSLAVE,
								  AeroTurret(mech, i), buffer);
	}
}

void mech_printf(MECH * mech, int type, char *format, ...)
{
	char buffer[LBUF_SIZE];
	int i;
	va_list ap;

	if(Uncon(mech))
		return;
	if(Blinded(mech))
		return;
	if(mech->mynum < 0)
		return;
	/* Let's do colorization too, just in case. */

	va_start(ap, format);
	vsnprintf(buffer, LBUF_SIZE, format, ap);
	va_end(ap);

	if(type == MECHPILOT) {
		if(GotPilot(mech))
			notify(MechPilot(mech), buffer);
		else
			mech_notify(mech, MECHALL, buffer);
	} else if((type == MECHALL && !Destroyed(mech)) ||
			  (type == MECHSTARTED && Started(mech))) {
		notify_except(mech->mynum, NOSLAVE, mech->mynum, buffer);
		if(arc_override)
			for(i = 0; i < NUM_TURRETS; i++)
				if(AeroTurret(mech, i) > 0)
					notify_except(AeroTurret(mech, i), NOSLAVE,
								  AeroTurret(mech, i), buffer);
	}
}
