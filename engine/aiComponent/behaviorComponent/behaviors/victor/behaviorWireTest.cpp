/**
 * File: BehaviorWireTest.cpp
 *
 * Author: Wire
 * Created: 2024-11-25
 *
 * Description: Test behavior that makes the robot say "Hello World" upon activation of the "test_wire" intent.
 *
 * Copyright: Anki, Inc. 2024
 **/

#include "engine/aiComponent/behaviorComponent/behaviors/victor/behaviorWireTest.h"
#include "engine/actions/sayTextAction.h"
#include "engine/aiComponent/behaviorComponent/userIntentComponent.h"
#include "engine/actions/animActions.h"
#include "engine/aiComponent/behaviorComponent/userIntents.h"
#include "util/logging/logging.h"

#define LOG_CHANNEL "BehaviorWireTest"

namespace Anki {
namespace Vector {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
BehaviorWireTest::InstanceConfig::InstanceConfig()
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
BehaviorWireTest::DynamicVariables::DynamicVariables()
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
BehaviorWireTest::BehaviorWireTest(const Json::Value& config)
 : ICozmoBehavior(config)
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
BehaviorWireTest::~BehaviorWireTest()
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool BehaviorWireTest::WantsToBeActivatedBehavior() const
{
  // We only want this activated upon a test_wire user intent
  auto& uic = GetBehaviorComp<UserIntentComponent>();
  return uic.IsUserIntentPending(USER_INTENT(test_wire));
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void BehaviorWireTest::GetBehaviorOperationModifiers(BehaviorOperationModifiers& modifiers) const
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void BehaviorWireTest::GetAllDelegates(std::set<IBehavior*>& delegates) const
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void BehaviorWireTest::GetBehaviorJsonKeys(std::set<const char*>& expectedKeys) const
{
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void BehaviorWireTest::OnBehaviorActivated() 
{

  _dVars = DynamicVariables();

  // Activate the "test_wire" intent
  // Lets the system know that a behavior has responded to the intent
  UserIntentPtr intentData = SmartActivateUserIntent(USER_INTENT(test_wire));
  if (!intentData) {
    PRINT_NAMED_WARNING("BehaviorWireTest.OnBehaviorActivated", "No pending 'test_wire' intent found");
    return;
  }

  // Define an action
  auto* greetingAnimAction = new TriggerLiftSafeAnimationAction( AnimationTrigger::GreetAfterLongTime );

  // Actually perform actions
  DelegateIfInControl(
    greetingAnimAction,
    // Callback, will be activated after animation
    // DelegateIfInControl does not hang until completion of action
    [this](){
      // example of defining a new action
      auto* sayHelloAction = new SayTextAction("Hello World", SayTextAction::AudioTtsProcessingStyle::Default_Processed);
      DelegateIfInControl(sayHelloAction);
    }
  );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void BehaviorWireTest::BehaviorUpdate() 
{
  // No periodic updates are necessary for this behavior
}

}
}
