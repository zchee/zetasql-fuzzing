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

#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <string>

#include "zetasql/public/evaluator.h"
#include "zetasql/fuzzing/oss_fuzz.h"

// Fuzz target interface implementaion. This function takes of length *Size* 
// an array of randomly generated input of uint8_t, and tries to interpret it
// as a SQL expression.
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  #ifdef __OSS_FUZZ__
    static bool Initialized = zetasql_fuzzer::DoOssFuzzInit();
    if (!Initialized) { std::abort(); }
  #endif

  const std::string sqlExp(reinterpret_cast<const char*>(Data), Size);
  zetasql::PreparedExpression expression(sqlExp);
  expression.Execute(); // Value ignored
  return 0;
}