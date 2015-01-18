#include "script_component.hpp"

class CfgPatches {
  class ADDON {
    units[] = {};
    weapons[] = {};
    requiredVersion = REQUIRED_VERSION;
    requiredAddons[] = {"ace_common"};
    author[] = {"commy2", "KoffeinFlummi", "CAA-Picard", "bux578"};
    authorUrl = "https://github.com/commy2/";
    VERSION_CONFIG;
  };
};

#include "CfgEventHandlers.hpp"

#include "CfgVehicles.hpp"

#include <Menu_Config.hpp>

class ACE_Default_Keys {
  class openInteractionMenuNew {
    displayName = "$STR_ACE_Interaction_InteractionMenu";
    condition = "true";
    statement = QUOTE(call FUNC(onButtonDown));
    conditionUp = QUOTE(!isNull (findDisplay 1713999) && {profileNamespace getVariable [ARR_2(QUOTE(QGVAR(AutoCloseMenu)), false)]});
    statementUp = QUOTE(if (GVAR(MenuType) mod 2 == 0) then {call FUNC(onButtonUp)};);
    exceptions[] = {"ACE_Drag_isNotDragging", "ACE_Medical_canTreat", "ACE_Interaction_isNotEscorting", "ACE_Interaction_isNotSwimming"};
    key = 219;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class openInteractionMenuSelfNew {
    displayName = "$STR_ACE_Interaction_InteractionMenuSelf";
    condition = "true";
    statement = QUOTE(call FUNC(onButtonDownSelf));
    conditionUp = QUOTE(!isNull (findDisplay 1713999) && {profileNamespace getVariable [ARR_2(QUOTE(QGVAR(AutoCloseMenu)), false)]});
    statementUp = QUOTE(if (EGVAR(interaction,MenuType) mod 2 == 1) then {call FUNC(onButtonUp)};);
    exceptions[] = {"ACE_Drag_isNotDragging", "ACE_Medical_canTreat", "ACE_Interaction_isNotEscorting", "ACE_Interaction_isNotSwimming", "ACE_Common_notOnMap"};
    key = 219;
    shift = 0;
    control = 1;
    alt = 0;
  };
};

class ACE_Options {
  class Interaction_FlowMenu {
    displayName = "$STR_ACE_Interaction_FlowMenu";
    default = 0;
  };
  class Interaction_AutoCloseMenu {
    displayName = "$STR_ACE_Interaction_AutoCloseMenu";
    default = 0;
  };
  class Interaction_AutoCenterCursor {
    displayName = "$STR_ACE_Interaction_AutoCenterCursor";
    default = 1;
  };
};

class ACE_Parameters_Boolean {
  ACE_Interaction_EnableTeamManagement = 1;
};

class ACE_canInteractConditions {
  class GVAR(isNotEscorting) {
    condition = QUOTE( !(_player getVariable ['ACE_isEscorting', false]) );
  };
  class GVAR(isNotCaptive) {
    condition = QUOTE( !(_player getVariable ['ACE_isCaptive', false]) );
  };
  class GVAR(isNotSurrendering) {
    condition = QUOTE( !(_player getVariable ['ACE_isSurrender', false]) );
  };
  class GVAR(isNotSwimming) {
    condition = QUOTE( !underwater _player );
  };
};
