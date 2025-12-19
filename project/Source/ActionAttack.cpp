#include "ActionAttack.h"

/// <summary>
/// UŒ‚ˆ—
/// </summary>
void ActionAttack::Execute()
{
	target->TakeDamage(attacker->GetCurrentPower() * buffValue);
}
