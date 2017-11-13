/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef THIRD_PARTY_TENSORFLOW_COMPILER_XLA_SERVICE_WHILE_LOOP_SIMPLIFIER_H_
#define THIRD_PARTY_TENSORFLOW_COMPILER_XLA_SERVICE_WHILE_LOOP_SIMPLIFIER_H_

#include "tensorflow/compiler/xla/service/hlo_module.h"
#include "tensorflow/compiler/xla/service/hlo_pass_interface.h"
#include "tensorflow/compiler/xla/statusor.h"

namespace xla {

// HLO pass that makes the following transformations on while loops:
//
//  - A while loop with static trip count of 0 is deleted.
//  - A while loops with static trip count of 1 is replaced by its body (sans
//    loop).
//  - Elements of a while loop's tuple that the loop doesn't use are removed
//    from the tuple.
//
class WhileLoopSimplifier : public HloPassInterface {
 public:
  ~WhileLoopSimplifier() override {}
  tensorflow::StringPiece name() const override {
    return "simplify-while-loops";
  }
  StatusOr<bool> Run(HloModule* module) override;
};

}  // namespace xla

#endif  // THIRD_PARTY_TENSORFLOW_COMPILER_XLA_SERVICE_WHILE_LOOP_SIMPLIFIER_H_