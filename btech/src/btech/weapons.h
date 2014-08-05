/*
 * $Id: weapons.h,v 1.1.1.1 2005/01/11 21:18:33 kstevens Exp $
 *
 * Last modified: $Date: 2005/01/11 21:18:33 $
 *
 * Header file for weapons, includes specific featured lists.
 */

#ifdef BT_USE_VRT
#include "weapons.vrt.h"
#else
#include "weapons.fasa.h"
#endif

struct weapon_struct MechWeapons[] = {

/* Clan Normal AC's. Couldn't find a reference for these anywhere. -- 02/13/07 Power_Shaper */
/*
    {"CL.AC/10", VRT_CL_AC10, TAMMO, 3, 10, 0, 5, 10, 15, 0, -1, -1, -1, 6,
	10, 1100, -1, CLAT | RFAC, 124},
    {"CL.AC/2", VRT_CL_AC2, TAMMO, 1, 2, 4, 8, 16, 24, 0, -1, -1, -1, 1,
	45, 500, -1, CLAT | RFAC, 37},
    {"CL.AC/20", VRT_CL_AC20, TAMMO, 7, 20, 0, 3, 6, 9, 0, -1, -1, -1, 9,
	5, 1300, -1, CLAT | RFAC, 178},
    {"CL.AC/5", VRT_CL_AC5, TAMMO, 1, 5, 3, 6, 12, 18, 0, -1, -1, -1, 3,
	20, 700, -1, CLAT | RFAC, 70}, 
*/

    {"CL.A-Pod", VRT_CL_APOD, TBEAM, 0, 0, 0, 1, 1, 1, 0, -1, -1, -1, 1, 0,
	50, -1, CLAT | A_POD, 1,1500,0,0},


    {"CL.StreakSRM-2", VRT_CL_SSRM2, TMISSILE, 2, 2, 0, 4, 8, 12, 0, -1,
	-1, -1, 1, 50, 100, -1, STREAK | CLAT | NOSPA, 40},
    {"CL.StreakSRM-4", VRT_CL_SSRM4, TMISSILE, 3, 2, 0, 4, 8, 12, 0, -1,
	-1, -1, 1, 25, 200, -1, STREAK | CLAT | NOSPA, 79},
    {"CL.StreakSRM-6", VRT_CL_SSRM6, TMISSILE, 4, 2, 0, 4, 8, 12, 0, -1,
	-1, -1, 2, 15, 300, -1, STREAK | CLAT | NOSPA, 119},
    {"IS.LongTom", VRT_IS_LONGTOM, TARTILLERY, 20, 20, 0, 0, 0, 20, 0, -1,
	-1, -1, 30, 5, 3000, -1, IDF | DAR, 171},
    {"PC.Blazer", VRT_PC_BLAZER, TAMMO, 0, 32, 0, 24, 48, 72, 0, -1, -1,
	-1, 1, 30, 0, -1, PC_HEAT, 1},
    {"PC.Crossbow", VRT_PC_BLAZER, TAMMO, 0, 9, 0, 9, 18, 27, 0, -1, -1,
	-1, 1, 20, 0, -1, PC_IMPA | NOBOOM, 1},
    {"PC.FederatedLongRifle", VRT_PC_FLRIFLE, TAMMO, 0, 9, 0, 22, 44, 66,
	0, -1, -1, -1, 1, 50, 0, -1, PC_IMPA, 1},
    {"PC.FlamerPistol", VRT_PC_FLAMER, TAMMO, 0, 7, 0, 4, 9, 13, 0, -1, -1,
	-1, 1, 50, 0, -1, PC_HEAT, 1},
    {"PC.GyroslugRifle", VRT_PC_GYROSLUG, TAMMO, 0, 14, 0, 30, 60, 90, 0,
	-1, -1, -1, 1, 15, 0, -1, PC_IMPA, 1},
    {"PC.HeavyGyrojetGun", VRT_PC_HGGUN, TAMMO, 0, 27, 0, 35, 70, 105, 0,
	-1, -1, -1, 1, 10, 0, -1, PC_IMPA, 1},
    {"PC.IntekLaserRifle", VRT_PC_ILRIFLE, TAMMO, 0, 9, 0, 40, 80, 120, 0,
	-1, -1, -1, 1, 45, 0, -1, PC_HEAT | NOBOOM, 1},
    {"PC.LaserRifle", VRT_PC_LRIFLE, TAMMO, 0, 17, 0, 24, 48, 72, 0, -1,
	-1, -1, 1, 30, 0, -1, PC_HEAT | NOBOOM, 1},
    {"PC.PulseLaserPistol", VRT_PC_PLPISTOL, TAMMO, 0, 11, 0, 5, 10, 15, 0,
	-1, -1, -1, 1, 50, 0, -1, PC_HEAT | NOBOOM, 1},
    {"PC.PulseLaserRifle", VRT_PC_PLRIFLE, TAMMO, 0, 13, 0, 22, 44, 66, 0,
	-1, -1, -1, 1, 30, 0, -1, PC_HEAT | NOBOOM, 1},
    {"PC.SMG", VRT_PC_SMG, TAMMO, 0, 10, 0, 7, 14, 20, 0, -1, -1, -1, 1,
	50, 0, -1, PC_IMPA, 1},
    {"PC.Shotgun", VRT_PC_SHOTGUN, TAMMO, 0, 12, 0, 6, 12, 18, 0, -1, -1,
	-1, 1, 10, 0, -1, PC_IMPA, 1},
    {"PC.SternsnachtPistol", VRT_PC_SPISTOL, TAMMO, 0, 16, 0, 7, 14, 20, 0,
	-1, -1, -1, 1, 50, 0, -1, PC_IMPA, 1},
    {"PC.SunbeamLaserPistol", VRT_PC_SLPISTOL, TAMMO, 0, 18, 0, 8, 16, 24,
	0, -1, -1, -1, 1, 50, 0, -1, PC_HEAT | NOBOOM, 1},
    {"PC.ZeusHeavyRifle", VRT_PC_ZHRIFLE, TAMMO, 0, 21, 0, 19, 38, 57, 0,
	-1, -1, -1, 1, 30, 0, -1, PC_IMPA, 1},

/* TacMunch stuff */

    {"IS.ELRM-5", VRT_IS_ELRM5, TMISSILE, 3, 1, 10, 12, 24, 36, 0, -1, -1,
	-1, 1, 18, 600, -1, IDF | ELRM | NOSPA, 67, 60000, 8, 35000},
    {"IS.ELRM-10", VRT_IS_ELRM10, TMISSILE, 6, 1, 10, 12, 24, 36, 0, -1,
	-1, -1, 4, 9, 800, -1, IDF | ELRM | NOSPA, 133, 200000, 17, 35000},
    {"IS.ELRM-15", VRT_IS_ELRM15, TMISSILE, 8, 1, 10, 12, 24, 36, 0, -1,
	-1, -1, 6, 6, 1200, -1, IDF | ELRM | NOSPA, 200, 350000, 25, 35000},
    {"IS.ELRM-20", VRT_IS_ELRM20, TMISSILE, 10, 1, 10, 12, 24, 36, 0, -1,
	-1, -1, 8, 4, 1800, -1, IDF | ELRM | NOSPA, 268, 500000, 34, 35000},
    {"IS.LR_DFM-5", VRT_IS_LR_DFM5, TMISSILE, 2, 2, 4, 6, 12, 18, 0, -1,
	-1, -1, 1, 24, 200, -1, IDF | DFM | NOSPA, 1000},
    {"IS.LR_DFM-10", VRT_IS_LR_DFM10, TMISSILE, 4, 2, 4, 6, 12, 18, 0, -1,
	-1, -1, 2, 12, 500, -1, IDF | DFM | NOSPA, 1000},
    {"IS.LR_DFM-15", VRT_IS_LR_DFM15, TMISSILE, 5, 2, 4, 6, 12, 18, 0, -1,
	-1, -1, 3, 8, 700, -1, IDF | DFM | NOSPA, 1000},
    {"IS.LR_DFM-20", VRT_IS_LR_DFM20, TMISSILE, 6, 2, 4, 6, 12, 18, 0, -1,
	-1, -1, 5, 6, 1000, -1, IDF | DFM | NOSPA, 1000},
    {"IS.SR_DFM-2", VRT_IS_SR_DFM2, TMISSILE, 2, 3, 0, 2, 4, 6, 0, -1, -1,
	-1, 1, 50, 100, -1, DFM | NOSPA, 1000},
    {"IS.SR_DFM-4", VRT_IS_SR_DFM4, TMISSILE, 3, 3, 0, 2, 4, 6, 0, -1, -1,
	-1, 1, 25, 200, -1, DFM | NOSPA, 1000},
    {"IS.SR_DFM-6", VRT_IS_SR_DFM6, TMISSILE, 4, 3, 0, 2, 4, 6, 0, -1, -1,
	-1, 2, 15, 300, -1, DFM | NOSPA, 1000},

/* Technically, we use ammo mode for these CASELESS weapons, so lets get them out of the DB */
//    {"IS.CaselessAC/2", VRT_IS_CAC2, TAMMO, 1, 2, 4, 8, 16, 24, 0, -1, -1,
//	-1, 1, 67, 600, -1, NOSPA | CASELESS, 1000},
//    {"IS.CaselessAC/5", VRT_IS_CAC5, TAMMO, 1, 5, 3, 6, 12, 18, 0, -1, -1,
//	-1, 4, 30, 800, -1, NOSPA | CASELESS, 1000},
//    {"IS.CaselessAC/10", VRT_IS_CAC10, TAMMO, 3, 10, 0, 5, 10, 15, 0, -1,
//	-1, -1, 6, 15, 1200, -1, NOSPA | CASELESS, 1000},
//    {"IS.CaselessAC/20", VRT_IS_CAC20, TAMMO, 7, 20, 0, 3, 6, 9, 9, 0, -1,
//	-1, -1, 8, 1400, -1, NOSPA | CASELESS, 1000},
/* End Caseless */

    {"IS.HyperAC/2", VRT_IS_HAC2, TAMMO, 1, 2, 3, 10, 20, 35, 0, -1, -1,
	-1, 4, 30, 800, -1, NOSPA | HYPER, 53, 100000, 7, 3000},
    {"IS.HyperAC/5", VRT_IS_HAC5, TAMMO, 3, 5, 0, 8, 16, 28, 0, -1, -1, -1,
	5, 15, 1200, -1, NOSPA | HYPER, 109, 160000, 14, 10000},
    {"IS.HyperAC/10", VRT_IS_HAC10, TAMMO, 7, 10, 0, 6, 12, 20, 0, -1, -1,
	-1, 6, 8, 1400, -1, NOSPA | HYPER, 158, 230000, 20, 20000},

/* .. normal cont'd ; energy weapons .. */

/* Clan Level 1/2 Energy Weapons -- Verified 9/21/11 -- Power_Shaper */
    {"CL.ERLargeLaser", VRT_CL_ERLL, TBEAM, 12, 10, 0, 8, 15, 25, 0, 5, 10,
	15, 1, 0, 400, -1, CLAT, 249, 200000, 0, 0},
    {"CL.ERMediumLaser", VRT_CL_ERML, TBEAM, 5, 7, 0, 5, 10, 15, 0, 3, 7,
	10, 1, 0, 100, -1, CLAT, 108, 80000, 0, 0},
    {"CL.ERSmallLaser", VRT_CL_ERSL, TBEAM, 2, 5, 0, 2, 4, 6, 0, 1, 2, 4,
        1, 0, 50, -1, CLAT, 31, 11250, 0, 0},
    {"CL.ERMicroLaser", VRT_CL_ERMICRO, TBEAM, 1, 2, 0, 1, 2, 4, 0, 1,
        2, 2, 1, 0, 25, -1, CLAT, 7, 10000, 0, 0},
    {"CL.ERPPC", VRT_CL_ERPPC, TBEAM, 15, 15, 0, 7, 14, 23, 0, 4, 10, 16,
	2, 0, 600, -1, CLAT, 412, 300000, 0, 0},
    {"CL.Flamer", VRT_CL_FLAMER, TBEAM, 3, 2, 0, 1, 2, 3, 0, -1, -1, -1, 1,
	0, 50, -1, CLAT | CHEAT, 6, 7500, 0, 0},
    {"CL.HeavyLargeLaser", VRT_CL_HLL, TBEAM, 18, 16, 0, 5, 10, 15, 0, 3,
	6, 9, 3, 0, 400, -1, CLAT | HVYW, 243, 250000, 0, 0},
    {"CL.HeavyMediumLaser", VRT_CL_HML, TBEAM, 7, 10, 0, 3, 6, 9, 0, 2, 4,
	6, 2, 0, 100, -1, CLAT | HVYW, 76, 100000, 0, 0},
    {"CL.HeavySmallLaser", VRT_CL_HSL, TBEAM, 3, 6, 0, 1, 2, 3, 0, 1, 2,
	-1, 1, 0, 50, -1, CLAT | HVYW, 15, 20000, 0, 0},
    {"CL.LargePulseLaser", VRT_CL_LPL, TBEAM, 10, 10, 0, 6, 14, 20, 0, 4,
	10, 14, 2, 0, 600, -1, PULSE | CLAT, 265, 175000, 0, 0},
    {"CL.MediumPulseLaser", VRT_CL_MPL, TBEAM, 4, 7, 0, 4, 8, 12, 0, 3, 5,
	8, 1, 0, 200, -1, PULSE | CLAT, 111, 60000, 0, 0},
    {"CL.SmallPulseLaser", VRT_CL_SPL, TBEAM, 2, 3, 0, 2, 4, 6, 0, 1, 2, 4,
	1, 0, 100, -1, PULSE | CLAT, 24, 16000, 0, 0},
    {"CL.MicroPulseLaser", VRT_CL_MICROPL, TBEAM, 1, 3, 0, 1, 2, 3, 0, 1,
            2, 2, 1, 0, 50, -1, PULSE | CLAT, 12, 12500, 0, 0},

/* Clan Level 3 Energy Weapons -- Verified 9/21/11 -- Power_Shaper */
/* Missing LaserAMS. Its in this table somewhere, but the rules aren't setup for it.
 * As well as Plasma Rifle, but that's a UK Weapon */
    {"CL.ERLargePulseLaser", VRT_CL_ERLPL, TBEAM, 13, 10, 0, 7, 15, 23, 0,
            4, 10, 16, 3, 0, 600, -1, PULSE | CLAT, 271, 400000, 0, 0},
    {"CL.ERMediumPulseLaser", VRT_CL_ERMPL, TBEAM, 6, 7, 0, 5, 9, 14, 0, 3,
            6, 8, 2, 0, 200, -1, PULSE | CLAT, 116, 150000, 0, 0},
    {"CL.ERSmallPulseLaser", VRT_CL_ERSPL, TBEAM, 3, 5, 0, 2, 4, 6, 0, 2,
            3, 4, 1, 0, 150, -1, PULSE | CLAT, 36, 30000, 0, 0},

/* Clan Level 1/2 Ballistic Weapons -- Verified 9/21/11 -- Power_Shaper */
/* Clan Vehicle Flamer Missing, but the same as IS Version in stats */
/* Missing Hyper Assault Gauss (HAG) Variants (15/20/40) + Rules */
/* Missing Light Machine Gun */
/* Missing Heavy Machine Gun */
/* Missing Sniper/Thumper Artillery. Maybe Same as IS version */
/* Rotary AC versions (UK) are L3 */
    {"CL.Anti-MissileSystem", VRT_CL_AMS, TMISSILE, 1, 2, 0, 1, 1, 1, 0,
            -1, -1, -1, 1, 24, 50, -1, CLAT | AMS, 63, 100000, 21, 2000},
    {"CL.GaussRifle", VRT_CL_GR, TAMMO, 1, 15, 2, 7, 15, 22, 0, -1, -1, -1,
            6, 8, 1200, 20, GAUSS | CLAT, 321, 300000, 33, 20000},
    {"CL.LB2-XAC", VRT_CL_LBX2, TAMMO, 1, 2, 4, 10, 20, 30, 0, -1, -1, -1,
            3, 45, 500, -1, LBX | CLAT, 47i, 150000, 6, 2000},
    {"CL.LB5-XAC", VRT_CL_LBX5, TAMMO, 1, 5, 3, 8, 15, 24, 0, -1, -1, -1,
            4, 20, 700, -1, LBX | CLAT, 93, 250000, 12, 9000},
    {"CL.LB10-XAC", VRT_CL_LBX10, TAMMO, 2, 10, 0, 6, 12, 18, 0, -1, -1,
            -1, 5, 10, 1000, -1, LBX | CLAT, 148, 400000, 19, 12000},
    {"CL.LB20-XAC", VRT_CL_LBX20, TAMMO, 6, 20, 0, 4, 8, 12, 0, -1, -1, -1,
            9, 5, 1200, -1, LBX | CLAT, 237, 600000, 33, 20000},
    {"CL.MachineGun", VRT_CL_MG, TAMMO, 0, 2, 0, 1, 2, 3, 0, -1, -1, -1, 1,
            200, 25, -1, CLAT | GMG, 5, 5000, 1, 1000},
    {"CL.LightMachineGun", VRT_CL_LMG, TAMMO, 0, 1, 0, 2, 4, 6, 0, -1, -1, -1, 1,
    	    200, 25, -1, CLAT | GMG, 5, 5000, 1, 500},  
    {"CL.HeavyMachineGun", VRT_CL_HMG, TAMMO, 0, 3, 0, 1, 2, 3, 0, -1, -1,
                -1, 1, 100, 50, -1, CLAT | GMG, 6, 7500, 1, 1000},
    {"CL.UltraAC/2", VRT_CL_UAC2, TAMMO, 1, 2, 2, 9, 18, 27, 0, -1, -1, -1,
            2, 45, 500, -1, ULTRA | CLAT, 62, 120000, 8, 1000},
    {"CL.UltraAC/5", VRT_CL_UAC5, TAMMO, 1, 5, 0, 7, 14, 21, 0, -1, -1, -1,
            3, 20, 700, -1, ULTRA | CLAT, 123, 200000, 15, 9000},
    {"CL.UltraAC/10", VRT_CL_UAC10, TAMMO, 3, 10, 0, 6, 12, 18, 0, -1, -1,
            -1, 4, 10, 1000, -1, ULTRA | CLAT, 211, 320000, 26, 12000},
    {"CL.UltraAC/20", VRT_CL_UAC20, TAMMO, 7, 20, 0, 4, 8, 12, 0, -1, -1,
            -1, 8, 5, 1200, -1, ULTRA | CLAT | SPLIT_CRITS, 337, 480000, 35, 20000},
    {"CL.ArrowIVSystem", VRT_CL_ARROWIV, TARTILLERY, 10, 20, 0, 0, 0, 6, 0,
            -1, -1, -1, 12, 5, 1200, -1, IDF | DAR | CLAT, 171, 450000, 11, 10000},

/* Clan Level 1/2 Missile Weapons -- Verified 9/21/11 -- Power_Shaper */
    {"CL.ATM-3", VRT_CL_ATM3, TMISSILE, 2, 2, 4, 5, 10, 15, 0, -1, -1,
        -1, 2, 20, 150, -1, IDF | CLAT, 53, 50000, 14, 75000},
    {"CL.ATM-6", VRT_CL_ATM6, TMISSILE, 4, 2, 4, 5, 10, 15, 0, -1, -1,
        -1, 3, 10, 350, -1, IDF | CLAT, 105, 125000, 26, 75000},
    {"CL.ATM-9", VRT_CL_ATM9, TMISSILE, 6, 2, 4, 5, 10, 15, 0, -1, -1,
        -1, 4, 7, 500, -1, IDF | CLAT, 147, 225000, 36, 75000},
    {"CL.ATM-12", VRT_CL_ATM12, TMISSILE, 8, 2, 4, 5, 10, 15, 0, -1, -1,
        -1, 5, 5, 700, -1, IDF | CLAT, 212, 350000, 54, 75000},
    {"CL.LRM-5", VRT_CL_LRM5, TMISSILE, 2, 1, 0, 7, 14, 21, 0, -1, -1, -1,
            1, 24, 100, -1, IDF | CLAT, 55, 30000, 7, 30000},
    {"CL.LRM-10", VRT_CL_LRM10, TMISSILE, 4, 1, 0, 7, 14, 21, 0, -1, -1,
            -1, 1, 12, 250, -1, IDF | CLAT, 109, 100000, 14, 30000},
    {"CL.LRM-15", VRT_CL_LRM15, TMISSILE, 5, 1, 0, 7, 14, 21, 0, -1, -1,
            -1, 2, 8, 350, -1, IDF | CLAT, 164, 175000, 21, 30000},
    {"CL.LRM-20", VRT_CL_LRM10, TMISSILE, 6, 1, 0, 7, 14, 21, 0, -1, -1,
            -1, 4, 6, 500, -1, IDF | CLAT, 220, 250000, 27, 30000},
    {"CL.NarcBeacon", VRT_CL_NARC, TMISSILE, 1, 4, 0, 4, 8, 12, 0, -1, -1,
            -1, 1, 6, 200, -1, NARC | CLAT, 30, 100000, 0, 6000},
    {"CL.SRM-2", VRT_CL_SRM2, TMISSILE, 2, 2, 0, 3, 6, 9, 0, -1, -1, -1, 1,
            50, 50, -1, CLAT, 21, 10000, 3, 27000},
    {"CL.SRM-4", VRT_CL_SRM4, TMISSILE, 3, 2, 0, 3, 6, 9, 0, -1, -1, -1, 1,
            25, 100, -1, CLAT, 39, 60000, 5, 27000},
    {"CL.SRM-6", VRT_CL_SRM6, TMISSILE, 4, 2, 0, 3, 6, 9, 0, -1, -1, -1, 1,
            15, 150, -1, CLAT, 59, 80000, 7, 27000},

/* Don't know why we have clan versions of these. Not used */
//    {"CL.LargeLaser", VRT_CL_LL, TBEAM, 8, 8, 0, 5, 10, 15, 0, 3, 6, 9, 1,
//          0, 400, -1, CLAT, 124},
//    {"CL.MediumLaser", VRT_CL_ML, TBEAM, 3, 5, 0, 3, 6, 9, 0, 2, 4, 6, 1,
//            0, 100, -1, CLAT, 46},
//    {"CL.PPC", VRT_CL_PPC, TBEAM, 10, 10, 3, 6, 12, 18, 3, 4, 7, 10, 2, 0,
//            600, -1, CLAT, 176},
//    {"CL.SmallLaser", VRT_CL_SL, TBEAM, 1, 3, 0, 1, 2, 3, 0, 1, 2, -1, 1,
//            0, 50, -1, CLAT, 9},

/* IS Level 1 Energy Weapons -- Verified 02/13/07 -- Power_Shaper */
    {"IS.PPC", VRT_IS_PPC, TBEAM, 10, 10, 3, 6, 12, 18, 3, 4, 7, 10, 3, 0,
        700, -1, NONE, 176, 200000, 0, 0},
    {"IS.LargeLaser", VRT_IS_LL, TBEAM, 8, 8, 0, 5, 10, 15, 0, 3, 6, 9, 2,
        0, 500, -1, NONE, 123, 100000, 0, 0},
    {"IS.MediumLaser", VRT_IS_ML, TBEAM, 3, 5, 0, 3, 6, 9, 0, 2, 4, 6, 1,
        0, 100, -1, NONE, 46, 40000, 0, 0},
    {"IS.SmallLaser", VRT_IS_SL, TBEAM, 1, 3, 0, 1, 2, 3, 0, 1, 2, -1, 1,
        0, 50, -1, NONE, 9, 11250, 0, 0},
    {"IS.Flamer", VRT_IS_FLAMER, TBEAM, 3, 2, 0, 1, 2, 3, 0, -1, -1, -1, 1,
    	0, 100, -1, CHEAT, 6, 7500, 0, 0},

/* IS Level 2 Energy Weapons -- Verified 02/13/07 -- Power_Shaper */
    {"IS.ERPPC", VRT_IS_ERPPC, TBEAM, 15, 10, 0, 7, 14, 23, 0, 4, 10, 16,
        3, 0, 700, -1, NONE, 229, 300000, 0, 0},
    {"IS.ERLargeLaser", VRT_IS_ERLL, TBEAM, 12, 8, 0, 7, 14, 19, 0, 3, 5,
        12, 2, 0, 500, -1, NONE, 163, 200000, 0, 0},
    {"IS.ERMediumLaser", VRT_IS_ERML, TBEAM, 5, 5, 0, 4, 8, 12, 0, 3, 5, 8,
        1, 0, 100, -1, NONE, 62, 80000, 0, 0},
    {"IS.ERSmallLaser", VRT_IS_ERSL, TBEAM, 2, 3, 0, 2, 4, 5, 0, 1, 2, 3,
        1, 0, 50, -1, NONE, 17, 11250, 0, 0},
    {"IS.LargePulseLaser", VRT_IS_LPL, TBEAM, 10, 9, 0, 3, 7, 10, 0, 2, 5,
        7, 2, 0, 700, -1, PULSE, 119, 175000, 0, 0},
    {"IS.MediumPulseLaser", VRT_IS_MPL, TBEAM, 4, 6, 0, 2, 4, 6, 0, 2, 3,
        4, 1, 0, 200, -1, PULSE, 48, 60000, 0, 0},
    {"IS.SmallPulseLaser", VRT_IS_SPL, TBEAM, 2, 3, 0, 1, 2, 3, 0, 1, 2,
        -1, 1, 0, 100, -1, PULSE, 12, 16000, 0, 0},
/* ERFlamer does half heat. Figure that out then add it here. */
/*
    {"IS.ERFlamer", VRT_IS_FLAMER, TBEAM, 4, 2, 0, 3, 5, 7, 0, -1, -1, -1, 1,
    	0, 100, -1, CHEAT, 16, 15000, 0, 0},
*/

/* IS Level 3 Energy Weapons -- Verified 02/13/07 -- Power_Shaper */
    {"IS.X-LargePulseLaser", VRT_IS_XLPL, TBEAM, 14, 9, 0, 5, 10, 15, 0, 3,
        6, 9, 2, 0, 700, -1, PULSE, 178, 275000, 0, 0},
    {"IS.X-MediumPulseLaser", VRT_IS_XMPL, TBEAM, 6, 6, 0, 3, 6, 9, 0, 2,
        4, 6, 1, 0, 200, -1, PULSE, 71, 110000, 0, 0},
    {"IS.X-SmallPulseLaser", VRT_IS_XSPL, TBEAM, 3, 3, 0, 2, 4, 5, 0, -1,
        -1, -1, 1, 0, 100, -1, PULSE, 21, 31000, 0, 0},
/* Missing PPC/ERPPC Capacitors */

/* IS Energy Weapons that are tech-level less as per Total Warfare */
    {"IS.SnubNosedPPC", VRT_IS_SNUBNOSEDPPC, TBEAM, 10, 10, 0, 9, 13, 15, 0, 6, 8, 9,
        2, 0, 600, -1, SNUBPPC, 165, 300000, 0, 0},
    {"IS.LightPPC", VRT_IS_LIGHTPPC, TBEAM, 5, 5, 3, 6, 12, 18, 3, 4, 8, 10,
        2, 0, 300, -1, NONE, 88, 150000, 0, 0},
    {"IS.HeavyPPC", VRT_IS_HEAVYPPC, TBEAM, 15, 15, 3, 6, 12, 18, 3, 4, 8, 10,
        4, 0, 1000, -1, NONE, 317, 250000, 0, 0},

/* IS Level 1 Ballistic Weapons -- Verified 02/13/07 -- Power_Shaper */
    {"IS.AC/2", VRT_IS_AC2, TAMMO, 1, 2, 4, 8, 16, 24, 0, -1, -1, -1, 1,
        45, 600, -1, RFAC, 37, 75000, 5, 1000},
    {"IS.AC/5", VRT_IS_AC5, TAMMO, 1, 5, 3, 6, 12, 18, 0, -1, -1, -1, 4,
        20, 800, -1, RFAC, 70, 125000, 9, 4500},
    {"IS.AC/10", VRT_IS_AC10, TAMMO, 3, 10, 0, 5, 10, 15, 0, -1, -1, -1, 7,
        10, 1200, -1, RFAC, 124, 200000, 15, 6000},
    {"IS.AC/20", VRT_IS_AC20, TAMMO, 7, 20, 0, 3, 6, 9, 0, -1, -1, -1, 10,
        5, 1400, -1, RFAC | SPLIT_CRITS, 178, 300000, 20, 10000},
    {"IS.VehicleFlamer", VRT_IS_VFLAMER, TAMMO, 3, 2, 0, 1, 2, 3, 0, -1, -1, -1, 1,
        20, 50, -1, CHEAT, 5, 7500, 1, 1000},
    {"IS.MachineGun", VRT_IS_MG, TAMMO, 0, 2, 0, 1, 2, 3, 0, -1, -1, -1, 1,
        200, 50, -1, GMG, 5, 5000, 1, 1000},
    {"IS.LightMachineGun", VRT_IS_MG, TAMMO, 0, 1, 0, 2, 4, 6, 0, -1, -1, -1, 1,
        200, 50, -1, GMG, 5, 5000, 1, 500},

/* IS Level 2 Ballistic Weapons -- Verified 02/13/07 -- Power_Shaper */
    {"IS.Anti-MissileSystem", VRT_IS_AMS, TMISSILE, 1, 2, 0, 1, 1, 1, 0,
        -1, -1, -1, 1, 12, 50, -1, AMS, 32, 100000, 11, 2000},
    {"IS.GaussRifle", VRT_IS_GR, TAMMO, 1, 15, 2, 7, 15, 22, 0, -1, -1, -1,
        7, 8, 1500, 20, GAUSS, 321, 300000, 37, 20000},
    {"IS.LightGaussRifle", VRT_IS_LGR, TAMMO, 1, 8, 3, 8, 17, 25, 0, -1,
        -1, -1, 5, 16, 1200, 16, GAUSS, 159, 275000, 20, 20000},
    {"IS.HeavyGaussRifle", VRT_IS_HGR, TAMMO, 2, 25, 4, 6, 13, 20, 0, -1,
        -1, -1, 11, 4, 1800, 25, GAUSS | HVYGAUSS | SPLIT_CRITS, 346, 500000, 43, 20000},
    {"IS.LB2-XAC", VRT_IS_LBX2, TAMMO, 1, 2, 4, 9, 18, 27, 0, -1, -1, -1,
        4, 45, 600, -1, LBX, 42, 150000, 5, 2000},
    {"IS.LB5-XAC", VRT_IS_LBX5, TAMMO, 1, 5, 3, 7, 14, 21, 0, -1, -1, -1,
        5, 20, 800, -1, LBX, 83, 250000, 10, 9000},
    {"IS.LB10-XAC", VRT_IS_LBX10, TAMMO, 2, 10, 0, 6, 12, 18, 0, -1, -1,
        -1, 6, 10, 1100, -1, LBX, 148, 400000, 19, 12000},
    {"IS.LB20-XAC", VRT_IS_LBX20, TAMMO, 6, 20, 0, 4, 8, 12, 0, -1, -1, -1,
        11, 5, 1400, -1, LBX | SPLIT_CRITS, 237, 600000, 27, 20000},
    {"IS.RotaryAC/2", VRT_IS_RAC2, TAMMO, 1, 2, 0, 6, 12, 18, 0, -1, -1,
        -1, 3, 45, 800, -1, RAC, 118, 175000, 15, 3000},
    {"IS.RotaryAC/5", VRT_IS_RAC5, TAMMO, 1, 5, 0, 5, 10, 15, 0, -1, -1,
        -1, 6, 20, 1000, -1, RAC, 247, 275000, 31, 12000},
    {"IS.UltraAC/2", VRT_IS_UAC2, TAMMO, 1, 2, 4, 8, 17, 25, 0, -1, -1, -1,
        3, 45, 700, -1, ULTRA, 56, 120000, 7, 1000},
    {"IS.UltraAC/5", VRT_IS_UAC5, TAMMO, 1, 5, 2, 6, 13, 20, 0, -1, -1, -1,
        5, 20, 900, -1, ULTRA, 113, 200000, 14, 9000},
    {"IS.UltraAC/10", VRT_IS_UAC10, TAMMO, 4, 10, 0, 6, 12, 18, 0, -1, -1,
        -1, 7, 10, 1300, -1, ULTRA, 253, 320000, 29, 12000},
    {"IS.UltraAC/20", VRT_IS_UAC20, TAMMO, 8, 20, 0, 3, 7, 10, 0, -1, -1,
        -1, 10, 5, 1500, -1, ULTRA | SPLIT_CRITS, 282, 480000, 32, 20000},
    {"IS.ArrowIVSystem", VRT_IS_ARROWIV, TARTILLERY, 10, 20, 0, 0, 0, 5, 0,
        -1, -1, -1, 15, 5, 1500, -1, IDF | DAR, 171, 450000, 11, 1000},
    {"IS.Sniper", VRT_IS_SNIPER, TARTILLERY, 10, 10, 0, 0, 0, 12, 0, -1,
        -1, -1, 20, 10, 2000, -1, IDF | DAR, 86, 300000, 5, 6000},
    {"IS.Thumper", VRT_IS_THUMPER, TARTILLERY, 6, 5, 0, 0, 0, 14, 0, -1,
        -1, -1, 15, 20, 1500, -1, IDF | DAR, 40, 187500, 3, 4500},

/* IS Level 3 Ballistic Weapons -- Verified 02/13/07 -- Power_Shaper */
/*NAME, VRT, TYPE, HEAT, DAMAGE, MIN, SR, MR, LR, WMIN, WSR, WMR, WLR, CRITS, AMMO, WT, EXP DAMAGE, SPEC, WBV, WCOST, ABV, ACOST */
    {"IS.HeavyFlamer", VRT_IS_HFLAMER, TAMMO, 5, 4, 0, 2, 4, 6, 0, -1, -1,
        -1, 1, 10, 100, -1, CHEAT, 20, 20000, 3, 2000},
    {"IS.LightAC/2", VRT_IS_LAC2, TAMMO, 1, 2, 0, 6, 12, 18, 0, -1, -1, -1,
        1, 45, 400, -1, RFAC, 30, 100000, 3, 2000},
    {"IS.LightAC/5", VRT_IS_LAC5, TAMMO, 1, 5, 0, 5, 10, 15, 0, -1, -1, -1,
        2, 20, 500, -1, RFAC, 62, 150000, 5, 5000},
    {"IS.LongTomCannon", VRT_IS_LONGTOMC, TARTILLERY, 20, 20, 4, 6, 13, 20, 0, -1, -1,
        -1, 15, 5, 2000, -1, IDF | DAR, 348, 650000, 48, 20000},
    {"IS.SniperCannon", VRT_IS_SNIPERC, TARTILLERY, 10, 10, 2, 4, 8, 12, 0, -1, -1, -1,
        10, 10, 1500, -1, IDF | DAR, 115, 475000, 16, 15000},
    {"IS.ThumperCannon", VRT_IS_THUMPERC, TARTILLERY, 6, 5, 3, 4, 9, 14, 0, -1, -1, -1,
        7, 20, 1000, -1, IDF | DAR, 58, 200000, 7, 10000},
    {"IS.HeavyMachineGun", VRT_IS_HMG, TAMMO, 0, 2, 0, 2, 4, 6, 0, -1, -1,
            -1, 1, 100, 100, -1, GMG, 6, 7500, 1, 1000},


/* IS Plasma Rifle */
    {"IS.PlasmaRifle", VRT_IS_PRIFLE, TAMMO, 10, 10, 0, 5, 10, 15, 0, -1, -1,
        -1, 2, 10, 600, -1, NOBOOM, 210, 260000, 86, 10000},

/* IS MML Missiles */
    {"IS.MML-3", VRT_IS_MML3, TMISSILE, 2, 1, 0, 3, 6, 9, 0, -1, -1, -1, 
    	2, 33, 150, -1, IDF, 29, 45000, 4, 27000},
/* MML is 30k for LRM Ammo (40/24/17/13), 27K for SRM (33/20/14/11 shots) (1.2 * SRM ammo rounded up = LRM Ammo)  (LRM * .825 = SRM)*/
    {"IS.MML-5", VRT_IS_MML5, TMISSILE, 3, 1, 0, 3, 6, 9, 0, -1, -1, -1,
    	3, 20, 300, -1, IDF, 45, 75000, 6, 27000},
    {"IS.MML-7", VRT_IS_MML7, TMISSILE, 4, 1, 0, 3, 6, 9, 0, -1, -1, -1,
    	4, 14, 450, -1, IDF, 67, 105000, 8, 27000},
    {"IS.MML-9", VRT_IS_MML9, TMISSILE, 5, 1, 0, 3, 6, 9, 0, -1, -1 ,-1,
    	5, 11, 600, -1, IDF, 86, 125000, 11, 27000},

/* IS Level 1 Missile Weapons */
    {"IS.LRM-5", VRT_IS_LRM5, TMISSILE, 2, 1, 6, 7, 14, 21, 0, -1, -1, -1,
        1, 24, 200, -1, IDF, 45, 30000, 6, 30000},
    {"IS.LRM-10", VRT_IS_LRM10, TMISSILE, 4, 1, 6, 7, 14, 21, 0, -1, -1, -1,
        2, 12, 500, -1, IDF, 90, 100000, 11, 30000},
    {"IS.LRM-15", VRT_IS_LRM15, TMISSILE, 5, 1, 6, 7, 14, 21, 0, -1, -1, -1,
        3, 8, 700, -1, IDF, 136, 175000, 17, 30000},
    {"IS.LRM-20", VRT_IS_LRM20, TMISSILE, 6, 1, 6, 7, 14, 21, 0, -1, -1, -1,
        5, 6, 1000, -1, IDF, 181, 250000, 23, 30000},
    {"IS.SRM-2", VRT_IS_SRM2, TMISSILE, 2, 2, 0, 3, 6, 9, 0, -1, -1, -1, 1,
        50, 100, -1, NONE, 21, 10000, 3, 27000},
    {"IS.SRM-4", VRT_IS_SRM4, TMISSILE, 3, 2, 0, 3, 6, 9, 0, -1, -1, -1, 1,
        25, 200, -1, NONE, 39, 60000, 5, 27000},
    {"IS.SRM-6", VRT_IS_SRM6, TMISSILE, 4, 2, 0, 3, 6, 9, 0, -1, -1, -1, 2,
        15, 300, -1, NONE, 59, 80000, 7, 27000},
     
/* All LRM/SRM have OS versions. BV/5, Cbill/2, WT+.5
 * LR Torp 5
 * LR Torp 10
 * LR Torp 15
 * LR Torp 20
 * SR Torp 2
 * SR Torp 4
 * SR Torp 6
 */

/* IS Level 2 Missile Weapons */
    {"IS.MRM-10", VRT_IS_MRM10, TMISSILE, 4, 1, 0, 3, 8, 15, 0, -1, -1, -1,
        2, 24, 300, -1, MRM, 56, 50000, 7, 5000},
    {"IS.MRM-20", VRT_IS_MRM20, TMISSILE, 6, 1, 0, 3, 8, 15, 0, -1, -1, -1,
        3, 12, 700, -1, MRM, 112, 125000, 14, 5000},
    {"IS.MRM-30", VRT_IS_MRM30, TMISSILE, 10, 1, 0, 3, 8, 15, 0, -1, -1,
        -1, 5, 8, 1000, -1, MRM, 168, 225000, 21, 5000},
    {"IS.MRM-40", VRT_IS_MRM40, TMISSILE, 12, 1, 0, 3, 8, 15, 0, -1, -1,
        -1, 7, 6, 1200, -1, MRM, 224, 350000, 28, 5000},
    {"IS.NarcBeacon", VRT_IS_NARC, TMISSILE, 1, 4, 0, 3, 6, 9, 0, -1, -1,
        -1, 2, 6, 300, -1, NARC, 30, 100000, 0, 6000},
    {"IS.iNarcBeacon", VRT_IS_INARC, TMISSILE, 1, 6, 0, 4, 9, 15, 0, -1,
        -1, -1, 3, 4, 500, -1, INARC, 75, 250000, 0, 7500},
    {"IS.StreakSRM-2", VRT_IS_SSRM2, TMISSILE, 2, 2, 0, 3, 6, 9, 0, -1, -1,
        -1, 1, 50, 150, -1, STREAK | NOSPA, 30, 15000, 4, 54000},
    {"IS.StreakSRM-4", VRT_IS_SSRM4, TMISSILE, 3, 2, 0, 3, 6, 9, -1, -1,
        -1, -1, 1, 25, 300, -1, STREAK | NOSPA, 59, 90000, 7, 54000},
    {"IS.StreakSRM-6", VRT_IS_SSRM6, TMISSILE, 4, 2, 0, 3, 6, 9, -1, -1,
        -1, -1, 2, 15, 450, -1, STREAK | NOSPA, 89, 120000, 11, 54000},
    {"IS.RL-10", VRT_IS_RL10, TMISSILE, 3, 1, 0, 5, 11, 18, 0, -1, -1, -1,
        1, 0, 50, -1, ROCKET | IDF, 18, 15000, 0, 0},
    {"IS.RL-15", VRT_IS_RL15, TMISSILE, 4, 1, 0, 4, 9, 15, 0, -1, -1, -1,
        2, 0, 100, -1, ROCKET | IDF, 23, 30000, 0, 0},
    {"IS.RL-20", VRT_IS_RL20, TMISSILE, 5, 1, 0, 3, 7, 12, 0, -1, -1, -1,
        3, 0, 150, -1, ROCKET | IDF, 24, 45000, 0, 0},


/* MRM OS Versions
 * Streak OS Versions
 */

/* IS Level 3 Missile Weapons */
    {"IS.Thunderbolt-5", VRT_IS_TBOLT5, TMISSILE, 3, 5, 5, 6, 12, 18, 0,
        -1, -1, -1, 1, 12, 300, -1, IDF | NOSPA, 64, 50000, 8, 50000},
    {"IS.Thunderbolt-10", VRT_IS_TBOLT10, TMISSILE, 5, 10, 5, 6, 12, 18, 0,
        -1, -1, -1, 2, 6, 700, -1, IDF | NOSPA, 127, 175000, 16, 50000},
    {"IS.Thunderbolt-15", VRT_IS_TBOLT15, TMISSILE, 7, 15, 5, 6, 12, 18, 0,
        -1, -1, -1, 3, 4, 1100, -1, IDF | NOSPA, 229, 325000, 26, 50000},
    {"IS.Thunderbolt-20", VRT_IS_TBOLT20, TMISSILE, 8, 20, 5, 6, 12, 18, 0,
        -1, -1, -1, 5, 3, 1500, -1, IDF | NOSPA, 305, 450000, 35, 50000},
						 
/* All minus Thunderbolt and Torps, Improved OS vers
 */

/* pc weapons without ammo */

    {"PC.Sword", VRT_PC_SWORD, THAND, 0, 5, 0, 1, 1, 1, 0, -1, -1, -1, 1,
	0, 0, -1, PC_SHAR, 1},
    {"PC.Vibroblade", VRT_PC_VIBROBLADE, THAND, 0, 7, 0, 1, 1, 1, 0, -1,
	-1, -1, 1, 0, 0, -1, PC_SHAR, 1},


/* MaxMunch stuff */
    {"CL.StreakLRM-5", VRT_CL_SLRM5, TMISSILE, 2, 1, 6, 7, 14, 21, 0, -1,
	-1, -1, 1, 24, 200, -1, STREAK | CLAT | NOSPA, 87},
    {"CL.StreakLRM-10", VRT_CL_SLRM10, TMISSILE, 4, 1, 6, 7, 14, 21, 0, -1,
	-1, -1, 2, 12, 500, -1, STREAK | CLAT | NOSPA, 173},
    {"CL.StreakLRM-15", VRT_CL_SLRM15, TMISSILE, 5, 1, 6, 7, 14, 21, 0, -1,
	-1, -1, 3, 8, 700, -1, STREAK | CLAT | NOSPA, 260},
    {"CL.StreakLRM-20", VRT_CL_SLRM20, TMISSILE, 6, 1, 6, 7, 14, 21, 0, -1,
	-1, -1, 5, 6, 1000, -1, STREAK | CLAT | NOSPA, 346},
    {"IS.A-Pod", VRT_IS_APOD, TBEAM, 0, 0, 0, 1, 1, 1, 0, -1, -1, -1, 1, 0,
	50, -1, A_POD, 1},

    /* new FM stuff */
    {"IS.MagshotGaussRifle", VRT_IS_MGR, TAMMO, 0, 2, 0, 3, 6, 9, 0, -1,
	-1, -1, 2, 50, 50, 3, GAUSS, 15, 8500, 2, 1000},

    /* Exile Munch Weapons */
    {"IS.CoolantGun", VRT_IS_COOLANTGUN, TAMMO, 0, 3, 0, 1, 2, 3, 0, -1, -1,
    -1, 1, 25, 100, -1, CHEAT, 15},
    {"IS.AcidThrower", VRT_IS_ACIDTHROWER, TAMMO, 3, 3, 0, 1, 2, 3, 0, -1, -1,
    -1, 2, 10, 150, -1, NONE, 30},

    /* Missing TL2 and TL3 Weapons */
    {"IS.VehicleHeavyFlamer", VRT_IS_VHFLAMER, TAMMO, 5, 4, 0, 2, 4, 6, 0, -1, -1,
    -1, 1, 20, 100, -1, CHEAT, 20},
    {"CL.RotaryAC/2", VRT_CL_RAC2, TAMMO, 1, 2, 2, 9, 18, 27, 0, -1, -1,
    -1, 4, 45, 700, -1, CLAT | RAC, 75},
    {"CL.RotaryAC/5", VRT_CL_RAC5, TAMMO, 1, 5, 0, 7, 14, 21, 0, -1, -1,
    -1, 5, 20, 1000, -1, CLAT | RAC, 150},
    {"CL.RotaryAC/10", VRT_CL_RAC10, TAMMO, 3, 10, 0, 6, 12, 18, 0, -1, -1,
    -1, 7, 10, 1400, -1, CLAT | RAC, 250},
    {"CL.RotaryAC/20", VRT_CL_RAC20, TAMMO, 7, 20, 0, 4, 8, 12, 0, -1, -1,
    -1, 10, 5, 1600, -1, CLAT | RAC, 400},
    {"CL.PlasmaRifle", VRT_CL_PLASMA, TBEAM, 15, 10, 0, 7, 14, 22, 0, 4, 10, 16,
    2, 0, 600, -1, CLAT, 400},
    {"CL.LaserAMS", VRT_CL_LASERAMS, TBEAM, 1, 2, 0, 1, 1, 1, 0,
    -1, -1, -1, 1, 24, 50, -1, CLAT | AMS, 105},
    {"IS.LaserAMS", VRT_IS_LASERAMS, TBEAM, 12, 2, 0, 1, 1, 1, 0,
    -1, -1, -1, 1, 24, 50, -1, AMS, 105},

    /* Infantry only Weapons */
    {"IS.LightInfantryRifle", VRT_IS_LIRFL, TAMMO, 0, 1, 0, 1, 2, 2, 0, -1, -1,
    -1, 1, 20, 50, -1, NONE, 5},
    {"IS.InfantryRifle", VRT_IS_MIRFL, TAMMO, 0, 1, 0, 1, 2, 3, 0, -1, -1,
    -1, 1, 10, 75, -1, NONE, 7},
    {"IS.HeavyInfantryRifle", VRT_IS_HIRFL, TAMMO, 0, 2, 0, 1, 2, 4, 0, -1, -1,
    -1, 1, 5, 100, -1, NONE, 9},
    {"IS.InfantryMachineGun", VRT_IS_IMG, TAMMO, 0, 1, 0, 1, 2, 3, 0, -1, -1,
    -1, 1, 20, 100, -1, NONE, 8},
    {"IS.InfantryLaser", VRT_IS_ILAS, TBEAM, 1, 2, 0, 1, 2, 3, 0, -1, -1,
    -1, 1, 0, 75, -1, NONE, 9},
    {"IS.InfantryFlamer", VRT_IS_IFLAM, TBEAM, 1, 1, 0, 1, 2, 3, 0, -1, -1,
    -1, 1, 0, 75, -1, CHEAT, 5},
    {"IS.InfantrySRM", VRT_IS_ISRM, TMISSILE, 1, 1, 0, 2, 4, 6, 0, -1, -1,
    -1, 1, 2, 100, -1, NONE, 12},
    {"IS.InfantryLRM", VRT_IS_ILRM, TMISSILE, 1, 1, 4, 6, 9, 12, 0, -1, -1,
    -1, 1, 1, 100, -1, IDF, 22},

    {NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, NONE, 1}

};

/* Prep work for unifying cluster hit tables */
#define CLUSTER_HIT_2  {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2} 
#define CLUSTER_HIT_10 {3, 3, 4, 6, 6, 6, 6, 8, 8, 10, 10}
#define CLUSTER_HIT_30 {10,10,12,18,18,18,18,24,24,30,30}

struct missile_hit_table_struct MissileHitTable[] = {
    {"CL.LB10-XAC", 0, {3, 3, 4, 6, 6, 6, 6, 8, 8, 10, 10}},
    {"CL.LB20-XAC", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"CL.LB2-XAC", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.LB5-XAC", 0, {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5}},
    {"CL.LRM-10", 0, {3, 3, 4, 6, 6, 6, 6, 8, 8, 10, 10}},
    {"CL.LRM-15", 0, {5, 5, 6, 9, 9, 9, 9, 12, 12, 15, 15}},
    {"CL.LRM-20", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"CL.StreakLRM-5", 0, {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5}},
    {"CL.StreakLRM-10", 0, {3, 3, 4, 6, 6, 6, 6, 8, 8, 10, 10}},
    {"CL.StreakLRM-15", 0, {5, 5, 6, 9, 9, 9, 9, 12, 12, 15, 15}},
    {"CL.StreakLRM-20", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"CL.LRM-5", 0, {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5}},
    {"CL.SRM-2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.SRM-4", 0, {1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4}},
    {"CL.SRM-6", 0, {2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6}},
    {"CL.StreakSRM-2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.StreakSRM-4", 0, {1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4}},
    {"CL.StreakSRM-6", 0, {2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6}},
    {"CL.ATM-3", 0, {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3}},
    {"CL.ATM-6", 0, {2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6}},
    {"CL.ATM-9", 0, {2, 2, 3, 4, 4, 5, 5, 6, 7, 8, 9}},
    {"CL.ATM-12", 0, {4, 4, 6, 6, 8, 8, 8, 10, 10, 12, 12}},
    {"CL.UltraAC/10", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.UltraAC/20", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.UltraAC/2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.UltraAC/5", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.AC/2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.AC/5", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.AC/10", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"CL.AC/20", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.LRM-5", 0, {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5}},
    {"IS.LRM-10", 0, {3, 4, 4, 5, 6, 6, 6, 8, 8, 10, 10}},
    {"IS.LRM-15", 0, {5, 5, 9, 9, 9, 9, 9, 12, 12, 15, 15}},
    {"IS.LRM-20", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"IS.SRM-2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.SRM-4", 0, {1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4}},
    {"IS.SRM-6", 0, {2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6}},
    {"IS.StreakSRM-2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.StreakSRM-4", 0, {1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4}},
    {"IS.StreakSRM-6", 0, {2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6}},
    {"IS.LB20-XAC", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"IS.LB10-XAC", 0, {3, 3, 4, 6, 6, 6, 6, 8, 8, 10, 10}},
    {"IS.LB2-XAC", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.LB5-XAC", 0, {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5}},
    {"IS.UltraAC/20", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.UltraAC/10", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.UltraAC/5", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.UltraAC/2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.AC/2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.AC/5", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.AC/10", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.AC/20", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.LightAC/2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.LightAC/5", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.Thunderbolt-5", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"IS.Thunderbolt-10", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"IS.Thunderbolt-15", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"IS.Thunderbolt-20", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"IS.ELRM-10", 0, {3, 4, 4, 5, 6, 6, 6, 7, 7, 10, 10}},
    {"IS.ELRM-5", 0, {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5}},
    {"IS.ELRM-15", 0, {5, 5, 9, 9, 9, 9, 12, 12, 12, 15, 15}},
    {"IS.ELRM-20", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"IS.LR_DFM-10", 0, {3, 4, 4, 5, 6, 6, 6, 7, 7, 10, 10}},
    {"IS.LR_DFM-5", 0, {1, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5}},
    {"IS.LR_DFM-15", 0, {5, 5, 9, 9, 9, 9, 12, 12, 12, 15, 15}},
    {"IS.LR_DFM-20", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"IS.SR_DFM-2", 0, {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2}},
    {"IS.SR_DFM-4", 0, {1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4}},
    {"IS.SR_DFM-6", 0, {2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 6}},
    {"IS.NarcBeacon", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"CL.NarcBeacon", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"IS.MRM-10", 0, {2, 3, 4, 5, 6, 6, 6, 8, 8, 10, 10}},
    {"IS.MRM-20", 0, { 6,  6,  9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"IS.MRM-30", 0, {10, 10, 12, 18, 18, 18, 18, 24, 24, 30, 30}},
    {"IS.MRM-40", 0, {12, 12, 18, 24, 24, 24, 24, 32, 32, 40, 40}},
    {"IS.iNarcBeacon", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"IS.RL-10", 0, {3, 4, 4, 5, 6, 6, 6, 8, 8, 10, 10}},
    {"IS.RL-15", 0, {5, 5, 9, 9, 9, 9, 9, 12, 12, 15, 15}},
    {"IS.RL-20", 0, {6, 6, 9, 12, 12, 12, 12, 16, 16, 20, 20}},
    {"IS.InfantrySRM", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"IS.InfantryLRM", 0, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}},
    {"NoWeapon", -1, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}
};

#define NUM_DEF_WEAPONS (((sizeof(MechWeapons))/ \
			 (sizeof(struct weapon_struct)))-1)
