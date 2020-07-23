//
// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef ZETASQL_FUZZING_INPUT_H
#define ZETASQL_FUZZING_INPUT_H

#include "zetasql/fuzzing/component/input_visitor.h"

namespace zetasql_fuzzer {

template<typename InputType>
class Input {
 public:
  void Accept(InputVisitor<InputType>& visitor) const;
};

}  // namespace zetasql_fuzzer

#endif  //ZETASQL_FUZZING_INPUT_H