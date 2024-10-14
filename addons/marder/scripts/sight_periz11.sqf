/*
    fn_MKK_SIGHT_PERI_11
    Leopard 1A1 sight simulation
    by Westalgie

    based of
    
    rhs_fnc_sight_bmp2
    BPK-1-42 simulation
    Handles optical devices switching with weaponary changing depe


    script is fired only once & is destroyed together with display
    a: reyhard
*/

if(not( isNull (uiNameSpace getVariable ["MKK_MARDER1A1_Ctrl",displayNull]))) exitWith{};

// remove additional handler if it's present
if( not ( (uiNameSpace getVariable ["mkk_peri_z11_eh",-1]) isEqualTo -1))then{
    (findDisplay 46) displayRemoveEventHandler ["KeyDown", uiNameSpace getVariable "mkk_peri_z11_eh"];
    (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNameSpace getVariable "mkk_peri_z11_eh_up"];
    //systemChat format[" %1 reload passed",(uiNameSpace getVariable ["rhs_hatch_handler_eh",-1])];
};

uiNameSpace setVariable ["MKK_MARDER1A1_Ctrl",_this select 0];

rhs_key_opn_cmp_GLB        = (profileNamespace getVariable ["rhs_key_opn_cmp","Binocular"]);
rhs_key_rng_up_GLB        = (profileNamespace getVariable ["rhs_key_rng_up","ZeroingUp"]);
rhs_key_rng_dwn_GLB        = (profileNamespace getVariable ["rhs_key_rng_dwn","ZeroingDown"]);
rhs_key_lase_tgt_GLB    = (profileNamespace getVariable ["rhs_key_lase_tgt","LockTarget"]);
rhs_key_dmp_lead_GLB    = (profileNamespace getVariable ["rhs_key_dmp_lead","Throw"]);
rhs_key_nxt_rnd_GLB        = (profileNamespace getVariable ["rhs_key_nxt_rnd","CarHandBrake"]);


// loop handling different optics mode, weapon changing & transition fade effect
["mkk_marder1a1_sight_handler", "onEachFrame", {
    params["_v","_mode_old","_restricted","_time"];

    private _currentWeapon = _v currentWeaponTurret [0];
    if(_currentWeapon in _restricted)then
    {
        private _weaponsList = _v weaponsTurret [0];
        _weaponsList = _weaponsList - _restricted;

        //hintSilent format["%1 %2",_restricted,(_weaponsList # 0)];
        _v selectWeaponTurret [(_weaponsList # 0),[0]];
    };

    // refresh rate 0.01s
    if(time > _time)then
    {
        _this set [3,time+0.01];

        private _mode = ctrlText (uiNamespace getVariable "MKK_MARDER1A1_Ctrl" displayCtrl 154);
        // check if mode was changed
        if(_mode!=_mode_old)then
        {

            // deinitialization part
            if(  ctrlText ( (uiNamespace getVariable "MKK_MARDER1A1_Ctrl")  displayCtrl 1000) != "MKK_SIGHT_PERI_11" )exitWith{
                // remove event handlers & deinitalize variables
                (findDisplay 46) displayRemoveEventHandler ["KeyDown", uiNameSpace getVariable "mkk_peri_z11_eh"];
                (findDisplay 46) displayRemoveEventHandler ["KeyUp", uiNameSpace getVariable "mkk_peri_z11_eh_up"];
                ["mkk_marder1a1_sight_handler", "onEachFrame"] call BIS_fnc_removeStackedEventHandler;
                uiNameSpace setVariable ["MKK_MARDER1A1_Ctrl",displayNull];
                {uiNameSpace setVariable [_x,nil]}foreach ["mkk_peri_z11_eh","mkk_peri_z11_eh_up"];
                {_x = nil}foreach [rhs_fnc_moveReticle];

                //systemChat "removing EH";
            };

            private _sight = (uiNamespace getVariable "MKK_MARDER1A1_Ctrl" displayCtrl 1);
            private _bar = (uiNamespace getVariable "MKK_MARDER1A1_Ctrl" displayCtrl 2);
            private _v = vehicle (call rhs_fnc_findPlayer);
            _this set [0,_v];
            //systemChat format["updating vehicle %1",_mode];

            switch(_mode)do{
                case "PERISCOPE" : {
                    {_x ctrlSetTextColor [0.7,0.074,0.02,1]; }foreach [_bar]; //придаем цвет сетки, чтобы ее было можно видеть
                    {_x ctrlSetTextColor [0.7,0.074,0.02,0]; }foreach [_sight]; //придаем цвет сетки, чтобы ее было можно видеть
                    _bar ctrlSetText "marder\data\WST_peri_z11_x2_sight_ca.paa";
                    _sight ctrlCommit 0.001;
                    _bar ctrlCommit 0.001;
                };
                case "NARROW" : {
                    {_x ctrlSetTextColor [0.7,0.074,0.02,1]; }foreach [_bar,_sight];
                    _sight ctrlSetText "marder\data\WST_peri_z11_x6_sight_ca.paa";
                    _bar ctrlSetText "marder\data\WST_peri_z11_x6_bar_ca.paa";
                    _sight ctrlCommit 0.001;
                    _bar ctrlCommit 0.001;
                };
            };
            // fade effect to simulate changing optical devices
            titleCut ["", "black in", 2];
            // update mode param
            _this set [1,_mode];
        };
    };
},[vehicle (call rhs_fnc_findPlayer),"",[""],time]] call BIS_fnc_addStackedEventHandler;

rhs_fnc_moveReticle = 
{
    // exit if play is not in optic mode
    if(cameraView != "GUNNER")exitWith{};

    params["_dir"];

    disableSerialization;

    private _sight    = (uiNamespace getVariable "MKK_MARDER1A1_Ctrl" displayCtrl 1);
    private _t        = (ctrLPosition _sight) select 1;
    private _move    = _t+0.003*_dir;
    if( (_move <=(16.86 *   (0.025 * SafezoneH))) && (_move >= (3.66 *   (0.025 * SafezoneH))) )then{
        _sight ctrlSetPosition [(ctrLPosition _sight) select 0,_move];
        _sight ctrlCommit 0.005;
    };
};

_id =  (findDisplay 46) displayAddEventHandler ["KeyDown", {
    private _handle=false;
    // reticle range adjustments
    switch(true) do {
        case (inputAction rhs_key_rng_up_GLB > 0): { [1] call rhs_fnc_moveReticle;};
        case (inputAction rhs_key_rng_dwn_GLB > 0): { [-1] call rhs_fnc_moveReticle };
    };
    _handle;
}];

_id2 =  (findDisplay 46) displayAddEventHandler ["KeyUp", {
    private _handle=false;

    //if (inputAction "nightvision" > 0)then {
    // reticle illumination handling
    if(((actionKeys "nightVision") select 0) isEqualTo (_this select 1))then
    {
        disableSerialization;
        private _sight = (uiNamespace getVariable "MKK_MARDER1A1_Ctrl" displayCtrl 1);
        private _bar = (uiNamespace getVariable "MKK_MARDER1A1_Ctrl" displayCtrl 2);
        /*
        if(ctrlText _sight ==  "rhsafrf\addons\rhs_optics\vehicles\data\rhs_bpk_1_42_sight.paa")then{
            _sight ctrlSetText "rhsafrf\addons\rhs_optics\vehicles\data\rhs_bpk_1_42_sight_night.paa";
            _bar ctrlSetText "rhsafrf\addons\rhs_optics\vehicles\data\rhs_bpk_1_42_bar_night.paa";
        }else{
            _sight ctrlSetText "rhsafrf\addons\rhs_optics\vehicles\data\rhs_bpk_1_42_sight.paa";
            _bar ctrlSetText "rhsafrf\addons\rhs_optics\vehicles\data\rhs_bpk_1_42_bar.paa";
        };*/
        //systemChat "change";
    };
    _handle;
}];
uiNameSpace setVariable ["mkk_peri_z11_eh",_id];
uiNameSpace setVariable ["mkk_peri_z11_eh_up",_id2];