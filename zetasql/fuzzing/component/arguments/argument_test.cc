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

#include <memory>
#include "zetasql/fuzzing/component/arguments/argument.h"

#include "gtest/gtest.h"

namespace zetasql_fuzzer {

namespace {

TEST(ArgumentTest, ReleaseValueTest) {
  SQLStringArg arg("test");

  std::unique_ptr<std::string> ptr(arg.Release().ValueOrDie());
  EXPECT_EQ(*ptr, "test");
  EXPECT_DEATH(arg.Release().ValueOrDie(), "Argument is either not set or has been released");
}

TEST(ArgumentTest, NullPtrTest) {
  SQLStringArg arg((std::unique_ptr<std::string>()));

  EXPECT_DEATH(arg.Release().ValueOrDie(), "Argument is either not set or has been released");
}

}  // namespace

}  // namespace zetasql_fuzzer