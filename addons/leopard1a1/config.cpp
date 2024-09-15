class CfgPatches
{
    class WST_mkk_leopard1a1
    {
        units[]= {
            "mkk_leopard1a1",
            "mkk_leopard1a1_r",
            "mkk_leopard1a1_g"
        };
        weapons[]={
            "mkk_leo_weap_l7a3_nofcs",
            "mkk_MG3_nofcs"
        };
        requiredVersion = 0.1;
        requiredAddons[] = {
            "mkk_ammo_config",
            "leopard1_c",
            "mkk_rhs_afrf_fix_m",
            "mkk_avrs",
        };
        author = "Westalgie";
    };
};

class RscOpticsText;
class RscOpticsValue;
class RscControlsGroup;
class HScrollbar;
class VScrollbar;
class RscPicture;
class RscText;

class RscInGameUI
{
    class RscUnitInfo;

    class MKK_RscWeaponLeopard1_FCS: RscUnitInfo
	{
		idd=300;
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call SG_fnc_sight_leopard1a1";
		controls[]=
		{
            "CA_DistanceText",
            "CA_Distance",
			"CA_IGUI_elements_group"
		};
        class CA_DistanceText: RscOpticsText
        {
			idc = -1;
			style = 2;
			colorText[] = {1,0,0,1};
			shadow = 3;
			colorShadow[] = {100,100,100,95};
			x = "0";
			y = "(SafezoneY+SafezoneH) - 0.05";
			w = "1";
			h = "0.05";
		};
        class CA_Distance: RscOpticsValue
		{
			idc = 198;
			style = 2;
			colorText[] = {0.9,0,0,1};
			shadow = 3;
			colorShadow[] = {100,100,100,95};
			font = "TahomaB";
			x = "0.45 * (SafezoneX+SafezoneW)";
			y = "0.35 * (SafezoneY+SafezoneH)";
			w = "1";
			h = "0.05";
		};
		class CA_IGUI_elements_group: RscControlsGroup
		{
			idc=170;
			class VScrollbar: VScrollbar
			{
				width=0;
			};
			class HScrollbar: HScrollbar
			{
				height=0;
			};
			x="0 * (0.01875 * SafezoneH) + (SafezoneX + ((SafezoneW - SafezoneH) / 2))";
			y="0 * (0.025 * SafezoneH) + (SafezoneY)";
			w="53.5 * (0.01875 * SafezoneH)";
			h="40 * (0.025 * SafezoneH)";
			class controls
			{
				class RDS_Sight: RscPicture
				{
					idc=1;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
					text="";
					x="13.4 *   (0.01875 * Safezoneh)"; //0.25125
					y="3.66 *   (0.025 * SafezoneH)";   // 0.0915
					w="25.5 *   (0.01875 * SafezoneH)"; // 0.478125
					h="25.5 *   (0.025 * SafezoneH)";   // 0.6375
				};
				class RDS_SightBar: RscPicture
				{
					idc=2;
					style="0x30 + 0x800";
					sizeEx="0.038*SafezoneH";
					colorText[]={0.70599997,0.074500002,0.0196,1};
					shadow=0;
					font="EtelkaMonospacePro";
					text="leopard1a1\data\WST_tzf_1a_sight_ca.paa";
					x="14.3 *   (0.01875 * SafezoneH)";
					y="7.26 *   (0.025 * SafezoneH)";
					w="25.5 *   (0.01875 * SafezoneH)";
					h="25.5 *   (0.025 * SafezoneH)";
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
				class CA_OpticsMode: CA_OpticsZoom
				{
					idc=154;
				};
				class RHS_ControlNumber: CA_OpticsZoom
				{
					idc=1000;
					text="MKK_SIGHT_TZF_1A";
				};
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
			};
		};
	};
};

class CfgAmmo
{
    class mkk_ammo_M1069;
    class mkk_ammo_DM512: mkk_ammo_M1069
    {
        airFriction = -0.00008;
    };
};

class CfgMagazines
{
    class mkk_leo1_mag_dm512;
    class mkk_leo1_mag_dm512_fix: mkk_leo1_mag_dm512
    {
        ammo = "mkk_ammo_DM512";
        displayName = "HE-T DM512";
        dispalyNameShort = "HE-T DM512";
        descriptionShort = "HE-T DM512";
        initSpeed = 900;
    };
    class mkk_csw_leo1_mag_dm512_fix: mkk_leo1_mag_dm512_fix
	{
		scope = 2;
		count = 1;
		picture = "\centauro\data\ui\he.paa";
	};
};

class CfgFunctions
{
    class SG
    {
        class Functions
        {
            class sight_leopard1a1
            {
                file="leopard1a1\scripts\sight_tzf1a.sqf";
				description="Leopard TZF-1A sight and FCS";
            };
        };
    };
};

class cfgWeapons
{
    class cannon_120mm;
    class mkk_leo_weap_l7a3: cannon_120mm
    {
        class close;
        class medium;
        class far;
        class short;
        class player;
    };
    class mkk_MG3_vehicle;

    class mkk_leo_weap_l7a3_nofcs: mkk_leo_weap_l7a3
    {
        magazines[] = { "mkk_leo1_mag_dm33","mkk_leo1_mag_dm12","mkk_leo1_mag_dm512_fix" };
        ballisticsComputer = "0";
        dispersion = 0;
        class close: close
        {
            dispersion = 0.0002;
        };
        class far: far
        {
            dispersion = 0.0002;
        };
        class medium: medium
        {
            dispersion = 0.0002;
        };
        class short: short
        {
            dispersion = 0.0002;
        };
        class player: player
        {
            dispersion = 0.0002;
        };
    };

    class mkk_MG3_nofcs: mkk_MG3_vehicle
    {
        ballisticsComputer = "0";
    };
};

class CfgVehicles
{
    class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
	};
    class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
                    class Loader;
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class EventHandlers;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
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

    class mkk_leopard1_base: Tank_F {
        class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class OpticsIn
				{
					class Wide
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.233*2;
						minFov = 0.233*2;
						maxFov = 0.233*2;
						visionMode[] = {"Normal","Ti","NVG"};
						thermalMode[] = {2,3};
						gunnerOpticsModel = "leopard1a1\WST_Optics_Gunner_Leopard1A5_Wide.p3d";
						gunnerOpticsEffect[] = {};
					};
					class Narrow: Wide
					{
						initFov = "0.233/4";
						minFov = "0.233/4";
						maxFov = "0.233/4";
						gunnerOpticsModel = "leopard1a1\WST_Optics_Gunner_Leopard1A5_Narrow.p3d";
					};
					class Narrow1: Narrow
					{
						initFov = "0.233/8";
						minFov = "0.233/8";
						maxFov = "0.233/8";
						gunnerOpticsModel = "leopard1a1\WST_Optics_Gunner_Leopard1A5_NATO.p3d";
					};
				};
				turretInfoType="mkk_RHS_RscWeaponM1_FCS_new";
			};
		};
    };

    class mkk_leopard1a1_base: mkk_leopard1_base
    {
        displayName = "Leopard 1A1";
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
                class Turrets: Turrets
                {
                    class CommanderOptics: CommanderOptics
                    {
                        class ViewOptics: ViewOptics
                        {
                            visionMode[] = {"Normal","NVG"};
                        };
                        class OpticsIn
                        {
                            class Wide
                            {
                                opticsDisplayName = "60HZ 1X";
                                initAngleX = 0;
                                minAngleX = -30;
                                maxAngleX = 30;
                                initAngleY = 0;
                                minAngleY = -100;
                                maxAngleY = 100;
                                initFov = 0.233*2.2;
                                minFov = 0.233*2.2;
                                maxFov = 0.233*2.2;
                                visionMode[] = {"Normal","NVG"};
                                gunnerOpticsModel = "\A3\weapons_f\reticle\optics_binoculars";
                                gunnerOpticsEffect[] = {};
                            };
                            class Narrow: Wide
                            {
                                opticsDisplayName = "60HZ 6X";
                                initFov = "0.233/6";
                                minFov = "0.233/6";
                                maxFov = "0.233/6";
                            };
                        };
                    };
                    class Loader: Loader
                    {
                        class ViewOptics: ViewOptics
                        {
                            visionMode[] = {"Normal","NVG"};
                        };
                        class OpticsIn
						{
							class Wide
							{
								initAngleX = 0;
								minAngleX = -30;
								maxAngleX = 30;
								initAngleY = 0;
								minAngleY = -100;
								maxAngleY = 100;
								initFov = 0.233*2.2;
								minFov = 0.233*2.2;
								maxFov = 0.233*2.2;
								visionMode[] = {"Normal","NVG"};
								gunnerOpticsModel="\A3\weapons_f\reticle\optics_generic_empty_f";
								gunnerOpticsEffect[] = {};
							};
							class Narrow: Wide
							{
								initFov = "0.233/4";
								minFov = "0.233/4";
								maxFov = "0.233/4";
							};
						};
                    };
                };
                class ViewOptics: ViewOptics
                {
                    visionMode[] = {"Normal","NVG"};
                };
                class OpticsIn
                {
                    class Periscope
                    {
                        opticsDisplayName = "PERISCOPE";
                        initAngleX = 0;
                        minAngleX = -30;
                        maxAngleX = 30;
                        initAngleY = 0;
                        minAngleY = -100;
                        maxAngleY = 100;
                        initFov = 0.233*2;
                        minFov = 0.233*2;
                        maxFov = 0.233*2;
                        visionMode[] = {"Normal","NVG"};
                        gunnerOpticsModel = "leopard1a1\WST_Optics_Gunner_Leopard1_Empty";
                        gunnerOpticsEffect[] = {};
                    };
                    class Narrow: Periscope
                    {
                        opticsDisplayName = "NARROW";
                        initFov = (0.233333 / 8);
                        minFov = (0.233333 / 8);
                        maxFov = (0.233333 / 8);
                    };
                };
                weapons[] = {"mkk_leo_weap_l7a3_nofcs","mkk_MG3_nofcs"};
                turretInfoType = "MKK_RscWeaponLeopard1_FCS";
            };
        };
        class AnimationSources: AnimationSources
		{
			class user_recoil
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
			};
			class muzzle_hide_cannon
			{
				source="reload";
				weapon="mkk_leo_weap_l7a3_nofcs";
			};
			class muzzle_rot_cannon
			{
				source="ammorandom";
				weapon="mkk_leo_weap_l7a3_nofcs";
			};
			class recoil_source
			{
				source="reload";
				weapon="mkk_leo_weap_l7a3_nofcs";
			};
			class muzzle_rot_mg
			{
				source="ammorandom";
				weapon="mkk_MG3_nofcs";
			};
		};
        class TransportMagazines
		{
			class leo1_apfsds_mags
			{
				magazine="mkk_csw_leo1_mag_dm33";
				count=5;
			};
			class leo1_heat_mags
			{
				magazine="mkk_csw_leo1_mag_dm12";
				count=5;
			};
			class leo1_he_mags
			{
				magazine="mkk_csw_leo1_mag_dm512_fix";
				count=5;
			};
			class _xx_BWA3_120Rnd_762x51
			{
				magazine="BWA3_120Rnd_762x51";
				count=5;
			};
		};
        class MKK_CSW
		{
			enabled=1;
			csw_weapons[]=
			{
				"mkk_leo_weap_l7a3_nofcs",
				"mkk_MG3_nofcs"
			};
			class mkk_leo_weap_l7a3_nofcs
			{
				condition="!(isTurnedOut _player)";
				can_refill="false";
				loadable_magazines[]=
				{
					"mkk_csw_leo1_mag_dm33",
					"mkk_csw_leo1_mag_dm12",
					"mkk_csw_leo1_mag_dm512_fix"
				};
				weapon_magazines[]=
				{
					"mkk_leo1_mag_dm33",
					"mkk_leo1_mag_dm12",
					"mkk_leo1_mag_dm512_fix"
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
			class mkk_MG3_nofcs
			{
				condition="!(isTurnedOut _player)";
				can_refill="false";
				loadable_magazines[]=
				{
					"BWA3_120Rnd_762x51",
					"BWA3_120Rnd_762x51_Tracer",
					"BWA3_120Rnd_762x51_ap",
					"BWA3_120Rnd_762x51",
					"BWA3_120Rnd_762x51_soft",
					"BWA3_120Rnd_762x51_Tracer_soft",
					"BWA3_120Rnd_762x51_ap_soft"
				};
				weapon_magazines[]=
				{
					"csw_BWA3_120Rnd_762x51",
					"csw_BWA3_120Rnd_762x51_Tracer",
					"csw_BWA3_120Rnd_762x51_ap",
					"csw_BWA3_1200Rnd_762x51",
					"csw_BWA3_120Rnd_762x51_soft",
					"csw_BWA3_120Rnd_762x51_Tracer_soft",
					"csw_BWA3_120Rnd_762x51_ap_soft"
				};
				max_magazine_count=10;
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

    class mkk_leopard1a1: mkk_leopard1a1_base
    {
        side = 1;
        scope = 2;
        faction = "BWA3_Faction_Fleck";
        crew = "B_Crew_F";
        typicalCargo[] = {"B_Crew_F"};
        hiddenSelectionsTextures[] = {"leopard1\data\body_woodland_co.paa","leopard1\data\armor_woodland_co.paa","leopard1\data\turret_woodland_co.paa","leopard1\data\gun_woodland_co.paa"};
    };

    class mkk_leopard1a1_r: mkk_leopard1_base
	{
		side = 0;
		scope = 2;
		faction="mkk_turki_side";
		crew="O_crew_F";
		typicalCargo[]={"O_Soldier_F"};
		hiddenSelectionsTextures[] = {"leopard1\data\body_field2_co.paa","leopard1\data\armor_field2_co.paa","leopard1\data\turret_field2_co.paa","leopard1\data\gun_field2_co.paa"};
	};

	class mkk_leopard1a1_g: mkk_leopard1_base
	{
		side = 2;
		scope = 2;
		faction="IND_F";
		crew="I_crew_F";
		typicalCargo[]={"I_Soldier_F"};
		hiddenSelectionsTextures[] = {"leopard1\data\body_aaf_co.paa","leopard1\data\armor_aaf_co.paa","leopard1\data\turret_aaf_co.paa","leopard1\data\gun_aaf_co.paa"};
	};
};