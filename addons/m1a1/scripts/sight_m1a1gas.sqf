params ["_veh"];

if(not( isNull (uiNameSpace getVariable ["MKK_M1A1_GAS_Ctrl",displayNull]))) exitWith{};

["mkk_avrs_load", {
    params ["_magazine"];
    _veh setVariable ["mkk_loaded_mag", _magazine, true];
    
}] call CBA_fnc_addEventHandler;
_handle = [{
    params["_v","_mode_old","_restricted","_time"];

    if(time > _time)then
    {
        _this set [3,time+0.01];

        private _mode = ctrlText (uiNamespace getVariable "MKK_M1A1_GAS_Ctrl" displayCtrl 154);
        // check if mode was changed
        if(_mode!=_mode_old)then
        {

            // deinitialization part
            if(  ctrlText ( (uiNamespace getVariable "MKK_M1A1_GAS_Ctrl")  displayCtrl 1000) != "MKK_SIGHT_PERI_11" )exitWith{
                // deinitalize variables
                [_handle] call CBA_fnc_removePerFrameHandler;
                uiNameSpace setVariable ["MKK_M1A1_GAS_Ctrl",displayNull];

                //systemChat "removing EH";
            };

            private _sight = (uiNamespace getVariable "MKK_M1A1_GAS_Ctrl" displayCtrl 1);
            private _v = vehicle (call rhs_fnc_findPlayer);
            private _shell = _v getVariable ["mkk_loaded_mag", "mkk_csw_mag_M829A3"];
            _this set [0,_v];
            //systemChat format["updating vehicle %1",_mode];

            switch(_mode)do{
                case "PERISCOPE" : {
                    {_x ctrlSetTextColor [0.7,0.074,0.02,0]; }foreach [_sight]; //придаем цвет сетки, чтобы ее было можно видеть
                    _sight ctrlCommit 0.001;
                };
                case "ZOOM" : {
                    {_x ctrlSetTextColor [0.7,0.074,0.02,1]; }foreach [_sight];
                    switch(_shell)do{
                        case "mkk_csw_mag_M829A3" : {
                            _sight ctrlSetText "m1a1\data\WST_m236_apfsds_ca.paa";
                        };
                        case "mkk_csw_mag_M830A1" : {
                            _sight ctrlSetText "m1a1\data\WST_m236_heat_ca.paa";
                        };
                        case "mkk_csw_mag_M1069" : {
                            _sight ctrlSetText "m1a1\data\WST_m236_he_ca.paa";
                        };
                    };
                    
                    _sight ctrlCommit 0.001;
                };
            };
            // fade effect to simulate changing optical devices
            titleCut ["", "black in", 2];
            // update mode param
            _this set [1,_mode];
        };
    };

}, 0.1, [vehicle (call rhs_fnc_findPlayer),"",[""],time]] call CBA_fnc_addPerFrameHandler;