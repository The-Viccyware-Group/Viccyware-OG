/**
 * File: BehaviorWireTest.h
 *
 * Author: Wire
 * Created: 2024-11-25
 *
 * Description: bruh
 *
 * Copyright: Anki, Inc. 2024
 *
 **/

#ifndef __Engine_AiComponent_BehaviorComponent_Behaviors_BehaviorWireTest__
#define __Engine_AiComponent_BehaviorComponent_Behaviors_BehaviorWireTest__
#pragma once

#include "engine/aiComponent/behaviorComponent/behaviors/iCozmoBehavior.h"

namespace Anki {
namespace Vector {

class BehaviorWireTest : public ICozmoBehavior
{
public: 
  virtual ~BehaviorWireTest();

protected:

  // Enforce creation through BehaviorFactory
  friend class BehaviorFactory;
  explicit BehaviorWireTest(const Json::Value& config);  

  virtual void GetBehaviorOperationModifiers(BehaviorOperationModifiers& modifiers) const override;
  virtual void GetAllDelegates(std::set<IBehavior*>& delegates) const override;
  virtual void GetBehaviorJsonKeys(std::set<const char*>& expectedKeys) const override;
  
  virtual bool WantsToBeActivatedBehavior() const override;
  virtual void OnBehaviorActivated() override;
  virtual void BehaviorUpdate() override;

private:

  struct InstanceConfig {
    InstanceConfig();
    // TODO: put configuration variables here
  };

  struct DynamicVariables {
    DynamicVariables();
    // TODO: put member variables here
  };

  InstanceConfig _iConfig;
  DynamicVariables _dVars;
  
};

} // namespace Vector
} // namespace Anki

#endif // __Engine_AiComponent_BehaviorComponent_Behaviors_BehaviorWireTest__
