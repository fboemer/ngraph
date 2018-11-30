//*****************************************************************************
// Copyright 2017-2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include <cstddef>

namespace ngraph
{
    namespace runtime
    {
        namespace reference
        {
            template <typename T>
            void logical_and(const T* arg0, const T* arg1, T* out, size_t count)
            {
                for (size_t i = 0; i < count; i++)
                {
                    out[i] = static_cast<T>(arg0[i] && arg1[i]);
                }
            }
        }
    }
}