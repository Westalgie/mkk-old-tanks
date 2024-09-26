class CfgPatches
{
    class WST_mkk_marder_1a5
    {
        units[]= {
            "mkk_Marder_1A1"
        };
        weapons[]={
            "mkk_veh_MG3_nofcs",
            "mkk_MK20FL_nofcs"
        };
        requiredVersion = 0.1;
        requiredAddons[] = {
            "mkk_ger_vehicles_c",
            "mkk_avrs"
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

    class MKK_RscWeaponMarder1A1_FCS: RscUnitInfo
	{
		idd=300;
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this call SG_fnc_sight_marder1a1";
		controls[]=
		{
			"CA_IGUI_elements_group"
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
					colorText[] = {1,1,1,1};
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
					text="MKK_SIGHT_PERI_11";
				};
                class CA_TurretIndicator: RscPicture
				{
					IDC = 206;
					type = 105;
					textSize = "0.02*SafezoneH";
					style = 0;
					color[] = {1,1,1,1};
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
					color[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
					text = "015";
					x = "25.15 * 		(0.01875 * SafezoneH)";
					y = "1.75 * 		(0.025 * SafezoneH)";
					w = "3 * 		(0.01875 * SafezoneH)";
					h = "1.2 * 		(0.025 * SafezoneH)";
				};
			};
		};
	};

    class MKK_RscWeaponMarder1A5_FCS: RscUnitInfo
	{
	    idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_DistanceText","CA_Distance","CA_Zeroing"};
		class CA_DistanceText: RscOpticsText
        {
            idc = -1;
            style = 2;
            colorText[] = {1,1,1,1};
            shadow = 0;
            colorShadow[] = {100,100,100,0};
            x = "0";
            y = "(SafezoneY+SafezoneH) - 0.05";
            w = "1";
            h = "0.05";
            size = 5;
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
					color[] = {1,1,1,1};
					shadow = 3;
					colorShadow[] = {100,100,100,95};
					x = "43 * 		(0.01875 * SafezoneH)";
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
					color[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
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
					colorText[] = {1,1,1,1};
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

class CfgFunctions
{
    class SG
    {
        class Functions
        {
            class sight_marder1a1
            {
                file="marder\scripts\sight_periz11.sqf";
				description="Marder Peri-Z11 sight and FCS";
            };
        };
    };
};

class cfgWeapons
{
    class mkk_MK20FL;
    class mkk_veh_MG3;

    class mkk_MK20FL_nofcs: mkk_MK20FL
    {
        ballisticsComputer = 0;
    };

    class mkk_veh_MG3_nofcs: mkk_veh_MG3
    {
        ballisticsComputer = 0;
    };
};

class CfgVehicles
{
    class LandVehicle;
    class Tank: LandVehicle
    {
        class NewTurret;
    };
    class Tank_F: Tank
    {
        class AnimationSources;
        class Turrets
        {
            class MainTurret: NewTurret {
                class Turrets
				{
					class CommanderOptics;
				};
            };
        };
    };
    class mkk_Marder_1A5_base: Tank_F
    {
        class Turrets: Turrets
		{
			class MainTurret: MainTurret
            {
                turretInfoType = "MKK_RscWeaponMarder1A5_FCS";
                class OpticsIn
				{
					class Day1
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.233*1.5;
						maxFov = 0.233*1.5;
						minFov = 0.233*1.5;
						visionMode[] = {"Normal","Ti","NVG"};
						thermalMode[] = {2,3};
						gunnerOpticsModel = "marder\WST_Optics_Gunner_Marder_Periscope";
						gunnerOpticsEffect[] = {};
					};
					class Day2: Day1
					{
                        initFov = 0.233/2;
						maxFov = 0.233/2;
						minFov = 0.233/2;
						gunnerOpticsModel = "marder\WST_Optics_Gunner_Marder_Wide";
					};
					class Day3: Day1
					{
                        initFov = 0.233/8;
						maxFov = 0.233/8;
						minFov = 0.233/8;
						gunnerOpticsModel = "marder\WST_Optics_Gunner_Marder_Narrow";
					};
				};
                class Turrets: Turrets
                {
                    class CommanderOptics: CommanderOptics
                    {
                        class OpticsIn
                        {
                            class Day1
                            {
                                initAngleX = 0;
                                minAngleX = -30;
                                maxAngleX = 30;
                                initAngleY = 0;
                                minAngleY = -100;
                                maxAngleY = 100;
                                initFov = 0.233/2;
                                maxFov = 0.233/2;
                                minFov = 0.233/2;
                                visionMode[] = {"Normal","Ti","NVG"};
                                thermalMode[] = {2,3};
                                gunnerOpticsModel = "marder\WST_Optics_Gunner_Marder_Wide";
                                gunnerOpticsEffect[] = {};
                            };
                        };
                    };
                };
            };
        };
    };

    class mkk_Marder_1A1_base: mkk_Marder_1A5_base
    {
        class Turrets: Turrets
        {
            class MainTurret: MainTurret
            {
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
                        initFov = 0.233*1.5;
                        minFov = 0.233*1.5;
                        maxFov = 0.233*1.5;
                        visionMode[] = {"Normal","NVG"};
                        gunnerOpticsModel = "leopard1a1\WST_Optics_Gunner_Leopard1_Empty";
                        gunnerOpticsEffect[] = {};
                    };
                    class Narrow: Periscope
                    {
                        opticsDisplayName = "NARROW";
                        initFov = (0.233333 / 6);
                        minFov = (0.233333 / 6);
                        maxFov = (0.233333 / 6);
                    };
                };
                turretInfoType = "MKK_RscWeaponMarder1A1_FCS";
                weapons[] = {"mkk_MK20FL_nofcs", "mkk_veh_MG3_nofcs"};
            };
        };
        class AnimationSources: AnimationSources
		{
			class recoil_source_1
			{
				source = "reload";
				weapon = "mkk_MK20FL_nofcs";
			};
			class recoil_source_2
			{
				source = "reload";
				weapon = "mkk_veh_MG3_nofcs";
			};
			class flash_mk_source
			{
				source = "reload";
				weapon = "mkk_MK20FL_nofcs";
				initPhase = 0;
			};
			class flash_mg3_source
			{
				source = "reload";
				weapon = "mkk_veh_MG3_nofcs";
				initPhase = 0;
			};
		};
        class MKK_CSW
        {
            enabled = 1;
            csw_weapons[] = {"mkk_veh_MG3_nofcs", "mkk_Milan_veh"};
            class mkk_Milan_veh
            {
                can_refill = "false";
                confition = "!(isTurnedOut _player)";
                loadable_magazines[] = {"mkk_Milan_Mag"};
                loading_time = 0.5;
                max_magazine_count = 1;
                turrets[] = {{0, 0}};
                unloading_time = 10;
                weapon_magazines[] = {"mkk_csw_Milan_Mag"};
                weapon_turret[] = {1};
            };
            class mkk_veh_MG3_nofcs
            {
                can_refill = "false";
                confition = "!(isTurnedOut _player)";
                loadable_magazines[] = {
                    "BWA3_120Rnd_762x51",
                    "BWA3_120Rnd_762x51_Tracer",
                    "BWA3_120Rnd_762x51_ap",
                    "BWA3_120Rnd_762x51",
                    "BWA3_120Rnd_762x51_soft",
                    "BWA3_120Rnd_762x51_Tracer_soft",
                    "BWA3_120Rnd_762x51_ap_soft"
                };
                loading_time = 0.5;
                max_magazine_count = 10;
                turrets[] = {{0}};
                unloading_time = 0.5;
                weapon_magazines[] = {
                    "csw_BWA3_120Rnd_762x51",
                    "csw_BWA3_120Rnd_762x51_Tracer",
                    "csw_BWA3_120Rnd_762x51_ap",
                    "csw_BWA3_1200Rnd_762x51",
                    "csw_BWA3_120Rnd_762x51_soft",
                    "csw_BWA3_120Rnd_762x51_Tracer_soft",
                    "csw_BWA3_120Rnd_762x51_ap_soft"
                };
                weapon_turret[] = {0};
            };
        };
    };

    class mkk_Marder_1A1: mkk_Marder_1A1_base
	{
		editorPreview = "\Redd_Marder_1A5\pictures\Marder_F_Pre_Picture.paa";
		scope = 2;
		scopeCurator = 2;
		displayName = "Marder 1A1";
		faction = "BWA3_Faction_Fleck";
		hiddenSelectionsTextures[] = {"\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo1_co.paa","\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo2_co.paa"};
		class textureSources
		{
			class Fleck
			{
				displayName = "$STR_Marder_1A5_Flecktarn";
				author = "ReddNTank";
				textures[] = {"\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo1_co.paa","\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo2_co.paa"};
				//factions[] = {"BLU_F"};
			};
			class Tropen
			{
				displayName = "$STR_Marder_1A5_Tropentarn";
				author = "ReddNTank";
				textures[] = {"\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo1_Trope_co.paa","\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo2_co.paa"};
				//factions[] = {"BLU_F"};
			};
			class Winter
			{
				displayName = "$STR_Marder_1A5_Winter";
				author = "ReddNTank";
				textures[] = {"\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo1_Winter_co.paa","\Redd_Marder_1A5\data\Redd_Marder_1A5_Camo2_co.paa"};
				//factions[] = {"BLU_F"};
			};
		};
		textureList[] = {"Fleck",0,"Tropen",0,"Winter",0};
	};
};