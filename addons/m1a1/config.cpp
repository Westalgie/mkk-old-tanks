class CfgPatches
{
    class WST_mkk_m1a1_no_fcs
    {
        units[]= {
            "rhsusf_m1a1aimwd_usarmy_nofcs"
        };
        weapons[]={
            "rhs_weap_m256_nofcs",
            "rhs_weap_m240_abrams_coax"
        };
        requiredVersion = 0.1;
        requiredAddons[] = {
            "mkk_rhs_usaf_fix_m_c",
            "rhsusf_c_m1a1",
            "mkk_avrs"
        };
        author = "Westalgie";
    };
};

class RscControlsGroup;
class HScrollbar;
class VScrollbar;
class RscPicture;
class RscText;

class RscInGameUI
{
    class RscUnitInfo;

    class MKK_RscWeaponM1A1_GAS_FCS: RscUnitInfo
	{
		idd=300;
		controls[]=
		{
			"CA_IGUI_elements_group"
		};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc = 170;
			class VScrollbar: VScrollbar
			{
				width = 0;
			};
			class HScrollbar: HScrollbar
			{
				height = 0;
			};
			x = "0 *   (0.01875 * SafezoneH) +   (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y = "0 *   (0.025 * SafezoneH) +   (SafezoneY)";
			w = "53.5 *   (0.01875 * SafezoneH)";
			h = "40 *   (0.025 * SafezoneH)";
			class controls
			{
				class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {0.49,0.78,0.46,1};
					shadow = 3;
					colorShadow[] = {100,100,100,95};
					x = "5.25 * 		(0.01875 * SafezoneH)";
					y = "3.5 * 		(0.025 * SafezoneH)";
					w = "6 * 		(0.01875 * SafezoneH)";
					h = "6 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorHull.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorTurret.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\turretIndicatorObsTurret.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class CA_HorizontalCompass: RscPicture
				{
					IDC = 207;
					type = 105;
					font = "TahomaB";
					style = 1;
					color[] = {0.49,0.78,0.46,1};
					shadow = 3;
					colorShadow[] = {100,100,100,95};
					textSize = "0.02*SafezoneH";
					x = "13.04 * 		(0.01875 * SafezoneH)";
					y = "3.5 * 		(0.025 * SafezoneH)";
					w = "27.18 * 		(0.01875 * SafezoneH)";
					h = "1 * 		(0.025 * SafezoneH)";
					imageHull = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassHull.paa";
					imageTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassTurret.paa";
					imageObsTurret = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\horizontalCompassObsTurret.paa";
					imageGun = "#(rgb,8,8,3)color(0,0,0,0)";
				};
				class AzimuthMark: RscPicture
				{
					IDC = 1012;
					text = "A3\Ui_f\data\IGUI\RscIngameUI\RscOptics\AzimuthMark.paa";
					x = "26.35 * 		(0.01875 * SafezoneH)";
					y = "3.0 * 		(0.025 * SafezoneH)";
					w = "0.5 * 		(0.01875 * SafezoneH)";
					h = "0.5 * 		(0.025 * SafezoneH)";
					colorText[] = {0.49,0.78,0.46,1};
					shadow = 3;
					colorShadow[] = {100,100,100,95};
				};
				class CA_Heading: RscText
				{
					idc = 156;
					style = 2;
					sizeEx = "0.032*SafezoneH";
					shadow = 3;
					colorShadow[] = {100,100,100,95};
					font = "TahomaB";
					colorText[] = {0.49,0.78,0.46,1};
					text = "015";
					x = "25.15 * 		(0.01875 * SafezoneH)";
					y = "1.75 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
				class CA_OpticsZoom: RscText
				{
					idc = 180;
					style = 1;
					colorText[] = {0.706,0.0745,0.0196,1};
					sizeEx = "0.038*SafezoneH";
					shadow = 3;
					colorShadow[] = {100,100,100,95};
					font = "TahomaB";
					text = "4.5";
					x = "43.85 *   (0.01875 * SafezoneH)";
					y = "19.6 *   (0.025 * SafezoneH)";
					w = "0*   (0.01875 * SafezoneH)";
					h = "0 *   (0.025 * SafezoneH)";
				};
			};	
		};
	};
};


class cfgWeapons
{
    class rhs_weap_m256;
    class rhs_weap_m240_abrams_coax;

    class rhs_weap_m256_nofcs: rhs_weap_m256
    {
        ballisticsComputer = "2";
    };

    class rhs_weap_m240_abrams_coax_nofcs: rhs_weap_m240_abrams_coax
    {
        ballisticsComputer = "2";
    };
};

class CfgVehicles
{
    class Land;
	class LandVehicle: Land
	{
		class Turrets;
		class NewTurret;
	};
    class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
		class CommanderOptics;
		class Components;
        class ViewOptics;
		class Turrets {
			class MainTurret: NewTurret {};
		};
	};
    class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
	};
    class MBT_01_base_F : Tank_F {};
    class rhsusf_m1a1tank_base : MBT_01_base_F {};
    class rhsusf_m1a1aimwd_usarmy: rhsusf_m1a1tank_base {};
    class rhsusf_m1a1aimwd_usarmy_nofcs: rhsusf_m1a1aimwd_usarmy
    {
		displayName = "M1A1AIM (GAS)";
        class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class OpticsIn
				{
                    class Periscope: ViewOptics
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.233333;
						minFov = 0.233333;
						maxFov = 0.233333;
						visionMode[] = {"Normal", "NVG"};
                        gunnerOpticsModel = "m1a1\WST_Optics_Gunner_M1A1_Periscope";
					};
					class APFSDS: Periscope
					{
						gunnerOpticsModel = "m1a1\WST_Optics_Gunner_M1A1_APFSDS";
						initFov = (0.233333 / 8);
						minFov = (0.233333 / 8);
						maxFov = (0.233333 / 8);
					};
                    class HEAT: APFSDS
					{
						gunnerOpticsModel = "m1a1\WST_Optics_Gunner_M1A1_HEAT";
					};
                    class HE: APFSDS
					{
						gunnerOpticsModel = "m1a1\WST_Optics_Gunner_M1A1_HE";
					};
				};
                turretInfoType = "MKK_RscWeaponM1A1_GAS_FCS";
                discreteDistance[] = {500};
                discreteDistanceInitIndex = 0;
                weapons[] = {"rhs_weap_m256_nofcs","rhs_weap_m240_abrams_coax_nofcs","rhsusf_weap_M250"};
			};
		};
        class AnimationSources: AnimationSources
		{
			class muzzle_hide_cannon
            {
                source = "reload";
                weapon = "rhs_weap_m256_nofcs";
            };

            class muzzle_rot_cannon
            {
                source = "ammorandom";
                weapon = "rhs_weap_m256_nofcs";
            };

            class muzzle_rot_CoaxMG
            {
                source = "ammorandom";
                weapon = "rhs_weap_m240_abrams_coax_nofcs";
            };

            class recoil_source
            {
                source = "reload";
                weapon = "rhs_weap_m256_nofcs";
            };
		};
        class MKK_CSW
		{
            enabled=1;
			csw_weapons[]=
			{
				"RHS_M2_Abrams_Commander",
				"rhs_weap_m240_abrams",
				"rhs_weap_m256_nofcs",
				"rhs_weap_m240_abrams_coax_nofcs"
			};
			class rhs_weap_m256_nofcs
			{
				condition="!(isTurnedOut _player)";
				can_refill="false";
				loadable_magazines[]=
				{
					"mkk_mag_M829A3",
					"mkk_mag_M830A1",
					"mkk_mag_M1069"
				};
				weapon_magazines[]=
				{
					"mkk_csw_mag_M829A3",
					"mkk_csw_mag_M830A1",
					"mkk_csw_mag_M1069"
				};
				max_magazine_count=1;
				turrets[]=
				{
					{0,1}
				};
				weapon_turret[]={0};
				loading_time=7;
				unloading_time=4;
			};
			class rhs_weap_m240_abrams_coax_nofcs
			{
				condition="!(isTurnedOut _player)";
				can_refill="false";
				loadable_magazines[]=
				{
					"rhsusf_100Rnd_762x51",
					"rhsusf_100Rnd_762x51_m80a1epr",
					"rhsusf_100Rnd_762x51_m61_ap",
					"rhsusf_100Rnd_762x51_m62_tracer"
				};
				weapon_magazines[]=
				{
					"mkk_100Rnd_762x51",
					"mkk_100Rnd_762x51_m80a1epr",
					"mkk_100Rnd_762x51_m61_ap",
					"mkk_100Rnd_762x51_m62_tracer"
				};
				max_magazine_count=12;
				turrets[]=
				{
					{0},
					{0,1}
				};
				weapon_turret[]={0};
				loading_time=0.5;
				unloading_time=0.5;
			};
		};
    };
};
